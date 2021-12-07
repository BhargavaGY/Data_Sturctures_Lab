#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int id;
    struct node *next;
};
struct node  *head = NULL;

void beginsert()
{
    int val;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&val);
    new->id = val;
    new->next = NULL;
    
    if(head == NULL)
       head = new;
    else
    {
        new->next = head;
        head = new;
    }
    printf("Node added at the beginning\n");
}

void lastinsert()
{
    int val;
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&val);
    new->id = val;
    new->next = NULL;
    
    if(head == NULL)
       head = new;
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void randominsert()
{
    int val, pos;
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&val);
    printf("Enter the position: ");
    scanf("%d", &pos);
    new->id = val;
    new->next = NULL;
    
    temp = head;
    for(i = 1; i < loc -1; i++)
    {
        temp = temp->next;
    }
    new-next = temp->next;
    temp->next = new;
}
void main()
{
    int choice = 0;
    while(choice >= 0)
    {
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at random position\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : beginsert();
                    break;
            case 2 : lastinsert();
                    break;
            case 3 : randominsert();
                    break;
            default : exit(0);
        }
    }
}

