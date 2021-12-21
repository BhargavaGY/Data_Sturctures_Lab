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

void start_delete()
{
    struct node *temp;
    if(head == NULL)
       printf("No node to delete\n");
    else
      if(head->next == NULL)
      {
          free(head);
          head = NULL;
      }
      else
      {
          temp = head;
          head  =  head->next;
          free(temp);
      }
}
void end_delete()
{
    struct node *temp, *prev;
    if(head == NULL)
      printf("No node to delete\n");
    else
      if(head->next == NULL)
      {
          free(head);
          head = NULL;
      }
      else
      {
          temp = head;
          while(temp->next != NULL)
          {
              prev = temp;
              temp = temp->next;
          }
          free(temp);
          prev->next = NULL;
          
      }
}

void random_delete()
{
    struct node *temp, *prev;
    if(head == NULL)
      printf("No node to delete\n");
    else
      {
          int pos, size = 0;
          temp = head;
          while(temp->next != NULL)
          {
            size++;
            temp = temp->next;
          }
          printf("Enter the position: ");
          scanf("%d", &pos);
          if(pos == 1)
            start_delete();
          else
            if(pos == size)
               end_delete();
            else
            {
              temp = head;
              for(int i = 1; i < pos; i++)
              {
                  prev = temp;
                  temp = temp->next;
                  
                  if(temp == NULL)
                  {  printf("Invalid position\n");
                     return;
                  }
              }
              prev->next = temp->next;
              free(temp);
            }
      }
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
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at random position\t4.Display\t5.Delete from start\t6.Delete from end\t7.Delete at random position\n");
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
            case 5 : start_delete();
                    break;
            case 6 : end_delete();
                    break;
            case 7 : random_delete();
                     break;
            default : exit(0);
        }
    }
}
