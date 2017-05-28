//Set Union Data Structure
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;
 long  findsets(long x,long set1[])
     {

         if(x!=set1[x])set1[x]=findsets(set1[x],set1);
         return set1[x];
     }
void mergesets(long x,long y,long set1[],long rank1[],long n)
     {
         long px,py;
         px=findsets(x,set1);
         py=findsets(y,set1);
         if(px==n)
         {
             set1[py]=px;
             rank1[px]=px+1;
                 return;
         }
         if(py==n)
         {
             set1[px]=py;
             rank1[py]=rank1[py]+1;
            return;
         }
         if(rank1[px]>rank1[py])
        {
          set1[py]=px;
         rank1[px]=rank1[px]+1;
        }
         else
         {
            set1[px]=py;
            rank1[py]=rank1[py]+1;
         }

     }



int main()
{
     int temp;
     long arr[3];
     long  a[20000];
     long set1[20000];
     long rank1[20000];
     cin>>temp;


   for(int t=1;t<=temp;t++)
   {

     for(int i=0;i<3;i++)
     {
         cin>>arr[i];
     }
     for(long j=1;j<arr[0];j++)
     {
         cin>>a[j];
     }
     for(long k=1;k<=arr[0];k++)
     {
         set1[k]=k;
         rank1[k]=0;

     }

     long x,y;
     long n=arr[0];
     long m=arr[1]+arr[2];
     for(long q=1;q<=m;q++)
     {
      cin>>x>>y;
      mergesets(x,y,set1,rank1,n);

     if(q>arr[1])
     {
         a[x]=0;
         a[y]=0;

     }

     }


    for(long w=1;w<n;w++)
     {
         long v=findsets(w,set1);
         if(v==n)
         {
             a[w]=0;

         }

     }

     long maxm=0;
     for(long y=1;y<arr[0];y++)
     {
         if(a[y]>maxm)
         {
             maxm=a[y];

         }
     }
     if(maxm==0)
     cout<<"Case #"<<t<<":"<<" "<<"impossible"<<"\n";
     else{
     cout<<"Case #"<<t<<":"<<" "<<maxm;
     cout<<"\n";
     }
   }
return(0);
}//end of func






