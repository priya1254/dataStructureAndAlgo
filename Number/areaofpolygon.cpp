// code taken from http://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/ from line 12 to 27
//Program Computing Area of Triangle
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long determinant(long result[3][3], int rows, int cols)
 {
        if (rows == 2)
            return result[0][0] * result[1][1] - result[0][1] * result[1][0];

        long determinant1 = 0, determinant2 = 0;
        for (int i = 0; i < rows; i++) {
            long temp = 1, temp2 = 1;
            for (int j = 0; j < cols; j++) {
                temp *= result[(i + j) % cols][j];
                temp2 *= result[(i + j) % cols][rows - 1 - j];
            }

            determinant1 += temp;
            determinant2 += temp2;
        }

        return determinant1 - determinant2;
    }

      long GCD(long a, long b) {
        if (b==0) return a;
        return GCD(b,a%b);
    }



int main()
{
    int t=0;
    cin>>t;

    for(int i1=1;i1<=t;i1++)
	{
     long n,m;
     cin>>n>>m;
     long x[n+1][2];
     long a[3][3];
     for(int i=0;i<n;i++)
     {
         cin>>x[i][0];
         cin>>x[i][1];
         x[i][0]=m*x[i][0];
         x[i][1]=m*x[i][1];

     }
        a[0][0]=x[0][0];
        a[0][1]=x[0][1];
        a[0][2]=1;
        long area=0;
    for(int i=1;i<n-1;i++)
    {

        a[1][0]=x[i][0];
        a[1][1]=x[i][1];
        a[1][2]=1;
        a[2][0]=x[i+1][0];
        a[2][1]=x[i+1][1];
        a[2][2]=1;
        area+=(determinant(a, 3, 3) );
    }
    //cout<<area<<endl;
    long subarea=0;
    for(int i=0;i<n;i++)
    {
       a[0][0]=x[i][0];
       a[0][1]=x[i][1];
       a[0][2]=1;
       if(i==0)
       {
           a[1][0]=(x[i+1][0]+((x[i][0])*(m-1)))/m;
           a[1][1]=(x[i+1][1] +((x[i][1])*(m-1)))/m;
            a[1][2]=1;
           a[2][0]=(x[n-1][0] +((x[i][0])*(m-1)))/m;
           a[2][1]=(x[n-1][1] +((x[i][1])*(m-1)))/m;
            a[2][2]=1;
        }
       else if(i==n-1)
       {
          a[1][0]=(x[0][0]+((x[i][0])*(m-1)))/m;
           a[1][1]=(x[0][1] +((x[i][1])*(m-1)))/m;
            a[1][2]=1;
           a[2][0]=(x[i-1][0] +((x[i][0])*(m-1)))/m;
           a[2][1]=(x[i-1][1] +((x[i][1])*(m-1)))/m;
            a[2][2]=1;

       }
       else
       {
            a[1][0]=(x[i+1][0]+((x[i][0])*(m-1)))/m;
           a[1][1]=(x[i+1][1] +((x[i][1])*(m-1)))/m;
            a[1][2]=1;
           a[2][0]=(x[i-1][0] +((x[i][0])*(m-1)))/m;
           a[2][1]=(x[i-1][1]+((x[i][1])*(m-1)))/m;
            a[2][2]=1;
       }
        subarea+=determinant(a,3,3);

    }



    long gcd = GCD(area, subarea);

    cout<<"Case #"<<i1<<": "<<endl;
    long div1=area/gcd;
    long div2=subarea/gcd;

    cout<<div2<<"/";
    cout<<div1;
    cout<<endl;






	}
    return 0;
}
