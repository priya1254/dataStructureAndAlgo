//Print all path to a destination
#include <bits/stdc++.h>
using namespace std;
#include<stdio.h>
int n;
int adj[505][505];
 int dist[505][505],max1=INT_MIN,rem[505];
  int a[505];
int m,g,u,v,w;
long max(long a,long b)
{
    return(a>b?a:b);
}

void printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index,int distance)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if(u!=n)
    {
        distance=distance+dist[u][path[path_index-2]];

    }
    if(dist[g][u]<=distance)
    {
        path_index--;
        return;
    }

    if (u == d)
    {
        long count1=0;
        for (int i = 0; i<path_index; i++)
            {
                //cout<<"path "<<path[i]<<" ";
                count1+=a[path[i]];
            }
            if(max1<count1){
            max1=count1;
           }
    }
    else
    {

        for (int i = u-1; i >=0 ; i--)
            if (adj[u][i]<INT_MAX && !visited[i] && !rem[i])
                printAllPathsUtil(i, d, visited, path, path_index,distance);


    }


    path_index--;
    visited[u] = false;
}


void floydWarshall (int graph[505][505],int V)
   {

    int i, j, k;


    for (i = 0; i <=V; i++)
    {
        for (j = 0; j <=V; j++)
        {
            dist[i][j] = graph[i][j];

        }

    }


    for (k = 0; k<=V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i<= V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j<= V; j++)
            {
                if(i==j)
                {dist[i][j]=0;}
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                else if( (dist[i][k]!=INT_MAX)&&(dist[k][j]!=INT_MAX)&&(dist[i][k] + dist[k][j] < dist[i][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];

                }
            }

        }
    }



}
int main() {
	int t=0;

	int shortdist;
	cin>>t;


	for(int i1=1;i1<=t;i1++)
	{


	    shortdist=0;
	    cin>>n>>m>>g;

	    a[0]=0;
	    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }


   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=n;j++)
       {
           adj[i][j]=INT_MAX;

       }

   }

    for(int q=1;q<=m;q++)
    {
        cin>>u;
        cin>>v;
        cin>>w;


        adj[u][v]=w;

       adj[v][u]=w;


    }


    floydWarshall (adj,n);
   if(dist[g][0]<=dist[n][0])
        {
            cout<<"Case #"<<i1<<": impossible \n";
            continue;
        }


    for(int i=0;i<=n;i++)
        {
            if(dist[g][i]<=dist[n][i])
            rem[i]=1;
            if(dist[n][i]==INT_MAX)
            rem[i]=1;
        }

        bool *visited = new bool[n+1];
        int *path = new int[n+1];
        int path_index = 0;
        memset(visited,0,sizeof(visited));
        printAllPathsUtil(n, 0, visited, path, path_index,0);
        cout<<"Case #"<<i1<<": ";
        if(max1==INT_MIN)
        {
            cout<<"impossible \n";
        }
        else
        {
            cout<<max1<<"\n";
        }





	}

	return 0;
}


