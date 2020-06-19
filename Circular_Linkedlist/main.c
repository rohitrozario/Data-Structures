#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int create(struct node *head)
{
    struct node *temp;
    int noofelements;
    printf("Enter the number of elements");
    scanf("%d",&noofelements);
    for (int i=1;i<=1;i++)
    {
        printf("Enter the data");
        scanf("%d",&head->data);
        head->next=head;
        temp=head;
    }

    for(int i=2;i<=noofelements;i++)
    {
        struct node *n=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&n->data);
        n->next=head;
        temp->next=n;
        temp=temp->next;

    }

    //display(head);
}

int search(struct node *head)
{
    int c=1,ele;
    struct node *temp=head;
    printf("Enter the element to search ");
    scanf("%d",&ele);
    do{

            if(temp->data==ele)
            {
                printf("Element found at position = %d \n",c);
                break;
            }
            temp=temp->next;
            c++;

    }while(temp!=head);
}

int insertatbeginning(struct node *head)
{
    struct node *p;
    int ele;
    p=head;
    printf("Enter the element to be inserted ");
    scanf("%d",&ele);
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=ele;
    n->next=head;
    while (p->next!=head)
        p=p->next;
    p->next=n;
    head=n;
    //display(head);


}

int insertatmiddle(struct node *head)
{
    struct node *p,*temp;
    int pos,ele;
    temp=p=head;
    printf("Enter the position to insert the element ");
    scanf("%d",&pos);
    printf("Enter the element ");
    scanf("%d",&ele);
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=ele;
    n->next=NULL;
    for(int i=1;i<pos;i++)
    {
        temp=p;
        p=p->next;
    }
    temp->next=n;
    n->next=p;
    display(head);

}

int insertatend(struct node *head)
{
    struct node *p;
    p=head;
    int ele;
    printf("Enter the element to be inserted ");
    scanf("%d",&ele);
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=ele;
    n->next=head;
    while (p->next!=head)
        p=p->next;
    p->next=n;
    //display(head);

}

int delatbeg(struct node *head)
{
    struct node *p;
    p=head;
    head=head->next;
    free(p);
    //display(head);

}

int delatmiddle(struct node *head)
{
    struct node *s,*p,*temp;
    p=temp=head;
    int pos;
    printf("Enter the position");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++)
    {
        temp=p;
        p=p->next;
    }
    s=p->next;
    temp->next=s;
    free(p);
    //display(head);
}

int delatend(struct node *head)
{
    struct node *temp,*p;
    p=temp=head;
    while(p->next!=head)
    {
        temp=p;
        p=p->next;
    }
    temp->next=head;
    free(p);
    //display(head);

}

int display(struct node *head)
{
    struct node *temp;
    temp=head;
    do
    {
        printf("%d",temp->data);
        temp=temp->next;
        printf("\n");
    }while(temp!=head);
}


int main()
{
    struct node *head;
    int choice;
    head=(struct node *)malloc(sizeof(struct node));
    while(1)
    {
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:  create(head);
                     break;
            case 2: search(head);
                    break;
            case 3:display(head);
                    break;
            case 4: insertatbeginning(head);
                    break;
            case 5: insertatmiddle(head);
                    break;
            case 6: insertatend(head);
                    break;
            case 7:delatbeg(head);
                   break;
            case 8:delatmiddle(head);
                    break;
            case 9:delatend(head);
                   break;
            default: printf("Invalid Input ");
                     break;
        }
    }
}
