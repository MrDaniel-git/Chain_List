#ifndef H_LIST
#define H_LIST

  typedef struct Element Element;
  struct Element
  {
    int number;
    Element *next;
  };
  
  typedef struct List List;
  struct List
  {
    Element *first;
  };
  
  List *initialization();
  void add(List *list, int newNumber);
  void toDelete(List *list);
  void seeList(List *list);
  
#endif