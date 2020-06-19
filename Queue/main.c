#include <stdio.h>
#include <stdlib.h>

int Enqueue(int *front,int *rear,int *size,int queue[*size])
{

if(*rear==(*size-1))
    printf("The Queue is Full");
else
{
    int data;
    if(*front ==-1)
        *front=0;
    printf("Enter the data");
    scanf("%d",&data);
    (*rear)++;
    queue[*rear]=data;

}

}


int Dequeue(int *front,int *rear,int *size,int queue[*size])
{
    if((*front)>(*rear) || (*front)==-1)
        printf("The Queue is Empty");
    else{
        free(queue[*front]);
        (*front)++;
    }
}


int display(int *front,int *rear,int *size,int queue[*size])
{
     if((*front)>(*rear) || (*front)==-1)
        printf("The Queue is Empty \n");
     else{
     printf("The data present in the queue:\n");

    for(int i=(*front);i<=(*rear);i++)
    {
        printf("%d",queue[i]);
        printf("\n");
    }
     }

}

int main()
{
   int  *front , *rear,*size;
   int    a=-1;int b=-1;int c=0;
   printf("Enter the size of the Queue");
   scanf("%d",&c);
   int queue[c];
   size=&c;

   front =&a;
   rear=&b;
   while(1)
   {
       int choice;
       printf("Enter your choice");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:Enqueue(front,rear,size,queue);
                  break;
           case 2:display(front,rear,size,queue);
                   break;
           case 3:Dequeue(front,rear,size,queue);
                  break;
           default :printf("Invalid Input");
                           break;
       }
   }


}



