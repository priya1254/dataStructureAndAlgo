//code from line no 5 to 29 and 52 to 66 is taken from https://comeoncodeon.wordpress.com/category/algorithm/
//code from line no 30 to 48 is taken from geeks for geeks//http://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b, long long MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n, long long MOD)
{
    return pow(n,MOD-2,MOD);
}
long long findMinX(long long num[], long long rem[], long long k)
{
    // Compute product of all numbers
    long long prod = 1;
    for (long long i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    long long result = 0;

    // Apply above formula
    for (long long i = 0; i < k; i++)
    {
        long long pp = prod / num[i];
        result += rem[i] * InverseEuler(pp, num[i]) * pp;
    }

    return result % prod;
}



long long C(long long n, long long r, long long MOD)
{
    vector<long long> f(n + 1,1);
    for (long long i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
long long Lucas(long long n, long long m, long long p)
{
    if (n==0 && m==0) return 1;
    long long ni = n % p;
    long long mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * C(ni, mi, p);
}
int main() {

	long long t=0;
	cin>>t;

	for(long long i1=1;i1<=t;i1++)
	{
	    long long n,m;
        cin>>n>>m;
        long long a1=0;
         long long rem[10];
       memset(rem, 0, sizeof(rem));

       long long num[10]={2,3,5,7,11,13,17,19,23};


       for(int i=0;i<9;i++)
       {
           rem[i]=Lucas(n, m, num[i]);
       }


         cout<<"Case #"<<i1<<": "<<" ";

           cout<<findMinX(num, rem, 9);
             cout<<"\n";

	}


	return 0;
}




