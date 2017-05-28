//BFS application
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;
int n;
int adj[10001][10001];
int visited[10001];
int parent[10001];
int a1[10001];
int count1;
int acyclic;

void bfs(int v)
{
    queue<int> q;
    acyclic=0;
    int ele;
    q.push(v);
    visited[v]=true;
    count1=0;

while(!q.empty())
       {
        ele=q.front();
           q.pop();

           count1=count1+1;
           for(int f=1;f<=n;f++)

           {


                if((visited[f]==true)&&(parent[ele]!=f)&&(adj[ele][f]==1))
                    {
                        acyclic=1;
                        count1=count1+1;
                    if((count1%2)==0)
                    {

                       count1=0;
                    }
                    else{
                    return;}

                    }
               if((adj[ele][f]==1)&&(visited[f]==false))
               {

                   q.push(f);
                    visited[f]=true;
                    parent[f]=ele;


               }
           }
    }

     }


int main()
{
   int temp;
   cin>>temp;


   for(int t=1;t<=temp;t++)
   {

       int m,x,y,connected;
       connected=0;

       cin>>n>>m;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++){
           adj[i][j]=0;}
       }

       for(int i=1;i<=m;i++)
       {
           cin>>x>>y;
           adj[x][y]=1;
           adj[y][x]=1;
       }
       if(m==0)
       {
    cout<<"Case #"<<t<<":"<<" "<<"yes";
     cout<<"\n";
     continue;
       }

         for(int i=1;i<=n;i++){
		visited[i]=false;
		parent[i]=i;}
        for(int r=1;r<=n;r++)
        {
            if(visited[r]==false)
             bfs(r);
              if((acyclic==1)&&((
                         count1%2)!=0)){

    cout<<"Case #"<<t<<":"<<" "<<"no";
     cout<<"\n";
     break;}
        }



      if((acyclic==0)||((count1%2)==0))
   {
    cout<<"Case #"<<t<<":"<<" "<<"yes";
     cout<<"\n";
   }
   }
return(0);
}//end of func





