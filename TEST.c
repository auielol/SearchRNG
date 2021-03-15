#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int getSelection(int select);
void createList();
void displayList();
void sortList();

int main()
{
	menu();
}

int menu()
{
	int select;
	
	printf("\n[1] CREATE LIST");
	printf("\n[2] DISPLAY LIST");
	printf("\n[3] EXIT\n");
	
	printf("\nSELECTION: ");
	scanf("%d", &select);
	
	getSelection(select);
}

int getSelection(int select)
{
	switch (select)
	{
		case 1:
			{
				createList();
				break;
			}
		case 2:
			{
				displayList();
				break;
			}
		case 3:
			{
				return 0;
			}
		default:
			{
				printf("INVALID INPUT");
				return menu();
			}
	}
	
	return menu();
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
    
    sortList();
}

void sortList()
{
	struct node *current = head, *index = NULL;  
    int temp;  
          
    if(head == NULL)
	{  
        return;  
    }  
    else
	{  
        while(current != NULL)
		{  
            index = current->next;  
                  
            while(index != NULL) 
			{
                if(current->data > index->data)
				{  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
                index = index->next;  
            }  
            
            current = current->next;  
            
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
