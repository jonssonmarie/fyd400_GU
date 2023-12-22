#include <ansi_c.h>
#include <stdio.h>
#include <utility.h>

/*prints Hello world! on one line and Skriv ut... on next line  */

int main()
{ 
	printf("Hello World! \n");
	printf("Skriv ut...");
	while ( !KeyHit( ) ) ;
	return 0;
}