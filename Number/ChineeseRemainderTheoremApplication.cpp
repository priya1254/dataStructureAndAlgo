//code from line no 5 to 29 and 52 to 66 is taken from https://comeoncodeon.wordpress.com/category/algorithm/
//code from line no 30 to 48 is taken from geeks for geeks//http://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/
#include <bits/stdc++.h>
using namespace std;

unsigned long long findMinX(unsigned long long num[], unsigned long long rem[], unsigned long long k)
{
    unsigned long long x = num[0]; // Initialize result

    // As per the Chinise remainder theorem,
    // this loop will always break.
    while (true)
    {
        // Check if remainder of x % num[j] is
        // rem[j] or not (for all j from 0 to k-1)
        unsigned long long j;
        for (j=0; j<k; j++)
            if (x%num[j] != rem[j])
               break;

        // If all remainders matched, we found x
        if (j == k)
            return x;
 // Else try next numner
        x+=num[0];
    }

    return x;
}



int main() {

	unsigned long long t=0;
	cin>>t;

	for(unsigned long long i1=1;i1<=t;i1++)
	{
	    unsigned long long n;
        cin>>n;
        unsigned long long r;
         unsigned long long num[1001];
        for(unsigned long long i=0;i<n;i++)
        {
            cin>>num[i];
        }
         unsigned long long rem[1001];
          unsigned long long rem1[1001];
          unsigned long long a,b;


      memset(rem, 0, sizeof(rem));
       memset(rem1, 0, sizeof(rem1));
        for(unsigned long long i=0;i<n;i++)
        {
            r=i%num[i];
            if(r==0)
            {
                rem[i]=0;
            }
            else rem[i]=num[i]-r;
        }

          a=findMinX(num, rem, n);
          b=findMinX(num, rem1, n);
         cout<<"Case #"<<i1<<": "<<" "<<a<<" "<<b;
        cout<<"\n";

	}


	return 0;
}




