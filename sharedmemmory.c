//send
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10
//structure for message queue
struct mesg-buffer {
    long mesg_type;
    char mesg_text[100];
} message;
int main()
{
    key_t key;
    int msgid;
    //ftook to generate unique key
    key = ftook("progfile",65);
    //msgget creates a messagw queue
    //and returns identifier 
    msgid = msgget(key, 0666 | ICP_CREAT);
    message.mesg_type=1;

    printf("Write Data :");
    fgets(message.mesg_text,MAX,stdin)

    //msgsnd to send message
    msgsnd(msgid, &message , sizeof(message), 0);

    //display the message
    printf("Data send is : %s \n", message.mesg_text);
    return 0;
}



//receive

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>