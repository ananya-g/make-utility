#include"sourceCPP.h"
#include"dataFunc.cpp"
#include"func.cpp"
using namespace std;
void getTar(struct tar* &ptr,char* line);
void getClr(struct tar* &ptr,char* line);
void getCmd(struct tar* &ptr,char* line);
bool executioner(struct tar* ptr);
struct tar *head=NULL;
int main(int argc,char *argv[] )
{
  ifstream mf;
  struct stat s;
  char (*mfBuf)[256]=NULL;
  int lc=0;
  mf.open("makef");
  if(stat("makef",&s)==-1)
  {
    cout<<"File doesnt Exist"<<endl;
    return 0;
  }
  if(s.st_size==0)
  {
    cout<<"Empty File"<<endl;
    return 0;
  }
  mfBuf= (char(*)[256]) calloc(1,sizeof(*mfBuf));
  while(mf.getline(mfBuf[lc],256))
  {
    if(mfBuf[lc][0]!=0)
    {
      lc++;
      mfBuf=(char(*)[256]) realloc(mfBuf,sizeof(*mfBuf)*(lc+1));
    }
  }
/*  cout<<lc<<endl;
  for(int i=0;i<lc;i++)
    cout<<mfBuf[i]<<endl;
*/  //2D array Created!
  int i=0;
  if(argc!=1 && strstr(argv[1],"clear"))
  {
    while(i<lc && (strstr(mfBuf[i],"clear") == 0) )
    i++;
    getClr(head,mfBuf[i]);
    getCmd(head,mfBuf[i+1]);
    goto END;
  }
  while(i<lc)
  {
    if(strchr(mfBuf[i],':')!=0)
      getTar(head,mfBuf[i]);
    else if(mfBuf[i][0]=='\t')
      getCmd(head,mfBuf[i]);
    i++;
  }
  /*
  t=head;
  {
    if(stat(t->name,&s)==-1)
    {
      //cout<<"File doesnt Exist"<<endl;
      stat(t->dep);
    }
  }
  */
END:
  struct tar *t= NULL;
  t= head;
  while(t)
  {
    t->display();
    t=t->link;
  }
//  executioner(head);
  t=head;
  executioner(t);
/*  {
    t=t->link;
    while(t && (strstr(t->name,"clear") ==0))
    {
      executioner(t);
      t=t->link;
    }
  }
//  while(executioner(t)== false)
//  { t=t-> link; }
*/  delete []mfBuf;
  mfBuf=NULL;
  return 0;
}
