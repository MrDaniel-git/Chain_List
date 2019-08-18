#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
  List *myList=initialization();
  
  toDelete(myList);
  add(myList,14);
  add(myList,13);
  addEnd(myList,16);
  addEnd(myList,17);
  addMid(myList,15);
  seeList(myList);
  
  return 0;
}