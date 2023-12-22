/*
1.3.6 Formatering och gränser - 1p
Skriv ett program som beräknar och skriver ut (med lämplig formatering) resultat från funktionen:
f(x) = 4x3 + 3sin2(x) - 5x – 7
Programmet ska beräkna funktionen med följande gränser:
i) Samtliga heltal x [-15,15]
ii) Samtliga x [-1,1] med en upplösning i x på 0.1
*/

#include <stdio.h>
#include <utility.h>
#include <math.h>

int calculate_func(float x)  // calculate the function
{
	float f_x = 0;
	const double pi = 3.1415926536;
	
	if (x >= -1  && x <=1 )
		{
		f_x = ( 4 * pow(x, 3) + 3 * pow(sin((x*2*pi)/360), 2) - 5 * x - 7 );  // grade to rad (x*2*pi)/360
		printf("The answer is: %.1f\n", f_x);
		}
	else if (x >= -15 && x <= 15)
		{
		f_x = ( 4 * pow(x, 3) + 3 * pow(sin((x*2*pi)/360), 2) - 5 * x - 7 );  
		printf("The answer is: %.3f\n", f_x);
		}
	
	while(!KeyHit());
	return f_x;
}


int main()
{
	float x;
	char ch;
	while(1)
		{
		printf("Enter a integer between -15 and 15!\n");
		scanf("%f", &x);
		scanf("%c", &ch);
		
			if (ch != '\n')
				{
				printf("Only numbers is allowed \n");
				fflush(stdin);
				}
			else if (x < -15 || x > 15)
				{
				printf("Only numbers between -15 and 15 is allowed \n");
				fflush(stdin);
				}
			else
				calculate_func(x);
		
		while(!KeyHit());
		return 0;
		}
}