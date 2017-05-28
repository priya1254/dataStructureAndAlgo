//Shortest Path Algorithm Dijkstra
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>
#define MAX 1005
#define TEMP 0
#define PERM 1
#define infinity 9999
#define FALSE 0
#define TRUE 1

using namespace std;
int n;
int adj[1005][1005];


struct node
{
	int predecessor;
	int dist; /*minimum distance of node from source*/
	int status;
};
int all_perm(struct node state[MAX] )
{
	int i;
	for(i=1;i<=n;i++)
	   if( state[i].status == TEMP )
	       return FALSE;
	return TRUE;
}/*End of all_perm()*/


void findpath(int s,int d,int path[MAX],int *sdist)
{
	struct node state[MAX];
	int i,min1,current,newdist,u,v;
	*sdist=0;
	/* Make all nodes temporary */
	for(i=1;i<=n;i++)
	{
		state[i].predecessor=0;
		state[i].dist = 0;
		state[i].status = TEMP;
	}

	/*Source node should be permanent*/
	state[s].predecessor=0;
	state[s].dist = 0;
	state[s].status = PERM;

	/*Starting from source node until destination is found*/
	current=s;

	while((all_perm(state) != TRUE)&&(current!=d))
	{

		for(i=1;i<=n;i++)
		{
			/*Checks for adjacent temporary nodes */
			if ( adj[current][i] > 0 && state[i].status == TEMP )
			{
				newdist=state[current].dist + adj[current][i];
				/*Checks for Relabeling*/
				if( newdist > state[i].dist )
				{
					state[i].predecessor = current;
					state[i].dist = newdist;
				}
			}
		}/*End of for*/

		/*Search for temporary node with minimum distand make it current node*/
		min1=0;
		current=0;
		for(i=1;i<=n;i++)
		{
			if(state[i].status == TEMP && state[i].dist > min1)
			{
				min1 = state[i].dist;
				current=i;
			}
		}/*End of for*/


		state[current].status=PERM;
		cout<<"curr ="<<current<<endl;
	}/*End of while*/

	/* Getting full path in array from destination to source	*/

		*sdist= state[d].dist;
	}



int main()
{
   int temp;
   int path[MAX];
   int u,v,w,x,y;
   int shortdist,count1;
   cin>>temp;


   for(int t=1;t<=temp;t++)
   {
       shortdist=0;
       memset(path,0,sizeof(path));
       memset(adj,0,sizeof(adj));

    cin>>n;
    for(int q=1;q<n;q++)
    {
        cin>>u>>v;
        for(int i=1;i<=v;i++)
        {
            cin>>w;
            adj[q][w]=u;

        }


    }
     for(int q=1;q<=n;q++)
    {

        for(int i=1;i<=n;i++)
        {

            cout<<adj[q][i]<<" ";

        }

cout<<endl;
    }
    cin>>x;
    cin>>y;

  findpath(1,n,path,&shortdist);
  cout<<shortdist<<endl;
  shortdist+=x;

     cout<<"Case #"<<t<<":"<<" "<<shortdist;
     cout<<"\n";
   }
   return(0);
}







