#include <stdio.h>
#include <stdlib.h>

int main()
{
    int front,rear,size,data,choice;
    front=rear=-1;
    printf("Enter the size of the Queue");
    scanf("%d",&size);
    int queue[size];
    while(1)
    {

        printf("Enter your choice 1)Enqueue 2)Display  3)Dequeue:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(front==(rear+1)%size)
                {
                    printf("The Queue is Full");
                }
                else{
                        printf("Enter the data");
                        scanf("%d",&data);
                        if(front==-1)
                        {
                        front=0;
                        }
                        rear=(rear+1)%size;
                        queue[rear]=data;

                }
                break;
                default:printf("Invalid Input");
                break;
        }

    }

}
