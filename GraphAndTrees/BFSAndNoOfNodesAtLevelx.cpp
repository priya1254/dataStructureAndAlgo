#include <bits/stdc++.h>
using namespace std;
int cnt;
void bfs(int s, vector<int>v[100000], int visited[],int x)
{
    queue<pair<int,int> > q;
    visited[s] = 1;
    q.push(make_pair(s,1));
    while(!q.empty())
    {
        pair<int,int> s = q.front();q.pop();
        int lev = s.second;
        if(lev == x)
        cnt++;
        for(int i = 0; i< v[s.first].size();i++)
        {

            if(visited[v[s.first][i]]==0)
            {
            visited[v[s.first][i]] = 1;
            q.push(make_pair(v[s.first][i],lev+1));
            }
        }
    }


}

int main()
{
    int n,m,x,a,b;
    cin>>n;
    int visited[n];
    memset(visited, 0,sizeof(visited));
    vector<int> v[100000];
    cnt=0;
    for(int i = 0; i<n-1; i++)
    {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
    }

    cin>>x;
    bfs(1,v,visited,x);
    cout<<cnt;

    return 0;
}
