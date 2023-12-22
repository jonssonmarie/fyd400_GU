// I C kan vi göra en massa saker med escape-sekvenser:
// vi har tabb eller vi kan aktivera ett larm (programmet ska larma vid exekvering)
// OBS: tomrummet mellan ”har” och ”tabb” är ett tabulatortecken.


#include <stdio.h>
#include <utility.h>

int main(void)
{
	printf("I C kan vi g\x94ra en massa saker med escape-sekvenser: \nvi har \t tabb \neller vi kan aktivera ett larm \a\n");
	while ( !KeyHit( ) ) ;
	return 0;
}