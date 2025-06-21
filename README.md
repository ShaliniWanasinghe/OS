# Multi-Threading Examples in C

This repository contains a collection of C programs demonstrating basic multi-threading concepts using pthreads.

## Contents

1. **Basic Thread Creation** (`threadex1.c`)
   - Creates two threads that print messages
   - Main thread waits for both threads to complete

2. **Multiple Thread Management** (`threadex2.c`)
   - Creates 5 threads that each print their thread ID
   - Main thread joins all threads and prints completion message

3. **Thread with Delay** (`threadex3.c`)
   - Creates a thread that counts from 1 to 10 with 1-second delays
   - Main thread waits for counting to complete

4. **Thread Synchronization** (`threadex4.c`)
   - Two threads (one incrementing, one decrementing) operate on a shared counter
   - Uses mutex locks for thread safety
   - Prints final counter value after both threads complete

5. **Thread Return Values** (`threadex5.c`)
   - Thread function takes an integer, squares it, and returns the result
   - Demonstrates using `pthread_exit` and retrieving values with `pthread_join`



## Notes

- All programs demonstrate proper thread joining to prevent resource leaks
- Program 4 shows critical section protection using mutex locks
- Program 5 demonstrates how to return values from threads using dynamic memory allocation

## Outputs


![1](https://github.com/user-attachments/assets/69f3d0dd-a710-4515-ab11-f0e8d3a45db7)
  
![2](https://github.com/user-attachments/assets/b982f3a2-da82-43b7-852f-bdc83001d476)

![3](https://github.com/user-attachments/assets/816d248d-fd72-4eae-abde-35eb1d6d610a)

![4](https://github.com/user-attachments/assets/85bdcc32-3c44-43e2-b360-17f1c2b4a0f7)

![5](https://github.com/user-attachments/assets/46729227-b671-471f-99ce-955ec3d516e5)




















