#include <bits/stdc++.h>
using namespace std;
int parent[1001];
int rankmatrix[1001];
int size[1001];
int findset(int x)
{
    if(x != parent[x]) return findset(parent[x]);
    else return x;
}

void unionset(int a, int b)
{

    if(findset(a) != findset(b))
    {
        a = findset(a); b = findset(b);
         if(rankmatrix[b] > rankmatrix[a])
         { int t  = a ; a = b; b = t;}
        parent[b]= a;
        rankmatrix[a] = rankmatrix[a]  +1;
         size[a] += size[b];
         size[b] = 0;
    }
    return;
}
int main()
{
int n,m;
cin>>n>>m;
for(int i = 1; i<= n; i++)
{   parent[i] = i;
    rankmatrix[i] = 1;
    size[i] = 1;
}
int size1[n+1];
for(int i = 0; i < m; i++)
{
    int a,b;
    cin>>a>>b;
    unionset(a,b);
      for(int i = 1; i<= n; i++)
    {
        size1[i] = size[i];
    }
    sort(size1, size1 +n+1);
     for(int i = 1; i<= n; i++)
    { if(size1[i] == 0)continue;
        cout<<size1[i]<<" ";}
    cout<<endl;

 }
return(0);
}

