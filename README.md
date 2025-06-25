#  Unix/Linux Lab Exercises

This repository contains practice exercises I completed during my university lab sessions, covering various Unix/Linux shell scripting concepts.

### 1. Student Marksheet (Q1)
**Description**: A script that takes student name and marks for 3 subjects, then displays a marksheet with grades, total, and average.

**Output**:
```
Enter student's name: Shalini
Enter marks for Subject 1: 89
Enter marks for Subject 2: 98
Enter marks for Subject 3: 80

--- Student Marksheet ---
Name    : Shalini
Subject 1   : 89 (Grade: B)
Subject 2    : 98 (Grade: A)
Subject 3    : 80 (Grade: B)
Total Marks : 267
Average    : 89
```

### 2. Multiplication Table (q2.sh)
**Description**: Generates a multiplication table for a given number.

**Output**:
```
Enter a number: 2

Multiplication Table for 2

2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20
```

### 3. Leap Year Checker (Q3.sh)
**Description**: Checks if a given year is a leap year.

**Output**:
```
Enter a year: 2025
2025 is NOT a Leap Year.

Enter a year: 2024
2024 is a Leap Year.
```

### 4. Birthday Checker (04.sh)
**Description**: Checks if today is the user's birthday.

**Output**:
```
Enter your birth day (DD): 12
Enter your birth month (MM): 05
Today is not your birthday, but I hope you're having a great day anyway!

Enter your birth day (DD): 23
Enter your birth month (MM): 06
Happy Birthday! 💬 Wishing you a fantastic day!
```

### 5. Process Communication (pipe example)
**Description**: Demonstrates inter-process communication using pipes.

**Output**:
```
Hello, I am Child B  
my id is 14437  
Enter two integers: 2  
7  
Hello, I am Child C  
my id is 14445  

Results in Parent (PID 14436)  
Sum : 9  
Difference : -5  
Product : 14  
Quotient : 0.29
```

## Usage
1. Clone the repository
2. Make scripts executable: `chmod +x *.sh`
3. Run scripts: `./script_name.sh`

