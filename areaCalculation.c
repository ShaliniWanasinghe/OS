Area Calculation program.

Circle => C
Triangle => T 
Square => S 
Rectangle => R 
Enter your choice: C 

Circle Area Calculation: 
 Enter the radius: 20.9
 Area is 1371.58
 
 code:
 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h> 

void calculate_area(char shape, double value) {
    double area = 0.0;
    switch (shape) {
        case 'C':
            area = 3.1416 * value * value;
            printf("Circle Area Calculation:\n Enter the radius: %.1f\n Area is %.2f\n", value, area);
            break;
        case 'T':
            area = 0.5 * value * value; 
            printf("Triangle Area Calculation:\n Enter the side length: %.1f\n Area is %.2f\n", value, area);
            break;
        case 'S':
            area = value * value;
            printf("Square Area Calculation:\n Enter the side length: %.1f\n Area is %.2f\n", value, area);
            break;
        case 'R':
            area = value * value; 
            printf("Rectangle Area Calculation:\n Enter the width: %.1f\n Area is %.2f\n", value, area);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int pipefd[2]; //pipe file description array
    pid_t pid;  //hold the pid afer fork()
    char shape;  //to store selected shapes 
    double value; //to store the values 
    char buffer[100];  //buffer to store the transmission

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork(); //to create the child process to Read fd[1]
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {  //parent process to write fd[0]
        close(pipefd[0]); 
        printf("Area Calculation program.\n\nCircle => C\nTriangle => T\nSquare => S\nRectangle => R\nEnter your choice: ");
        scanf(" %c", &shape); /
        printf("\nEnter the value (radius/side/width): ");
        scanf("%lf", &value);

        write(pipefd[1], &shape, sizeof(shape)); //send data to child using write()
        write(pipefd[1], &value, sizeof(value));
        close(pipefd[1]);
        wait(NULL); 
    } else {  // Child process
        close(pipefd[1]); 
        read(pipefd[0], &shape, sizeof(shape));
        read(pipefd[0], &value, sizeof(value));
        close(pipefd[0]);

			
        calculate_area(shape, value); //function calling for the calculation part in child process
        exit(0);
    }
    return 0;
}
