/* 1.5.1 
c) Gör ett program med funktionen dubblera som i uppgift 1.4.2, men använd en pekare för
att få det att fungera. dubblera har nu alltså deklarationen void dubblera(int *x)
  */


#include <ansi_c.h>
#include <utility.h>

void dubblera(int *x)  // multiplication with 2 and using pointer
	{
	printf("\n");
	printf("This is the integer you added: %i \n", *x);
	*x = *x * 2;
	printf("This is the number after multiplication with 2:  %i \n", *x); 
	}


int main(void)
	{
	int xx = 0;
	char ch;
	
	printf("Enter an integer: \n");
	scanf("%i", &xx);
	scanf("%c", &ch);
	
	if (ch != '\n')         // checks that only numbers are added
		{
		printf("Only numbers are allowed!");
		fflush(stdin);
		}
	else 
		dubblera(&xx);  
		
	while(!KeyHit());
	return 0;
	} 