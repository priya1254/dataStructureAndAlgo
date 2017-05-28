// A C++ program to check if a given point lies inside a given polygon
// code taken from http://stackoverflow.com/questions/11716268/point-in-polygon-algorithm,from line 12 to 21
// A C++ program to find convex hull of a set of points. Refer
// http://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()

//Code referred from : http://www.realtimerendering.com/resources/GraphicsGems//gemsiv/ptpoly_haines/ptinpoly.c (Line no 37 to 89)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;





int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
	{

     double x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
     cin>>x1>>y1>>x2>>y2>>x3>>y3;
     double m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,xm1=0,xm2=0,ym1=0,ym2=0;
     xm1=(x1+x2)/2;
     ym1=(y1+y2)/2;
     xm2=(x3+x2)/2;
     ym2=(y3+y2)/2;
     int flag=0;
     if((y2-y1)==0)
     {

       x4=x3;
       m5=-1*((x3-x2)/(y3-y2));
       y4=m5*x4-m5*x1+y1;
       x5=xm1;
       y5=m5*x5-m5*xm2+ym2;
       flag=1;
     }
      if((y3-y2)==0)
     {

       x4=x1;

       m4=-1*((x2-x1)/(y2-y1));

       y4=m4*x4-m4*x3+y3;
       x5=xm2;
       y5=m4*x5-m4*xm1+ym1;
       flag=1;
     }

     if(flag==0){


     m4=-1*((x2-x1)/(y2-y1));
     m5=-1*((x3-x2)/(y3-y2));
     x4=(m4*x3-m5*x1+y1-y3)/(m4-m5);
     y4=m4*x4-m4*x3+y3;
     x5=(m4*xm1-m5*xm2-ym1+ym2)/(m4-m5);
     y5=m4*x5-m4*xm1+ym1;
     }



     cout<<"Case #"<<i1<<": "<<endl;
     x6=(x1+x2+x3)/3;
     y6=(y1+y2+y3)/3;
     printf("%0.6lf %0.6lf\n",x6,y6);
     printf("%0.6lf %0.6lf\n",x4,y4);
     printf("%0.6lf %0.6lf\n",x5,y5);


	}
    return 0;
}
