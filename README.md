# 📚 Using Pipe
A pipe in Unix/Linux is a method for inter-process communication (IPC), allowing data to flow from one process to another.


These codes are Created using pipe(fd) which gives two file descriptors:
<ul>
  <li>fd[0] → read end</li>
  <li>fd[1] → write end</li>
</ul>


# 🧪 Pipe Exercises in C 
This repository contains two simple C programming exercises demonstrating inter-process communication using pipes (pipe()) in fedora(linux terminal).

### 📁 Files:
pipeExercise.c – : Simulates data transfer from parent to child using a pipe.

pipe.c –: Uses a pipe to send multiple "hello, world" messages within the same process.

pipeExercise2.c – : Using the inputs taken from Parent process child process perform Calculations.

### 🔧 Compilation and Execution
```
gcc pipeExercise.c -o pipeExercise
./pipeExercise
gcc pipe.c -o pipe
./pipe

```
📝 pipe.c – Pipe Without Fork
📄 Description:
This program uses pipe() in a single process to write and read "hello, world" messages.

![pipe1](https://github.com/user-attachments/assets/a924fbf7-c357-4ba2-bdfe-7dce61937275)


## 📝 Exercise 1 – Parent to Child Communication
📄 Description:
This program collects user input from the parent process (name, reg no, and age), sends it to the child process through a pipe, and the child displays it.

![exercise](https://github.com/user-attachments/assets/5bb650bb-5210-4991-a593-59f037d2a1c4)

## 📝 Exercise 2 – Parent to Child Communication
📄 Description:
This program collects user input from the parent process (number 1 & 2), sends it to the child process through a pipe, and the child perform calculations using it.

![exercise2](https://github.com/user-attachments/assets/ff0426f2-b723-423c-8e95-9e7033fa6de9)
