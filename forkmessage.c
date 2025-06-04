Exercise

IPC using Message Queue

read inputs from the parent process
Enter Name: Hi
Enter RegNo: 2175
Enter Age:24

Message sent Successfully!

give the output in the child process

Received Name: Hi
received RegNo: 2175
Received Age:24


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX 100

// Structure for the message queue
struct msg_buffer {
    long msg_type;
    char name[MAX];
    char regno[MAX];
    int age;
};

int main() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok("/tmp/75progfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msg_buffer message;
    message.msg_type = 1;

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // Parent process: input and send
    if (pid > 0) {
        printf("Enter Name: ");
        fgets(message.name, MAX, stdin);
        message.name[strcspn(message.name, "\n")] = 0; // Remove newline

        printf("Enter RegNo: ");
        fgets(message.regno, MAX, stdin);
        message.regno[strcspn(message.regno, "\n")] = 0;

        printf("Enter Age: ");
        scanf("%d", &message.age);

        // Send message
        if (msgsnd(msgid, &message, sizeof(struct msg_buffer) - sizeof(long), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("\nMessage sent Successfully!\n");
    }

    // Child process: receive and print
    else {
        // Receive message
        if (msgrcv(msgid, &message, sizeof(struct msg_buffer) - sizeof(long), 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("\nReceived Name: %s\n", message.name);
        printf("Received RegNo: %s\n", message.regno);
        printf("Received Age: %d\n", message.age);

        // Destroy the queue after use
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
