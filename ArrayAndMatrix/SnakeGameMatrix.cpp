//Matrix- Snake Game
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int facetop,facedown,faceright,faceleft;
int n;
int adj[10009][10009];
int cs,rs;
int count1;
int flag;



struct point{
int first;
int second;
};
queue<point> q;
void moveforward()
{
     if(faceright==1)
             {
                 if(cs==n)
                 {
                     cs=1;
                 }
                 else if(cs<n && cs>=1)
                    {
                        cs=cs+1;
                    }
                 point s;
                 s.first=rs;
                 s.second=cs;

                 if(adj[rs][cs]!=2)
                 {
                     point r=q.front();
                    q.pop();
                    adj[r.first][r.second]=0;

                        if(adj[rs][cs]==1)
                     {
                         flag=1;
                         return;
                     }

                     q.push(s);
                     adj[rs][cs]=1;
                }
                else
                {
                     count1=count1+1;
                     q.push(s);
                     adj[rs][cs]=1;

                }
                return;
        }
 else if(faceleft==1)
    {
                  if(cs==1)
                  {
                    cs=n;
                  }
                 else if(cs>1 && cs<=n)
                 {
                     cs=cs-1;
                 }
                 point s;
                 s.first=rs;
                 s.second=cs;
                 if(adj[rs][cs]!=2)
                 {
                point r=q.front();
                q.pop();
                adj[r.first][r.second]=0;
                 if(adj[rs][cs]==1)
                 {
                     flag=1;
                     return;
                 }
                 q.push(s);
                  adj[rs][cs]=1;
                }
                else
                {
                  count1=count1+1;
                   q.push(s);
                    adj[rs][cs]=1;

                }
                return;
    }
    else if(facetop==1)
    {
                  if(rs==1)
                    {
                        rs=n;
                    }
                 else if(rs>1 && rs<=n)
                 {
                     rs=rs-1;
                 }
                 point s;
                 s.first=rs;
                 s.second=cs;
                 if(adj[rs][cs]!=2){
                point r=q.front();
                q.pop();
                adj[r.first][r.second]=0;
                 if(adj[rs][cs]==1)
                 {
                     flag=1;
                     return;
                 }
                 q.push(s);
                  adj[rs][cs]=1;
                }
                else
                {
                  count1=count1+1;
                  q.push(s);
                   adj[rs][cs]=1;
                }
                return;
    }

    else if(facedown==1)
    {

                  if(rs==n)
                  {
                    rs=1;
                  }
                 else if(rs>=1 && rs<n)
                 {
                     rs=rs+1;
                 }
                 point s;
                 s.first=rs;
                 s.second=cs;
                 if(adj[rs][cs]!=2)
                 {
                point r=q.front();
                q.pop();
                adj[r.first][r.second]=0;
                if(adj[rs][cs]==1)
                 {
                     flag=1;
                     return;
                 }
                  q.push(s);
                   adj[rs][cs]=1;
                }

                else
                {
                  count1=count1+1;
                 q.push(s);
                adj[rs][cs]=1;

                }
                return;
   }
}

int main()
{
    int t=0;
    cin>>t;

    for(int i1=1;i1<=t;i1++)
	{
      int m;
      cin>>n>>m;
      count1=0;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              adj[i][j]=0;
          }
      }
      int c,r1,w,h,l;
      cs=0,rs=0;
      string str;
      cin>>cs>>rs;

      flag=0;

      for(int i=1;i<=m;i++)
      {
          cin>>c>>r1>>w>>h;
         for(int k=0;k<h;k++)
          {
              for(int y=0;y<w;y++){

             adj[r1+k][c+y]=2;

             }
         }
      }
      adj[rs][cs]=1;
      point p;
      p.first=rs;
      p.second=cs;
      q.push(p);

      cin>>l;
      cin>>str;
     int points=0;
     facetop=0;facedown=0;faceright=0;faceleft=0;

     faceright=1;
     for(int i=0;i<l;i++)
     {

         if(flag==1)
         {
             points=points-1;
             break;

         }
          points=points+1;
         if(str[i]=='F')
         {
             moveforward();
             continue;
         }
          if(str[i]=='L')
         {
             if(faceright==1)
              {
                 facetop=1;
                 faceright=0;
                 moveforward();
                 continue;
                }
                if(faceleft==1)
                {
                  facedown=1;
                 faceleft=0;
                 moveforward();
                 continue;
                }
                 if(facetop==1)
                {
                   faceleft=1;
                 facetop=0;
                 moveforward();
                 continue;
                }

                if(facedown==1)
                {
                  faceright=1;
                 facedown=0;
                 moveforward();
                 continue;
                }
         }
          if(str[i]=='R')
         {
               if(faceright==1)
                {
                 facedown=1;
                 faceright=0;
                 moveforward();
                 continue;
                }
                if(faceleft==1)
                {
                  facetop=1;
                 faceleft=0;
                 moveforward();
                 continue;
                }
                 if(facetop==1)
                {
                   faceright=1;
                 facetop=0;
                 moveforward();
                 continue;
                }

                if(facedown==1)
                {
                  faceleft=1;
                 facedown=0;
                 moveforward();
                 continue;
                }
         }

         }

  cout<<"Case #"<<i1<<": "<<points<<" "<<count1;
  cout<<endl;

	}
    return 0;
}
