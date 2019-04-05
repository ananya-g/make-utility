#include"source.h"
int del()
{
  STUDENT *t=NULL;
  fflush(stdin);
  if(head==NULL)
    { printf("Empty Database\n");return 0; }
  else
  {
    int d;
    t= head;
    printf("Enter roll number:" );
    scanf("%d",&d);
    while(t && (t->roll != d) )
      t=t-> next;
      if(t == NULL)
      { printf("Data Not Found\n"); return 0; }
    else if(t== head)
      { if(head->next)
        { head = head-> next;
          head->prev = NULL; }
        else head= NULL, tail= NULL;
      }
    else if(t== tail)
      { if(tail->prev)
        { tail= tail-> prev;
          tail->next= NULL; }
        else head= NULL, tail= NULL;
      }
    else
    {
      t->prev->next= t->next;
      t->next->prev= t->prev;
    }
    free(t); t= NULL;
  }
}
