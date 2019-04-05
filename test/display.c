#include"source.h"
void display()
{
  STUDENT *t=head;
  if(t != NULL)
  {
    while(t)
    {
      printf("%3d: %s\t %2f\n",\
      t->roll,t->name,t->avg );
      t= t-> next;
    
  }
}
