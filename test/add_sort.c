#include"source.h"
void add_sort()
{
  STUDENT *nu,*t;
  nu= calloc(1, sizeof(STUDENT));
  printf("Enter Roll: " );
  scanf("%d",&nu->roll);
  printf("Enter Name: " );
  scanf(" %[^\n]s",nu->name);
  printf("Enter percentage: " );
  scanf("%f",&nu->avg);
  if(head== NULL)
  {
    head= nu;
    tail= nu;
    nu->prev=nu->next=NULL;
  }
  else
  {
    t= head;
    while(t && (t->roll < nu-> roll))
            t= t->next;
    if(t == NULL)
    {
      if(tail) nu->prev = tail;
      tail-> next= nu;
//      else nu->prev= NULL;
//      nu->next = NULL;
      tail = nu;
    }
    else
    {
      nu->next = t;
      if(t== head) head= nu;
      else
      {
        nu->prev = t -> prev;
        t->prev = t;
        t->prev->next = nu;
      }
    }
  }
}
