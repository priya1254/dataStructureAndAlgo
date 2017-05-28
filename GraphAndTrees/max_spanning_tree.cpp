#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,long>
class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.second < p2.second;
    }
};
int main()
{

    int n;
    int temp;

    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
        priority_queue<pp, vector<pp > , Prioritize > Q;
        vector<pp> G[401];
        int adj[401][401];

      cin>>n;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
             pp p;
             p.first=i;
             cin>>p.second;
             if(p.second==0)
             { adj[i][j]=p.second;}
             else{
            G[j].push_back(p);
            adj[i][j]=p.second;}

          }
      }
       int d[n+1];
    for(int i=1;i<=n;i++)
    {
        d[i] = 5000;
    }

    d[1] = 0;
    Q.push(pp(1,d[1]));

   int u,v,w;
     while(!Q.empty())
    {

        u = Q.top().first;
        Q.pop();
        int size = G[u].size();
        for(int i = 0 ; i < size ; i++)
        {
            v = G[u][i].first;
            w = G[u][i].second;
            //cout<<u<<" "<<v<<" "<<w<<endl;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
              //cout<<"new weight"<<v<<"--"<<d[v]<<"\n";
                Q.push(pp(v,d[v]));
            }
        }
    }

     int val=0;
    for(int i=2;i<=n;i++)
    {
        int max=0;
        for(int j=1;j<=n;j++)
        {
            if((adj[i][j]>max)&&(d[j]<5000))
            {
                max=adj[i][j];
               // cout<<i<<"---->"<<j<<endl;
            }
        }
        val+=max;
    }

     cout<<"Case #"<<t<<":"<<" "<<val;
     cout<<"\n";
   }

    return 0;
}


