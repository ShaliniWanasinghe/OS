# Using Pipe for Calculations
<p>This is a area calculation program written using pipe.in the code, the <b>Parent process</b> is used to Read the input values(shape & Value) using the pipe fd[1], and <b>Child process</b> to read the values and perform the calculation at the other end of the pipe fd[0]</p>
<br>
<p>here i have used a function where switch case used to perform calculations and called it at the end of the child process fd[0] and exit</p>

![eaxmple Output](https://github.com/user-attachments/assets/65dc8336-63b3-422a-b995-43ef03b2f7bf)


![Area Cal](https://github.com/user-attachments/assets/f6bd893c-8479-48ca-a641-04660440ac99)


<p>Other than this method using 2 pipes also this programme can be run as making the pipe to work bidirectional</p>
<br>
<p>When using two pipes the process will be Parent to Child first and then from Child to Parent</p>
