#include <bits/stdc++.h>
using namespace std;
int flag;
int adj[15][15];
bool dp[15][2000];
int visited[15];
int n,m;


bool check_hamiltonianpath()
{
  for(int i = 0; i < (1<<n); i++)
  {

      for(int j = 0; j < n; j++)
      {

        if((1<<j) & i)
        {

          for(int k =0 ; k < n; k++)
          {
              if(k !=j && ((1<<k)&i) && adj[k][j]==1 && dp[k][i^(1<<j)]== true)
              {

                     dp[j][i] = true;
                     break;
              }
          }

        }

      }
  }

/*for(int i = 0; i < n; i++)
{
     for(int j = 0; j < 1<<n; j++)
       {
           cout<<i<<" "<<j<<" ";
           cout<<dp[i][j]<<endl;
       }
}*/
  for(int i = 0; i < n; i++)
  {
      if(dp[i][(1<<n)-1] == true)
        return true;
   }
   return false;
}





int main()
{

cin>>n>>m;
int a,b;


memset(visited, 0, sizeof(visited));
for(int j = 1; j <= m; j++)
{
   cin>>a>>b;
   adj[a][b] = 1;
   adj[b][a] = 1;
}

for(int i = 0; i < n; i++)
{
     for(int j = 0; j < 1<<n; j++)
       {
           dp[i][j] = false;
       }
}

for(int i = 0; i < n; i++)
{
   dp[i][1<<i] = true;
}


if(check_hamiltonianpath()) cout<<"YES";
else cout<<"NO";
cout<<endl;

return(0);
}
