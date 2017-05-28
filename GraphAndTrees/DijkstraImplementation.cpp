//Shortest Distance Dijkstra Implementation
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,long>
#define infinity 2147483647

class Prioritize
{
public:
    int operator() ( const pair<long, long>& p1, const pair<long, long>& p2 )
    {
        return p1.second < p2.second;
    }
};
int main()
{

    int n;
    int temp;
    long d[3005];
    long b[10001];
    int visited[3005];
    long a[3005];
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
       int num=0,flag=0;
        priority_queue<pp, vector<pp > , Prioritize > Q;
        long shortdist=infinity;
         int u,v,x,y;
         long w;
    cin>>n>>x>>y;
    memset(a,0,sizeof(a));
    vector< pp > G[3005];
     for(int q=1;q<=n;q++)
    {
       cin>>a[q];
    }

    for(int q=1;q<=n;q++)
    {
        cin>>u;

        for(int i=1;i<=u;i++)
        {
            cin>>w;
            if(w==q)
            {continue;}
          G[q].push_back(pp(w,a[q]));

        }
    }
     memset(b,0,sizeof(b));
     b[0]=1;
     long ptr;
     ptr=0;


    for(long q=1;q<=y;q++)
    {
        cin>>b[q];
        if(b[q]==0)
        {
            if(q<3)
            {
                b[q]=1;
            }
            else b[q]=b[q-2];

        }
        if(b[q]==1)
        {
            ptr=q;
        }


    }
       if(x==1)
        {
             cout<<"Case #"<<t<<":"<<" "<<a[1];
             cout<<"\n";
            continue;
        }
        for(long h=ptr;h<=y;h++)
     {
           if(b[h]==x)
         {

            flag=1;
            break;
        }
     }
     if(flag==1)
     {
        cout<<"Case #"<<t<<":"<<" "<<a[x];
        cout<<"\n";
            continue;
     }
     memset(visited,0,sizeof(visited));

  for(long h=ptr;h<=y;h++)
  {
     num=b[h];
     if(visited[num]==1)
     {continue;}
     visited[num]=1;
     for(int f=1;f<=n;f++)
     {
         d[f]=infinity;
     }
    d[num]=0;
    Q.push(pp(num,d[num]));
    while(!Q.empty())
    {
        u = Q.top().first;
        Q.pop();
        int size = G[u].size();
        for(int i = 0; i < size ; i++)
        {
            v = G[u][i].first;
            w = G[u][i].second;

            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push(pp(v,d[v]));

            }
        }
    }


   if(d[x]<shortdist)
   {
   shortdist=d[x];

   }

  }

  pp s(2,3);

  if(shortdist==infinity)
  {
     cout<<"Case #"<<t<<":"<<" "<<"impossible";
     cout<<"\n";
     continue;

  }

  shortdist+=a[x];

     cout<<"Case #"<<t<<":"<<" "<<shortdist;
     cout<<"\n";
   }

    return 0;
}

