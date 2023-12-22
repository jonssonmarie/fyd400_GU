/* 1.4.4 bit operationer – 1p
Skriv ett program med en funktion som skifta (eller flytta) ett teckenlöst heltal (unsigned int) ett
antal steg åt vänster. Båda ges som indata. Givet två tal, x och y, så skall bitarna i x flyttas y platser
åt vänster, och bitarna som förloras till vänster hamna till höger. D.v.s., bitarna som hamnar utanför
de mest signifikanta placeras i de minst signifikanta positionerna.

EJ KLAR !!!!!!!!!!!!!
*/

#include <ansi_c.h>
#include <stdio.h>
#include <utility.h>


void to_binary(unsigned n) 			// From unsigned int to binary 
{ 	
	int c, k;
	char bin_num1[33];
	
	for (c=32; c>=0; c--)
	{
		k= n >> c;
		if (k&1)
			strcpy(bin_num1,"1");
		else
			strcpy(bin_num1,"0");
	printf(" ");
	printf("%d has the binary number %s: \n",n, bin_num1);
	
	}
} 
  

int main(void)
{
	unsigned int num1=0, num2=0;
	
	printf("Enter a integer: \n");
	scanf("%u", &num1);
	printf("Enter a second integer: \n");
	scanf("%u", &num2);
	to_binary(num1);
	printf("\n");
	to_binary(num2);
	while(!KeyHit());
	return 0;
}