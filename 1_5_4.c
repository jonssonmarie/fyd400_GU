/* 
1.5.4 F�lt - 1p
Att deklarera ett f�lt av variabler (en array) �r i princip ett s�tt att allokera en viss m�ngd minne och
f� en pekare till det f�rsta elementet. 
F�rklara vad som h�nder i de tv� programsegmenten nedan
och ange speciellt var det finns fel som g�r igenom en kompilering men �nd� inte g�r det man kan
t�nka sig var det f�rv�ntade.
a) double dblField [100];         		//deklaration av f�lt med 100 element
. . .
dblField = dblField + 10;				// samma f�ltnamn f�r f�ltnamnet + 10 ????   g�r inte att assigna till d� det inte �r en pekare ???

b) double dblField [100], *pDblField;
. . .
pDblField = dblField + 10; 				// pekaren pDblField tilldelas f�ltnamnet dblField[0] v�rde + 10 om  &dblFields[0] skulle varit med
										// pDbldField + 10 -> ger adressen f�r plats 10 i dblField  om   pDblField = dblField

*/

#include<stdio.h>
#include<utility.h>

int main(void)
{
double dblField[100], *pDblField, *ppDblField;

//a
/*
dblField = dblField + 10;    // dblField points always on pos 0 and can not be changed 
printf("a) dblField %i\n", &dblField);
*/

// b

pDblField = dblField + 10;  // eqvivalent to &dblField[10] and pointer is given the 10th (act 9) adress wich is 80 byte (8 *10) ahead
ppDblField = dblField;
printf("dblField: %i\npDblField: %i\n", dblField, pDblField);
printf("ppDblField %i\n", ppDblField);
printf("dblField[0] %i\n",  &pDblField[0]);
printf("pDblField[9] %i\n", &pDblField[10]);

// If the purpose were to increase the array it is notpossible to do statically, the array i fixed, use dynamically with realloc() function if need to change array size





while(!KeyHit());
return 0;
}