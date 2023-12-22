// Allow multiplication for integers

#include <utility.h>
#include <stdio.h>

int main(void)
{
	int tal1, tal2, sum;
	printf("L\x86t oss g\x94ra lite matte! \n");  	// \x86 = å and \x94 = ö
	printf("Skriv in ett heltal: \n");
	scanf("%d", &tal1);								// sets input to tal1
	printf("Skriv in ett andra heltal \n");
	scanf("%d", &tal2);								// sets input to tal2
	sum = tal1 * tal2;
	printf("%d * %d = %d \n", tal1, tal2, sum);		// prints the sum
	while(!KeyHit());
	return 0;
}