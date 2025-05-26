# Process Concepts in C: PID,Parent and Child 🖥️
<!DOCTYPE html>
<html>
  <body>
    <p>In C, processes are managed using <b>fork()<b>, which creates a new process <b>(child)<b> by duplicating the calling process <b>(parent)<b></p>
1. PID (Process ID)
Definition: A unique integer identifier assigned by the OS to each process.

How to Get It:
getpid() → Returns the current process’s PID.
getppid() → Returns the parent’s PID.

2. Parent Process
Is the original process that creates one or more child processes using fork().

4. Child Process
A new process created by fork(). It runs concurrently with the parent.

<b>example</b>
<p>this exercise is created to get the factorial and Fibonnaci series by the child processes of same parent</p>
<img src="https://github.com/user-attachments/assets/23ed5907-a003-43b5-b64b-1c7cf3518bb4">
<br><br>

      
  </body>
</html>



