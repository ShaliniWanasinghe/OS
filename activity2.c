#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to compute factorial
void compute_factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of first number: %d\n", fact);
}

// Function to print Fibonacci series
void print_fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series: 0, 1");
    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        printf(", %d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

// Function to check if a number is prime
void check_prime(int n) {
    if (n <= 1) {
        printf("The number %d is not prime.\n", n);
        return;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            printf("The number %d is not prime.\n", n);
            return;
        }
    }
    printf("The number %d is prime.\n", n);
}

int main() {
    int num1, num2, num3;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the third number: ");
    scanf("%d", &num3);

    printf("Parent (A)\n");

    pid_t pid_b = fork();
    if (pid_b == 0) {
        // Child B
        printf("Child of A(B)\n");
        printf("Id:%d\n", getpid());
        printf("Parent Id:%d\n\n", getppid());
        compute_factorial(num1);
        exit(0);
    }

    pid_t pid_c = fork();
    if (pid_c == 0) {
        // Child C
        printf("Child of A(C)\n");
        printf("Parent Id:%d\n\n", getppid());

        pid_t pid_d = fork();
        if (pid_d == 0) {
            // Child D
            printf("Child of C(D)\n");
            printf("Parent (C)\n");
            printf("Parent Id:%d\n\n", getppid());
            printf("Id:%d\n", getpid());
            print_fibonacci(num2);
            exit(0);
        }

        pid_t pid_e = fork();
        if (pid_e == 0) {
            // Child E
            printf("Child of C(E)\n\n");
            printf("Parent Id:%d\n", getppid());
            check_prime(num3);
            exit(0);
        }

        // Wait for D and E to finish
        wait(NULL);
        wait(NULL);
        exit(0);
    }

    // Parent waits for B and C to finish
    wait(NULL);
    wait(NULL);

    return 0;
}