#include <bits/stdc++.h>
using namespace std;
int cnt;
void dfs(int x, vector<int> v[100000], int visited[])
{

    for(int i = 0; i < v[x].size(); i++)
    {
        if(visited[v[x][i]]!=1)
        {
            visited[v[x][i]] = 1;
            dfs(v[x][i],v,visited);
        }

    }

}
int main()
{
    int n,m,x,a,b;
    cin>>n>>m;
    int visited[n+1];
    memset(visited, 0, sizeof(visited));
    vector<int> v[100000];
    cnt=0;
    for(int i = 0; i<m; i++)
    {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
    }

    cin>>x;
    visited[x]=1;
    dfs(x,v,visited);
    for(int i = 1; i <= n;i++)
    {
        if(visited[i]==0)
        cnt++;
    }
    cout<<cnt;

    return 0;
}
