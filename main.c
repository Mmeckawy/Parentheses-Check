#include <stdio.h>
#include <stdlib.h>

#define MAX 200

struct stack {
  char array[MAX];
  int top;
}s;

void push(char item) {
  if (s.top == (MAX - 1))
    printf("Stack Overflow\n");

  else {
    s.top++;
    s.array[s.top] = item;
  }
}

char pop() {
  if (s.top == -1)
    printf("Stack is Empty\n");
  else
    return (s.array[s.top--]);
}

int checkPair(char val1,char val2){
    if(( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ))
        return 1;
    else
        return 0;
}

int check(char exp[])
{
        int i;
        char temp;
        for(i=0;i<strlen(exp);i++)
        {
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                    push(exp[i]);
            if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
                    if(s.top==-1)    /*stack empty*/
                    {
                       return 0;
                    }
                    else
                    {
                        temp = pop();
                    if(!checkPair(temp, exp[i]))
                    {
                        printf("%c and %c\n",temp,exp[i]);
                        return 0;
                    }
                    }
        }
        if(s.top==-1)
        {
            printf("Balanced Parentheses\n");
            return 1;
        }
        else
        {
            printf("Not Balanced Parentheses\n");
        }
}

int main() {
  char exp[MAX];
  int i = 0;
  s.top = -1;
  int len = strlen(exp);

  printf("Enter an expression : ");
  gets(exp);
  check(exp);

  return 0;
}
