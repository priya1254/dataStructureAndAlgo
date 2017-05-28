//Binary Search application
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int temp;
   cin>>temp;
   int s,f;
   unsigned long long u[1001];
   unsigned long long v[1001];
   unsigned long long y,c,mid,low,high;
    unsigned long long lo=0;
     unsigned long long hi=0;
     int flag=0;

   for(int t=1;t<=temp;t++)
   {
       cin>>s;
       cin>>f;
       flag=0;
       for(long k=0;k<s;k++)
       {
           cin>>u[k];

           cin>>v[k];

       }
       lo=u[0];
       hi=v[0];

        for(long j=1;j<s;j++)
       {

          if(u[j]<lo)lo=u[j];
          if(v[j]>hi)hi=v[j];
       }
       low=lo;
       high=hi;

       for(long b=0;b<f;b++)
       {
           cin>>y;
           if(flag==0)
           {
            cout<<"Case #"<<t<<":"<<" "<<endl;
            flag=1; }

           lo=low;
           hi=high;


       while(lo<hi)
       {

         c=0;

           mid=((lo+hi)/2);

           for(long i=0;i<s;i++)
           {
               if((mid>=u[i])&&(mid<=v[i]))
               {
                   c=c+mid-u[i]+1;
               }

               if((mid>u[i])&&(mid>v[i]))
               {
                   c=c+v[i]-u[i]+1;


               }


           }
            if(lo+1==hi)
           {
               if(c<y){
               cout<<hi;
               cout<<"\n";
               break;}
               if(c>y){
               cout<<lo;
               cout<<"\n";
               break;}

           }

           if(c>y)
           {
               hi=mid;
           }
           if(c<y)
           {
               lo=mid;
           }
           if(c==y)
           {
               cout<<mid;
               cout<<"\n";
               break;

           }

       }
       }
     cout<<"Case #"<<t<<":"<<" ";
     printf("%.10lf",mid);
     cout<<"\n";

   }


return(0);
}//end of func





