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
    for(int i = 1; i < pos -1; i++)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

void display()
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d\t",temp->id);
        temp = temp->next;
    }
}
void main()
{
    int choice = 0;
    while(choice >= 0)
    {
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at random position\t4.Display\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : beginsert();
                    break;
            case 2 : lastinsert();
                    break;
            case 3 : randominsert();
                    break;
            case 4 : display();
                    break;
            default : exit(0);
        }
    }
}
