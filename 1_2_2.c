/*
Input are two integers, return are:
• Talet P på hexadecimal form,
• Talet P/Q på flyttalsform med exakt 3 decimaler,
• Talet P%Q på heltalsform
• Talet Q*P på tiopotensform (”scientific notation”),
• Talet Q med nollpadding till totalt 9 siffror (ex: 747 skrivs 000000747)
*/


#include <stdio.h>
#include <utility.h>

int main(void)
{
	int numP = 0, numQ = 0, mod;
	float divsum, mult;
	
	printf("Enter an integer:\n");
	scanf("%d", &numP);
	printf("Enter an integer:\n");
	scanf("%d", &numQ);
	
	divsum = (float) numP/numQ;  	// division 
	mod = numP % numQ;  			// modulus, return remainder
	mult = numP * numQ; 			// multiplication
	
	printf("P as hexadecimal: %x \n", numP);
	printf("P/Q as float: %.3f \n", divsum);		
	printf("Return the remainder from the modulus operation: %d \n", mod);  
	// a % b = a - floor(a / b) * b,  if   a=5, b=7   ->    5 % 7 = 5 - floor(5 / 7) * 7 = 5
	printf("The scientific notation of P*Q is: %e \n", mult);
	printf("Padding number is: %09d \n",numQ); 
	while (!KeyHit());
	return 0;
}