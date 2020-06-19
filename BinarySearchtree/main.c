#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    struct node *rchild;
    int value;
};


   struct node *insert(struct node *tree,int val)
               {

                   if(tree==NULL)
                   {
                       tree=(struct node *)malloc(sizeof(struct node));
                       tree->lchild=tree->rchild=NULL;
                       tree->value=val;
                   }
                   else if(val<tree->value)
                   {
                       tree->lchild=insert(tree->lchild,val);
                   }
                   else if(val>tree->value)
                   {
                       tree->rchild=insert(tree->rchild,val);
                   }
                   else{printf("Duplicates Not Allowed ");}
                   return (tree);

                }



int min(struct node *root)
{
                   struct node *temp;
                   temp=root;
                   while(temp->lchild!=NULL)
                   {
                    temp=temp->lchild;
                   }
                   printf("The minimum value in the tree is : %d \n",temp->value);

}

int max(struct node *root)
{
    struct node *temp;
    temp=root;
    while(temp->rchild!=NULL)
        temp=temp->rchild;
    printf("The maximum element in the tree is : %d \n",temp->value);
}


int search(struct node *root)
{
    int key;
    printf("Enter the data to search");
    scanf("%d",&key);
    struct node *parent,*temp;
    temp=root;
    if(temp->value==key)
        printf("The data is present at the root node %d \n",temp->value);
    else
    {
        while(key!=temp->value && temp!=NULL)
        {
            parent=temp;
            if(key<temp->value)
            {
                temp=temp->lchild;
                if(temp->value==key)
                    printf("The data found , with %d as the parent node \n",parent->value);
        }
        else if(key>temp->value)
        {
            temp=temp->rchild;
            if(temp->value==key)
                    printf("The data found , with %d as the parent node \n",parent->value);


        }
    }
}

        if(temp==NULL)
        printf("The data not found \n");
}


int deleteanelement(struct node *root)
{
    int key;
    printf("Enter the element to be deleted");
    scanf("%d",&key);
    struct node *parent,*temp,*successor;
    temp=root;
    if(temp->value==key)
        printf("The data is present at the root node %d \n",temp->value);
    else
    {
        while(key!=temp->value && temp!=NULL)
        {
            parent=temp;
            if(key<temp->value)
            {
                temp=temp->lchild;
                if(temp->value==key)
                    printf("The data found , with %d as the parent node \n",parent->value);
        }
        else if(key>temp->value)
        {
            temp=temp->rchild;
            if(temp->value==key)
                    printf("The data found , with %d as the parent node \n",parent->value);


        }
    }
}

if(temp->lchild==NULL &&temp->rchild==NULL)
{
    if(parent->lchild==temp)
        parent->lchild=NULL;
    else
    {parent->rchild=NULL;}
    printf("The data deleted = %d \n", temp->value);
    free(temp);
}


if(temp->lchild!=NULL && temp->rchild==NULL)
{
    if(parent->lchild==temp)
        parent->lchild=temp->lchild;
    else
        parent->rchild=temp->lchild;
    printf("The data deleted = %d \n",temp->value);
    free(temp);
}

if(temp->lchild==NULL && temp->rchild!=NULL)
{
    if(parent->lchild==temp)
    {
        parent->lchild=temp->rchild;
    }
    else
        parent->rchild=temp->rchild;
    printf("The data deleted = %d \n",temp->value);
    free(temp);

}

if(temp->lchild!=NULL && temp->rchild!=NULL)
{

parent=temp;
successor=parent->rchild;
while(successor->lchild!=NULL)
{
    parent=successor;
    successor=successor->lchild;
}
temp->value=successor->value;
if(parent->lchild==successor)
    parent->lchild=NULL;
else
    parent->rchild=NULL;
printf("The data deleted =%d \n",key);
free(successor);

}

}


void preorder(struct node *temp)
{

if(temp!=NULL)
{
    printf("%d\n",temp->value);
    preorder(temp->lchild);
    preorder(temp->rchild);
}
}


 void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lchild);
        printf("%d\n",temp->value);
        inorder(temp->rchild);
    }
}


  void postorder(struct node *temp)
{

  if(temp!=NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d\n",temp->value);
    }
}



int traversal(struct node *root)
{
    int select;
    printf("Enter 1) Preorder 2) Inorder 3) Postorder :");
    scanf("%d",&select);
    if(select == 1)
    {
        preorder(root);
    }
    else if(select ==2)
    {
      inorder (root);
    }
    else if(select ==3)
    {
     postorder(root);
    }
    else {printf(" Invalid Input\n ");}
}

int main()
{
 struct node *tree=NULL;

    int choice,val;
   while(1)
   {

       printf("Enter your choice ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
               printf("Enter the value");
               scanf("%d",&val);
               tree=insert(tree,val);
               break;

           case 2:
                 min(tree);
                 break;
           case 3:
                max(tree);
                break;
           case 4:
                search(tree);
                break;
           case 5:
                traversal(tree);
                break;
           case 6:
               deleteanelement(tree);
               break;

          default : printf( "Invalid Input ");
                    break;

       }
   }
}
