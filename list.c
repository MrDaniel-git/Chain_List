#include <stdlib.h>
#include <stdio.h>

#include "list.h"

List *initialization()
{
  List *list=malloc(sizeof(*list));
  Element *element=malloc(sizeof(*element));
  
  if(list==NULL||element==NULL)
  exit(EXIT_FAILURE);
  
  element->number=0;
  element->next=NULL;
  list->first=element;
  list->numberElements++;
  
  return list;
}

void add(List* list, int newNumber)
{
  Element *newEl=malloc(sizeof(*newEl));
  if(list==NULL||newEl==NULL)
  exit(EXIT_FAILURE);
  
  newEl->number=newNumber;
  
  newEl->next=list->first;
  list->first=newEl;
  
  list->numberElements++;
}

void addEnd(List *list, int newNumber)
{
  Element *newEl=malloc(sizeof(*newEl));
  if(list==NULL||newEl==NULL)
  exit(EXIT_FAILURE);
  
  newEl->number=newNumber;
  newEl->next=NULL;
  
  Element *actual=list->first;
  while(actual->next!=NULL)
  actual=actual->next;
  
  actual->next=newEl;
  list->numberElements++;
}

void addMid(List *list, int newNumber)
{
  if(list==NULL)
  exit(EXIT_FAILURE);
  Element *newEl=malloc(sizeof(*newEl));
  if(newEl==NULL)
  exit(EXIT_FAILURE);
  
  newEl->number=newNumber;//add number in this new element
  
  Element *actual=list->first;
  int i=1,x=list->numberElements;
  
  while(actual->next!=NULL && i!=(x/2))
  {
   actual=actual->next;
   i++;
  }//to find the middle
  
  if(actual->next!=NULL)
  {
    newEl->next=actual->next;//we add the new one element
    actual->next=newEl;
  }
  
  list->numberElements++;
}

void toDelete(List *list)
{
  if(list==NULL)
  exit(EXIT_FAILURE);
  
  if(list->first!=NULL)
  {
    Element *whatToDelete=list->first;
    list->first=list->first->next;
    free(whatToDelete);
    
    list->numberElements--;
  }
}

void toDeleteEnd(List *list)
{
  if(list==NULL)
  exit(EXIT_FAILURE);
  
  if(list->first!=NULL)
  {
  Element *actual=list->first;
  Element *tempo;
  Element *previous;
    if(actual->next==NULL)
    {
      tempo=list->first;
      list->first=list->first->next;
      free(tempo);
    }
    else
    {
      previous=list->first;
      actual=list->first->next;
      while(actual->next!=NULL)
      {
       previous=previous->next;
       actual=actual->next;
      }
      if(actual!=NULL)
      {
       previous->next=NULL;
       free(actual);
      } //end if
    list->numberElements--;
    } //end else
  } //end control if
} //end function

void toDeleteAll(List *list)
{
  if(list==NULL)
  exit(EXIT_FAILURE);
  
  if(list->first!=NULL)
  {
    Element *actual=list->first;
    while(actual!=NULL)
    {
     actual=actual->next;
     toDeleteEnd(list); //clean all the elements except the first
    }
    toDeleteEnd(list); //clean the first
  }
  list->numberElements--; //numberElements==0 now
}

void seeList(List *list)
{
  if(list==NULL)
  exit(EXIT_FAILURE);
  
  Element *actual=list->first;
  
  printf("La liste contient %d element(s)\n",list->numberElements); // maybe -1
  
  while(actual!=NULL)
  {
    printf("%d->",actual->number);
    actual=actual->next;
  }
  printf("FIN DE LISTE\n");
}