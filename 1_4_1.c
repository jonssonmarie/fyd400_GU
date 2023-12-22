/* 1.4.1 Funktioner - 2p
Du skall nu skriva ett program som str�cker sig �ver flera k�llkodsfiler. I de flesta projekt
organiseras kod i separata funktioner, i olika filer, efter syfte. Den som sedan vill anv�nda sig av
funktionerna inkluderar koden med hj�lp av preprocessordirektiv. Du kommer nu skapa ett enkelt
s�dant bibliotek f�r konvertering mellan enheter.
a) Skapa filerna convert.h, convert.c samt main.c. I convert.c skapar du en funktion som tar
emot avst�nd m�tt i meter, och returnerar avst�ndet i millimeter. Placera en
funktionsprototyp i convert.h. Skriv sedan ett enkelt program i main.c som anv�nder sig av
funktionen ur convert.h.

b) F�rklara hur instruktioner till f�rbehandlaren kan f�rhindra att samma
deklarationsinformation inkluderas dubbelt under kompilering
Svar: 
opt1: L�gg alla deklarationer i samma .h fil och inkludera denna .h fil i alla .c filer
opt2. koppla .h och .c filerna efter vad som beh�vs genom att skapa moduler i
	- .h filerna: funktions deklarationer 
	(inneh�ller bara funktionshuvudet ( eg. float medevarde(float x, float y, ...), kallas ocks� funktionsprototyp)
	- .c filer: motsvarande funktions definitioner 
		( eg. fkn definition
 		float medelvarde(float x, float y)
		{
		return (x+y)/2;
		}
detta ger tydlighet mindra att kompilera.

c) F�rklara skillnaden mellan f�ljande tv� preprocessordirektiv:
#include <Test.h>
#include �Test.h�
Svar: <> pilparanteserna brukar anv�ndas normalt sett f�r att visa att h-filen ing�r i systemet, 
" " betyder att "jag" sj�lv lagt till en h-fil som ligger i min working directory. 
*/


// SKISS

// convert.h
// Placera en funktionsprototyp i convert.h for fkn i convert.c

// convert.c
// I convert.c skapar du en funktion som tar emot avst�nd m�tt i meter, och returnerar avst�ndet i millimeter. 

// main.c
// Skriv sedan ett enkelt program i main.c som anv�nder sig av funktionen ur convert.h.

/*
#include <stdio.h>
#include <utility.h>

float convert_distance()    // will be in convert.c
{
	float dist = 0;
	int dist_mm = 0;
	
	printf("Enter a distance in meter: \n");
	scanf("%f", &dist);
	
	dist_mm = dist * 1000;
	printf("distance in mm %d", dist_mm);
	return dist_mm;
}

int main()				
{
	convert_distance();
	
	while(!KeyHit());
	return 0;
}
*/