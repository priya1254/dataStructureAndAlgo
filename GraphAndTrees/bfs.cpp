//program implementing breadth first Search
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
        int h,v,e,s,a,b;
          int ele;

       cin>>v;
       cin>>e;
       h=0;
       int a1[1000][1000];
       int visited[1000];
       queue<int> q;


       while(h<e){
       cin>>a>>b;


               a1[a][b]=1;

       h++;
       }
       q.push(1);
       for(int l=1;l<=v;l++)
       {
        visited[l]=false;
       }
       while(!q.empty())
       {
        ele=q.front();


           q.pop();
           for(int f=1;f<=v;f++)
           {
               if((a1[ele][f]==1)&&(visited[f]==false))
               {
                   q.push(f);
                    visited[ele]=true;


               }
           }
       }


     cout<<"\n";
   }
return(0);
}//end of func





