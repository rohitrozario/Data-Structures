#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

int create(struct node *head,struct node *temp)
{

    int elements,noofelements,d;
    printf("Enter the no of nodes");
    scanf("%d",&noofelements);
    int a[noofelements];
    for(int i=1;i<=1;i++)
    {
        printf("Enter the data");
        scanf("%d",&d);
        head->data=d;
        head->next=NULL;
        temp=head;

    }
    for(int i=2;i<=noofelements;i++)
    {

        struct node *n=(struct node*)malloc (sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&d);
        n->data=d;
        n->next=NULL;
        temp->next=n;
        temp=n;

    }
printf("%p",head);
return 0;

}


int insertatmiddle(struct node *head)
{
    struct node *p,*old;
    int pos,ele;
    printf("Enter the element");
    scanf("%d",&ele);
    printf("Enter the the position");
    scanf("%d",&pos);
    struct node *n=(struct node*)malloc (sizeof(struct node));
    n->data=ele;
    p=old=head;
    for(int i=1;i<pos;i++)
    {
        old=p;
        p=p->next;
    }
    old->next=n;
    n->next=p;
    display(head);
    return 0;

}

int insertatend(struct node *head)
{
    int ele;
    struct node *p;
    p=head;
    printf("Enter the element to be inserted ");
    scanf("%d",&ele);
    struct node *n=(struct node *) malloc(sizeof(struct node));
    n->data=ele;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=n;
    n->next=NULL;
    display(head);

}

int deleteatthebeginning(struct node *head)
{
    struct node *p;
    p=head;
    head=p->next;
    free(p);
    display(head);

}

int deleteatmiddle(struct node *head)
{
    struct node *old,*p,*s;
    int pos;
    old=p=head;
    printf("Enter the position to delete");
    scanf("%d",&pos);
    for(int i=1;i<pos;i++)
    {
        old=p;
        p=p->next;
    }
    s=p->next;
    old->next=s;
    display(head);
}

int deleteatend(struct node *head)
{

    struct node *p,*old;
    p=old=head;
    while(p->next!=NULL)
    {
        old=p;
        p=p->next;
    }
    old->next=NULL;
    free(p);
    display(head);
}

int printinrev(struct node *p)
{
    if (p==NULL)
        return;
    else
        printinrev(p->next);
        printf("%d\n",p->data);
}
int  display(struct node *head)
{

    printf("Displaying the list \n");
    struct node *p=head;

    while(p!=NULL)
    {

        printf("%d",p->data);
        p=p->next;
        printf("\n");
    }

return 0;

}

int main()
{

  struct node *head,*temp;
  head=temp=NULL;
  head=(struct node*)malloc (sizeof(struct node));
  temp=(struct node*)malloc (sizeof(struct node));

    //printf("%d",head);
    int choice,c;
    while(1)
    {
         printf("Enter your choice");
         scanf("%d",&c);
      switch(c)
    {
        case 1: create(head,temp);
                break;
        case 2: display(head);
                 break;
        case 3: insertatmiddle(head);
                break;
        case 4: insertatend(head);
                break;
        case 5: deleteatthebeginning(head);
                break;
        case 6: deleteatmiddle(head);
                break;
        case 7: deleteatend(head);
                break;
        case 8: printinrev(head);
                break;

        default: printf("Invalid input");
                break;
    }
    }
    return 0;
}
