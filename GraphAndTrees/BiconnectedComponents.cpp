//find biconnected components in a graph.
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
int counteven =0, countodd =0, no;
stack<pair<int, int> >s;
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
                s.push(make_pair(src, i));
                dfs(i,time+1);
                low[src] = min(low[src], low[i]);

                if((parent[src] == -1 && child[src] > 1)  || (low[i] >= disc[src]))
                {
                   set<int> set1;
                   AP[src]= true; no += 1;
                   pair<int, int> p = s.top();
                   while( ( p.first != src && p.second != i ))
                   {
                       set1.insert(p.first);
                       set1.insert(p.second);
                       s.pop();
                       p = s.top();
                   }

                    set1.insert(p.first);
                    set1.insert(p.second);
                    if(set1.size()%2 == 0) counteven++;
                    else countodd++;
                    s.pop();

                }


            }
            else if(parent[src] != i && disc[i]<low[src])
            {
                s.push(make_pair(src, i));
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
memset(child, 0, sizeof(child));
memset(parent, -1, sizeof(parent));

for(int i = 0; i < n; i++)
{
    if(visited[i] == 0)
    {

        dfs(i,0);

               if(!s.empty())
                {
                   set<int> set1;
                   while( !s.empty())
                   {

                    pair<int, int> p = s.top();
                    set1.insert(p.first);
                    set1.insert(p.second);
                    s.pop();
                   }
                    if(set1.size()%2 == 0)counteven++;
                    else countodd++;
               }
    }
}

 cout<<counteven<<" "<<countodd<<endl;

return(0);
}





