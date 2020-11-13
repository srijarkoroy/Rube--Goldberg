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
  Person *person;
  struct node *next;
}Node;

/* Queue*/
typedef struct queue {
  Node *head;
  Node *tail;
  int size;
}Queue;

/*Function Declaration*/
Queue *createQueue();
Node *createNode(Person *aPerson, Node *ptro);
void insert(Person *aPerson, char firstName [40], char lastName [40], int age, char dob [20]);
void read();
Node *headNode(Queue *c);
Node *tailNode(Queue *c);
bool emptyQueue(Queue *c);

Queue *createQueue()
{
    Queue *aQueue;

    /* memory for the Queue */
    if((aQueue = (Queue *) malloc(sizeof(Queue))))
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
        aNode->person = aPerson;
        aNode->next = pointer;
    }
    return aNode;
}

void insert(Person *aPerson, char firstName [40], char lastName[40], int age, char dob[20])
{
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
}    

/* first node of Queue */
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

void read()
{

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
        insert(&tempPerson, tempPerson.firstName, tempPerson.lastName, tempPerson.age, tempPerson.dob);

        /* Write output file for test */
        fprintf(output, "%s ", tempPerson.firstName);
        fprintf(output, "%s ", tempPerson.lastName);
        fprintf(output, "%i ", tempPerson.age);
        fprintf(output, "%s", tempPerson.dob);

    }

    /* Close files */       
    fclose(input);      
    fclose(output);
}

int main (int argc , char ** argv)
{
    /* Call read function */
    read();

    return 0;

}
