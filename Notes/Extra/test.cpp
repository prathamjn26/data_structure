#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int r1,r2,rt;
 cin>>r1>>r2>>rt;
 int a[n+1];
 memset(a,0,sizeof(a));
 int s;
 int a1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 for(int i=1;i<=12;i++)  //month loop
 {
     for(int j=1;j<=a1[i-1];j++)  // day loop
     {
      int k=6-i;
      int d=min(n,((k*k)+abs(j-15)));
      for(int k=0;k<=n;k++)  // loop  of rooms
      {
          int p1,p2;
          p1=k;p2=n-k;
          int left;
          if(p2>=d)
          a[k]+=d*r2;
          else
          {
              left=d-p2;
              a[k]+=(left*r1+p2*r2);
          }
      }
     }
 }
 int no_of_rooms=0;
 for(int i=0;i<=n;i++)
 {
     no_of_rooms=i;
     if(a[i]>=rt)
     break;
 }
 cout<<no_of_rooms;
}

