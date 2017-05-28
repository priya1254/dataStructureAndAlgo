#include<bits/stdc++.h>
using namespace std;

/* Program of shortest path between two node in graph using Djikstra algorithm */
#include<stdio.h>
#define MAX 151
#define TEMP 0
#define PERM 1
#define infinity 99999999

#define FALSE 0
#define TRUE 1

struct node
{
	long predecessor;
	long dist; /*minimum distance of node from source*/
	long status;
};


long adj[MAX][MAX];
long n;

	 long wt_tree;

/*This function returns TRUE if all nodes are permanent*/
int all_perm(struct node state[MAX] )
{
	int i;
	for(i=1;i<=n;i++)
	   if( state[i].status == TEMP )
	       return FALSE;
	return TRUE;
}/*End of all_perm()*/



long maketree(struct node state[MAX])
{

	long i,k,min,count,current,newdist;
	long m;
	long u1,v1;
	wt_tree=0;
	/*Make all nodes temporary*/
	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = infinity;
		state[i].status = TEMP;
	}
	/*Make first node permanent*/
	state[1].predecessor=0;
	state[1].dist = 0;
	state[1].status = PERM;

	/*Start from first node*/
	current=1;
	count=0; /*count represents number of nodes in tree */
	while( all_perm(state) != TRUE ) /*Loop till all the nodes become PERM*/
	{
		for(i=1;i<=n;i++)
		{
			if ( adj[current][i] > 0 && state[i].status == TEMP )
			{
				if(  adj[current][i] < state[i].dist )
				{
					state[i].predecessor = current;
					state[i].dist = adj[current][i];
				}
			}
		}/*End of for*/

		/*Search for temporary node with minimum distance
		and  make it current node*/
		min=infinity;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist < min)
			{
				min = state[i].dist;
				current=i;
			}
		}/*End of for*/

		state[current].status=PERM;

		/*Insert this edge(u1,v1) into the tree */
		u1=state[current].predecessor;
		v1=current;
		count++;

		/*Add wt on this edge to weight of tree	*/
		wt_tree=wt_tree+adj[u1][v1];
	}/*End of while*/
	return (count);
}/*End of maketree()*/





int main()
{


struct node state[MAX];
    int temp=0;

    cin>>temp;


    for(int t=1;t<=temp;t++)
   {

    cin>>n;
    long count=0;

    for(long q=1;q<=n;q++)
    {


        for(long i=1;i<=n;i++)
        {
            cin>>adj[q][i];
        }
    }



		count = maketree(state);

	long current=n;
	long a[n+1];
	memset(a,0,sizeof(a));
   long	k=0;
   while( current!=0 )
	{

       a[k++]=current;
		current=state[current].predecessor;

	}
	cout<<"Case #"<<t<<":"<<" ";
	for(long i=k-1;i>=0;i--)
{
    cout<<a[i]<<" ";
}
cout<<"\n";






   }

    return 0;
}

