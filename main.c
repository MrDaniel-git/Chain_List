#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
  List *myList=initialization();
  toDelete(myList);
  add(myList,13);
  add(myList,5);
  add(myList,7);
  add(myList,20);
  toDelete(myList);
  
  seeList(myList);
  
  return 0;
}