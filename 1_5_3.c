/* 1.5.3 Minnesadresser - 1p
Pekarvariabler är helt enkelt heltal som kan tolkas som en viss position i datorns minne: en adress.
Anledningen till att vi inte bara använder heltal är att pekare har en egen matematik.

Skriv ett program som har tre pekarfält: en int*[], en char*[], och en double*[], alla med 4 element.
Programmet ska skriva ut adressen till alla element med hjälp av en for-loop och pekararitmetik.
Programmet ska även skriva ut skillnaden mellan adresserna i det tredje och det andra elementet av
alla fält.
Vad får du för resultat? Varför är det på detta sätt?

Kommentar till mig själv:
To declare a pointer variable: When a pointer variable is declared in C, there must be a * before its name
Int* my_array[] etc är en pekare till en int så en hel array kan hittas då en hel array inte kan skickas till en funktion: 
*/

#include <ansi_c.h>
#include <stdio.h>
#include <utility.h>

int main(void)
{
	int *num, i;
	char *name;
	double *dubbel;
	 
	int n[4] = {1,2,3,4};
	char c[5] = "abcd";
	double d[4] = {1.00, 2.00, 3.00, 4.00};
				   
	// assign the adress of eg. n[0] to num 			   
	num = n;
	name = c;
	dubbel = d;
	
 	printf("\n");
	for (i=0; i < 4; i++)
		{
		printf("The adress for num[%d] is: %p (hex) or as %d (int) \n", i, num, num);
		num++;
		}

	int *num2 = n + 1;  // points to 2nd element
	int *num3 = n + 2;  // points to 3rd element
	
	printf("\n");
	printf("The adress of 2nd element: %p (hex) or as %d (int)\n", num2, num2);
	printf("The adress of 3rd element: %p (hex) or as %d (int) \n", num3, num3);
	
	printf("\n");
	printf("Difference between 2nd and 3rd element is: %d\n", (num3 -num2));
	 /* Pointer subtraction yields the number of array elements between two pointers of the same type.
	 In this case 1, if between [0]  and [3] it would be 3 */

	printf("--------------------------------------------------------------\n");	
	printf("\n");
	for (i=0; i < 4; i++)
		{
		printf("The adress for name [%d] is: %p (hex) or as %d (int) \n", i, name, name);
		name++;
		}
		
	char *name2 = c + 1;  // points to 2nd element
	char *name3 = c + 2;  // points to 3rd element
	
	printf("\n");
	printf("The adress of 2nd element: %p (hex) or %d (int)  \n", name2, name2);
	printf("The adress of 2nd element: %p (hex) or %d (int)  \n", name3, name3);
	
	printf("\n");
	printf("Difference between 2nd and 3rd element is: %d \n", (name3 - name2)); 
	/* Pointer subtraction yields the number of array elements between two pointers of the same type.
	 In this case 1, if between [0]  and [3] it would be 3 */
	
	printf("---------------------------------------------------------------\n");	
	printf("\n");
	
	for (i=0; i < 4; i++)
		{
		printf("The adress for dubbel [%d] is:  %p (hex) or as %d (int)\n", i, dubbel, dubbel);
		dubbel++;
		}
	
	double *dubbel2 = d + 1;  // points to 2nd element
	double *dubbel3 = d + 2;  // points to 3rd element
	
	printf("\n");
	printf("The adress of 2nd element: %p (hex) or as %d (int)\n", dubbel2, dubbel2);
	printf("The adress of 2nd element: %p (hex) or as %d (int)\n", dubbel3, dubbel3);
	
	printf("\n");
	printf("Difference between 2nd and 3rd element is: %i \n", dubbel3 - dubbel2); 
	/* Pointer subtraction yields the number of array elements between two pointers of the same type.
	 In this case 1, if between [0]  and [3] it would be 3 */
	printf("\n");
	printf("------------------------ END --------------------------------------\n");	
		
	while(!KeyHit());
	return 0;
	}