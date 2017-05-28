
//string to number
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{

   int temp;
   char msg[200];
   cin>>temp;
   int number;
   int k=0;
   int arr[200];
   int flag;
   for(int t=1;t<=temp;t++)
   {
       flag=0;
       int f=0;
    cout << int('\n');
     while(flag==0)
     {
         cin>>msg[f];
         cout<< int('\n');
         if(msg[f]==10)
         {
           flag=1;
         }

            f++;

     }
     int p=0;
     int j=0;
     while(msg[p]!='#')
     {
         arr[j]=msg[p]-'0';
         cout<<msg[p];
         cout<<arr[j];
         p++;
         j++;
     }
     cout<<p;
     if(p==1)
     {
      number=arr[0];
     }
     if(p==2)
     {
         number=(10*arr[0])+arr[1];

     }
     if(p==3)
     {
         number=(100*arr[0])+(10*arr[1])+arr[2];
     }
     cout<<number;
     int len=0;
     len=strlen(msg);

cout<<"Case #"<<t<<":";

     for(int i=number+1;i<len;i++)
     {

        cout<<msg[i];

     }
     for(int q=p+1;q<=number;q++)
     {
         cout<<msg[q];

     }
     }
   return(0);
}//end of func





