//wap to check strongly connected components
#include <bits/stdc++.h>
using namespace std;
int flag;
int adj[15][15];
int adj2[15][15];
int visited[15];
int n,m;

int no = 0;
int counteven =0, countodd =0;
stack<int> s;
void dfs(int src)
{
  visited[src] = 1;
  for(int i = 1; i <= n; i++)
  {
      if(adj[src][i] == 1 && visited[i] == 0 )
      {
          dfs(i);
          s.push(i);
      }
  }

}
void dfs1(int src)
{
  no++;visited[src] =1;
  for(int i = 1; i <= n; i++)
  {
      if(adj2[src][i] == 1 && visited[i] == 0 )
      {

          dfs1(i);

      }
  }

}



int main()
{

cin>>n>>m;
int a,b;



for(int j = 1; j <= m; j++)
{
   cin>>a>>b;
   adj[a][b] = 1;
}
memset(visited, 0, sizeof(visited));
for(int i = 1; i <= n; i++)
{
    if(visited[i] == 0)
    {
        dfs(i);
        s.push(i);
    }

}
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {

           adj2[i][j] = 0;

    }
}
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {
       if(adj[i][j] == 1)
       {
           adj2[j][i] = 1;

       }
    }
}

memset(visited, 0, sizeof(visited));
while(!s.empty())
{
    int k = s.top();
    s.pop();
    if(visited[k] == 0)
    {

        no = 0;
        dfs1(k);
        if(no%2 == 0)
        counteven +=no;
        else
        countodd +=no;
    }
}
 cout<<countodd-counteven<<endl;

return(0);
}





