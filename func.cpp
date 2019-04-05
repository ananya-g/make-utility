#include"sourceCPP.h"
struct tar;
using namespace std;
extern struct tar *head;
bool executioner (tar *ptr)
{
  struct tar *t= ptr;
  int x;
  for(int i=0; i < ptr->dc ; i++)
  {
    if(ptr-> modTar==0 || ptr-> modTar < ptr-> modDep[i])
    {
      while(t && (strcmp(t->name,ptr->dep[i]) !=0) )
      { t=t->link; }
      if(t==NULL)
      {
        cout<<"\n1"<<endl;
        if(ptr==head)
        {
          while(t && (strstr(t->name,"clear") ==0))
          {
            cout<<"Checking dependencies";
            executioner(t);
            t=t->link;
          }
        }
        break;
      }
      else
      {
        cout<<"Entering dependency: "<< ptr->dep[i]<<endl;
        executioner(t);
        sleep(1);
      }
    }
  }
  cout<<"Executing cmd of Target: "<< ptr->name<<endl;
  if( system(ptr->cmd)!=0)
  {
    cout<<x<<endl;
    cout<<"Illegally Terminated!"<<endl;
    exit(0);
  }
  else
  {
    cout<<"Executed"<<endl;
    sleep(1);
    return true;
  }
  return false;
}

void getTar(struct tar* &ptr,char* line)
{
  struct tar* nu;
  nu= new struct tar;
  char* tok;
//note: i guess this is call by address...
//      so buffer will be edited... MIND IT
  tok= strtok(line," :");
  strcpy(nu->name,tok);
  if(stat(nu->name,&(nu->statTar))!= -1 )
  {
    nu->modTar= nu->statTar.st_ctime;
  }
  else nu->modTar=0;
  //CHECK FOR TARGET ERROR, ONLY ONE AT A TIME
  tok= strtok(NULL," \n");
  while(tok)
  {
    struct stat *temp;
    temp =new struct stat;
    strcpy(nu->dep[nu->dc],tok);
    if(stat(nu->dep[nu->dc],(temp))!= -1 )
    {
      nu->modDep[nu->dc]= temp->st_ctime;
    }
    else nu->modDep[nu->dc]=0;
    (nu->dc)++;
    nu->dep=(char(*)[32]) realloc(nu->dep,((nu->dc)+1)*sizeof(*(nu->dep)));
    nu->modDep=(time_t*) realloc(nu->modDep,((nu->dc)+1)*sizeof(*(nu->modDep)));
    tok= strtok(NULL," \n");
    delete temp;
  }
/*cout<<"tar: "<<nu->name<<endl;
  for(int i=0;i<nu->dc;i++)
    cout<<"dep:"<<nu->dep[i]<<endl;
*/
  //LINKING
  if(ptr== NULL)
    ptr= nu;
  else
  {
    struct tar *t=ptr;
    while(t->link)
      t=t->link;
    t->link=nu;
  }
  //cout<<nu->name;
}

void getClr(struct tar* &ptr,char* line)
{
  struct tar *clr= new struct tar;
  char *tok;
  tok= strtok(line," :");
  strcpy(clr->name,tok);
  tok= strtok(NULL," \n");
  while(tok)
  {
    strcpy(clr->dep[clr->dc],tok);
    (clr->dc)++;
    clr->dep=(char(*)[32]) realloc(clr->dep,((clr->dc)+1)*sizeof(*(clr->dep)));
    tok= strtok(NULL," \n");
  }
  if(ptr==NULL )  // && argc == 2
  {
    ptr=clr;
  }
  else
  {
    struct tar *t=ptr;
    while(t->link)
      t=t->link;
    t->link=clr;
  }
}

void getCmd(struct tar* &ptr,char* line)
{
  if(ptr == NULL)
  {
    //ERROR WRITE LATER ALL OF THEM
  }
  else
  {
    struct tar *t=ptr;
    while(t->link)
      t=t-> link;
    strcpy(t->cmd,line+1);
  }
}
