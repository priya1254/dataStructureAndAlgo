//mimimum spanning tree
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
long adj[1005][1005];
struct node
{
	int predecessor;
	long dist;
	int status;
};

 long abs1(long x)
    {

        if(x<0){
            long y;
            y=-x;

            return y;}
        else
        {
        return x;}
    }

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
	int m;
	long min1;
	int u1,v1;
	*weight=0;

	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = infinity;
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
				if(adj[current][i] < state[i].dist)
				{
					state[i].predecessor = current;
					state[i].dist = adj[current][i];
				}
			}
		}


		min1=infinity;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist < min1)
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
       long a1[1005],a2[1005],a3[1005];
       long wt_tree=0;


       for(int p=1;p<=n;p++){
        cin>>a1[p]>>a2[p]>>a3[p];}
        for(long l=1;l<=n;l++)
        {
            for(long k=1;k<=n;k++)
            {

                adj[l][k]=abs1(a1[l]-a1[k])+abs1(a2[l]-a2[k])+abs1(a3[l]-a3[k]);
            }
        }

  maketree(&wt_tree);

    cout<<"Case #"<<t<<":"<<" "<<wt_tree;
     cout<<"\n";
   }
return(0);
}//end of func
