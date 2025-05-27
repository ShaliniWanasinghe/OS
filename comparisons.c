#########if else
	if(condition){
		//body of if statement;
		
	}
	else{
		//body of else statement;
	}
	
	Example:Enter your age and verify your aligible or not for the election voting
	using if else condition.
	
	
	--code-----
	
	#include<stdio.h>
	int main()
	{
		int age;
		printf("Enter your age:");
		scanf("%d", &age);
		
		if(age>=18){
			printf("You are an eligible voter!");
		}
		else if(age<18){
			printf("Sorry! You are not eligible to Vote");
		}
		else{
			printf("Please enter a valid age!");
		}
		
	return 0;
	}

#output
[2021ict75@fedora ~]$ ./vote
Enter your age:24
You are an eligible voter!

Enter your age:2
Sorry! You are not eligible to Vote	

------------------------------------------------------------------

2)#########Ternary Operator


test_condition ? expression1 : expression2;

#include<stdio.h>
int main()
{
	int age;
		printf("Enter your age:");
		scanf("%d", &age);
	(age>=18 ? printf("You can Vote") : printf("you cannot vote\n"));
	
	return 0;
}

[2021ict75@fedora ~]$ vi ternary.c
[2021ict75@fedora ~]$ gcc ternary.c -o ternary
[2021ict75@fedora ~]$ ./ternary
Enter your age:24
You can Vote

------------------------------------------------------------------------

3)######switch operator


switch(variable/expression){
	case 1:
	//body of case 1
	break
	
	case n:
	//body of case n
	break
	
	default:
	//body of default
}

example 1: Enter the value between 1 to 7  and create a program for following output:
enter the number between 1 to 7 : 1
Today is Sunday!


#code

#include<stdio.h>
int main(){
	int num;
	printf("\nEnter a number");
	scanf("%d",&num);
	
	switch(num){
		case 1:
		printf("\nToday is Sunday");
		break;
		
		case 2:
		printf("\nToday is Monday");
		break;
		
		case 3:
		printf("\nToday is Tuesday");
		break;
		
		case 4:
		printf("\nToday is Wednesday");
		break;
		
		case 5:
		printf("\nToday is Thursday");
		break;
		
		case 6:
		printf("\nToday is Friday");
		break;
		
		case 7:
		printf("\nToday is Saturday");
		break;
		
		default:
		printf("\ninvalid Number");
	}
	
	return 0;
}


Today is Monday[2021ict75@fedora ~]$ vi switch.c
[2021ict75@fedora ~]$ gcc switch.c -o switch
[2021ict75@fedora ~]$ ./switch

Enter a number: 1

Today is Sunday



example 2:
Write a code for small astrology based on your life path number for that get date of birth
from user then calculate lufe path number.(use switch case)

calculation
  a=date%10
   b=date/10 
   c=a+$b

in life path number
  1) "Lucky" 
  2)"Carefully Do your work" 
  3) "Strange" 
  4)"Happy" 
  5)"Can get help" 
  6) "Doubt" 
  7)"Sad" 
  8)"Like"
  9)"Courage"
  *)"Invalid input! " 

#code

#include<stdio.h>
int main()
{
	int date;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	printf("Enter your Birthday: ");
	scanf("%d",&date);
	
   a=date%10;
   b=date/10 ;
   c=a+b;
   d=c%10;
   e=c/10;
   f=d+e;
  
 
   switch(c){
	   
	   case 1:
	   printf("Lucky!");
	   break;
	   
	   case 2:
	   printf("Carefully Do your work!");
	   break;
	   
	   case 3:
	   printf("Strange!");
	   break;
	   
	   case 4:
	   printf("Happy!");
	   break;
	   
	   case 5:
	   printf("Can get help");
	   break;
	   
	   case 6:
	   printf("Doubt!");
	   break;
	   
	   case 7:
	   printf("Sad!");
	   break;
	   
	   case 8:
	   printf("Like!");
	   break;
	   
	   case 9:
	   printf("Courage");
	   break;
	 
	   
	   default:
	   switch(f){
	   
	   case 1:
	   printf("Lucky!");
	   break;
	   
	   case 2:
	   printf("Carefully Do your work!");
	   break;
	   
	   case 3:
	   printf("Strange!");
	   break;
	   
	   case 4:
	   printf("Happy!");
	   break;
	   
	   case 5:
	   printf("Can get help");
	   break;
	   
	   case 6:
	   printf("Doubt!");
	   break;
	   
	   case 7:
	   printf("Sad!");
	   break;
	   
	   case 8:
	   printf("Like!");
	   break;
	   
	   case 9:
	   printf("Courage");
	   break;  
	   
	   default:
       printf("Invalid input!");
    }
   }
 
	return 0;
	
}



##output

[2021ict75@fedora ~]$ vi LPNum.c
[2021ict75@fedora ~]$ gcc LPNum.c -o LPNum
[2021ict75@fedora ~]$ ./LPNum
Enter your Birthday: 12
Strange!

--------------------------------------------------------------
Example 3:
Give list of numbers then calculate the summation and multiplication using for loop.
Example:- 1 2 3 4 5
summation =15
multiplication =120

##Code##

#include<stdio.h>
int main(){
	int sum=0;
	int mul;
	for (i=1 ; i<=5; i++)
	{
		sum=sum+i;
		mul=i*i;
		printf("Summation is:" ,+sum);
		printf("Multiplication is: ");
	}
}

##Output
Summation is: 1
Multiplication is: 1
Summation is: 3
Multiplication is: 4
Summation is: 6
Multiplication is: 9
Summation is: 10
Multiplication is: 16
Summation is: 15
Multiplication is: 25

-----------------------------------------------------------------
Example 4:
Print the integers from 1 to 10 using while loop.

##Code##
#include <stdio.h>

int main() {
    int i = 1;

    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}


##Output
1
2
3
4
5
6
7
8
9
10
----------------------------------------------------------------

Example 5:
Write a C program to generate  and print the Fibinnaci series up to a specified number of terms.
The program should take the number of terms as input from the user and then display the corresponding Fibonnaci sequence

##Code##
#include <stdio.h>

int main() {
    int n, i;
    int first = 0, second = 1, next;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }

    return 0;
}


##Output
Enter the number of terms: 7
Fibonacci Series: 0 1 1 2 3 5 8

----------------------------------------------------------------
Example 6:
Write a C program to calculate the factorial of a given non-negative integer.

##Code##
#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1;

    // Get user input
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check for negative input
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;
}


##Output

Enter a non-negative integer: 5
Factorial of 5 = 120

-----------------------------------------------------------------

Example 7:
Write a C program that:
Accepts two strings as input from the user.
Concatenates the two strings Displays the concatenated result.

##Code##
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];

    // Input 
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove newline 
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    
    strcpy(result, str1);      // Copy str1 into result
    strcat(result, str2);      // Append str2 to result

    // Display the result
    printf("Concatenated string: %s\n", result);

    return 0;
}


##Output
Enter the first string: Hello
Enter the second string: World
Concatenated string: HelloWorld

----------------------------------------------------------------- 
Example 8:
Write  a C program that takes a binary number(as an integer) as input and converts it to its decimal equivalent

##Code##
#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, rem;

    
    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        rem = binary % 10;           // Get the last digit
        decimal += rem * base;       // Add to decimal value
        binary /= 10;                // Remove last digit
        base *= 2;                   // Increase power of 2
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}


##Output
Enter a binary number: 1011
Decimal equivalent: 11

-------------------------------------------------------------------------------

Example 9:
Write a C program that 
Accepts an array of integers from the user,
Finds and  display the max and min values in the array

##code
#include <stdio.h>

int main() {
    int arr[100], n, i;
    int max, min;

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

  
    max = min = arr[0];

   
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

   
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}

##output
Enter the number of elements in the array: 5
Enter 5 integers:
12 7 25 3 18
Maximum value: 25
Minimum value: 3


-------------------------------------------------------------------------------
Example 10:
C program to generate Pascal's Triange
 output:
 
 no of rows=5

           1
		 1   1
	   1   2   1
      1  3   3    1
	1   4  6   4    1
	
##code
#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int rows, i, j, space;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(i = 0; i < rows; i++) {
        
        for(space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }

        
        for(j = 0; j <= i; j++) {
            printf("%4d", combination(i, j));
        }
        printf("\n");
    }

    return 0;
}


## output
Enter number of rows: 5

        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
