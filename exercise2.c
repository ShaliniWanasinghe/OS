exercise 02

step 1: Parent process: get input from user

step 2: sending those inputs to chil process

step 3: Child process getting those inputs from parent and doing calculations

step 4: send the calculated values to parent

step 5: parent print the output

--code----

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd1[2], pipefd2[2];  // Two pipes: one for input, one for returning results
    pid_t pid;

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();  // Create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {  // Parent Process
        close(pipefd1[0]);  // Close read end of first pipe
        close(pipefd2[1]);  // Close write end of second pipe

        int a, b, results[3];

        // Getting input from user
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);

        // Sending data to child
        write(pipefd1[1], &a, sizeof(a));
        write(pipefd1[1], &b, sizeof(b));
        close(pipefd1[1]);  // Close write end

        // Receiving results from child
        read(pipefd2[0], results, sizeof(results));
        close(pipefd2[0]);  // Close read end

        // Printing results
        printf("\nResults from Child Process:\n");
        printf("Sum: %d\n", results[0]);
        printf("Difference: %d\n", results[1]);
        printf("Product: %d\n", results[2]);
        
    } else {  // Child Process
        close(pipefd1[1]);  // Close write end of first pipe
        close(pipefd2[0]);  // Close read end of second pipe

        int x, y, result_values[3];

        // Reading data from parent
        read(pipefd1[0], &x, sizeof(x));
        read(pipefd1[0], &y, sizeof(y));
        close(pipefd1[0]);  // Close read end

        // Performing calculations
        result_values[0] = x + y;
        result_values[1] = x - y;
        result_values[2] = x * y;

        // Sending results back to parent
        write(pipefd2[1], result_values, sizeof(result_values));
        close(pipefd2[1]);  // Close write end
    }

    return 0;
}


