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

void sum_value()   		// calculate the number of banknotes and coins to return to buyer
{
	float cost, received, remain_cost, adjust_cost;	
	float num = 0, num_ore = 0;
	int tot_int, int_cost;
	char ch;
	
	printf("Enter the purchase price: \n");
	scanf("%f", &cost);
	scanf("%c", &ch);
	
	if (ch != '\n')   				// checks the input
			{
			printf("Only numbers is allowed \n");
			fflush(stdin);
			}
	else
		{
		printf("Enter the sum received: \n");
		scanf("%f", &received);
		scanf("%c", &ch);
		if (ch != '\n')    			// checks the input
			{
			printf("Only numbers is allowed \n");
			fflush(stdin);
			}
		else
			{
			int_cost = (int)cost;        // only integer of cost
			remain_cost = cost - (float)int_cost;    // get the decimals eg 3.25 - 3 = 0.25  
			if (remain_cost <= 0.25)
				remain_cost = 0.0;
			else if (remain_cost > 0.75 && remain_cost <=1)
				remain_cost = 1;	
			else if (remain_cost > 0.25 && remain_cost <= 0.75)
				remain_cost = 0.5;
			
			
			adjust_cost = ((float)int_cost + remain_cost);  // adding the rounded up to get total adjusted cost
			
			float diff_return = received - adjust_cost;  	// calculate the difference
			
			if (diff_return < 0)            // checks that enough money is left for the purchase	
				{
				printf("The buyer has given too little money! \n");
				printf("The buyer has to add %.2f: SEK \n", fabs(diff_return));
				printf("\n");
				}
			else if (diff_return >=0)
				{
				tot_int = (int)(diff_return);    
				num_ore = ((diff_return - (float)tot_int)*100)/50;  // calculate the number of ore    
						
				num = tot_int/1000;
				if (num != 0)
					printf("Number of 1000 notes : %.0f \n", fabs(num));
				tot_int= (int)tot_int % 1000;
				
				num = tot_int/500;
				if (num != 0)
					printf("Number of 500 notes : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 500;
				
				num = tot_int/100;
				if (num != 0)
					printf("Number of 100 notes : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 100;
					
				num = tot_int/50;
				if (num != 0)
					printf("Number of 50 notes : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 50;
				
				num = tot_int/20;
				if (num != 0)
					printf("Number of 20 notes : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 20;
				
				num = tot_int/10;
				if (num != 0)
					printf("Number of 10 coins : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 10;
				
				num = tot_int/5;
				if (num != 0)
					printf("Number of 5 coins : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 5;
				
				num = tot_int/1;
				if (num != 0)
					printf("Number of 1 coins : %.0f \n", fabs(num));
				tot_int = (int)tot_int % 1;
				
				if (num_ore != 0)
					printf("Number of 50 \x94re: %.0f \n", num_ore);
				
				num = tot_int/1;
				if (num == 0)
					printf("Even sum, nothing to give back!");
				}
			}
		}
}
	
	
int main(void)
	{
	sum_value();

	while(!KeyHit());
	return 0;
	}