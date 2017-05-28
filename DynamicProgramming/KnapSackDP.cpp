#include <bits/stdc++.h>
using namespace std;
 int K[10000][10000];
 int keep[10000][10000];

struct node
{
 long p;
 long l;
 long s;
};

int knapSack(int W, struct node a[], int n)
{
   int i, w;
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           K[i][w]=0;
           keep[i][w]=0;
       }
   }
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0){
               K[i][w] = 0;
              // cout<<K[i][w]<<" ";
              }
           else if ((a[i-1].l <= w)&&((a[i-1].s + K[i-1][w-a[i-1].l])>K[i-1][w])){
                 K[i][w] = a[i-1].s + K[i-1][w-a[i-1].l] ;
                 keep[i][w]=1;
                //cout<<K[i][w]<<" ";
           }
           else
                 {
                     K[i][w] = K[i-1][w];
                 keep[i][w]=0;
                      //cout<<K[i][w]<<" ";
                 }

       }
       //cout<<endl;
   }

   return K[n][W];
}


int main() {
	int t=0;
	long n,W;


	cin>>t;

	for(int i1=1;i1<=t;i1++)
	{
	    cin>>W;
	    cin>>n;
	    struct node a[10000];
	    int l1,p1,s1;
	    memset(a,0,sizeof(a));
        int r=0,z=1;
        int j;
	    for(long i=0;i<n;i++)
        {
            cin>>p1;
            cin>>l1;
            cin>>s1;
            for(j=r;j<p1+r;j++)
            {
                a[j].p=z;
                a[j].l=l1;
                a[j].s=s1;

            }
            r=j;
            z++;

        }
    n=r;


int sum =knapSack(W, a, n);

int len=W;
int f=0;
int a1[10000];
memset(a1,0,sizeof(a1));
   for(int i=n;i>=0;i--)
   {
       if(keep[i][len]==1)
       {
           len=len-a[i-1].l;
          // cout<<a[i-1].p;
           //cout<<endl;
           a1[f++]=a[i-1].p;
       }
   }

	    cout<<"Case #"<<i1<<": ";
	    for(long i=f-1;i>=0;i--)
        {
            cout<<a1[i]<<" ";
        }
	    cout<<"\n";

	}

	return 0;
}


