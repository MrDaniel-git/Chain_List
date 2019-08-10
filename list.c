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
  }
}

void seeList(List *list)
{
  if(list==NULL)
  exit(EXIT_FAILURE);
  
  Element *actual=list->first;
  
  while(actual!=NULL)
  {
    printf("%d->",actual->number);
    actual=actual->next;
  }
  printf("NULL\n");
}