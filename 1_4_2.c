
/*
1.4.2 Funktionsargument � pass by value - 1p
Skriv ett program med en funktion dubblera, som dubblerar ett tal:
void dubblera(int x)
{
x = 2*x;
}
G�r en main-funktion som 1) initierar ett heltal till n�got v�rde, 2) skriver ut det, 3) anv�nder
funktionen dubblera p� det och 4) skriver ut talet igen.
a) Vad ger ditt program f�r svar, och varf�r?
b) Ge ett f�rslag p� hur man kan g�ra en dubblera-funktion ist�llet.
*/


#include <ansi_c.h>
#include <stdio.h>
#include <utility.h>

/*
void dubblera(int x)     // 1.4.2 a)    multiplication with 2
{
	x = (2 * x);
	
}

int main()
{
	int x;
	x = 0;
	printf("Enter an integer: \n");
	scanf("%i", &x);
	printf("This is the integer you added: %i \n", x);
	printf("\n");
	printf("This is the number after multipilcation with 2:  %i \n", dubblera(x));   // Answer: error: argument tyoe "void" is incomplete 
	
	while(!KeyHit());
	return 0;
} 

*/

void dubblera(void)    // 1.4.2 b)  multiplication with 2
{
	int x;
	x = 0;
	printf("Enter an integer: \n");
	scanf("%i", &x);
	printf("\n");
	printf("This is the integer you added: %i \n", x);
	x = (2 * x);
	printf("This is the number after multiplication with 2:  %i \n", x); 

}

int main()
{
	dubblera();  
	
	while(!KeyHit());
	return 0;
} 
