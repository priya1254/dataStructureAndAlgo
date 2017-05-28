//Kruskal Algorithm
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>
#define MAX 10005

using namespace std;
long n,m,cnt;

struct edge
{
	int u;
	int v;
	int weight;

}tree[100005];

long father[MAX]; /*Holds father of each node */
long wt_tree; /*Weight of the spanning tree */
long r;
void insert_array(long i,long j,long wt)
{

	tree[r].u=i;
	tree[r].v=j;
	tree[r].weight = wt;
	r++;

}/*End of insert_array()*/
bool cmp(struct edge q, struct edge b)
{
   if(q.weight>b.weight)
   return 1;
   else
   return 0;
}



void make_tree()
{
	struct edge tmp;
	long node1,node2,root_n1,root_n2;
	cnt=0;

	while(cnt<m) /*Loop till n-1 edges included in the tree*/
	{

		tmp=tree[cnt];
		node1=tmp.u;
		node2=tmp.v;
		while( node1 > 0)
		{
			root_n1=node1;
			node1=father[node1];
		}
		while( node2 >0 )
		{
			root_n2=node2;
			node2=father[node2];
		}

		if(root_n1!=root_n2)
		{

		      wt_tree=wt_tree+tmp.weight;
		      father[root_n2]=root_n1;
		}
		cnt++;
	}/*End of while*/
}/*End of make_tree()*/

int main()
{
   int temp;
   cin>>temp;


   for(int t=1;t<=temp;t++)
   {
   wt_tree=0;
        long sum=0;
        r=0;

       long x,y,z;
            cin>>n>>m;

            memset(father,0,sizeof(father));

       for(long i=1;i<=m;i++)
       {
           cin>>x>>y>>z;
           sum+=z;
           insert_array(x,y,z);

       }

sort(tree,tree+m,cmp);


    make_tree();
       sum=sum-wt_tree;
    cout<<"Case #"<<t<<":"<<" "<<sum;
     cout<<"\n";

   }
return(0);
}//end of func






