#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int marks;
    char name[20];
    char usn[10];
    struct node *next;
};
struct node  *head = NULL;

void insert()
{
    int marks;
    char name[20];
    char usn[20];
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the usn: ");
    scanf("%s", usn);
    printf("Enter the marks: ");
    scanf("%d", &marks);

    new->marks = marks;
    strcpy(new->name, name);
    strcpy(new->usn, usn);
    new->next = NULL;
    
    if(head == NULL)
       head = new;
    else
    {
        new->next = head;
        head = new;
    }
    
}

void display()
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("Name: %s\nUSN: %s\nMarks: %d\n\n", temp->name, temp->usn, temp->marks);
        temp = temp->next;
    }
}

void delete()
{
    struct node *temp, *ptr, *prv;
    int lowest;

    if(head == NULL)
      printf("No student information to delete\n");
    else
      if(head->next == NULL)
      {
          printf("Deleted Student info: \n");
          printf("Name: %s\nUSN: %s\nMarks: %d\n\n", head->name, head->usn, head->marks);
          free(head);
          head = NULL;
      }

      else
      {
          temp = head;
          lowest = head->marks;
          ptr = head;

          while (temp->next != NULL)
          {
              if(temp->next->marks < lowest)
              {
                  lowest = temp->next->marks;
                  ptr = temp->next;
                  prv = temp;
              }
              temp = temp->next;

          }
          printf("Deleted Student info: \n");
          printf("Name: %s\nUSN: %s\nMarks: %d\n\n", ptr->name, ptr->usn, ptr->marks);
          prv->next = ptr->next;
          free(ptr);    
      }
    
    
}

void main()
{
    int choice = 0;
    while(choice >= 0)
    {
        printf("\n1.Add a Student\t2.Delete Student\t3.Display\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : insert();
                    break;
            case 2 : delete();
                    break;
            case 3 : display();
                    break;
            default : exit(0);
        }
    }
}
