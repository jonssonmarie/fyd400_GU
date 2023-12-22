/*
Pekarvariabler �r helt enkelt heltal som kan tolkas som en viss position i datorns minne: en adress.
Alla variabler finns lagrade n�gonstans i minnet, och har en adress. En pekare anv�nds f�r att
referera till olika st�llen i minnet. Har man en pekare kan man referera till det den pekar till med *-
operatorn. Vice versa kan man med en variabel f� veta dess adress med &-operatorn. F�ljande
uppgifter syftar till att praktisera dessa

1.5.1 Pekare, avreferering och adresser � 2p
a) Om vi har deklarationerna
int heltal = 10;
int *pekare_till_heltal = &heltal;
Vilka av f�ljande uttryck resulterar i en utskrift av talet 11? (och varf�r? Testa!)
1) printf("%i\n", pekare_till_heltal + 1);
2) printf("%i\n", heltal+1);
3) printf("%i\n", *(&heltal)+1);
4) printf("%i\n", *(pekare_till_heltal + 1));
5) printf("%i\n", *pekare_till_heltal + 1);
6) printf("%i\n", &heltal + 1);
b) Du har m�nga g�nger anv�nt funktionen scanf(�%d�, &heltal); Vad g�r &-tecknet
egentligen s� att scanf fungerar som den g�r?
c) G�r ett program med funktionen dubblera som i uppgift 1.4.2, men anv�nd en pekare f�r
att f� det att fungera. dubblera har nu allts� deklarationen void dubblera(int *x)

*/

#include <stdio.h>
#include <utility.h>

int main(void)   // test of pointer setup
{
	int heltal = 10;
	int *pekare_till_heltal = &heltal;
	
	// a)
	printf("1: %i\n", pekare_till_heltal + 1);  	// 1  ger fel svaret : 1638076 d� pekare_till_heltal ger adress
	printf("2: %i\n", heltal + 1);  				// 2  ger 11      svaret: 11, d� variable = 10 + 1
	printf("3: %i\n", (&heltal) + 1);  				// 3  ger adress pga &heltal    svaret : 1638076
	//printf("4: %i\n", *(pekare_till_heltal + 1)); // 4  ger fel        svaret: Dereference of out-of-bounds pointer
	printf("5: %i\n", *pekare_till_heltal + 1);  	// 5  ger 11 d� pointer ger 10 + 1
	printf("6: %i\n", &heltal + 1);  				// 6  ger adress pga &heltal   svaret : 1638076

	// b)
	// Svar: & tecknet ger memory adressen f�r variabeln och modiferar v�rdet p� adressen, variabeln uppdateras allts�
	
while(!KeyHit());	
return 0;
}