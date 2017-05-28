//code from line no 6 to 18 is taken from geeks for geeks//http://www.geeksforgeeks.org/sieve-of-eratosthenes/
#include <bits/stdc++.h>
using namespace std;
bool prime[100000007];
unsigned long long prime1[100000007];
unsigned long long a1,b1;
unsigned long long k;
void SieveOfEratosthenes(unsigned long long n)
{
    for (unsigned long long p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (unsigned long long i=p*2; i<=n; i += p){
                prime[i] = false;}
        }
    }
    k=1;
     for(unsigned long long i=2;i<=n;i++)
            {
                if(prime[i]==true)
                {
                    prime1[k++]=i;
                }
            }
}
void even(unsigned long long n)
{
    for(unsigned long long i=1;i<k;i++)
            {
                if((2*prime1[i])==n)
                {
                   a1=prime1[i];
                   b1=prime1[i];
                   return;

                 }
                 else
                    {
                        if(prime[n-prime1[i]]==true){
                        a1=prime1[i];
                        b1=n-prime1[i];
                        return;}
                    }
                }


}
int main() {

	unsigned long long t=0;
	memset(prime, true, sizeof(prime));
    SieveOfEratosthenes(100000000);
	cin>>t;

	for(unsigned long long i1=1;i1<=t;i1++)
	{
	    unsigned long long n;
        cin>>n;

        if(n%2==0)
        {
            even(n);
             cout<<"Case #"<<i1<<": "<<" ";
           cout<<a1<<" "<<b1;;
             cout<<"\n";
             continue;

        }
         if(n%2!=0)
        {
           if(prime[n-4]==true)
           {
               unsigned long long num=n-4;
               cout<<"Case #"<<i1<<": "<<" ";
             cout<<"2"<<" "<<"2"<<" "<<num;
             cout<<"\n";
             continue;


           }
           else{

            even(n-3);
             cout<<"Case #"<<i1<<": "<<" ";
           cout<<"3"<<" "<<a1<<" "<<b1;
             cout<<"\n";
               continue;
        }


	}

	}
	return 0;
}




