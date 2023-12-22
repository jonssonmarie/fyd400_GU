/* 1.3.1 Bitar – 1p
Skriv ett program som skriver ut antalet bitar i en int på din dator. 
*/

#include <utility.h>
#include <stdio.h>

int main(void)   // return the size in byte of an integer
	{
	int num;
	printf("Enter a integer: ");
	scanf("%d", &num);
	printf("The size of bites is: %zd\n", (sizeof(num)*8));
	while(!KeyHit());
	return 0;
	}