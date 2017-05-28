#include <bits/stdc++.h>
using namespace std;
long long fact[100001];
long long factorial(long long n)
{
    if(fact[n]) return fact[n];
    if((n == 1) || (n == 0))
    {fact[n] = 1; return fact[n];}
    else
    {
        fact[n] = n * factorial(n-1);
        return fact[n];
    }
}

int main()
{
    int t;
    cin>>t;
    for(int testcase = 0; testcase < t; testcase++)
    {
        memset(fact, 0 ,sizeof(fact));
       long long n,fact;
       cin>>n;
       fact = factorial(n);
       cout<<fact%(1000000000 + 7)<<endl;
    }
        return(0);
}
