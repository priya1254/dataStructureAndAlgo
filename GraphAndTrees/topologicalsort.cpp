//topological sort problem
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
long adj[10005][10005];
long n;

int main()
{
   int temp;
   cin>>temp;
    long m,x,y;
    long a[10005];

   int val;
   for(int t=1;t<=temp;t++)
   {
       val=0;
     queue<int> q;
	long i,j=0,k;
	long indeg[10005];

    cin>>n;
    cin>>m;
    for(long p=1;p<=n;p++)
    {
        cin>>a[p];
    }
     for(long f=1;f<=n;f++)
       {
           for(long g=1;g<=n;g++)
           {
               adj[f][g]=0;
           }


       }
       memset(indeg,0,sizeof(indeg));

    for(long h=1;h<=m;h++)
    {
        cin>>x>>y;
        if(adj[x][y]==0)
        indeg[y]++;
        adj[x][y]=1;


    }

	for(i=1;i<=n;i++)
	{
		if( indeg[i]==0 )
			q.push(i);
	}

	while(!q.empty())
	{
		k=q.front();
		q.pop();
		val=val+a[k];

		for(i=1;i<=n;i++)
		{
			if( adj[k][i]==1  )
			{
				adj[k][i]=0;
				indeg[i]=indeg[i]-1;
				if(indeg[i]==0)
					q.push(i);
			}
		}
	}

    cout<<"Case #"<<t<<":"<<" "<<val;
     cout<<"\n";
   }
return(0);
}//end of func
