// A C++ program to check if a given point lies inside a given polygon
// code taken from http://stackoverflow.com/questions/11716268/point-in-polygon-algorithm,from line 12 to 21
// A C++ program to find convex hull of a set of points. Refer
// http://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()

//Code referred from : http://www.realtimerendering.com/resources/GraphicsGems//gemsiv/ptpoly_haines/ptinpoly.c (Line no 37 to 89)
#include <iostream>
#include <bits/stdc++.h>
#define X	0
#define Y	1
#define M_PI 3.14159265358979323846
using namespace std;
int k;


struct Point
{
    double x;
    double y;
};
#define INF 10000

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
double orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

double polygon[305][2];

int AngleTest(int numverts, double point[2])
{
	 double *vtx0, *vtx1, angle, len, vec0[2], vec1[2], vec_dot;
	 int j;
	int	inside_flag;

	/* sum the angles and see if answer mod 2*PI > PI */
	vtx0 = polygon[numverts - 1];
	vec0[X] = vtx0[X] - point[X];
	vec0[Y] = vtx0[Y] - point[Y];
	len = sqrt(vec0[X] * vec0[X] + vec0[Y] * vec0[Y]);
	if (len <= 0.0) {
		/* point and vertex coincide */
		return(1);
	}
	vec0[X] /= len;
	vec0[Y] /= len;

	angle = 0.0;
	for (j = 0; j < numverts; j++) {
		vtx1 = polygon[j];
		vec1[X] = vtx1[X] - point[X];
		vec1[Y] = vtx1[Y] - point[Y];
		len = sqrt(vec1[X] * vec1[X] + vec1[Y] * vec1[Y]);
		if (len <= 0.0) {
			/* point and vertex coincide */
			return(1);
		}
		vec1[X] /= len;
		vec1[Y] /= len;

		/* check if vec1 is to "left" or "right" of vec0 */
		vec_dot = vec0[X] * vec1[X] + vec0[Y] * vec1[Y];
		if (vec_dot < -1.0) {
			/* point is on edge, so always add 180 degrees.  always
			* adding is not necessarily the right answer for
			* concave polygons and subtractive triangles.
			*/
			angle += M_PI;
		}
		else if (vec_dot < 1.0) {
			if (vec0[X] * vec1[Y] - vec1[X] * vec0[Y] >= 0.0) {
				/* add angle due to dot product of vectors */
				angle += acos(vec_dot);
			}
			else {
				/* subtract angle due to dot product of vectors */
				angle -= acos(vec_dot);
			}
		} /* if vec_dot >= 1.0, angle does not change */

		  /* get to next point */
		vtx0 = vtx1;
		vec0[X] = vec1[X];
		vec0[Y] = vec1[Y];
	}
	/* test if between PI and 3*PI, 5*PI and 7*PI, etc */
	inside_flag = fmod(fabs(angle) + M_PI, 4.0*M_PI) > 2.0*M_PI;

	return(inside_flag);
}
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
// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
Point p0;
Point arr1[90602];
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two points
long swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
long distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}



// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   // Find orientation
   long o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}



// Prints convex hull of a set of n points.
int convexHull(Point points[], long n)
{
    memset(arr1,0,sizeof(arr1));
   // Find the bottommost point
   long ymin = points[0].y, min = 0;
   for (long i = 1; i < n; i++)
   {
     long y = points[i].y;

     // Pick the bottom-most or chose the left.
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }

   // Place the bottom-most point at first position
   swap(points[0], points[min]);

   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted ouput if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);

   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   long m = 1; // Initialize size of modified array
   for (long i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  // Update size of modified array
   }

   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return 1;

   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   // Process remaining n-3 points
   for (long i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }


    cout<<S.size()<<endl;
   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
       cout<<p.x<<" "<<p.y<<endl;

       S.pop();
   }
   return 0;

}

// Driver program to test above functions
int main()
{
    int t=0;
    cin>>t;
    for(int i1=1;i1<=t;i1++)
	{

     int n;
    cin>>n;
    k=0;
    Point polygon1[90602];
    Point arr[n+1];
    int k1=0;
    int mx=305,my=305,m1x=0,m1y=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            polygon[i][j]=0;
        }
    }

   for(int i=0;i<n;i++)
   {
       cin>>arr[i].x>>arr[i].y;
       polygon[i][0]=arr[i].x;
       polygon[i][1]=arr[i].y;

     if(mx>arr[i].x)
     {
         mx=arr[i].x;
     }
   if(my>arr[i].y)
     {
         my=arr[i].y;
     }
      if(m1x<arr[i].x)
     {
         m1x=arr[i].x;
     }
   if(m1y<arr[i].y)
     {
         m1y=arr[i].y;
     }


   }
   for(int i=mx;i<=m1x;i++)
   {
       for(int j=my;j<=m1y;j++)
       {
          Point p;
           p.x=i;
           p.y=j;
           double point[2];
           point[0]=i;
           point[1]=j;
            if((pnpoly(n,arr,p)==1)||(AngleTest(n, point)))
            {
            polygon1[k1].x=p.x;
            polygon1[k1++].y=p.y;

            }

       }

   }

    cout<<"Case #"<<i1<<": "<<endl;
    if(k1==0)
    {cout<<k1<<endl;
    continue;}
    if(k1<3)
    {
        cout<<k1<<endl;
        for(int i=0;i<k1;i++)
        {   cout<<polygon1[i].x<<" "<<polygon1[i].y<<endl;

        }
        continue;
    }

    if (convexHull(polygon1, k1))
			{
				int xmin=1000,yminm=1000,xmaxm=-1000,ymaxm=-1000;
				for (int i = 0; i < k1; i++)
				{
					if (xmin>polygon1[i].x)
						{xmin=polygon1[i].x;}
					if (yminm>polygon1[i].y)
						{ yminm=polygon1[i].y;}

					if (xmaxm<polygon1[i].x)
					{xmaxm=polygon1[i].x;}

					if (ymaxm<polygon1[i].y)
					{ymaxm=polygon1[i].y;}


				}
				cout<<"2"<<endl;
				cout<<xmin<<" "<<yminm<<endl;
				cout<<xmaxm<<" "<<ymaxm<<endl;
			}


	}
    return 0;
}
