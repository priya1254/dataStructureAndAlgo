//PushRelabel MaxFlow Algorithm application
#include<bits/stdc++.h>
#define infinity 999

using namespace std;
int n;
int cap[500][500];
int flow[500][500];
int cf[500][500];
int excess[500];
int height[505];

void initialize_preflow(int source,vector<int> G[500])
      {
         int i, v;
         height[source] = n;

         for(i=0;i<G[source].size();i++)
         {
            v = G[source][i];
            flow[source][v] = cap[source][v];
            flow[v][source] = -cap[source][v];
            excess[v] = cap[source][v];
            excess[source] -=cap[source][v];
            cf[source][v] = cap[source][v]-flow[source][v];
            cf[v][source] = cap[v][source]-flow[v][source];
         }
      }
   void push(int u, int v)
      {
         int push_val = min(cf[u][v], excess[u]);
         flow[u][v] += push_val;
         flow[v][u] = -flow[u][v];
         excess[u] -=push_val;
         excess[v] +=push_val;
         cf[u][v] = cap[u][v]-flow[u][v];
         cf[v][u] = cap[v][u]-flow[v][u];

      }
   int max_flow(int source, int sink,vector<int> G[500])
      {
         initialize_preflow(source,G);
         queue<int> q;
         bool considered[n+1];
         int u, v, m, i;
         memset(considered, false, sizeof(considered));
        for(i=0;i<G[source].size();++i)
         {
           v=G[source][i];

            if(v!=sink)
            {
               q.push(v);
               considered[v] = true;
            }
         }
         bool flag;
         u = -1;
         while(!q.empty())
         {

            u = q.front();
            m = -1;
            for(i=0;i<G[u].size() && excess[u]>0; i++)
            {

               v = G[u][i];
               if(cf[u][v]>0)
               {
                  if(height[u]>height[v])
                  {
                     push(u,v);
                     if(!considered[v] && v!=sink && v!=source)
                     {
                        considered[v] = true;
                        q.push(v);
                     }
                  }
                  else if(m==-1) m = height[v];
                  else   m = min(m, height[v]);
               }
            }

            if(G[u].empty()) {q.pop();continue;}
            if(excess[u]!=0) height[u] = m+1;
            else
            {
               q.pop();
               considered[u] = false;
            }
         }
         return excess[sink];
      }





int main()
{

    int temp;
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
       int m;
       int a,b,w;

       vector<int> G[500];
      cin>>n>>m;
       memset(excess,0,sizeof(excess));
       memset(height,0,sizeof(height));
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              cap[i][j]=0;
              flow[i][j]=0;
              cf[i][j]=0;
          }
      }
      for(int i=1;i<=m;i++)
      {
          cin>>a;
          cin>>b;
          if(a==b)
          {
              cin>>w;
             continue;
          }
          G[a].push_back(b);
          G[b].push_back(a);
          cin>>w;
          if(cap[a][b]!=0)
          {
              cap[a][b]+=w;
              cap[b][a]+=w;
              cf[a][b]+=w;
              cf[b][a]+=w;
          }
          else{
          G[a].push_back(b);
          G[b].push_back(a);
          cap[a][b]=w;
          cap[b][a]=w;
          cf[a][b]=w;
          cf[b][a]=w;}
      }
      int max1;
     max1= max_flow(1,n,G);

      if(max1==0)
      {
    cout<<"Case #"<<t<<":"<<" "<<"impossible";
     cout<<"\n";
     continue;

      }

     cout<<"Case #"<<t<<":"<<" "<<max1;
     cout<<"\n";


   }

    return 0;

}


