#include <bits/stdc++.h>
using namespace std;
int flag;
int adj[15][15];
int adj2[15][15];
int indeg[15];
int n,m;

int no = 0;
int counteven =0, countodd =0;
queue<int> q;

void topologicalsort()
{

   for(int i = 0; i < n; i++)
   {
       if(indeg[i] == 0)
       {
           q.push(i);
       }
   }

    while(!q.empty())
    {
        int k = q.top();q.pop();
        cout<<k<<" ";

        for(int i = 0; i < n; i++)
       {
           if(adj[k][i] == 1)
           {
               indeg[k]--;
               if(indeg[k] == 0)
               {
                   q.push(i);
               }

           }
       }
    }

    cout<<endl;

}


int main()
{

cin>>n>>m;
int a,b;

memset(indeg,0,sizeof(indeg));

for(int j = 1; j <= m; j++)
{
   cin>>a>>b;
   adj[a][b] = 1;
   indeg[b]++;
}

topologicalsort();
return(0);
}





