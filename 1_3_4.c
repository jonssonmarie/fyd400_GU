
/* 1.3.4 while- och case-satser - 2p
Skriv ett program som låter användaren manipulera ett heltal genom en meny. Talet är från början
lika med 0, och användaren erbjuds följande val i en meny:
1) Addera 1
2) Multiplicera med 2
3) Subtrahera 3
4) Avsluta programmet
Vid val 1-3 utförs operationen, och användaren kommer tillbaka till menyn. Vid val 4 avslutas
programmet. Om användaren matar in något annat så skall programmet hantera det på något
lämpligt vis. Tips: använd en case-sats för användarens val i menyn, och en while-sats för att
repetera programmet tills användaren väljer att avsluta. Detta är ett vanligt mönster som du kan
återanvända i andra program!  flera felfall tex 1 mellanslag  eller 1a 1a
*/

#include <ansi_c.h>
#include <stdio.h>
#include <stdbool.h>

void menu(void)  // menu for operations 1 - 4 
{
	int x, choice;
	float result;
	char ch;
 	x = 0;
	
	while(1)
	{
		printf("The number is %d\n",  x );
		printf("The operations you can choose from are: \n1. Addition +1\n2. Multiplication *2\n3. Subtraction -3\n4. Exit\n");
		printf("Choose an operation: \n");
		scanf("%d", &choice);  // 
		scanf("%c", &ch);
		if (ch != '\n')
			{
			printf("Make a new choice \n");
			fflush(stdin);
			continue;
			}
		printf("\n");
	
		switch(choice)
		{
		case 1:
			result = x + 1;
			x = result;
			printf("The new value after addition with +1 is %f \n", result);
			printf("\n");
			break;
			
		case 2:
			result = x * 2;
			x = result;
			printf("The new value after multiplication with 2 is %f \n", result);
			printf("\n");
			break;
	
		case 3:
			result = x -  3;
			x = result;
			printf("The new value after subtraction with 3 is %f \n", result);
			printf("\n");
			break;
			
		case 4:
			exit(1);					// exits the function 
			
		default:
			printf("Enter an correct option\n");
			printf("\n");
			break;
		}
	}
}


int main(void)
{
	menu();
	return 0;
}


