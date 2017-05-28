//bellmen ford algorithm to find shortest Distance
#include<bits/stdc++.h>
using namespace std;
#define infinity 1.0/0.0
int bellmanFord(
                    vector< list< pair<int, long double> > > adjacencyList,
                    int vertices,
                    int startVertex,
                    vector< pair<long double, int> > & shortestDistances
               )
{
    list< pair<int,long double> >::iterator traverse;
    int i, j, k;


    for (i = 0; i <= vertices; ++i) {
        shortestDistances[i].first = LDBL_MAX;
        shortestDistances[i].second = -1;
    }

    shortestDistances[startVertex].first = 0;
    shortestDistances[startVertex].second = 0;


    for (i = 1; i <= vertices-1 ; ++i) {    // Runs 'vertices - 1' times = O(|V|)
        for (j = 1; j <= vertices; ++j) {    // Runs as many times as the edges = O(|E|)
            // The code ahead basically explores the whole of Adjcency List,
            // covering one edge once, so the runtime of the code in this
            // block is O(|E|)

            traverse = adjacencyList[j].begin();

            while (traverse != adjacencyList[j].end()) {
                if (shortestDistances[j].first == LDBL_MAX) {

                    ++traverse;
                    continue;
                }

                // Checking for Relaxation
                if ((*traverse).second + shortestDistances[j].first <
                                        shortestDistances[(*traverse).first].first) {
                    // Relaxation
                    shortestDistances[(*traverse).first].first = (*traverse).second
                                        + shortestDistances[j].first;
                    shortestDistances[(*traverse).first].second = j;
                }

                ++traverse;
            }
        }
    }

    // Checking for Negative Cycles
    for (j = 1; j <= vertices; ++j) {
        traverse = adjacencyList[j].begin();

        while (traverse != adjacencyList[j].end()) {
            // Checking for further relaxation
            long double val=(*traverse).second + shortestDistances[j].first;
            if (val<shortestDistances[(*traverse).first].first) {
                // Negative Cycle found as further relaxation is possible

                return j;
            }


            ++traverse;
        }


    }

    return -1;
}

int main()
{
    int temp;
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
    int vertices, edges, v1, v2;
    long double weight;
    scanf("%d", &vertices);
    scanf("%d", &edges);

    vector< list< pair<int,long double> > > adjacencyList(vertices + 1);

    for (int i = 1; i <= edges; ++i)
    {
        scanf("%d%d%llf", &v1, &v2, &weight);
            double s;
            s=log(weight);
        // Adding Edge to the Directed Graph
        adjacencyList[v1].push_back(make_pair(v2, s));

    }

    vector< pair<long double, int> > shortestDistances(vertices + 1);
    int startVertex;

     startVertex=1;
    int returnValue = bellmanFord(adjacencyList, vertices, startVertex, shortestDistances);


    if (returnValue != -1)
    {

     cout<<"Case #"<<t<<":"<<" "<<"Jackpot";
     cout<<"\n";
     continue;


    }
    long double d=exp(shortestDistances[vertices].first);

     if(d==infinity)
  {
     cout<<"Case #"<<t<<":"<<" "<<"impossible";
     cout<<"\n";
     continue;

  }


     cout<<"Case #"<<t<<":"<<" ";
     printf("%0.6llf",d);
     cout<<"\n";
   }
    return 0;
}
