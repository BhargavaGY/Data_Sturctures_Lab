#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char value)
{
    stack[++top] = value;
}

char pop()
{
    return(stack[top--]);
}

bool isempty()
{
    if(top == -1)
       return true;
    else
       return false;
}

int pr(char symbol)
{
    if(symbol == '^')
       return(3);
    else if(symbol == '*' || symbol == '/')
       return(2);
    else if(symbol == '+' || symbol == '-')
       return(1);
    else 
       return(0);
    
}

void infixtopostfix(char expr[],int length)
{
    char postfix[SIZE];
    int i;
    int k = 0;
    char elem;

    for(i = 0; i < length; i++)
    {
        if(expr[i] == '(')
           push(expr[i]);
        else
        {
          if(isalnum(expr[i]))
            postfix[k++] =+ expr[i];
          else
            if(expr[i] == ')')
            {  while(stack[top] != '(')
                    postfix[k++] =+ pop();
                elem = pop();
            }
            else
            {
                while(pr(stack[top]) >= pr(expr[i]))
                    postfix[k++] =+ pop();
                push(expr[i]);
            }
           
        }
    }
    
    while(!(isempty()))
    {
        postfix[k++] =+ pop();
    }

    postfix[k] = '\0';
    
    printf("Postfix expression is: %s",postfix);
   
}

int main()
{
    char expression[SIZE];
    printf("Enter the infix expression");
    gets(expression);
    
    infixtopostfix(expression,strlen(expression));
    
    return 0;
}
