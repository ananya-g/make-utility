#include"source.h"
void add_end()
{
  STUDENT *nu;
  nu= calloc(1, sizeof(STUDENT));
  printf("Enter Roll: " );
  scanf("%d",&nu->roll);
  printf("Enter Name: " );
  scanf(" %[^\n]s",nu->name);
  printf("Enter percentage: " );
  scanf("%f",&nu->avg);
  if(tail== NULL)
  {
    head= nu;
    tail= nu;
    nu->prev=nu->next=NULL;
  }
  else
  {
    nu->prev= tail;
    tail->next= nu;
    tail= nu;
  }
}
