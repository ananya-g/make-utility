#include"source.h"
void add_beg()
{
  STUDENT *nu;
  nu= calloc(1, sizeof(STUDENT));
  printf("Enter Roll: " );
  scanf("%d",&nu->roll);
  printf("Enter Name: " );
  scanf(" %[^\n]s",nu->name);
  printf("Enter percentage: " );
  scanf("%f",&nu->avg);
  nu->next= head;
  if(head)  head->prev= nu;
  else nu->prev= nu->next=NULL, tail= nu;
  head= nu;
}
