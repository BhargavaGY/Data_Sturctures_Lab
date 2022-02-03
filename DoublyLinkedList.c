#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int id;
    struct  node *next;
    struct node *prev;
};

struct node *head = NULL;

void start_insert()
{
    struct node *new;
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);

    new = (struct node *)malloc(sizeof(struct node));
    new->id = val;
    new->prev = NULL;

    if(head == NULL)
    {
        new->next = NULL;
        head = new;
    }
    else
    {
        new->next = head;
        head->prev = new;
        head =  new;
    }
    
}

void end_insert()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter the value ");
    scanf("%d", &val);
    new->id = val;
    new->next = NULL;

    if(head == NULL)
    {
        head == new;
        head->next = NULL;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        new->prev = temp;
        temp->next = new;
    }
}

void display()
{
    struct node *temp;

    if(head == NULL)
      printf("No node to delete\n");
    else
    {
       temp = head;
       while(temp != NULL)
       {
           printf("%d ", temp->id);
           temp = temp->next;
       }
    }
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
          head == NULL;
      }
      else
      {
          temp = head;
          head = head->next;
          head->prev = NULL;
          free(temp);
      }
       
}

void end_delete()
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
          while(temp->next != NULL)
          {
              temp = temp->next;
          }
          temp->prev->next = NULL;
          free(temp);
      }

}

void random_delete()
{
    struct node *temp;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = head;
    for(int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void main()
{
    int c;
    while(true)
    {
        printf("\n1.Insert from start\t2.Insert from end\t3.Display\t 4.Delete at start\t5.Delete at end\t6.Delete at random position\t7.Exit\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                start_insert();
                break;
            case 2:
                end_insert();
                break;
            case 3:
                display();
                break;
            case 4:
                start_delete();
                break;
            case 5:
                end_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7 :
                exit(0);

        }
    }
}
