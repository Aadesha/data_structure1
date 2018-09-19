#include<stdio.h>
#include<stdlib.h>
struct tree
{ int data;
    struct tree*r;
    struct tree*l;
    struct tree*p;
}*root=NULL,*temp=NULL,*temp3;
void search(struct tree*);
void inorder(struct tree*);
void insert(void);
void delete(void);
struct tree *min(struct tree*);

void create(void);
void search1(struct tree*,int );
void hi(struct tree*);
int main()
{   int choice;
    int cont=1;
     while(cont==1)
     {
         printf("\n1:inorder\n2:insert\n3:delete");
         printf("enter your choice");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
                 inorder(root);
                 break;
             case 2:
                 insert();
                 break;
             case 3:
                 delete();
                 break;
         }
       //  printf("to continue =1");
         //scanf("%d",&cont);
     }
    return 0;
}

void create()
{   int key;
    printf("\n enter value ");
    scanf("%d",&key);
    temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=key;
    temp->p=NULL;
    temp->l=NULL;
    temp->r=NULL;
    
}
void insert()
{
    create();
 if(root==NULL)
 {
     root=temp;
     return ;
 }
  else
  {
      search(root);
  }
    
}

void search(struct tree* temp1)
{
    if(temp->data>temp1->data)
    {   if(temp1->r==NULL)
    {
        temp1->r=temp;
        temp->p=temp1;
        return ;
    }else{
        search(temp1->r);
    }
    }
    if(temp->data<temp1->data)
    {   if(temp1->l==NULL)
    {
        temp1->l=temp;
        temp->p=temp1;
        return ;
    }else{
        search(temp1->l);
    }
    }
    
   
}

void delete()
{   int key;
    printf("\n enter the key to be deleted");
    scanf("%d",&key);
    
    search1(root,key);
}

void search1(struct tree*temp2,int k)
{
    if(k>temp2->data)
    {   if(temp2->r==NULL)
    {
        printf("\n no such node exits");
        return ;
    }else{
        search1(temp2->r,k);
    }
    }
    else if(k<temp2->data)
    {   if(temp2->l==NULL)
    {
        printf("\n no such node exits");
        return ;
    }else{
        search1(temp2->l,k);
    }
    }
    else{
        if(k==temp2->data)
        {
            hi(temp2);
            return ;
            
        }
        
    }
}

void  hi(struct tree *t)
{
    if((t->l==NULL)&&(t->r==NULL))
    {
        if(t->p->r==t)
        { t->p->r=NULL;
            free(t);
            return ;
        }
        else
        { t->p->l=NULL;
            free(t);
            return ;
        }
        
        
    
}
else if(t->l==NULL)
{
    if(t->p->r==t)
    { t->p->r=t->r;
        free(t);
        return ;
    }
    else
    { t->p->l=t->r;
        free(t);
        return ;
    }
}
else if(t->r==NULL)
{
    if(t->p->r==t)
    { t->p->r=t->l;
        free(t);
        return ;
    }
    else
    { t->p->l=t->l;
        free(t);
        return ;
    }
}
else{
    temp3=min(t->r);
    
    for(;temp3->r!=NULL;)
    {
        if(temp3->p->r==temp3)
    { temp3->p->r=temp3->r;
        temp3->r->p=temp3->p;
    }
    else
    { temp3->p->l=temp3->r;
        temp3->r->p=temp3->p;
    }
    if(t->p->r==t)
    { t->p->r=temp3;
        temp3->p=t->p;
        free(t);
        return ;
    }
    else
    { t->p->l=temp3;
        temp3->p=t->p;
        free(t);
        return ;
    }
    }
    if(temp3->p->r==temp3)
    {
        temp3->p->r=NULL;
    }
    else{
        temp3->p->l=NULL;
    }
}
}

struct tree* min(struct tree *f)
{
    if(f->l!=NULL)
    {
         min(f->l);
    }
    
    return f;
    }

void inorder(struct tree*r)
{   if(r->l!=NULL)
   {inorder(r->l);}
    printf("%d",r->data);
    if(r->r!=NULL)
    {inorder(r->r);}
    return ;
    
}

