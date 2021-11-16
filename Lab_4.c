//C Program to perform circular queue operation
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 3

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
    if(front == 0 && rear == SIZE - 1)
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
          rear = (rear+1)%SIZE;
        queue[rear] = value;
    }
    
}

void dequeue()
{
    if(IsEmpty())
      printf("Queue is empty");
    else
      if((front+1)%SIZE == rear)
        front = rear =  -1;
      else
        front = (front+1) % SIZE;
}

void display()
{
    if(IsEmpty())
      printf("Queue is empty\n");
    else
    {
      printf("Elements in the queue are:\n");
      for(int i = front; i != rear; i = (i+1)%SIZE)
        printf("%d ", queue[i]);
      printf("%d",queue[rear]);
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
                break;
        }
    }
    return 0;
}

/*OUTPUT:
Choose the opertaion to perform:

1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the value to be added to the queue: 1

1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the value to be added to the queue: 2

1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the value to be added to the queue: 3

1.Enqueue
2.Dequeue
3.Display
4.Exit
3
Elements in the queue are:
1 2 3
1.Enqueue
2.Dequeue
3.Display
4.Exit
2

1.Enqueue
2.Dequeue
3.Display
4.Exit
3
Elements in the queue are:
2 3
1.Enqueue
2.Dequeue
3.Display
4.Exit
1
Enter the value to be added to the queue: 4

1.Enqueue
2.Dequeue
3.Display
4.Exit
3
Elements in the queue are:
2 3 4
1.Enqueue
2.Dequeue
3.Display
4.Exit*/
