//DFS and MST application
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>
#define MAX 1005
#define TEMP 0
#define PERM 1
#define FALSE 0
#define TRUE 1
#define infinity 1000005
using namespace std;
int n;
int m;
long adj[1005][1005];
int visited[1005];

void dfs(int c)
{
    for(int l=1;l<=n;l++)
    {
        if((visited[l]==false)&&(adj[c][l]>0))
        {
            visited[l]=true;
            dfs(l);
        }
    }
    return;
}
struct node
{
	int predecessor;
	long dist;
	int status;
};

int all_perm(struct node state[MAX] )
{
	int i;
	for(i=1;i<=n;i++)
	   if( state[i].status == TEMP )
	       return FALSE;
	return TRUE;
}
void maketree(long *weight)
{
	struct node state[1005];
	int i,k,current;
	long newdist;
    long min1;
	int u1,v1;
	*weight=0;

	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = 0;
		state[i].status = TEMP;
	}

	state[1].predecessor=0;
	state[1].dist = 0;
	state[1].status = PERM;


	current=1;

	while( all_perm(state) != TRUE )
	{
		for(i=1;i<=n;i++)
		{
			if ( adj[current][i] > 0 && state[i].status == TEMP )
			{
				if(adj[current][i] > state[i].dist)
				{
					state[i].predecessor = current;
					state[i].dist = adj[current][i];
				}
			}

		}


		min1=0;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist > min1)
			{
				min1 = state[i].dist;
				current=i;
			}
		}

		state[current].status=PERM;
		u1=state[current].predecessor;
		v1=current;
		*weight=*weight+adj[u1][v1];
	}/*End of while*/

}/*End of maketree()*/




int main()
{
   int temp;
   cin>>temp;


   for(int t=1;t<=temp;t++)
   {

       cin>>n;
       cin>>m;
       int x,y,z,u;
       int sum=0;
       long wt_tree=0;

       for(int f=1;f<=n;f++)
       {
           visited[f]=false;
           for(int g=1;g<=n;g++)
           {
               adj[f][g]=0;
           }
       }

       int d;
       int rem=0;
       for(int p=1;p<=m;p++){
        cin>>x>>y>>z>>u;
        d=(z*u);
        if(adj[x][y]>=d)
        {
            rem+=d;
        }

        if((adj[x][y]<d)&&(adj[x][y]>0))
        {
            rem=rem+adj[x][y];
        }
        if(adj[x][y]<d)
        {

        sum=sum-adj[x][y];
        adj[x][y]=(z*u);
        adj[y][x]=(z*u);
        sum=sum+(z*u);
        }

        }

        int flag=0;
        visited[1]=true;
        dfs(1);
        for(int v=1;v<=n;v++)
        {
            if(visited[v]==false)
            {
                cout<<"Case #"<<t<<":"<<" "<<"impossible";
                 cout<<"\n";
                 flag=1;
                 break;
            }

        }

     if(flag==0){
     maketree(&wt_tree);
     wt_tree=sum-wt_tree+rem;

    cout<<"Case #"<<t<<":"<<" "<<wt_tree;
     cout<<"\n";}
   }
return(0);
}//end of func
