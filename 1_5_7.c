/*
1.5.7 Mer dynamisk minnesallokering � 1p
Skriv ett program som l�ser in ett valfritt antal ord. 
Orden skall lagras i str�ngar som allokerats f�r att f� plats med varje ord, 
och pekare till varje ord skall lagras i en allokerad lista av pekare. 
Den f�rsta indatan till programmet �r antalet ord som f�ljer. 

Exempel:
Hur m�nga ord vill du mata in? 5
Ge 5 ord nu:
Idag �r en bra dag.
H�r �r dina ord:
Idag
�r
en
bra
dag.
Anv�nd malloc() och antalet ord f�r att skapa ett dynamisk f�lt med pekare till char. Eftersom varje
element i listan �r en pekare, blir pekaren till listan en pekare till pekare till char. Vid inmatningen
av varje ord kan det lagras i en tempor�r str�ng av fix storlek. Sedan allokeras dynamiskt minne f�r
ordet och det kopieras till det minnesutrymmet.
*/

#include <stdio.h>
#include <utility.h>
#include <string.h>
#define STR_LEN 200

int main (pcw)
{
	char word_list[STR_LEN +1];
	int n = 0;
	
	printf("How many words do you want to enter? \n");
	scanf("%i", &n);
	fflush(stdin);
	
	printf("Enter %i words!\n", n);
	fgets(word_list, STR_LEN +1, stdin); 				
	fflush(stdin);
	printf("\n");
		
	int len = strlen(word_list);						// used for memory
	
	char *ptr = (char *) malloc(len * 8 + 1);   		// initial memory allocation
	strcpy(ptr, word_list);								// copy word_list into ptr 
	
	char *token = strtok(ptr," ,.-"); 					//strtok() break with delimiters and return pointer to the first word
	
	printf("Here are your words\n");
	
	while (token != NULL)
		{
		printf("%s\n", token);
		token = strtok(NULL," ,.-");					// strtok steps through and give pointer to each word
		}
	
	while(!KeyHit());
	free (ptr);
	return 0;
}

