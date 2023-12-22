/*
1.3.7 Sten, sax, p�se � 1p
Anv�nder din kunskap om C programmering f�r att skriva ett sten, sax p�se spel: anv�nder mot
dator.*/

#include <ansi_c.h>
#include <stdio.h>
#include <utility.h>
#include <stdlib.h>
#define NO_TIMES 10

int main(void)
{
	int choice, i =0;
	char ch;
	int comp;
	
	char r[] ="Rock";
	char s[]="Scissor";
	char p[] = "Paper";
	
	while (i < NO_TIMES)
	{
	printf("Choose either: \n");
	printf("1. Rock\n2. Scissor\n3. Paper\n4. Quit game\n");  // Sten, Sax, P�se
	
	scanf("%i", &choice);
	scanf("%c", &ch);
	printf("\n");
	
	if ((ch != ('\n')) || (choice< 1) || (choice > 4) )
		{
		printf("Only number 1 -3 are allowed");
		printf("\n");
		fflush(stdin);
		}
	else
		{
		srand (time(0));
		// datorn v�ljer random
		comp = rand()%3+1;  // 1, 2 el 3  sten, sax, p�se
		
		
		switch(choice)
			{
			case 1: //1						 
				if (comp == 1)			// sten vs sten - > even
					printf("Computer: %s and Player: %s: Even! \n", r, r);
				else if (comp == 2)		// sten vs sax -> player wins
					printf("Computer: %s and Player: %s: Computer wins! \n", s, r);
				if (comp == 3) 	    	// sten vs p�se  -> Comp wins
					printf("Computer: %s and Player: %s: Computer wins! \n", p, r);
				printf("\n");
				break;
			
			case 2:							
				if (comp == 2) 		   // sax vs sax - > even
					printf("Computer: %s and Player: %s: Even! \n", s, s);
				else if (comp == 1)		// sax vs sten - > Comp wins
					printf("Computer: %s and Player: %s: Computer wins! \n", r, s);
				else if (comp == 3)		// sax vs p�se -> Player wins
					printf("Computer: %s and Player: %s: Player win! \n", p, s);
				printf("\n");
				break;
				
			case 3:	//3						
				if (comp == 3)				// p�se vs p�se -> Even
					printf("Computer: %s and Player: %s: Even! \n", p, p);
				else if (comp == 2)			// p�se vs sax -> Comp wins
					printf("Computer: %s and Player: %s: Computer wins! \n", s, p);
				else if (comp == 1)			// p�se vs sten -> Comp wins
					printf("Computer: %s and Player: %s: Player win!\ n", r, p);
				printf("\n");
				break;	
				
			case 4:		
				exit(1);  // exits the function 						 
			}
		}
		i++;
		printf("Round %i of %i: \n", i, NO_TIMES);
	}
	while(!KeyHit());
	return 0;
}