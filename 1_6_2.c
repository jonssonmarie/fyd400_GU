/* 1.6.2 Binärträd - 2p
Utgå från följande deklaration av en nod i ett binärträd:
struct node {
int data;
struct node *parent;
struct node *left;
struct node *right;
};
Skriv ett program som skapar trädet i figuren till höger. Skapa en
funktion som givet en rot-nod skriver ut trädet på något lämpligt sätt.
Ditt program måste allokera noderna dynamiskt, och frigöra minnet
för dem efteråt.
*/

/*
Kommentar om syntax: Vissa programmerare gillar att förenkla
syntaxen för struct med hjälp av en typedef, såhär:
struct min_typ_t
{
double data;
struct min_typ_t *next;
};
typedef struct min_typ_t min_typ;
Efter det kan man använda ”min_typ” utan att behöva skriva ”struct” hela tiden. Vilket sätt ni
väljer är en smaksak, det är ingen rätt eller fel i sammanhanget. Notera att i själva deklarationen av
16
struct är inte typedef giltig ännu, så självreferenser måste alltid göras explicit. */

#include <stdio.h>
#include <stdlib.h>
#include <utility.h>

struct node 
	{
	int data;
	struct node *parent;
	struct node *left;
	struct node *right;
	};



//a) skapa en ny nod
void add_node(struct node **parent_ref, double new_data)  
	{
	struct node *new_node = (struct node*) calloc(1, sizeof(struct node));   // create memory and place dynamically

	//new_node->data = new_data;  			// add the data
	// new_node->next = (*head_ref);		// link the old node off the new list    
	//(*head_ref) = new_node;				// move the pointer to point at the new node  
	
	if (*parent_ref == NULL) 			// new _node is head if linked list are empty, then create a first node
		{
		new_node->parent = new_data;  		// add the data
		new_node->left = NULL;
		new_node->right = NULL ;
		*parent_ref = new_node;
		printf("The added start node is %.0lf\n", new_data);
		return;
		}
	else if (*parent_ref != NULL)
		{
		new_node->left == NULL;
		new_node->right == NULL;
		*left = new_node; 
		
		
		
		}
	else
		printf("First node is not possible to change\n");
		return;
	} 

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



void printall(void)
	{
	struct *parent;
	printf("");

	}









int main()
{
	struct node *parent = NULL;

}