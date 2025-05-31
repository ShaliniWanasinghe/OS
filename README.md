# Message Queue Implementation

<!DOCTYPE html>
<html>
  <body>


<p>This project demonstrates inter-process communication using message queues in C. It consists of two programs: </p>
<ol>
  <li>send.c - Sends a message to the message queue</li>
  <li>receive.c - Receives the message from the message queue</li>
</ol>
<div>
  <ul>
    <p><h6>Requirements: </h6></p>
    <li>Linux environment (tested on Fedora via PuTTY)</li>
    <li>GCC compiler</li>
    <li>Basic system libraries for IPC</li>
  </ul>
</div> 
<h5>Files</h5>
  <ol>
  <li>send.c - Message sender program</li>
    <li>receive.c - Message receiver program</li>
  </ol>
  <br>
<h5>Testing Notes</h5>
<ul>
  <li>The sender program (send.c) worked successfully as shown here</li><br>
  <img src="https://github.com/user-attachments/assets/fe742d3c-deae-4ef4-beea-139ee52d6edc">
  <br>
  <li>The receiver program (receive.c) encountered an error (ftok failed: No such file or directory) as shown in receive.png</li><br>
  <img src="https://github.com/user-attachments/assets/6d66bba5-051d-4094-956e-bd4fce671eb7">
<br>

</ul>

  </body>
</html>



