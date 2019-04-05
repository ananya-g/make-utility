#include"source.h"
STUDENT *head=NULL, *tail=NULL;
int cnt=0;
int main()
{
  int ch;
  while(1)
  {
    printf("1. add_beg\t 2. add_end\t 3. add_sort\n");
    printf("4. delete\t 5. find\t 6. sort\n");
    printf("7. display\t 8. quit\n");
    printf("ENTER CHOICE: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: add_beg(); break;
      case 2: add_end(); break;
      case 3: add_sort(); break;
      case 4: if(del()) cnt --;
              break;
/*      case 5: find(); break;
      case 6: sort(); break;
*/      case 7: display(); break;
      case 8: goto END; break;
      default: printf("INVALID CHOICE\n"); break;
    }
    if(ch<=3 && ch>0) cnt++;
    while(getchar()!= '\n');
  }
END:  printf("\nRECORDS ENTERED: %d\n",cnt);
}
