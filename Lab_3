#include<stdio.h>
#include<stdbool.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

bool IsEmpty()
{
    if(front == -1 && rear == -1)
       return true;
    else
       return false;
}

bool IsFull()
{
    if(rear == SIZE - 1)
       return true;
    else
       return false;
}

void enqueue(int value)
{
    if(IsFull())
    {
      printf("Queue is full");
      return;
    }
    else
    {
       if(IsEmpty())
       {
          rear = 0;
          front = 0;
       }
        else
          rear =+ 1;
    }
    queue[rear] = value;
}

void dequeue()
{
    if(IsEmpty())
      printf("Queue is empty");
    else
      if(front == rear)
        front = rear =  -1;
      else
        front =+ 1;
}

void display()
{
    if(IsEmpty())
      printf("Queue is empty\n");
    else
    {
      printf("Elements in the queue are:\n");
      for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    }
}

int main()
{
    int choice = 0;
    printf("Choose the opertaion to perform:\n");
    while(choice >= 0)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
                {
                  int value;
                  printf("Enter the value to be added to the queue: ");
                  scanf("%d", &value);
                  enqueue(value);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default : printf("Enter a valid choice!!\n"); 
        }
    }
    return 0;
}
