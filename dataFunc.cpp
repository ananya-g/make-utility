#include"sourceCPP.h"
using namespace std;
struct tar
{
//Data Members
  char name[32]; //target
  char (*dep)[32]; int dc; //dependencies and count
  struct stat statTar, statDep; //filesize and mod time
  time_t modTar, *modDep;
  char cmd[512];  //command string
  struct tar *link;
  //dep=realloc(dep,(dc+1)*sizeof(*dep);
  //statDep= realloc(statDep,(dc+1)*sizeof(struct stat))
//Constructor
  tar()
  {
    dep = (char(*)[32])calloc(1,sizeof(*dep));
  //  statDep= (struct stat *) calloc(1,sizeof(*statDep));
    modDep= (time_t*) calloc(1,sizeof(*modDep));
    dc=0;
    link= NULL;
  }
//Destructor
  ~tar()
  {
    delete []dep; dep=NULL;
//    delete []statDep; statDep=NULL;
    dc=0;
    link=NULL;
  }
  void display()
  {
    cout<<"Target Name: "<<name<< ": "<<modTar<<endl;
    cout<<"Command: "<<cmd<<endl;
    cout<<"dependencies: "<<endl;
    for(int i=0;i<dc;i++)
    {
      cout<<dep[i]<<": "<<modDep[i]<<"\t";
    }
    cout<<endl<<endl;
  }
};
