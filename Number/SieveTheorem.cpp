//code from line no 6 to 18 is taken from geeks for geeks//http://www.geeksforgeeks.org/sieve-of-eratosthenes/
#include <bits/stdc++.h>
using namespace std;
bool prime[100000007];
unsigned long long prime1[100000007];
unsigned long long visited[100000007];
unsigned long long k;
int ar[10];


unsigned long long x=0;
double r;
int s;
unsigned long long count1;
int flag=0;
int h;
int flagr=0;




void check(int arr1[10])
{
   s=0;
   x=0;
  while(s<h)
  {
      x=x*10+arr1[s];
      s++;
  }
   //cout<<"permuted no"<<x<<endl;
   if(prime[x]==false)
   {
       flagr=1;
   }
  if((prime[x]==true)&&(visited[x]==false))
  {
      count1=count1+1;
  }

   visited[x]=true;
   //cout<<"r is "<<r;
   //cout<<"count1 is"<<count1<<endl;
  if(count1>r)
         {

             flag=1;
             return;
         }


}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a, int l, int r)
{
   unsigned long long i;
    s=0;
   x=0;
  while(s<h)
  {
      x=x*10+a[s];
      s++;
  }
  if(visited[x]==true)
  {
      return;
  }

   if (l == r){
      check(a);
     if(flag==1)
        {
            return;
        }
     }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }

}



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

int main() {

	unsigned long long t=0;
	memset(prime, true, sizeof(prime));
    SieveOfEratosthenes(100000000);
	cin>>t;

	for(unsigned long long i1=1;i1<=t;i1++)
	{
	    unsigned long long n,n1;
        cin>>n;
        unsigned long long a1=0;
       memset(visited, false, sizeof(visited));
       n1=n;
       while(n1>0)
        {
            n1=n1/10;
           a1=(a1*10)+9;
        }
        //cout<<a1<<endl;


     unsigned long long max1,t1,t2;

       for(unsigned long long q=1;q<k;q++)
       {
           if(prime1[q]<=n)
                {
                    continue;
                }
                else
                {
                   t1=q;
                   break;

                }
      }

     unsigned long long i;

     for(unsigned long long j=t1;prime[j]<=a1;j++)
     {
         i=prime1[j];
        //cout<<"hello"<<i<<endl;

        memset(ar, 0, sizeof(ar));
         h=0;
         count1=0;
         if((prime[i]==true)&&(visited[i]==false))
         {
             flag=0;
             int w=0;
             //cout<<"hello 2"<<endl;
             unsigned long long i1=i;
        while(i1>0)
        {
            w=i1%10;
            i1=i1/10;
           ar[h++]=w;

        }

          r=log10(i);
          flagr=0;
          permute(ar, 0, h-1);
          if(flagr==0)
          {
               max1=i;
               //cout<<"hi"<<endl;
             break;
          }

          if(count1>r)
         {
             max1=i;
             break;
         }

         }

     }
         cout<<"Case #"<<i1<<": "<<" ";
           cout<<max1;
             cout<<"\n";

	}


	return 0;
}




