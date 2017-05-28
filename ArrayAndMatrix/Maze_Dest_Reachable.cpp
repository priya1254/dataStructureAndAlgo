//check if destination is reachable or not in a maze
#include <bits/stdc++.h>
using namespace std;
int flag;
int a[11][11];
int visited[11][11];
int destx, desty;
int n,m;
void dfs(int x, int y)
{

    if( x < 1 || x > n || a[x][y] == 0) return;
    if( y < 1 || y > m  || a[x][y] == 0) return;
    if(visited[x][y] == 1)return;
    visited[x][y] = 1;
    if(x == destx && y == desty){ cout<<"Yes"<<endl; flag = 1;return;}
    dfs(x+1,y+1);
    dfs(x-1,y-1);
    dfs(x-1,y+1);
    dfs(x+1,y-1);
    dfs(x,y-1);
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);

}
int main()
{

cin>>n>>m;
int ch;
flag = 0;
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m ; j++)
    {
        cin>>a[i][j];
    }
}
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= m ; j++)
    {
        visited[i][j] = 0;
    }
}

destx = n;desty = m;
dfs(1,1);
if(flag ==0) cout<<"False"<<endl;
return(0);
}

