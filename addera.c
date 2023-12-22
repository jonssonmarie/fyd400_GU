#include <ansi_c.h>
#include <utility.h>

void addera(int x)  // addition with 2 and using pointer
{
	printf("\n");
	printf("This is the integer you added: %i \n", x);
	x = x + 2;
	printf("This is the number after multiplication with 2:  %i \n", x); 
	return x;
	}