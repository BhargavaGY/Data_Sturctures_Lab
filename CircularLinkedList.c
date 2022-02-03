#include<stdio.h>
#include<stdlib.h>

struct node
{
    int id;
    struct node *next;
};

struct node *head = NULL;

void start_insert()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    int val;

    printf("Enter the value: ");
    scanf("%d", &val);
    new->id = val;

    if(head == NULL)
    {
       head = new;
       new->next = head;
    }
    else
       if(head->next == head)
       {
           new->next = head;
           head->next = new;
           head = new;
       }
       else
       {
           new->next = head;

           temp = head;
           while(temp->next != head)
           {
               temp = temp->next;
           }
           head = new;
           temp->next = head;
       }

    printf("Node added successfully!!");
}

void end_insert()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    int val;

    printf("Enter the value ");
    scanf("%d", &val);
    new->id = val;

    if(head == NULL)
    {
        head = new;
        head->next = head;
    }
    else
    {
        temp = head->next;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head; 
    }
       
    
}

random_insert()
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    int value;
    int pos;
    printf("Enter the value: ");
    scanf("%d", &value);
    printf("Enter the position: ");
    scanf("%d", &pos);
    new->id = value;
    if(pos == 1)
       start_insert();
    else
    {
        temp = head;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
            if(temp == head)
            {
                printf("Invalid position!!");
                return;
            }

            new->next = temp->next;
            temp->next = new;
        }
    }

}

void start_delete()
{
    struct node *temp,*ptr;
    if(head == NULL)
       printf("No node to delete\n");
    else
       if(head->next == head)
        {  
            free(head);
            head = NULL;
        }
       else
       {
           ptr = head;
           head = head->next;
           temp = head;
           free(ptr);

           while(temp->next != head)
           {
               temp = temp->next;
           }

           temp->next = head;          
       }
}

void end_delete()
{
    struct node *temp,*prev;
    if(head == NULL)
      printf("No node to delete\n");
    else
      if(head->next == head)
      {
          free(head);
          head = NULL;
      }
      else
      {
        temp = head;
        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
      }
}

void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d ",temp->id );
        temp = temp->next;
    } while (temp != head);
      
}

void main()
{
    int choice = 0;
    printf("Enter your choice: ");
    while(choice != 7)
    {
        printf("\n1.Insert from start\t2.Insert from End\t3.Insert at random position\t4.Display\t5.Delete from start\t6.Delete from end\t7.Delete at random position ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start_insert();
            break;
        case 2:
            end_insert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            display();
            break;
        case 5:
            start_delete();
            break;
        case 6:
            end_delete();
            break;
        
        default: exit(0);
        }
    }
}
