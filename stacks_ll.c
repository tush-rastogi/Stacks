// Implementation of stacks through linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
         int info;
         struct node *link;
      

}*top=NULL;
void push(int);
void pop();
void display();
int main()
{
   
      int x;
      while(1)
       {
      
             printf("Enter 1 to insert element in stack\n");
             printf("Enter 2 to remove element from stack\n");
             printf("Enter 3 to display elements of stack\n");
             printf("Enter 4 to exit\n");

 
             
             scanf("%d",&x); 

                if(x==4)
                  break;
             
             switch(x)
             { 
               case 1:
               {
                   int x;
                   printf("Enter element to insert\n");
                   scanf("%d",&x);
                   
                   push(x);
                  break;
               
               }
             
                case 2:
                
                  pop();
                  break;
                case 3:
                display();
                break;
             
             }
      
      
      }
     
     
     
     return 0;

}
  
  void push(int item)
  {
  
      struct node *temp=malloc(sizeof(struct node *));
      
        temp->info=item;
        temp->link=top;
        top=temp;
  
  
  }
  
  void pop()
  {
  
      if(top==NULL)
      {
        printf("Underflow\n");
        return ;
      
      }
  
      struct node *temp;
      temp=top;
      top=top->link;
      free(temp);
      
  }
  
  
  
  void display()
  {
     if(top==NULL)
     {
        printf("Stack is empty\n");
        return ;
     
     }
  
        struct node *p=top;
       while(p!=NULL)
       {
         printf("%d\n",p->info);
         p=p->link;
        
       }
  
  }
