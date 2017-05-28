//Maximum spanning tree implementation
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second > p2.second;
    }
};
int main()
{

    int n;

    int temp;

    int d[1005];
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
        priority_queue<pp, vector<pp > , Prioritize > Q;
        int shortdist=0;
         int u,v,w,x,y;
    cin>>n;
    vector< pp > G[1005];
    for(int q=1;q<n;q++)
    {
        cin>>u;
        cin>>v;
        for(int i=0;i<v;i++)
        {
            cin>>w;

        G[q].push_back(pp(w,u));

        }
    }

    cin>>x;
    cin>>y;

    memset(d,0,sizeof(d));

    Q.push(pp(1,d[1]));
    while(!Q.empty())
    {

        u = Q.top().first;

        Q.pop();
        int size = G[u].size();
        for(int i = 0; i < size ; i++)
        {
            v = G[u][i].first;
            w = G[u][i].second;

            if(d[v] < d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(pp(v,d[v]));
            }
        }
    }

shortdist=d[n];

  shortdist+=x;

     cout<<"Case #"<<t<<":"<<" "<<shortdist;
     cout<<"\n";
   }

    return 0;
}
