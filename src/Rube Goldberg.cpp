#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h >

/*Person*/
typedef struct person {
  char firstName [40];
  char lastName [40];
  int age;
  char dob[20];
}Person;

/* Node */
typedef struct node {
  Person *p;
  struct node *next;
}Node;

/* Queue*/
typedef struct queue {
  Node *head;
  Node *tail;
  int size;
}Queue;

/*Function Declaration*/
/*Queue *createQueue();
void display(Queue *);
Node *createNode(Person *aPerson, Node *ptro);
void insert(Person *aPerson, Queue *q, char firstName [40], char lastName [40], int age, char dob [20]);
void read();
Node *headNode(Queue *c);
Node *tailNode(Queue *c);
bool emptyQueue(Queue *c);*/

Queue *createQueue()
{
    Queue *aQueue;
    /* memory for the Queue */
    if(aQueue = (Queue *) malloc(sizeof(Queue)))
    {
        /* Queue initialize empty */
        aQueue->size = 0;
        /* head and tail pointer -> Null */
        aQueue->head = aQueue->tail = NULL;
    }
    return aQueue;
}

Node *createNode(Person *aPerson, Node *pointer)
{
    Node *aNode;

    /* memory for the Node */
    if((aNode = (Node *) malloc(sizeof(Node))))
    {
        /* values of Node */
        aNode->p = aPerson;
        aNode->next = pointer;
    }
    return aNode;
}

Queue* insert(Person *aPerson, Queue *q, char firstName [40], char lastName[40], int age, char dob[20])
{
	Node *ptr; 
	ptr = (Node*)malloc(sizeof(Node));
    if(aPerson = (Person *) malloc(sizeof(Person)))
    {
        strcpy(aPerson->firstName, firstName);
        strcpy(aPerson->lastName, lastName);
        aPerson->age = age;
        strcpy(aPerson->dob, dob);
    }
    else
    {
        printf("Couldn't insert data\n");
        
    }
    ptr->p = aPerson;
    if(q -> head == NULL)
	{
		 q -> head = ptr;
		 q -> tail = ptr;
		 q -> head -> next = q -> tail -> next = NULL;
	}
	else
	{
	 q -> tail -> next = ptr;
	 q -> tail = ptr;
	 q -> tail -> next = NULL;
	}
	return q;
}
Node *headNode(Queue *c)
{
    return c->head;
}

/* last node of Queue */
Node *tailNode(Queue *c)
{
    return c->tail;
}

/* returns true if Queue is empty, false otherwise */
bool emptyQueue(Queue *c)
{
    return (c->head == NULL) ? true : false;
}

Queue* read()
{
	
    Queue * K;
	Queue * C;
    C = createQueue();

    /* Files to read and write, respectively */
    FILE *input;
    FILE *output;

    /* String to be read */
    char data[201];

    /* Temp auxiliar Person */
    Person tempPerson;

    /* Tokenize */
    char * token;

    /* Open input file */
    input = fopen("input.txt" , "r");

    /* not sure abour this */
    if(input == NULL) 
    {
        printf("Couldn't open file\n");
        exit(0);
    }

    /* Open output file for test */
    output = fopen("output.txt" , "w");

    /* Read string */
    while(fgets(data, 201, input) != NULL)
    {

        /* Tokenize by "\t" (tab) */
        token = strtok(data,"\t");

        /* Count */ 
        int count = 0;
        while (token != NULL)
        {
            if(count == 0)
            {
                strcpy(tempPerson.firstName, token);
            }
            if(count == 1)
            {
                strcpy(tempPerson.lastName, token);
            }
            if(count == 2)
            {
                tempPerson.age = atoi(token);
            }
            if(count == 3)
            {
                strcpy(tempPerson.dob, token);
            }
            count++;
            token = strtok(NULL, "\t");
        }

        /* Call insert function */
        K=insert(&tempPerson, C , tempPerson.firstName, tempPerson.lastName, tempPerson.age, tempPerson.dob);
 
        /* Write output file for test */
        fprintf(output, "%s ", tempPerson.firstName);
        fprintf(output, "%s ", tempPerson.lastName);
        fprintf(output, "%i ", tempPerson.age);
        fprintf(output, "%s", tempPerson.dob);

    }

    /* Close files */       
    fclose(input);      
    fclose(output);
    return K;
}

void display(Queue *q)
{
Node *ptr;
ptr = q -> head;
if(ptr == NULL)
 printf("\n QUEUE IS EMPTY");
else
{
 printf("\n");
 while(ptr!=q -> tail)
 {
 printf("%d\t", ptr -> p);
 ptr = ptr -> next;
 }
 printf("%d\t", ptr -> p);
}
}

int main (int argc , char ** argv)
{
    /* Call read function */
    
    Queue * Q;
    //Q = createQueue();
	Q=read();
	display(Q);
    return 0;

}
