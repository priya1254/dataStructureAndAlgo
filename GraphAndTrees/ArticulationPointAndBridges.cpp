//find articulation point and bridges in the graph
#include <bits/stdc++.h>
using namespace std;
int flag;
int adj[11][11];
int visited[11];
int n,m;
int disc[11];
int low[11];
int parent[11];
int child[11];
bool AP[11];
int no;
vector<pair<int,int> > bridges;
bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first< b.first) return 1;
    else if(a.first == b.first) return a.second < b.second;
    else return 0;
}
void dfs(int src, int time)
{

    disc[src] = low[src] = time+1;

    visited[src] = 1;
    for(int i = 0; i < n; i++)
    {
        if(adj[src][i] == 1)
        {
            if(visited[i] == 0)
            {
                child[src] += 1;
                parent[i] = src;
                dfs(i,time+1);
                low[src] = min(low[src], low[i]);
                if(parent[src] == -1 && child[src] > 1)
                {  AP[src]= true; no += 1;}
                if(parent[src] != -1 && low[i] >= disc[src])
                {
                    AP[src] = true; no += 1;
                }
                if(low[i] > disc[src])
                {
                    bridges.push_back(make_pair(src,i));
                }
            }
            else if(parent[src] != i)
            {
                low[src] = min(low[src], disc[i]);
            }
        }
    }
}


int main()
{
no = 0;
cin>>n>>m;
int a,b;



for(int j = 1; j <= m; j++)
{
   cin>>a>>b;
   adj[a][b] = 1;
   adj[b][a] = 1;
}
memset(visited, 0, sizeof(visited));
memset(child,0,sizeof(child));
memset(parent, -1, sizeof(parent));
dfs(0,0);
cout<<no<<endl;
for(int i = 0; i < n; i++)
{
    if(AP[i] == true)cout<<i<<" ";
}
cout<<endl;
sort(bridges.begin(),bridges.end(),comp);
cout<<bridges.size()<<endl;
for(vector<pair<int,int> >:: iterator it = bridges.begin(); it!= bridges.end(); it++)
{
    cout << it->first<<" "<< it->second<<endl;
}

return(0);
}



