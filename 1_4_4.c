/* 1.4.4 bit operationer � 1p
Skriv ett program med en funktion som skifta (eller flytta) ett teckenl�st heltal (unsigned int) ett
antal steg �t v�nster. B�da ges som indata. Givet tv� tal, x och y, s� skall bitarna i x flyttas y platser
�t v�nster, och bitarna som f�rloras till v�nster hamna till h�ger. D.v.s., bitarna som hamnar utanf�r
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