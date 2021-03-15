#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createList();
void displayList();

int main()
{
	createList();
	
	printf("\nData in the list \n");
    displayList();
}

void createList()
{
	struct node *newNode, *temp;
    int data, i;
    
    head = (struct node *)malloc(sizeof(struct node));
    
    time_t t;
		srand((unsigned) time(&t));
		
        data = rand() %101;

        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i <= 10; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                data = rand() %101;

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next; 
            }
        }
}

void displayList()
{
	struct node *temp;
	
	if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}
