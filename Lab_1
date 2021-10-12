// C Program to perform stack operation

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define SIZE 10

void push();
void pop();
bool isFull();
bool isEmpty();
void display();


int A[SIZE];
int top = -1;

void push()
{
    int value;
    printf("enter the value: ");
    scanf("%d",&value);
    
    if(isFull())
     printf("Stack is full\n");
    else
     A[++top] = value;
}

void pop()
{
    if(isEmpty())
     printf("Stack is empty\n");
    else
     {
         printf("%d\n",A[top]);
         A[top] = 0;
         top = top -1;
     }
}

bool isFull()
{
    if(top == SIZE)
     return true;
    else
     return false;
}

bool isEmpty()
{
    if(top == -1)
     return true;
    else
     return false;
}

void display()
{
  if(isEmpty())
   printf("Stack is empty");
  else
    {
     for( int i = top; i > -1; i--)
     {
         printf("%d\n",A[i]);
     }
        }
}

int main()
{
    int choice;
    while(true)
    {
        printf("MENU\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 : push();
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
        }
    }
   return 0;
} 
