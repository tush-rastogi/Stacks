// Reversal of string through stack
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *reverse(char *);
char arr[20];
int top=-1;
void push(char);
char pop();
int main()
{
   
   
      char string[20];
        int i;
      printf("Enter the string\n");
      scanf("%s",string);
        int l=strlen(string);
       for(i=0;i<l;i++)
       {
           push(string[i]);
       
       }
          
          for(i=0;i<l;i++)
          {
            string[i]=pop();
          
          }
          
          printf("Reversed string is-%s",string);
     
     return 0;

}
 
void push(char s)
{
   top+=1;
   arr[top]=s;


}

char pop()
{
     return arr[top--];

}
