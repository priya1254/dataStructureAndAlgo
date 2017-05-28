#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int temp;
   cin>>temp;


   for(int t=1;t<=temp;t++)
   {
     long arr[3];
     long  a[20000];
     long a2[20000][3];
     long  a3[20000][3];
     queue <long> a1;
     long  z;
     for(int i=0;i<3;i++)
     {
         cin>>arr[i];
     }
     for(long j=1;j<arr[0];j++)
     {
         cin>>a[j];
     }
     for(long k=1;k<=arr[1];k++)
     {
         for(long p=1;p<=2;p++)
         {
            cin>>a2[k][p];
         }
     }
      for(long m=1;m<=arr[2];m++)
     {
         for(long n=1;n<=2;n++)
         {
            cin>>a3[m][n];
           z=a3[m][n];
            a[z]=0;
         }
     }
     long maxm=0;
     long  x;
     long  c;

     a1.push(arr[0]);

     while(!a1.empty())
     {
       long num=a1.front();
       a1.pop();
       a[num]=0;
    for(long g=1;g<=arr[1];g++)
     {
         long p=1;
             if(a2[g][p]==0)
                  {
                    continue;
                  }
                if(a2[g][p]==num)
                  {

                     x=a2[g][p+1];
                     a1.push(x);
                     a2[g][p]=0;
                     a2[g][p+1]=0;
                  }
                  if(a2[g][p+1]==num)
                  {
                      x=a2[g][p];
                     a1.push(x);
                      a2[g][p]=0;
                      a2[g][p+1]=0;
                   }

     }
            for(long q=1;q<=arr[2];q++)
             {
                 long d=1;
                  if(a3[q][d]==0)
                  {
                    continue;
                  }

                  if(a3[q][d]==num)
                  {
                     c=a3[q][d+1];
                    a1.push(c);
                     a3[q][d]=0;
                     a3[q][d+1]=0;

                  }
                  if(a3[q][d+1]==num)
                  {
                      c=a3[q][d];
                      a1.push(c);
                       a3[q][d]=0;
                     a3[q][d+1]=0;

                  }
            }

          }


     for(long y=1;y<arr[0];y++)
     {
         if(a[y]>maxm)
         {
             maxm=a[y];

         }
     }
     if(maxm==0)
     cout<<"Case #"<<t<<":"<<" "<<"impossible";
     else{
     cout<<"Case #"<<t<<":"<<" "<<maxm;
     cout<<"\n";
     }
   }
return(0);
}//end of func





