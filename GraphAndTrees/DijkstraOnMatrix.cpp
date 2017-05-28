//Shortest Path Dijkstra Application
#include<bits/stdc++.h>
#define infinity 999
#define pp pair<int,int>


     int flag=0;
using namespace std;


         vector<pp> FindShortestPath(char matrix[205][205], int rows, int cols, pp s, pp e,  vector< pp > currPath)
        {

            pp as=s;
            bool visited[205][205];
            pp parent[205][205];
            int hop[205][205];

            for (int i = 1; i <= rows; i++)
             {

                for (int j = 1; j <= cols; j++)
                {
                    visited[i] [j] = 0;
                    parent[i] [j] = make_pair(0,0);
                    hop[i][j]=0;

                }
             }
            queue <pp> q ;
            q.push(as);
            visited[as.first][as.second]=1;
          while (!q.empty())
            {

                pp curr = (pp) q.front();
                q.pop();

                if (curr.first == e.first && curr.second == e.second)
                {

                    while((parent[curr.first][curr.second].first != as.first) || (parent[curr.first][curr.second].second != as.second))
                 {
                        curr = parent[curr.first][curr.second];

                          currPath.push_back(pp(curr.first,curr.second));
                          pp curr2= parent[curr.first][curr.second];


                }

                     flag=1;
                     break;

                }


                if (curr.second + 1 <=cols && matrix[curr.first][curr.second + 1] != '0' && !visited[curr.first][curr.second + 1])
                {




                    q.push(pp(curr.first, curr.second + 1));
                    parent[curr.first][curr.second + 1] = pp(curr.first,curr.second);
                      visited[curr.first][curr.second+1] = 1;


                }
                if( curr.second + 2 <cols && matrix[curr.first][curr.second + 1] =='0' && !visited[curr.first][curr.second + 2]){
                            if(matrix[curr.first][curr.second+2]=='1'){

                        if( hop[curr.first][curr.second ]<3)
                        {
                            hop[curr.first][curr.second +2]= hop[curr.first][curr.second ] +1 ;
                            parent[curr.first][curr.second + 1]=pp(curr.first,curr.second );
                            parent[curr.first][curr.second + 2] = pp(curr.first,curr.second +1);
                         q.push(pp(curr.first, curr.second + 2));
                            visited[curr.first][curr.second+2] = 1;}
                        }
                       }

                  if( curr.second - 2 >1 && matrix[curr.first][curr.second - 1] =='0' && !visited[curr.first][curr.second - 2]){
                                    if( matrix[curr.first][curr.second - 2] =='1'){

                        if( hop[curr.first][curr.second]<3)
                        {
                            hop[curr.first][curr.second -2]= hop[curr.first][curr.second ] +1 ;
                             parent[curr.first][curr.second - 1]=pp(curr.first,curr.second );
                            parent[curr.first][curr.second - 2] = pp(curr.first,curr.second-1);
                         q.push(pp(curr.first, curr.second - 2));
                            visited[curr.first][curr.second-2] = 1;
                        }

                       }
                               }

                if (curr.second - 1 >=1 && matrix[curr.first][curr.second - 1] != '0' && !visited[curr.first][curr.second - 1])
                {


                          q.push(pp(curr.first, curr.second - 1));

                    parent[curr.first][curr.second - 1] = pp(curr.first,curr.second);
                       visited[curr.first][curr.second-1] = 1;


                }
                  if( curr.first - 2 >1 && matrix[curr.first -1][curr.second] =='0' && !visited[curr.first -2][curr.second]){
                                    if( matrix[curr.first -2][curr.second] =='1'){


                        if( hop[curr.first][curr.second ]<3)
                        {
                            hop[curr.first-2][curr.second ]= hop[curr.first][curr.second ] +1 ;
                             parent[curr.first-1][curr.second ]=pp(curr.first,curr.second );
                            parent[curr.first-2][curr.second] = pp(curr.first-1,curr.second);
                         q.push(pp(curr.first-2, curr.second ));
                          visited[curr.first-2][curr.second] = 1;
                        }


                       }

                       }
                if (curr.first - 1 >=1 && matrix[curr.first - 1][curr.second] != '0' && !visited[curr.first -1][curr.second])
                {

                            q.push(pp(curr.first - 1, curr.second));
                            parent[curr.first - 1][curr.second] = pp(curr.first,curr.second);

                      visited[curr.first-1][curr.second] = 1;


                }
                 if(curr.first + 2 <rows && matrix[curr.first +1][curr.second] =='0' && !visited[curr.first + 2][curr.second]){
                             if( matrix[curr.first +2][curr.second] =='1'){

                        if( hop[curr.first][curr.second ]<3)
                        {
                            hop[curr.first +2][curr.second ]= hop[curr.first][curr.second ] +1 ;
                             parent[curr.first +1][curr.second ]=pp(curr.first,curr.second );
                            parent[curr.first +2][curr.second] = pp(curr.first +1,curr.second);
                         q.push(pp(curr.first +2, curr.second ));
                          visited[curr.first +2][curr.second] = 1;
                        }

                             }
                       }

                if (curr.first + 1 <=rows && matrix[curr.first + 1][curr.second] != '0' && !visited[curr.first + 1][curr.second])
                {


                            q.push(pp(curr.first + 1, curr.second));

                    parent[curr.first + 1][ curr.second] = pp(curr.first,curr.second);
                    visited[curr.first+1][curr.second] = 1;



            }
            }
     if(flag==1)
     {
         while(!q.empty())
         {
             pp temp1=q.front();
             q.pop();

         }

     }
     return currPath;
        }

int main()
{

    int temp;
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
  char maze[205][205];
    int m,n;
     int si,sj,di,dj;
     vector< pp > currPath;

    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='*')
            {
                si=i;
                sj=j;
            }
             if((maze[i][j]=='_')&&((i==1)||(j==1)||(j==m)||(i==n)))
            {
                di=i;
                dj=j;
            }
            if(maze[i][j]=='_')
            {
                maze[i][j]='1';
            }
            if(maze[i][j]=='@')
            {
               maze[i][j]='0';
            }
        }
    }

 currPath= FindShortestPath(maze, n, m,pp(si, sj),pp(di, dj),currPath);

      int size = currPath.size();
       pp pp1[3];
      int cnt=0;
      for(int i=0;i<size;i++)
      {
          int l,q;
          l=currPath[i].first;
          q=currPath[i].second;
          if(maze[l][q]=='0')
          {
              pp1[cnt].first=l;
              pp1[cnt].second=q;
            cnt++;
          }


      }


      cnt=cnt-1;
     cout<<"Case #"<<t<<":"<<" ";
     cout<<"\n";
    for(int op=0;op<=cnt;op++)
    {
        cout<<pp1[op].second<<" "<<pp1[op].first;
        cout<<"\n";
    }
    for(int xz=cnt+1;xz<3;xz++)
    {
        cout<<"unused";
        cout<<"\n";
    }

   }

    return 0;

}


