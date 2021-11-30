#include<stdio.h>
#include<stdlib.h>

#define SIZE 3
int p_queue[SIZE];
int rear = -1, front = -1;

void insert()
{
    if(rear == -SIZE - 1)
      printf("Queue is full");
    else
    {
        int data;
        printf("Enter the data to be added: \n");
        scanf("%d", &data);
        
        if(rear == -1)
        {
            front++;
            p_queue[++rear] = data;
        }
        
        else
        {  
           check(data);
           rear++;
        }
    }
    
}

void delete()
{
    if(rear == -1)
       printf("Queue is Empty\n");
    else
       if(front == rear)
          front = rear = -1;
       else
          front++;
}

void check(int data)
{
    int i, j;
    
    for( i = 0; i <= rear; i++)
    {
        if(data <= p_queue[i])
        {
            for(j = rear + 1; j > i; j--)
            {
                p_queue[j] = p_queue[j-1];
            }
            break;
        }
    }
  p_queue[i] = data;
}

void display()
{
    if(rear == -1)
      printf("Queue is Empty\n");
      
    else
      for( int k = front; k <= rear; k++)
          printf("%d", p_queue[k]); 
}


void main()
{
    int choice = 0;
    printf("Enter your choice:\n");
    
    while(choice >= 0)
    {
        printf("\n1.Insert by priority\t2.Delete by priority\t3.Display\t4.Exit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            
            default: printf("Enter a valid choice!!\n");
        }
    }
}

/* OUTPUT
Enter your choice:

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
1
Enter the data to be added: 
2

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
1
Enter the data to be added: 
4

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
1
Enter the data to be added: 
3

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
3
2 3 4 
1.Insert by priority    2.Delete by priority    3.Display       4.Exit
1
Enter the data to be added: 
8

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
1
Enter the data to be added: 
6

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
3
2 3 4 6 8 
1.Insert by priority    2.Delete by priority    3.Display       4.Exit
2

1.Insert by priority    2.Delete by priority    3.Display       4.Exit
3
3 4 6 8 
1.Insert by priority    2.Delete by priority    3.Display       4.Exit
4*/
