/* 2.1.2 Textanalys - 1p
Att söka i texter är ju ett mycket generellt programmeringsproblem.
Här ska du skapa ett program som kan avgöra om ett inmatat ord finns i en godtycklig fil. Om ordet
hittas ska programmet meddela hur många bytes in filen ordet hittades. Om ordet finns mer är en
gång skall samtliga positioner presenteras. Utskrift ska ske till stdout. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <utility.h>
#include <string.h>
#include <errno.h>
#define BUFFERSIZE 150
#define USED_FILE "PTSD.txt"


int find_word( FILE *point, char *ord)
	{	
	int row_n = 1;				// keep track of the rows number		
	int index; 					// for jumping x step with pointer, 
	int count = 0;				// for check if any word exist
	char tempory[BUFFERSIZE];	// field for tempory store one line
	char *tp; 					// pointer to tempory 
	char *pow;					// pointer to found word
	
	tp = tempory;   // pointer points to tempory[0]
	
	while ((fgets(tempory, BUFFERSIZE, point)) != NULL)  			// read line by line 
		{
			
		index = 0;
		
		while ((pow = strstr(tp + index, ord)) != NULL)
			{
			index = (pow - tp) + 1;									// from tp adress jump to pointer position +1 from found word 
			fprintf(stdout, "\nA match found on line: %d\n", row_n);
			fprintf(stdout, "The adress is %i\n", pow);
			count++;
			}
			row_n++;
		}
		
		printf("\n \"%s\" is found %i times", ord, count);
		fflush(stdout);
			
		if(count == 0)
			printf("\nCouldn't find the word.\n");
		
		if(point)
			fclose(point);
		
		fflush(stdin);
		
		return 0;
	}

extern int errno ;

int main(void)
{
	FILE *sfp; 
	sfp = fopen(USED_FILE, "r");							// open file with read
	int errnum;
	

	if (sfp == NULL) 
		{
	    errnum = errno;														// error code
	    fprintf(stderr, "Value of errno: %d\n", errno);						// stderr
	    perror("Error reported from perror");								// displays the string you pass to it and the representation of the current errno value.
	    fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));	// strerror returns a pointer to the representation of the current errno value.
   		}
	else
		{
		char word[50];
		char *pword = word;
		printf("Enter the word you want to search for: \n");
		scanf("%s", word);
		find_word(sfp, pword);										// call function
		}
	while(!KeyHit());
	return 0;
}
