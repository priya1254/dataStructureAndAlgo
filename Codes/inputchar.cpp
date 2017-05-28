//wap to input characters
#include<bits/stdc++.h>
using namespace std;
int number,number2;
int a1[20];
int source1,source2;
 int a2[20],a3[20];
  int a4[20],a5[20];


 char a[5][5];
  int top=0;
 int count1;
 pair<int,int> s1[20];


int main()
{

    int temp;
    cin>>temp;

    for(int t=1;t<=temp;t++)
   {
       number=0;
       number2=0;
       count1=0;
       int k,k1=0;
     int h,w;
  scanf("%d", &h);
  scanf("%d", &w);
           memset(a1,0,sizeof(a1));
      memset(a2,0,sizeof(a2));
       memset(a3,0,sizeof(a3));
        memset(a4,0,sizeof(a4));
         memset(a5,0,sizeof(a5));
          for(int i=1;i<=4;i++)
     {
         for(int j=1;j<=4;j++)
         {
             a[i][j]=0;}
     }
     for(int i=1;i<=4;i++)
     {
         for(int j=1;j<=4;j++)
         {
             char c1;
             printf("start");
            scanf("%c", &c1);
          //   a[i][j]=c1;

             printf("%c",c1);
             printf("hi");



         }
     }

     cout<<endl<<"hello";
     cout<<number<<number2<<endl;


   }
   return 0;
}


