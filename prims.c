#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#define infinity 999
int j=0;
int adjacent[20];
int cost=0;
int Totalcost=0;
struct listnode
{
int v;
int cost;
struct listnode *next;
};
typedef struct listnode *list;
struct tableEntry
{
 list head;
 int known;
 int dist;
 int path;
 };
 typedef struct tableEntry Table[10];
  Table T;
 void buildad(int v1,int v2,int c1)
 {
 list temp=(list)malloc(sizeof(struct listnode));
  list temp1=(list)malloc(sizeof(struct listnode));
    temp->v=v2;
    temp1->v=v1;
    temp1->cost=c1;
    temp->cost=c1;
    temp->next=NULL;
    temp1->next=NULL;
   temp->next=T[v1].head->next;
   T[v1].head->next=temp;
   temp1->next=T[v2].head->next;
   T[v2].head->next=temp1;
 }
 void calad(int s)
 {
    list temp;
    j=0;
   for(temp=T[s].head->next;temp!=NULL;temp=temp->next)
 {
 adjacent[++j]=temp->v;
 }
 }
 void findcost(int s,int d)
 {
	list temp;
   for(temp=T[s].head->next;temp->v!=d;temp=temp->next)
 {
 }
 cost=temp->cost;
 }
 void ReadGraph()
  {
    int ed,v1,v2,c1,i;
 printf("\nenter the no of edges:");
 scanf("%d",&ed);
 for(i=1;i<=ed;i++)
 {
 printf("\nEnter the Vertices pair along with cost");
 scanf("%d%d%d",&v1,&v2,&c1);
 buildad(v1,v2,c1);
 }
 }
 void initTable(int s,int NV)
 {
 int i;
  for(i=1;i<=NV;i++)
 {
 T[i].head=(list)malloc(sizeof(struct listnode));
 T[i].head->next=NULL;
 T[i].known=0;
 T[i].dist=infinity;
 T[i].path=0;
 }
 T[s].dist=0;
 ReadGraph();
 }
 void printTable(int N)
 {
 int i;
 list temp;
 printf("\n***FINAL TABLE****");
 printf("\n------------------");
 printf("\nvertex\tKnown  dv    Pv");
 printf("\n------------------------");
 for(i=1;i<=N;i++)
 {
 printf("\n%d\t%d\t%d\t%d",i,T[i].known,T[i].dist,T[i].path);
 }
 }
void prims(int N)
 {
  int v,w,i,c=0,min=99;
   while(c!=N)
  {
  for(i=1;i<=N;i++)
  {
   if(T[i].known==0)
   {
   if(min>T[i].dist)
   {
    min=T[i].dist;
    v=i;
    }
    }
    }
  T[v].known=1;
  Totalcost+=T[v].dist;
  ++c;
  calad(v);
  for(i=1;i<=j;i++)
    {
     w=adjacent[i];
    if(T[w].known==0)
    {
      findcost(v,w);
     if(cost<T[w].dist)
	{
	  T[w].dist=cost;
	  T[w].path=v;
	  }
	}
 }
 min=99;
 }
}
 void main()
 {
 int s,NV,d;
 printf("Enter the source vertex:");
 scanf("%d",&s);
 printf("Enter the No of vertices:");
 scanf("%d",&NV);
 initTable(s,NV);
 prims(NV);
printTable(NV);
printf("\n**************************************");
printf("\n\nMinimum cost of the tree is %d:",Totalcost);
printf("\n**************************************");
 getch();
 }

