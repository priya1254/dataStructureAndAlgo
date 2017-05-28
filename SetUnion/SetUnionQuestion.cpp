//Set Union Implementation
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;
long count1;
bool visited[20000];
queue <long> queuef,queuee;
long  findsets(long x,long set1[])
     {
         if(x!=set1[x])set1[x]=findsets(set1[x],set1);
         return set1[x];
     }
void mergesetsf(long x,long y,long set1[],long rank1[],long n1,long n)
     {
         long px,py;
         px=findsets(x,set1);
         py=findsets(y,set1);
         if(px==n1)
         {
             set1[py]=px;
             rank1[px]=px+1;

             if(visited[py]==false)
             {
              queuef.push(py);
              visited[py]=true;
              count1++;
             }


                 return;
         }
         if(py==n1)
         {

             set1[px]=py;
             rank1[py]=rank1[py]+1;
              if(visited[px]==false)
               {
             queuef.push(px);
              visited[px]=true;
             count1++;
               }
            return;
         }
         if(rank1[px]>rank1[py])
        {
          set1[py]=px;
         rank1[px]=
         rank1[px]+1;
        }
         else
         {
            set1[px]=py;
            rank1[py]=rank1[py]+1;
         }

     }
     void mergesetse(long x,long y,long n1)
     {
         if(x==n1)
         {
              if(visited[y]==false)
              {
              queuee.push(y);
              visited[y]=true;
              }

                 return;
         }
         if(y==n1)
         {

             if(visited[x]==false)
            {
             queuee.push(x);
             visited[x]=true;
             }
            return;
         }
     }
int main()
{
   int temp;
   cin>>temp;
   long n;
   long no;
   char z;
   long x;
   long y;
   char a1[76000];
   long a2[76000];
   long a3[76000];
   long set1[76000];
   long rank1[76000];

  visited[1]=true;
   long k;
   for(int t=1;t<=temp;t++)
   {
       k=0;
       cin>>n;
       cin>>no;
       count1=1;
     for(long p=1;p<=n;p++)
     {
         set1[p]=p;
         rank1[p]=0;
         visited[p]=false;

     }
    visited[1]=true;
       for(long q=1;q<=no;q++)
       {
           cin>>z;
           cin>>x;
           cin>>y;
           a1[k]=z;
           a2[k]=x;
           a3[k]=y;
           k++;

           if(z=='F')
           {
            mergesetsf(x,y,set1,rank1,1,n);

           }
           else
           {
               if((x==1)||(y==1))
               {
                mergesetse(x,y,1);
               }

           }

       }
        for(long b=1;b<=n;b++)
     {
         set1[b]=b;
     }

    long num;
    num=queuef.front();

      while((!queuef.empty())||(!queuee.empty()))
      {
          if(!queuef.empty())
          {
          num=queuef.front();

          queuef.pop();
          long g=0;
          while(g<no)
          {
              if(a1[g]=='A')
            {

                if((a2[g]==num)||(a3[g]==num))
                {
                    mergesetse(a2[g],a3[g],num);
                }
                g++;
            }
            else
            {
                 if(a2[g]==num)
                    {


                    mergesetsf(1,a3[g],set1,rank1,1,n);
                }
                if(a3[g]==num)
                {

                    mergesetsf(1,a2[g],set1,rank1,1,n);
                }

                 g++;
            }

          }
   }
while(!queuee.empty())
      {
          long num=queuee.front();
          queuee.pop();
          long g=0;
          while(g<no)
          {
              if(a1[g]=='F')
              {
                   if((a2[g]==num)||(a3[g]==num))
                   {
                    mergesetse(a2[g],a3[g],num);
                   }
              }

          else
          {
             if(a2[g]==num)
             {
            mergesetsf(1,a3[g],set1,rank1,1,n);
             }

          if(a3[g]==num)
          {
           mergesetsf(1,a2[g],set1,rank1,1,n);
          }

     }
      g++;
      }

   }
      }

     if(count1>n/2)
    cout<<"Case #"<<t<<":"<<" "<<"yes"<<"\n";
    else
    cout<<"Case #"<<t<<":"<<" "<<"no"<<"\n";

   }
return(0);
}//end of func





