/* 1.3.5 V�xelkassa � 2p
N�r du handlar i en aff�r och betalar kontant f�r du kanske v�xel tillbaka. I regel f�r aff�rsbitr�det
hj�lp av kassaapparaten med att ber�kna summan man ska f� tillbaka, men inte alltid vilka sedlar
och mynt som ska l�mnas tillbaka. Skriv ett program som ber�knar den v�xel bitr�det ska ge
tillbaka i samband med ett k�p. Programmet ska, f�rutom att presentera beloppet kunden f�r
tillbaka avrundat till n�rmsta 50-�ring, �ven best�mma vilka, och antalet, sedlar och mynt. Kunden
ska f� s� f� sedlar och mynt som m�jligt tillbaka. Programmet ska kunna ge v�xel tillbaka med
sedlar av val�rerna 1000, 500, 100, 50 och 20 samt mynten 10, 5, 1 och 50-�ring. Du kan anta att
det alltid finns tillr�ckligt antal av de sedlar och mynt som kr�vs.
*/

#include <ansi_c.h>
#include <stdio.h>
#include <utility.h>

float sum_value()   // 
{
	float cost, received;	
	float num, tot_ore, num_ore;
	int tot_int;
	
	printf("Enter the purchase price: \n");
	scanf("%f", &cost);
	printf("Enter the sum received: \n");
	scanf("%f", &received);
	  
	float diff_return = received - cost;
	tot_int = (int)diff_return;
	num_ore = (diff_return - (float)tot_int)*100/50;
	
	num = tot_int/1000;
	if (num != 0)
		printf("Number of 1000 notes : %.0f \n", num);
	tot_int= (int)tot_int % 1000;
	
	num = tot_int/500;
	if (num != 0)
		printf("Number of 500 notes : %.0f \n", num);
	tot_int = (int)tot_int % 500;
	
	num = tot_int/100;
	if (num != 0)
		printf("Number of 100 notes : %.0f \n", num);
	tot_int = (int)tot_int % 100;
		
	num = tot_int/50;
	if (num != 0)
		printf("Number of 50 notes : %.0f \n", num);
	tot_int = (int)tot_int % 50;
	
	num = tot_int/20;
	if (num != 0)
		printf("Number of 20 notes : %.0f \n", num);
	tot_int = (int)tot_int % 20;
	
	num = tot_int/10;
	if (num != 0)
		printf("Number of 10 coins : %.0f \n", num);
	tot_int = (int)tot_int % 10;
	
	num = tot_int/5;
	if (num != 0)
		printf("Number of 5 coins : %.0f \n", num);
	tot_int = (int)tot_int % 5;
	
	num = tot_int/1;
	if (num != 0)
		printf("Number of 1 coins : %.0f \n", num);
	tot_int = (int)tot_int % 1;
	
	printf("Number of 50 ore: %.2f \n", num_ore);
	return 0;	
}
	
	
int main(void)
	{
	sum_value();

	while(!KeyHit());
	return 0;
	}