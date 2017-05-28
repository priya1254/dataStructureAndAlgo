// A C++ program to check if a given point lies inside a given polygon
// code taken from http://stackoverflow.com/questions/11716268/point-in-polygon-algorithm,from line 12 to 21
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    float x;
    float y;
};
int pnpoly(int nvert,Point polygon[], Point test)
{
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((polygon[i].y>test.y) != (polygon[j].y>test.y)) &&
     (test.x < (polygon[j].x-polygon[i].x) * (test.y-polygon[i].y) / (polygon[j].y-polygon[i].y) + polygon[i].x) )
       c = !c;
  }
  return c;
}

// Driver program to test above functions
int main()
{
    int t=0;
    cin>>t;
    int x1,y1,x2,y2,x3,y3,n,x4,y4;
    for(int i1=1;i1<=t;i1++)
	{


    cin>>x1>>y1>>n;
    Point p;
    p.x=x1;
    p.y=y1;
    Point polygon1[n+1];
    Point arr[n+1][2];
  int k=0;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i][0].x>>arr[i][0].y>>arr[i][1].x>>arr[i][1].y;


   }
   for(int i=0;i<n;i++)
   {
       polygon1[i].x=arr[i][0].x;
        polygon1[i].y=arr[i][0].y;

       x2=arr[i][1].x;
       y2=arr[i][1].y;


       for(int j=i+1;j<n;j++)
       {
           if((arr[j][0].x==x2)&&(arr[j][0].y==y2))
           {

               x3=arr[i+1][0].x;
               y3=arr[i+1][0].y;
               x4=arr[i+1][1].x;
               y4=arr[i+1][1].y;

               arr[i+1][0].x=arr[j][0].x;
               arr[i+1][0].y=arr[j][0].y;
               arr[i+1][1].x=arr[j][1].x;
               arr[i+1][1].y=arr[j][1].y;

               arr[j][0].x=x3;
               arr[j][0].y=y3;
               arr[j][1].x=x4;
               arr[j][1].y=y4;

               break;
           }
       }
  }


    cout<<"Case #"<<i1<<": ";
    //isInside(polygon1, n, p)? cout << "jackpot \n": cout << "too bad \n";
     pnpoly(n,polygon1,p)? cout << "jackpot \n": cout << "too bad \n";


	}
    return 0;
}
