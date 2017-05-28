//Snake Game , Matrix Implementation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int facetop,facedown,faceright,faceleft;
 int facetailrght,facetaillft,facetailtp,facetaildwn;

int n;
int adj[10002][10002];
int cs,rs;
int u,v;
int count1;
int flag;
int flag1;
struct facetail{
int facetaildown;
int facetailleft;
int facetailright;
int facetailtop;

};
facetail store[10002];
int x;
int r;
void changetail()
{
    facetaildwn=store[r].facetaildown;
    facetaillft=store[r].facetailleft;
    facetailrght=store[r].facetailright;
    facetailtp=store[r++].facetailtop;
    if(facetailrght==1)
    {
         //cout<<u<<" "<<v<<" "<<adj[u][v]<<endl;
                adj[u][v]=0;
                 if(v==n)
                 {
                     v=1;
                 }
                 else{
                 v=v+1;}
    }
     if(facetaillft==1)
    {
         adj[u][v]=0;
            //     cout<<u<<" "<<v<<" "<<adj[u][v]<<endl;
                 if(v==1)
                 {
                     v=n;
                 }
                 else{
                 v=v-1;}
    }
     if(facetailtp==1)
    {
          adj[u][v]=0;
              //   cout<<u<<" "<<v<<" "<<adj[u][v]<<endl;
                 if(u==1)
                 {
                     u=n;
                 }
                 else{
                 u=u-1;}
    }
      if(facetaildwn==1)
    {

                adj[u][v]=0;
                // cout<<u<<" "<<v<<" "<<adj[u][v]<<endl;
                 if(u==n)
                 {
                     u=1;
                 }
                 else{
                 u=u+1;}

    }


   flag1=0;


}

void moveforward()
{
     if(faceright==1)
             {
                  if(cs<n){

                 cs=cs+1; }
                 else
                 {
                     cs=1;
                 }
           //        cout<<"right "<<rs<<" "<<cs<<endl;


                 if(adj[rs][cs]!=2){
             //        cout<<"hello"<<endl;


                 store[x].facetailright=faceright;
                 store[x].facetailleft=0;
                 store[x].facetailtop=0;
                 store[x++].facetaildown=0;


                 changetail();
                    if(adj[rs][cs]==1)
                 {
                     flag=1;
               //      cout<<"bite the tail"<<endl;
                     return;
                 }
                 adj[rs][cs]=1;
                }
                else
                {
                    count1++;
                 //   cout<<"count increased"<<count1<<endl;
                 adj[rs][cs]=1;



                 store[x].facetailright=faceright;
                 store[x].facetailleft=0;
                 store[x].facetailtop=0;
                 store[x++].facetaildown=0;



                }
                }
 if(faceleft==1)
    {
                  if(cs>1){

                 cs=cs-1; }
                 else
                 {
                     cs=n;
                 }
                  //cout<<"left "<<rs<<" "<<cs<<endl;

                 if(adj[rs][cs]!=2){

                  store[x].facetailleft=faceleft;
                  store[x].facetailright=0;
                  store[x].facetailtop=0;
                  store[x++].facetaildown=0;

                   changetail();
                      if(adj[rs][cs]==1)
                 {
                     flag=1;
                    // cout<<"bite the tail"<<endl;
                     return;
                 }
                 adj[rs][cs]=1;
                }
                else
                {
                    count1++;
                    //cout<<"count increased"<<count1<<endl;

                 store[x].facetailleft=faceleft;
                      store[x].facetailright=0;
                  store[x].facetailtop=0;
                 store[x++].facetaildown=0;


                 adj[rs][cs]=1;
                }
    }
     if(facetop==1)
    {
                  if(rs>1){

                 rs=rs-1; }
                 else
                 {
                     rs=n;
                 }
                  //cout<<"top "<<rs<<" "<<cs<<endl;


                 if(adj[rs][cs]!=2){

                  store[x].facetailtop=facetop;
                  store[x].facetailleft=0;
                  store[x].facetailright=0;
                  store[x++].facetaildown=0;

                   changetail();
                      if(adj[rs][cs]==1)
                 {
                     flag=1;
                    // cout<<"bite the tail"<<endl;
                     return;
                 }
                 adj[rs][cs]=1;
                }
                else
                {

                    count1++;
                    //cout<<"count increased"<<count1<<endl;
                 adj[rs][cs]=1;

                  store[x].facetailtop=facetop;
                  store[x].facetailleft=0;
                  store[x].facetailright=0;
                  store[x].facetaildown=0;


                }
    }

    if(facedown==1)
    {
                  if(rs<n){

                 rs=rs+1; }
                 else
                 {
                     rs=1;
                 }
                  //cout<<"down "<<rs<<" "<<cs<<endl;

                 if(adj[rs][cs]!=2){

                  store[x].facetaildown=facedown;
                  store[x].facetailleft=0;
                  store[x].facetailright=0;
                  store[x++].facetailtop=0;


                 changetail();
                    if(adj[rs][cs]==1)
                 {
                     flag=1;
                    // cout<<"bite the tail"<<endl;
                     return;
                 }
                 adj[rs][cs]=1;
                }

                else
                {
                    count1++;
                    //cout<<"count increased"<<count1<<endl;
                 adj[rs][cs]=1;


                  store[x].facetaildown=facedown;
                  store[x].facetailleft=0;
                  store[x].facetailright=0;
                  store[x++].facetailtop=0;

                }
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
 facetailrght =0;
 facetaillft=0;
 facetailtp=0;
 facetaildwn=0;
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              adj[i][j]=0;
          }
      }
      memset(store,0 ,sizeof(facetail));
      x=0;
      r=0;
      int c,r,w,h,l;
      cs=0,rs=0;
      string str;
      cin>>cs>>rs;
      adj[rs][cs]=1;
      flag=0;
      flag1=0;
      for(int i=1;i<=m;i++)
      {
          cin>>c>>r>>w>>h;
          for(int k=0;k<w;k++)
          {
              if(adj[r][c+k]==1)
              {continue;}
              else{
             adj[r][c+k]=2;}
          }
         for(int k=0;k<h;k++)
          {
               if(adj[r+k][c]==1)
              {continue;}
              else{
              for(int y=0;y<w;y++){
             adj[r+k][c+y]=2;}
             }
          }
      }
     cin>>l;
     cin>>str;
     int points=0;


    facetop=0;facedown=0;faceright=0;faceleft=0;

     u=rs;
     v=cs;
     faceright=1;
     for(int i=0;i<l;i++)
     {

         if(flag==1)
         {
             points=points-1;
             break;}
          points++;
         if(str[i]=='F')
         {
            // cout<<str[i]<<endl;
             moveforward();
             continue;
         }
          if(str[i]=='L')
         {
         //    cout<<str[i]<<endl;
             if(faceright==1)
                {
                 facetop=1;
                 faceright=0;
           //      cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }
                if(faceleft==1)
                {
                  facedown=1;
                 faceleft=0;
             //    cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }
                 if(facetop==1)
                {
                   faceleft=1;
                 facetop=0;
               //  cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }

                if(facedown==1)
                {
                  faceright=1;
                 facedown=0;
                 //cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }
         }
          if(str[i]=='R')
         {
              //cout<<str[i]<<endl;
               if(faceright==1)
                {
                 facedown=1;
                 faceright=0;
                // cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }
                if(faceleft==1)
                {
                  facetop=1;
                 faceleft=0;
                 //cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }
                 if(facetop==1)
                {
                   faceright=1;
                 facetop=0;
                 //cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
                 moveforward();
                 continue;
                }

                if(facedown==1)
                {
                  faceleft=1;
                 facedown=0;
                 //cout<<"top ="<<facetop<<" down= "<<facedown<<" right="<<faceright<<" left="<<faceleft<<endl;
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
