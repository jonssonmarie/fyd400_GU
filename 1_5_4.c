/* 
1.5.4 Fält - 1p
Att deklarera ett fält av variabler (en array) är i princip ett sätt att allokera en viss mängd minne och
få en pekare till det första elementet. 
Förklara vad som händer i de två programsegmenten nedan
och ange speciellt var det finns fel som går igenom en kompilering men ändå inte gör det man kan
tänka sig var det förväntade.
a) double dblField [100];         		//deklaration av fält med 100 element
. . .
dblField = dblField + 10;				// samma fältnamn får fältnamnet + 10 ????   går inte att assigna till då det inte är en pekare ???

b) double dblField [100], *pDblField;
. . .
pDblField = dblField + 10; 				// pekaren pDblField tilldelas fältnamnet dblField[0] värde + 10 om  &dblFields[0] skulle varit med
										// pDbldField + 10 -> ger adressen för plats 10 i dblField  om   pDblField = dblField

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