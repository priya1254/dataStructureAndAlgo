//check binary number is odd or even
#include <iostream>
using namespace std;

int main()
{
   int n, q;
   cin>>n>>q;
   int a[n+1];
   for(int i=1;i<=n;i++)
   {cin>>a[i];}
   int x,x1,x2;
   for(int i=0;i<q;i++)
   {
	   cin>>bit;
	   if(bit == 1)
		  {
		   cin>>x;
		   if(a[x] == 1)
		   a[x] = 0;
		   else
		   a[x] = 1;
		  }
	   else
	   {
		   cin>>x1>>x2;
		   if(a[x2] == 1)
		   cout<<"ODD\n";
		   else
		   cout<<"EVEN\n";
	   }

    }
    return 0;
}
