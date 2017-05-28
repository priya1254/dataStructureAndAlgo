//DFS Application
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;
int n;
bool adj[10001][10001];
int visited[10001];
int count1;
int flag=1;

void DFS(int v,int u,bool adj[10001][10001],int n,int count1)
{
    if(flag==0){return;}
    visited[u]=1;
    for(int i=1;i<=n;i++)
    {

        if(adj[u][i]==1)
        {

            if(v==i && visited[v]==1 && count1%2==1)
            {
                 flag=0;
                return;
            }
            if(!visited[i])
            {
            count1++;
            visited[i]=1;
            DFS(v,i,adj,n,count1);
            if(flag==0){return;}
            count1--;
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
      flag=1;
       int m,x,y;
       cin>>n>>m;
        if(m==0)
       {
    cout<<"Case #"<<t<<":"<<" "<<"yes";
     cout<<"\n";
     continue;
       }
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


         for(int r=1;r<=n;r++)
        {
            memset(visited,0,sizeof(visited));

             DFS(r,r,adj,n,1);
              if(flag==0){

    cout<<"Case #"<<t<<":"<<" "<<"no";
     cout<<"\n";
     break;}
        }



    if(flag)
   {
     cout<<"Case #"<<t<<":"<<" "<<"yes";
     cout<<"\n";
   }
   }
return(0);
}//end of func





