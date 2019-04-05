#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct student
{
  int roll;
  char name[20];
  float avg;
  struct student *next, *prev;
}STUDENT;
extern STUDENT *head, *tail;
extern int cnt;
extern void add_beg();
extern void add_end();
extern void add_sort();
int del();
extern void display();
