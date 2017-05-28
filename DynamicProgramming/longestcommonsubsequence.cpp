#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b)? a : b;
}
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int main() {
	int t=0;
	int profite;


	cin>>t;

	for(int i1=1;i1<=t;i1++)
	{
      char X[251],Y[251];


       cin>>X>>Y;
       int m = strlen(X);
       int n = strlen(Y);
       int max=0;


   char rev[251];
          for(int s=0,l=n-1;s<n;s++,l--)
          {
              rev[s]=Y[l];


          }


              profite=lcs( X, Y, m, n ) ;

          if(profite>max)
          {
             max= profite;

          }
           profite=lcs( X,rev, m, n ) ;
           if(profite>max)
          {
             max= profite;

          }

          for(int count=1;count<=2;count++)
          {

          for(int j=0;j<n;j++)
          {
              int k=0;
              char z[251];
          for(int i=0;i<n;i++)
          {

              if(i==n-1)
          {
              z[k++]=Y[0];
          }
          else
          {

              z[k++]=Y[i+1];

          }
          }


              profite=lcs( X, z, m, n ) ;

          if(profite>max)
          {
             max= profite;

          }
         for(int r=0;r<n;r++)
         {
             Y[r]=z[r];
         }

          }
           for(int r=0;r<n;r++)
         {
             Y[r]=rev[r];
         }

          }





    profite=max;


	    cout<<"Case #"<<i1<<": "<<profite;

	    cout<<"\n";

	}

	return 0;
}

