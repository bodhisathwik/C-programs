//write the code for creating and display of linked lists
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create()
 struct Node
{
   int data;
   struct Node *next;
}*head = NULL;

void display()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct Node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp->next != NULL)
      {
  printf("%d --->",temp->data);
  temp = temp->next;
      }
      printf("%d --->NULL",temp->data);
   }
}
int main(){
 create();
 display();
 big=maxval();
 printf("\nBiggest value in the list is %d",big);
 return 0;
}