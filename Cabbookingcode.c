#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int G[10][10],cost[10][10],pay[10][10],sum=0;
int INF=999;
struct next
{
    char name[100];
    int hour;
    long int number;
}q[10];
int min(int a,int b)
{
    return (a<b)?a:b;
}
void LocationsInCity()
{
    printf("1.Kukatpally\n");
    printf("2.Hi-tech City\n");
    printf("3.Dilsukhnagar\n");
    printf("4.Lakdikapul\n");
    printf("5.Medhipatnam\n");
}
void dijkstra(int cost[10][10],int startnode,int dst)
{
int v=dst;
int distance[10],pred[10];
int visited[10],count,mindistance,nextnode,i,j,sum=0;
for(i=1;i<=5;i++)
{
for(j=1;j<=5;j++)
{
pay[i][j]=cost[i][j];
}
}
for(i=1;i<=5;i++)
{
distance[i]=pay[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<4)
{
mindistance=INF;
for(i=1;i<=5;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}
visited[nextnode]=1;
for(i=1;i<=5;i++)
if(!visited[i])
if(mindistance+pay[nextnode][i]<distance[i])
{
distance[i]=mindistance+pay[nextnode][i];
pred[i]=nextnode;
}
count++;
}
for(i=1;i<=5;i++)
if(i!=startnode)
{
if(v==i){
printf("\nPath");
switch(i)
{
  case 1:{
      printf("<-Kukatpally");
      break;}
  case 2:{
      printf("<-Hi-tech City");
      break;}
  case 3:{
      printf("<-Dilsukhnagar");
      break;}
  case 4:{
      printf("<-Lakdikapul");
      break;}
  case 5:{
       printf("<-Medhipatnam");
      break;}
}
j=i;
do
{
j=pred[j];
switch(j)
{
  case 1:{
      printf("<-Kukatpally");
      break;}
  case 2:{
      printf("<-Hi-tech City");
      break;}
  case 3:{
      printf("<-Dilsukhnagar");
      break;}
  case 4:{
      printf("<-Lakdikapul");
      break;}
  case 5:{
       printf("<-Medhipatnam");
      break;}
}
//printf("\n");
}while(j!=startnode);
}}

}
int Map(int src,int dst)
{
    cost[1][1]=0;
    cost[1][2]=100;
    cost[1][3]=150;
    cost[1][4]=100;
    cost[1][5]=INF;
    cost[2][1]=200;
    cost[2][2]=0;
    cost[2][3]=150;
    cost[2][4]=INF;
    cost[2][5]=INF;
    cost[3][1]=INF;
    cost[3][2]=INF;
    cost[3][3]=0;
    cost[3][4]=200;
    cost[3][5]=150;
    cost[4][1]=INF;
    cost[4][2]=INF;
    cost[4][3]=INF;
    cost[4][4]=0;
    cost[4][5]=100;
    cost[5][1]=200;
    cost[5][2]=INF;
    cost[5][3]=INF;
    cost[5][4]=INF;
    cost[5][5]=0;
    int i,j,k,a[10][10];
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            a[i][j]=cost[i][j];
        }
    }
    for(k=1;k<=5;k++)
    {
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=5;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    dijkstra(cost,src,dst);
  return a[src][dst];
}
int dijkstra1(int G[10][10],int startnode,int dst)
{
int v=dst;int totaltime=0;
int distance[10],pred[10];
int visited[10],count,mindistance,nextnode,i,j,sum=0;
for(i=1;i<=5;i++)
{
for(j=1;j<=5;j++)
{
pay[i][j]=G[i][j];
}
}
for(i=1;i<=5;i++)
{
distance[i]=pay[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<4)
{
mindistance=INF;
for(i=1;i<=5;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}
visited[nextnode]=1;
for(i=1;i<=5;i++)
if(!visited[i])
if(mindistance+pay[nextnode][i]<distance[i])
{
distance[i]=mindistance+pay[nextnode][i];
pred[i]=nextnode;
}
count++;
}
for(i=1;i<=5;i++)
if(i!=startnode)
{
if(v==i){totaltime+=distance[i];
j=i;
do
{
j=pred[j];
}while(j!=startnode);
}}
return totaltime;
}
int Time(int k,int src)
{
    G[1][1]=0;
    G[1][2]=1;
    G[1][3]=1;
    G[1][4]=4;
    G[1][5]=INF;
    G[2][1]=2;
    G[2][2]=0;
    G[2][3]=3;
    G[2][4]=INF;
    G[2][5]=INF;
    G[3][1]=INF;
    G[3][2]=INF;
    G[3][3]=0;
    G[3][4]=2;
    G[3][5]=4;
    G[4][1]=INF;
    G[4][2]=INF;
    G[4][3]=INF;
    G[4][4]=0;
    G[4][5]=3;
    G[5][1]=2;
    G[5][2]=INF;
    G[5][3]=INF;
    G[5][4]=INF;
    G[5][5]=0;
    dijkstra1(G,k,src);
}
int printRandoms(int lower, int upper,int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return num;
    }
}
int main() {
 int source,destination,n,passengers,choice,ri,time1,k,p,w,noofreq,xx;
 int lower = 1, upper = 5, count = 1,temp,kb,x=0,f,i,j,r,flag=0;
 int d[10],J[10];
 char c[100],h[100];
 char copy[100];
 long int yy,m;
 int u=1;
 while(u!=-1)
 {printf("Welcome to our online cab booking services!!!\n");
 printf("1.normal cab\t 2.rent tour own car\t");
 scanf("%d",&w);
 switch(w)
 {
 case 1:{
    printf("enter your name and mobile number");
 scanf("%s %ld",c,&m);
 printf("Enter ur pick up location\n");
 printf("Enter ur desired destination\n");
 printf("Choose the number corresponding to the pick up and drop location->\n");
 LocationsInCity();
 scanf("%d%d",&source,&destination);
 printf("Enter the number of passengers->");
 scanf("%d",&passengers);
 if(passengers==1)
 {
     printf("Choose any one of the available options->");
     printf("Press 1.Auto\t 2.Bike\t 3.Cab\n");
     scanf("%d",&choice);
     r=Map(source,destination);
     switch(choice)
     {
       
         case 1:{
                 printf("\n The total fare is : %d\n",r/2);
               
                 break;}
         case 2:{
             printf("\n The total fare is: %d\n",r/3);
             break;}
         case 3:{
             printf("\n The total fare is: %d\n",r);
             break;}
     }
 }
 if(passengers>=2 && passengers<=4)
 {
     printf("Choose any one of the available options->");
     printf("1.Auto\t 2.Cab\n");
     scanf("%d",&choice);
     r=Map(source,destination);
     switch(choice)
     {
         
         case 1:{printf("\n The total fare is: %d\n",r/2);break;}
         case 2:{printf("\n The total fare is: %d\n",r); break;}
     }
 }
 else{
     printf("Too many passengers cannot be accomadated!!");
 }
 printf("\nYour vehicle is successfully booked!!");
 printf("\n Your ride is on the way!!!");
   srand(time(0));
  k=printRandoms(lower, upper, count);
  time1=Time(k,source);
  if(time1==0)
  {
      printf("\n Your ride is here!!!");
  }
  else{
 printf("\nYour ride will arive in %d minutes",time1);
  }
  srand(time(0));
  p=printRandoms(1000,9999,1);
  printf("\n The OTP is: %d\n",p);
  break;
 }
    case 2:
    {     printf("Rent your own car");
           printf("enter your name and mobile number");
           scanf("%s%ld",c,&m);
           x=x+1;
           flag=1;
           printf("please enter your pickup location");
           scanf("%s",h);
           printf("when u want to book ur cab - no of hours");
           scanf("%d",&f);
           q[x-1].hour=f;
           strcpy(q[x-1].name,c);
           q[x-1].number=m;
          for(i=0;i<x;i++)
          {
           for(j=0;j<x-i-1;j++)
           {
             if(q[j].hour<q[j+1].hour)
             {
                 temp=q[j].hour;
                 q[j].hour=q[j+1].hour;
                 q[j+1].hour=temp;
                  strcpy(copy,q[j].name);
                 strcpy(q[j].name,q[j+1].name);
                 strcpy(q[j+1].name,copy);
                 yy=q[j].number;
                 q[j].number=q[j+1].number;
                 q[j+1].number=yy;
             }
           }
         }
      break;    
    }
 }
 scanf("%d",&u);
}
if(flag==1)
{
         for(i=0;i<x;i++)
         {
             printf("\n The rented cab bookings are->\n");
             printf("%s %d %ld",q[i].name,q[i].hour,q[i].number);
             printf("The total price is :%d\n",q[i].hour*100);
         }
}
 return 0;
}






