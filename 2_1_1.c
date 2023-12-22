/* 2.1.1 Filer - 1p
Det kan ibland vara lite sv�rt att avg�ra vad som finns i en fil och/eller i minnet. H�r en �vning som
testar din f�rm�ga att separera begreppen och att h�lla tungan r�tt i mun.
Konstruera ett program som f�rst skapar tre matriser:
0.0  1.0 	0.0 1.0		 0.0 -1.0
-1.0 0.0 	1.0 0.0 	 1.0  0.0
N�r matriserna �r skapade ska programmet skriva ner var och en av dessa till en egen fil med
namnen matris1.bin, matris2.bin och matris3.bin. 
Om filerna redan finns ska programmet skriva �ver dessa. Data skall skrivas till filerna i bin�rformat. 
Efter att samtliga matriser �r sparade till fil ska programmet skriva ut matriserna som finns i minnet till stdout varp� de minnesresidenta
matriserna skall nollst�llas. 
Programmet ska nu �nyo ladda in respektive matrisdata till r�tt matris och sedan skriva ut den nyligen inl�sta informationen till stdout. 

1. skapa 3 matriser
2. skapa filerna
3. transformera float till bin�r i matriserna, anv�nda pekare och loop
4. skriva ut filerna till stdout och matriserna nollst�llas
5. l�sa in matriserna igen och l�gga i r�tt matris och sedna skriva ut till stdout.
*/

#include <ansi_c.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility.h>
#include <stdint.h>

#define ARRAY1 "matris1.dat"
#define ARRAY2 "matris2.bin"
#define ARRAY3 "matris3.bin"


int i,ii, j;
int row;
 
char *decimal_to_binary(int n)  // fixa for -1
	{
	  int c, k, t;
	  char *pbin;
	  t = 0;
	  
	  pbin = (char*)malloc(32+1);

	  if (pbin == NULL)
	    exit(EXIT_FAILURE);

	  for (c = 31 ; c >= 0 ; c--)
		  {
		   k = n >> c;
		   if (k & 1)
		      *(pbin+t) = 1 + '0';
		   else
		      *(pbin+t) = 0 + '0';

		   t++;
		  }
		  
	  *(pbin+t) = '\0';
	  return  pbin;
	}
 

 /*  #include<stdio.h>  // fr�n l�raren

int main () 
  	{
   FILE *fp;
   char str[] = "This is tutorialspoint.com";

   fp = fopen( "file.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );

   fclose(fp);
  
   return(0);
	}
 */

 

int main(void)
	{
	float array1[2][2] = {{0.0, 1.0}, {-1.0, 0.0}};    // 0000, 0001  0001-> 1110+1 = 1111   , 0000
	float array2[2][2] = {{0.0, 1.0}, {1.0, 0.0}};
	float array3[2][2] = {{0.0, -1.0}, {1.0, 0.0}};
			
	FILE *arr1, *arr2, *arr3;
	
	arr1 = fopen(ARRAY1, "w+");   // �ppnar och skapar filerna
	arr2 = fopen(ARRAY2, "w+");
	arr3 = fopen(ARRAY3, "w+");
	
	
	for (i=0; i<3; ++i) // loop row by row 
		printf(array1[i]);
		fwrite(array1, 1, sizeof(float), arr1);
	fclose(arr1);
	
	float (*prow_array1)[2] = array1;  // pointer for row in array1
	float  *pcol_array1 = NULL;		// pointer for column in array1
	
	
	for (;prow_array1 != array1+2; ++prow_array1)
		{
		for (pcol_array1 = *prow_array1; pcol_array1 != *prow_array1+2; ++pcol_array1)
			printf("%i\n", &pcol_array1);
		}
		
	
	/*if (arr1 == NULL || arr2 == NULL || arr3 == NULL)
		{
		printf("Can't open file");
		exit(EXIT_FAILURE);		
		}
	else 
		{
		arr1 = fopen(array1_file, "wb");
		for (i=0; i<10; ++i) // loop row by row 
			float *f = (float) i;
			fwrite(&f, sizeof(float), 1, array1_file);
	 	}
	*/
	
	

	  int n;
	  char *p;

	  printf("Enter an integer in decimal number system\n");
	  scanf("%d", &n);

	  p = decimal_to_binary(n);
	  printf("Binary string of %d is: %s\n", n, p);

	  free(p);

	  


	while(!KeyHit());
	return 0;
	}
