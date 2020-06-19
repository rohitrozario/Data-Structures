#include <stdio.h>
#include <stdlib.h>

int isFull(int top,int MAX_size)
{
    if (top>=MAX_size-1)
    {
        //printf("Stack is Full");
        return 1;
    }
    return 0;
}

int isEmpty (int top,int MAX_size)
{
    if(top==-1)
    {
        //printf("Stack is Empty");
        return 1;
    }
    else return 0;
}

int push(int MAX_size,int top,int stack[MAX_size])
{
     int check ;
     check =isFull(top,MAX_size);
     if(check == 1)
        printf("The stack is FULL \n");
     else{
            int  data;
            printf("Enter the data");
            scanf("%d",&data);
            top++;
            stack[top]=data;
     }
     return top;
printf("%d",top);

}

int pop(int MAX_size,int top,int stack[MAX_size])
{
  int check;
  check=isEmpty(top,MAX_size);
  if(check==1)
    printf("The stack is Empty \n");
  else
  {
      int n=stack[top];
      top--;
      printf("The data popped out of stack : %d \n",n);
  }
  return top;
}


int peep(int MAX_size,int top,int stack[MAX_size])
{
    int check;
    check=isEmpty(top,MAX_size);
    if(check==1)
        printf("The stack is Empty \n");
    else{
             printf("The data in the stack : \n");
            for(int i=top;i>=0;i--)
            {
            printf("%d",stack[i]);
            printf("\n");
            }

    }
}

int main()
{
 int MAX_size=0, top=-1, stack[MAX_size],choice;
  printf("Enter the size of the stack");
  scanf("%d",&MAX_size);

 while(1)
 {
     printf("Enter your choice");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1: top=push(MAX_size,top,stack);
                 break;
         case 2:peep(MAX_size,top,stack);
                break;
        case 3: top=pop(MAX_size,top,stack);
                break;
          default : printf("Invalid Input");
                    break;
     }
 }
}
