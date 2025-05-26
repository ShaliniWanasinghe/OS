<!DOCTYPE html>
<html>
<body>
    <p>In C, processes are managed using <b>fork()</b>, which creates a new process <b>(child)</b> by duplicating the calling process <b>(parent)</b></p>
<ol>
<li> <b>PID (Process ID)</b> </li>
     <br>
     <p>Definition: A unique integer identifier assigned by the OS to each process.</p>
     <br>
         <b>How to Get It:</b>
    
<ul>
      <li>getpid() → Returns the current process’s PID.</li><br>
      <li>getppid() → Returns the parent’s PID.</li>
  
</ul>
<br>
<li> <b> Parent Process</b> </li><br>
<p>Is the original process that creates one or more child processes using fork().</p>

<li> <b> Child Process</b> </li>
<br>
<p>A new process created by fork(). It runs concurrently with the parent.</p>
     
  </ol>



<b>example output:</b>
<p>This is a sample of an activity we tested to get calculations from parent and child processes separately tp check it's functionality</p><br>
<img src="https://github.com/user-attachments/assets/6794e8bb-8f94-4b56-839b-42cddc2eb84f">

</body>
</html>
