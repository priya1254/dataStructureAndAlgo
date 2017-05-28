#include <bits/stdc++.h>
using namespace std;
int flag;
int adj[100][100];
int visited[100];
int n,m;
char s,t;
vector<pair<int, pair<int,int> > > G[100];
vector<pair<int, pair<int,int> > > resG[100];

bool bfs(int src)
{
    q.push(src);
    while(!q.empty())
    {

    src = q.front();
    if(src == (t -'A'))
    {
        return true;
    }
    q.pop();

    for(int i = 0; i < G[src].size(); i++)
    {
        if(visited[G[src][i]] == 0)

        {
            visited[src] = 1;
            q.push(G[src][i]);
        }
    }
    }
    return false;
}
int maxflow()
{
    while(bfs(source))
    {
       for(vector<pair<int, pair<int, int> > > itr = G.begin(); itr < G.end(); itr++)
       {

       }

    }

}
int main()
{
    char a,b;
    int cost;
    cin>>n;
    cin>>s>>t;
    for(int i = 0; i < n; i++)
    {
       cin>>a>>b>>cost;
       G[a-'A'].push_back(make_pair(b-'A',cost));
    }

    ans = maxflow();
    cout<<ans<<endl;

            return(0);
}
