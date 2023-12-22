/*
1.5.2 Flyttande pekare – 1p
Gör ett program med en meny liknande uppgift 1.3.4 - ändrat från 1.3.3. MARIE
Ditt program skall skapa en sträng i minnet:
char text[] = "Gothenburg";
samt en pekare som pekar på början av strängen:
char *my_pointer = text;
Låt nu användaren manipulera pekaren med menyvalen, och skriv ut vad pekaren pekar på. Pekaren
får inte peka utanför det allokerade minnet. Exempel på utskrift kan vara:
Strängen är: ”Gothenburg”.
Pekaren pekar på ”G”, välj en operation:
1) Plus 1
2) Minus 1
4) Avsluta programmet
*/

#include <ansi_c.h>
#include <stdio.h>


void menu(void)  // menu for operations 1 - 3 
{
	char text[11] = "Gothenburg";
 	char *my_pointer, ch;  
	int nchar = 0, choice;
	
	my_pointer = text;              // points at text[0]
		
		while(*my_pointer !='\0') 
			{	
				printf("The string is %s \n", text);
				printf("The pointer points at %c\n", *my_pointer);
				printf("\n");
				
				printf("The operations you can choose from are: \n1. Addition +1\n2. Subtraction -1\n3. Exit\n");
				printf("Choose an operation:  ");
				scanf("%i", &choice);
				scanf("%c", &ch);
				printf("--------------------------------------------\n");
			
				if (ch != '\n')   				// checks the input
					{
					printf("Only numbers is allowed\n");
					printf("\n");
					fflush(stdin);
					}
				else 
					{
					switch(choice)
						{
						case 1:		
							if (*my_pointer == text[0])  // check if the value my_pointer points to is the same as the 0:nd element
								{
								nchar++;   			// calculate the number of elements in text
								my_pointer++;		// moves pointer 1 step up
								printf("The character after addition with +1: %c \n", *my_pointer);
								printf("\n");
								break;
								}
							else if (*my_pointer == text[9])  // check if pointer value corresponds to the value of the 9:th element
								{
								my_pointer = text;  	// points at text[0]
								printf("The character is: %c \n", *my_pointer);
								printf("\n");
								break;
								}
							else 							
								{
								nchar ++;
								my_pointer++;
								printf("The character after addition with +1: %c \n", *my_pointer);
								printf("\n");
								break;
								}
							
						case 2:
							if (*my_pointer == text[0])  	// check if the value of my_pointer points to is the same as the 0:nd element of text
								{
								my_pointer = text; 			// points at text[0]
								printf("The character is: %c \n", *my_pointer);
								printf("\n");
								break;
								}
							else if (*my_pointer == text[9]) 	// check if pointer value corresponds to the value of the 9:th element
								{
								nchar--;
								my_pointer--;			// moves pointer 1 step down
								printf("The character after subtraction with -1: %c \n", *my_pointer);
								printf("\n");
								break;
								}
							else
								{
								nchar--;
								my_pointer--;
								printf("The character after subtraction with -1: %c \n", *my_pointer);
								printf("\n");
								break;
								}
					
						case 3:
							exit(1);					// exits the function 
							
						default:
							printf("Enter an correct option\n");
							printf("\n");
							break;
						}
					}	
				}
}


int main(void)
{
	menu();
	return 0;
}