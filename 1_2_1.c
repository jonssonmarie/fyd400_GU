/* 1.2.1 Inmatning och utmatning av tal
From the user input the integer in multiplied with 2 and count how many numbers there are in the number
and print the result.
If the input is not integers (note) a message is writen and exit program.

Note: scanf cut after the integer so: 
	if input 45xjsj then 45 is used, 
	if input is 4.6 then 4 is used, 
	if input is ghnv or &¤#€ the program prints message and exit program 
 */

#include <stdio.h>
#include <utility.h>

int count_digits(int sum) 	// function that count the number of digits in the given number
{
	int count = 0;
	while (sum > 0)
	{
		sum /=10;
		count++;
	}
	return count;
}


int main(void)
{
	int num, sum;
	printf("Enter an Integer: ");
	
	if (scanf("%d", &num) == 1)
		{
		sum = num * 2;
		printf("Number of digits in the integer %d", count_digits(sum));
		}
	else
		{
		while (scanf("%d", &num) != 1)
			{	
			printf("You have not entered an interger!");
			while (!KeyHit());
			exit(0);
			}
		}
	while (!KeyHit());
	return 0;
}

