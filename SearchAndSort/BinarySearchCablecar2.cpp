//Application OF binary Search
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
    double d=0,p=0,u=0,v=0;

    double mid=0;
    double filled=1;

    cin>>d>>p>>u>>v;
    double lo,hi,curr;
    lo=0;hi=2*d;

    while(hi-lo>0.0001)
    {

        curr=0;
        mid=((lo+hi)/2);
        filled=1;
        while(1)
        {
            if(curr+mid<=d)
            {
                curr=curr+mid;
                if((curr>u)&&(curr<v))
                    curr=v;

                filled++;
            }
            else
               break;
        }
    if(filled<p)
        hi=mid;

    else
        lo=mid;
    }



    cout<<"Case #"<<t<<":"<<" ";
     printf("%.10lf",mid);
     cout<<"\n";



   }
return(0);
}//end of func






