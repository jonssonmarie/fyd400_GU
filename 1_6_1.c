/* 1.6.1 Länkad lista – 2p
Utgå från följande deklaration av en nod i en dubbelt länkad lista:
struct node {
double data;
struct node *next;
struct node *previous;
};

Skriv ett program som har interaktiva funktioner för att
a) Skapa en ny nod (dvs, kedjan med en ensam nod),
b) lägga till en nod i slutet av kedjan av noder,
c) ta bort en nod på en viss plats i kedjan av noder,
d) gå igenom kedjan och skriva ut alla värden.
Och demonstrera denna funktionalitet. Ditt program måste allokera noderna dynamiskt, och frigöra
minnet för dem efteråt.
*/

#include <utility.h>
#include <stdio.h>
#include <stdlib.h>

struct node 						// declaration of struct
	{
	double data;
	struct node *next;
	struct node *previous;
	};


//a) skapa en ny nod
void add_node(struct node **head_ref, double new_data)  
	{
	struct node *new_node = (struct node*) calloc(1, sizeof(struct node));   // create memory and place dynamically

	//new_node->data = new_data;  			// add the data
	// new_node->next = (*head_ref);		// link the old node off the new list    
	//(*head_ref) = new_node;				// move the pointer to point at the new node  
	
	if (*head_ref == NULL) 			// new _node is head if linked list are empty, then create a first node
		{
		new_node->data = new_data;  		// add the data
		new_node->previous = NULL;
		*head_ref = new_node;
		printf("The added start node is %.0lf\n", new_data);
		return;
		}
	else
		printf("First node is not possible to change\n");
		return;
	} 


//b)  lägga till nod sist i kedjan
void append(struct node **head_ref, double new_data)
	{
	struct node *new_node = (struct node*)calloc(1, sizeof(struct node)); // allocation of memory for the size of struct node
	struct node *last = *head_ref;
	
	new_node->data = new_data;  	// add new data
	new_node->next == NULL;     	// make the new node to be the last node and set it to null
	
	if (*head_ref == NULL) 			// new _node is head if linked list are empty, then create a first node
		{
		new_node->previous = NULL;
		*head_ref = new_node;
		return;
		}
	
	while (last->next != NULL)		// else go to last node, loop until found node that ends with next pointing to NULL
		last = last -> next;
	
	last->next = new_node;			// new_mode is now last in line
	new_node->previous = last;		// make last as previous of new node
	printf("The added node is %.0lf\n", new_data);
	return;
	}


//c) ta bort nod från specifik plats i kedjan 
// head_ref - pointer to start node, del  - pointer to the node to be removed

void remove_node(struct node **head_ref, struct node *del) 
	{
    if (*head_ref == NULL || del == NULL)  		// if first node or node to delete is null
		{
		printf(" Delete is not possible. No data in the list!\n");
	 	return;
		}
		
    if (*head_ref == del)  			// If *head_ref is pointing to the same node as * del
        *head_ref = del->next;
 	
    if (del->next != NULL) 			// Change next only if node to be deleted is not the last node 
        del->next->previous = del->previous;
 
    if (del->previous != NULL)		// Change previous only if node to be deleted is not the first node 
        del->previous->next = del->next;
	
    // Free the memory for del
    free(del);
    return;
	}


//delete a node at the given position 
void remove_byposition(struct node** head_ref, int n) 
{ 
    // if list is NULL or invalid position  
    if (*head_ref == NULL || n <= 0) 
		{printf("Delete is not possible. No data in the list!\n");
        return; 
		}
  
    struct node *current = *head_ref; 
  
    for (int i = 1; current != NULL && i < n; i++) 		// loop the nodes at position 'n' from the beginning 
        current = current->next; 
  
    if (current == NULL) 					// if 'n' is greater than the number of nodes in the doubly linked list 
		{
		printf("The node do not exist!\n");
        return; 
		}
  
    remove_node(head_ref, current); 		// delete the node pointed to by 'current' 
	printf("The removed node is %i\n", n);
} 
  

// d) gå igenom och skriva ut alla värden i kedjan
void print_lists(struct node *head)
	{
	printf("This is the current tree \n"); 
	while(head != NULL)
		{
		printf("%.0lf\n", head->data);
		head = head->next;  
		}	
	}


int main(void)
	{
	struct node *head = NULL;  // Start with empty tree and therefor rot is NULL and is declared in main
	int num = 0, choice;
	char ch;
	
	while(1)
		{
		printf("The operations you can choose from are: \n1. Create a start node \n2. Add a node \n3. Remove a node by position \n4. Print the tree \n5. Exit \n");
				printf("Choose an operation:  ");
				scanf("%i", &choice);
				scanf("%c", &ch);
				printf("--------------------------------------------\n");
			
				if (ch != '\n')   				// checks the input
					{
					printf("Only integer numbers is allowed\n");
					printf("\n");
					fflush(stdin);
					}
				else 
					{
					switch(choice)
						{
						case 1:		
								printf("Enter an integer \n");
								scanf("%i", &num);
								scanf("%c", &ch);
								if (ch != '\n') 	// checks the input
									{
									printf("Only integer numbers is allowed\n");
									printf("\n");
									fflush(stdin);
									}
								else 
									{
									add_node(&head, num);
									}
								break;
								
									
						case 2:
								printf("Enter an integer \n");
								scanf("%i", &num);
								scanf("%c", &ch);
								if (ch != '\n') 	// checks the input
									{
									printf("Only integer numbers is allowed\n");
									printf("\n");
									fflush(stdin);
									}
								else 
									{
									append(&head, num);
									break;
									}
							
						case 3:
								printf("Enter an integer \n");
								scanf("%i", &num);
								scanf("%c", &ch);
								if (ch != '\n') 	// checks the input
									{
									printf("Only integer numbers is allowed\n");
									printf("\n");
									fflush(stdin);
									}
								else 
									{
									remove_byposition(&head, num); 
									break;
									}
									
						case 4:							
									print_lists(head); 
									break;
							
						case 5:
								exit(1);			// exits the function 
							
						default:
								printf("Enter an correct option\n");
								printf("\n");
								break;
						}
					}
		}	
	}
	

	
