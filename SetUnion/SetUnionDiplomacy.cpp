//Set UnionQuestion
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;
long count1;
bool visited[20000];
queue <long> queuef,queuee;

void mergesetsf(long x)
     {

            if(visited[x]==false)
             {
             queuef.push(x);
              visited[x]=true;
              count1++;
             }
                 return;
         }



     void mergesetse(long x)
     {
             if(visited[x]==false)
             {

             queuee.push(x);
             visited[x]=true;
             }
            return;
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
            if(x==1)
            {
            mergesetsf(y);
           }
           if(y==1)
           {
               mergesetsf(x);
           }
           }
           else
           {
            if(x==1)
            {
            mergesetse(y);
           }
           if(y==1)
           {
               mergesetse(x);
           }

           }

       }


    long num;
    num=queuef.front();
     if((queuef.empty())&&(queuee.empty()))
      {
           cout<<"Case #"<<t<<":"<<" "<<"no"<<"\n";
           continue;
      }

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

                if(a2[g]==num)

                {
                    mergesetse(a3[g]);
                }
                if(a3[g]==num)

                {
                    mergesetse(a2[g]);
                }
                g++;
            }
            else
            {
                 if(a2[g]==num)
                {
                    mergesetsf(a3[g]);
                }
                if(a3[g]==num)
                {

                    mergesetsf(a2[g]);
                }

                 g++;
            }

          }
   }
if(!queuee.empty())
      {
          long num=queuee.front();
          queuee.pop();
          long g=0;
          while(g<no)
          {
              if(a1[g]=='F')
              {
                   if(a2[g]==num)
                   {
                    mergesetse(a3[g]);
                   }
              }

          else
          {
             if(a2[g]==num)
             {
            mergesetsf(a3[g]);
             }

          if(a3[g]==num)
          {
           mergesetsf(a2[g]);
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





