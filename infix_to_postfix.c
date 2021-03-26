#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 20
char infix[MAX];
char postfix[MAX];
int stack[MAX];
int top=-1;
int pop();
void push(int);
int priority(char);
void infix_to_postfix();
int eval_post(void);
int main()
{
      
        int value;
      
      printf("Enter expression\n");
     scanf("%[^\n]s",infix);
     
      infix_to_postfix();
      printf("Postfix:%s\n",postfix);
      
      value =eval_post();
      printf("%d",value);
      
      
   
   
   
     return 0;

}
  
int priority(char c)
{

    switch(c)
    {
      
       case '(':
         return 0;
        
         
         case '+':
         case '-':
            return 1;
            
            
            case '/':
            case '%':
            case '*':
            
            return 2;
             
               
               
               case '^':
                return 3;
                 
                 
                 
                 default:
                  return 0;
                  
              
    }
}
   void infix_to_postfix()
   {
   
          int i,p=0;
          char k,t;
          for (i =0; i < strlen(infix); i += 1)
          {
          	k=infix[i];
          	
          	switch(k)
          	{
          	
          	  case '(':
          	    push(k);
          	    break;
          	    
          	     case ')':
          	           
          	              while((t=pop())!='(')
          	                postfix[p++]=t;
          	                break;
          	    
          	    
          	    
          	    case '+':
          	    case '-':
          	    case '/':
          	    case '*':
          	    case '%':
          	    case '^':
          	    
          	        while(top!=-1&&(priority(stack[top])>=priority(k)&&k!='^'))
          	          postfix[p++]=pop();
          	          
          	          push(k);
          	           break;
          	           
          	           
          	           default:
          	           
          	           postfix[p++]=k;
          	         
          	}
          	
          }	
          	
              while(top!=-1)
              {
                 postfix[p++]=pop();
                 }
                 
                 postfix[p]='\0';
          
          
          }
       
       
  int  pop()
{

     if(top==-1)
     {
       printf("Underflow\n");
         exit(1);
       
       }
       
       
         return stack[top--];
       
       }
       
       void push(int c)
       {
          
           if(top>MAX)
           {
             printf("Overflow\n");
               return ;
               
               }
               
               
               
               stack[++top]=c;
               
             }
             
             
             
       int eval_post()
       {
       
           int i,a,b,result;
           char c;
           for (i = 0; i <strlen(postfix); i += 1)
           {
           	
           	  
           	  if(postfix[i]>='0'&&postfix[i]<='9')
           	    push(postfix[i]-'0');
           	    
           	    else
           	    {
           	       a=pop();
           	       b=pop();
           	       
           	        switch(postfix[i])
           	        {
           	        
           	           case '+':
           	             
           	               result =b+a;
           	               break;
           	               
           	               case '-':
           	                result=b-a;
           	                 break;
           	                 
           	                 case '*':
           	                 result=b*a;
           	                   break;
           	                 case '/':
           	                       result=b/a;
           	                         break;
           	                   case '%' :
           	                       result =b%a;
           	                       break;
           	                       
           	                       case '^':
           	                        result=pow(b,a);
           	                        break;
           	                        
           	                      }
           	                      
           	                      push(result);
           	                      
           	                      }  
           	    
           }
       
       
              result=pop();
              
                return result;
              } 
             
