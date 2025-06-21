Q1 --> Write a C program that creates two threds. Each thread should print a message indicating it is running. The main thread should wait for both threads to finish before exiting.

#include <stdio.h>
#include <pthread.h>

void* run_thread(void* arg) {
    printf("Thread %s is running.\n", (char*)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, run_thread, "1");
    pthread_create(&t2, NULL, run_thread, "2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Both threads have finished.\n");
    return 0;
}


output:
[2021ict75@fedora ~]$ vi threadex1.c
[2021ict75@fedora ~]$ gcc threadex1.c -o threadex1
[2021ict75@fedora ~]$ ./threadex1
Thread 1 is running.
Thread 2 is running.
Both threads have finished.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Q2 --> Write a C program that creates 5 threds. Each thread should print its thread ID and then exit. The main thread should join all threads and print a completion message.

#include <stdio.h>
#include <pthread.h>

void* print_id(void* arg) {
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, print_id, NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed.\n");
    return 0;
}

output:

[2021ict75@fedora ~]$ vi threadex2.c
[2021ict75@fedora ~]$ gcc threadex2.c -o threadex2
[2021ict75@fedora ~]$ ./threadex2
Thread ID: 140441704359488
Thread ID: 140441712752192
Thread ID: 140441695966784
Thread ID: 140441687574080
Thread ID: 140441679181376
All threads have completed.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Q3 --> Write a C program that creates a threds whitch prints numbers from 1 to 10 with a 1-second delay between each number. The main thread should wait for this threads to finish.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* count_to_ten(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, count_to_ten, NULL);
    pthread_join(t, NULL);
    printf("Counting complete.\n");
    return 0;
}

output:

[2021ict75@fedora ~]$ vi threadex3.c
[2021ict75@fedora ~]$ gcc threadex3.c -o threadex3
[2021ict75@fedora ~]$ ./threadex3
1
2
3
4
5
6
7
8
9
10
Counting complete.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Q4 --> Create two threads here one thread increments a global counter 100 times and the other thread decrements the same counter 100 times. Print the final value of the counter after both threads finish.

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t inc, dec;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&inc, NULL, increment, NULL);
    pthread_create(&dec, NULL, decrement, NULL);

    pthread_join(inc, NULL);
    pthread_join(dec, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter);
    return 0;
}

output:

[2021ict75@fedora ~]$ vi threadex4.c
[2021ict75@fedora ~]$ gcc threadex4.c -o threadex4
[2021ict75@fedora ~]$ ./threadex4
Final counter value: 0


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Q5 --> Implement a thread function that takes an integer argument, squares it, and returns the result to the main thread using pthread_exit and pthread_join.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    pthread_exit(result);
}

int main() {
    pthread_t t;
    int number = 7;
    void* result;

    pthread_create(&t, NULL, square, &number);
    pthread_join(t, &result);

    printf("Square of %d is %d\n", number, *(int*)result);
    free(result);
    return 0;
}

output:

[2021ict75@fedora ~]$ vi threadex5.c
[2021ict75@fedora ~]$ gcc threadex5.c -o threadex5
[2021ict75@fedora ~]$ ./threadex5
Square of 7 is 49

