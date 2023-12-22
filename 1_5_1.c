/*
Pekarvariabler är helt enkelt heltal som kan tolkas som en viss position i datorns minne: en adress.
Alla variabler finns lagrade någonstans i minnet, och har en adress. En pekare används för att
referera till olika ställen i minnet. Har man en pekare kan man referera till det den pekar till med *-
operatorn. Vice versa kan man med en variabel få veta dess adress med &-operatorn. Följande
uppgifter syftar till att praktisera dessa

1.5.1 Pekare, avreferering och adresser – 2p
a) Om vi har deklarationerna
int heltal = 10;
int *pekare_till_heltal = &heltal;
Vilka av följande uttryck resulterar i en utskrift av talet 11? (och varför? Testa!)
1) printf("%i\n", pekare_till_heltal + 1);
2) printf("%i\n", heltal+1);
3) printf("%i\n", *(&heltal)+1);
4) printf("%i\n", *(pekare_till_heltal + 1));
5) printf("%i\n", *pekare_till_heltal + 1);
6) printf("%i\n", &heltal + 1);
b) Du har många gånger använt funktionen scanf(”%d”, &heltal); Vad gör &-tecknet
egentligen så att scanf fungerar som den gör?
c) Gör ett program med funktionen dubblera som i uppgift 1.4.2, men använd en pekare för
att få det att fungera. dubblera har nu alltså deklarationen void dubblera(int *x)

*/

#include <stdio.h>
#include <utility.h>

int main(void)   // test of pointer setup
{
	int heltal = 10;
	int *pekare_till_heltal = &heltal;
	
	// a)
	printf("1: %i\n", pekare_till_heltal + 1);  	// 1  ger fel svaret : 1638076 då pekare_till_heltal ger adress
	printf("2: %i\n", heltal + 1);  				// 2  ger 11      svaret: 11, då variable = 10 + 1
	printf("3: %i\n", (&heltal) + 1);  				// 3  ger adress pga &heltal    svaret : 1638076
	//printf("4: %i\n", *(pekare_till_heltal + 1)); // 4  ger fel        svaret: Dereference of out-of-bounds pointer
	printf("5: %i\n", *pekare_till_heltal + 1);  	// 5  ger 11 då pointer ger 10 + 1
	printf("6: %i\n", &heltal + 1);  				// 6  ger adress pga &heltal   svaret : 1638076

	// b)
	// Svar: & tecknet ger memory adressen för variabeln och modiferar värdet på adressen, variabeln uppdateras alltså
	
while(!KeyHit());	
return 0;
}