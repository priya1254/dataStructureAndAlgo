//Difference in macros and inline functions
#include<bits/stdc++.h>
using namespace std;
#define Multiply(a,b)( a *b )
#define max1(a,b)(a>b?a:b)
#define DOUBLE(x) (x *x)
inline int Doub(int x)
{
    int c = x * x;
    return c;
}
inline int multiply(int a , int b)
{
    int c = a * b;
    return c;
}
int main()
{
    int d ,a ,b;
    a = 2, b = 3;
    d = multiply(a++,b);
    cout<<a<<" "<<b<<endl;
    cout <<d<<endl;
    a = 2, b = 3;
    int e = Multiply(a++,b);
    cout<<a<<" "<<b<<endl;
    cout<<e<<endl;
    int max2;
    max2 = max1(a,b);
    cout<<max2<<endl;
    int y = 5;
    int j = DOUBLE(++y)üu
    int n = 1;
    y = 5;
    cout<< ++y * ++y <<endl;
    cout<<"y is "<<y<<endl;
    y = 5;
    cout<< (++y * ++y) <<endl;
    cout<<"y is "<<y<<endl;
    int x = n++ + ++n;

    cout<<"x is "<<x<<endl;
    cout<<"n is "<<n<<endl;
    cout<<j<<endl;
    y = 5;
    j = Doub(++y);
    cout<<j<<endl;
    return(0);
}
