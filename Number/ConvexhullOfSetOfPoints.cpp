// A C++ program to find convex hull of a set of points. Refer
// http://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long k;

struct Point
{
    long x, y;
};

// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qs#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

stringmap merge (stringmap a,stringmap b) {
  stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}

int main ()
{
  stringmap first;                              // empty
  stringmap second ( {{"apple","red"},{"lemon","yellow"}} );       // init list
  stringmap third ( {{"orange","orange"},{"strawberry","red"}} );  // init list
  stringmap fourth (second);                    // copy
  stringmap fifth (merge(third,fourth));        // move
  stringmap sixth (fifth.begin(),fifth.end());  // range

  std::cout << "sixth contains:";
  for (auto& x: sixth) std::cout << " " << x.first << ":" << x.second;
  std::cout << std::endl;

  return 0;
}ort()
Point p0;
Point arr1[1005];
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

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
long orientation(Point p, Point q, Point r)
{
    long val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
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
long comp(Point a, Point b)
{
   if(b.x>a.x)
   {
       return 1;
   }
   if(a.x==b.x)
   {
       return(a.y<b.y);
   }
   else
    return 0;

}


// Prints convex hull of a set of n points.
void convexHull(Point points[], long n)
{
   // Find the bottommost point
   long ymin = points[0].y, min = 0;
   for (long i = 1; i < n; i++)
   {
     long y = points[i].y;

     // Pick the bottom-most or chose the left
     // most point in case of tie
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
   if (m < 3) return;

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

   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
       cout << p.x << " " << p.y << endl;
   }

}
int main()
{
    long t=0;
    cin>>t;
    long x1,y1,n;
    for(long i1=1;i1<=t;i1++)
	{

    k=0;
    cin>>n;
    for(long i=0;i<n;i++)
    {
        arr1[i].x=0;
        arr1[i].y=0;
    }
    Point polygon1[n+1];

   for(long i=0;i<n;i++)
   {
       cin>>polygon1[i].x>>polygon1[i].y>>x1>>y1;

   }

    cout<<"Case #"<<i1<<": "<<endl;
    convexHull(polygon1, n);
    cout<<k<<endl;
    sort(arr1,arr1+k,comp);

    for(long i=0;i<k;i++)
   {

       cout<<arr1[i].x<<" "<<arr1[i].y;
       cout<<"\n";
   }
	}
    return 0;
}
