/* using array
*/
#include<stdio.h>
#include<stdlib.h>
#define max 10
int top=-1;
int arr[max];
void push(int);
void pop(void);
void display(void);
int main(){

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

      
     if(top==max-1)
     {
        printf("Stack is full\n");
        return ;
     
     }

       
      top+=1;
      arr[top]=item;

}
void pop()
{

    if(top==-1)
    {
      printf("Stack underflow\n");
       return ;
    
    }


   top-=1;



}


void display()
{

   if(top==-1)
   {
     printf("Stack is empty\n");
      return ;
   
   }
     
       int i;
       for(i=top;i>=0;i--)
       {
       
          printf("%d\n",arr[i]);
       
       }
   
}
