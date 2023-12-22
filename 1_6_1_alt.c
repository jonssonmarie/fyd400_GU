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
väljer är en smaksak, det är ingen rätt eller fel i sammanhanget. 
Notera att i själva deklarationen av 16 struct är inte typedef giltig ännu, så självreferenser måste alltid göras explicit.
*/

#include <utility.h>
#include <stdio.h>
#include <stdlib.h>

struct node 
	{
	double data;
	struct node *next;
	struct node *previous;
	};

// declare an empty node
struct node *head = NULL;

int hashfunc(double d)
	{
	return(d % NHASH);
	
	
	
	
	}

// a) skapa en ny nod

struct node *create_node(void)
	{
	
	struct node *np; 										// declare pointer for new node
	np = (struct node *)calloc(1,sizeof(struct node));		// check needed size and create memory and allocate
	if (np == NULL)
		{
		fprintf(stderr, "Run out of memory!");
		exit(99);
		}
	else
		{
		return np;
		}
	}

struct node *find_node(double d)
	{
	struct node *dp;
	dp = head; 				// pointer points to 1st node and thats the head
	while (dp != NULL && dp->data != d)
		{
		if (d < dp->data)
			dp = dp->previous;
		else
			dp = dp->next;
		}
	return dp;
	}

void add_node (double d)
	{
	struct node *new;  // declare a pointer for the new node
	
	if (find_node(d) == NULL)
		{
		new = create_node();  // create and return pointer for new node
		new->data = d;
		add_to_tree(&head, new);		
		}
	}

// b) add node to tree - not yet the last position --------------------------------
void add_to_tree(struct node **head_ref, const struct node *dp)
	{
	if (*head_ref == NULL)
		*head_ref = dp;
	else if (dp->data < *head_ref->data)
		add_to_tree(&(*head_ref)->previous, dp);
	else
		add_to_tree(&(head_ref)->next, dp);	
	}

// c) remove a node


// d) print all nodes

void print_all(void)
	{
	struct node *dp;
	printf("All nodes\n");
	inorder(head);
	}

void inorder(const struct node *head)
	{
	if (head == NULL)
		{
		inorder(head->next);
		printf("Nodes", head->data);
		}
	}


int main(void)
{
	while(1)
	{
	
	printf
	
	
	
	
	}
	 


}





