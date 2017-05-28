//Share WorkLoad Binary Search Application
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int temp;
   cin>>temp;
    unsigned long long bowls[1000099],x,lo,hi,max1,sum,required,curr;
       unsigned long long maxm=0;
       unsigned long long left=0;
        unsigned long long n;
       unsigned long long p,q,r,s;


   for(int t=1;t<=temp;t++)
   {

       cin>>n;
       cin>>p>>q>>r>>s;

       max1=0;
       sum=0;
       if(n==1)
       {
           left=0;

     cout<<"Case #"<<t<<":"<<" "<<left;
     cout<<"\n";
           continue;
       }
      for(unsigned long long d=0;d<n;d++)
       {
           bowls[d]=((((d+1)*p)+q)%r)+s;
           sum=sum+bowls[d];

         if(max1<bowls[d])
           {
               max1=bowls[d];
           }

       }

   lo=max1;
   hi=sum;

       while(lo<hi)
       {
         x=(lo+hi)/2;
           required=1;
               curr=0;
           for(unsigned long long i=0;i<n;i++)
           {

               if(curr+bowls[i]<=x)
               {
                   curr=curr+bowls[i];
               }
               else
                {
                  ++required;
                 curr=bowls[i];
                }
           }
           if(required<=3)
           {
               hi=x;
           }
           else
             lo=x+1;
       }

       unsigned long long y=0;
       unsigned long long a1=0;
       unsigned long long a2=0;
       unsigned long long a3=0;
       unsigned long long k;
        unsigned long long h;
         unsigned long long l;
       for(k=0;k<n;k++)
       {
          if((a1+bowls[k])<=lo)
           {
             a1=a1+bowls[k];
           }
           else
           break;

       }
     for(h=k;h<n;h++)
       {
          if((a2+bowls[h])<=lo)
           {
             a2=a2+bowls[h];
           }
           else
           break;

       }
        for(l=h;l<n;l++)
       {
          if((a3+bowls[l])<=lo)
           {
             a3=a3+bowls[l];
           }

       }


        if((a1>=a2)&&(a1>=a3))
       {
          maxm= a1;
          left=a2+a3;
       }
       if((a2>=a3)&&(a2>=a1))
       {
           maxm= a2;
           left=a1+a3;

       }


      if((a3>=a2)&&(a3>=a1))
      {
           maxm= a3;
           left =a1+a2;
      }

     cout<<"Case #"<<t<<":"<<" "<<left;
     cout<<"\n";

   }

return(0);
}//end of func





