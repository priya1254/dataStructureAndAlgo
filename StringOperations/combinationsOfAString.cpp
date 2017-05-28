//Combination Of a string
#include <bits/stdc++.h>
using namespace std;
int max1,valid;



void checkstring(char str[12])
{
    //cout<<"inside checkstring"<<endl;
    int count1=0;
    for(int i=0;i<11;i++)
    {
       if(str[i]=='G')
       {
          count1++;

          if(count1>1)
          { //cout<<"hi g >1"<<endl;
              valid=0;
              return;
          }
       }
    }
    if(count1==0)
    {valid=0;
        return;
    }
   if((str[6]=='D')&&(str[5]=='D'))
   {

      valid=0;
      return;

   }
   if((str[7]=='D')&&(str[4]=='D'))
   {

      valid=0;
      return;

   }
   if((str[8]=='D')&&(str[3]=='D'))
   {

      valid=0;
      return;

   }
   if((str[9]=='D')&&(str[2]=='D'))
   {

      valid=0;
      return;

   }
   if((str[10]=='D')&&(str[1]=='D'))
   {

      valid=0;
      return;

   }
    if((str[6]=='M')&&(str[5]=='M'))
   {

      valid=0;
      return;

   }
   if((str[7]=='M')&&(str[4]=='M'))
   {

      valid=0;
      return;

   }
   if((str[8]=='M')&&(str[3]=='M'))
   {

      valid=0;
      return;

   }
   if((str[9]=='M')&&(str[2]=='M'))
   {

      valid=0;
      return;

   }
   if((str[10]=='M')&&(str[1]=='M'))
   {

      valid=0;
      return;

   }
    if((str[6]=='S')&&(str[5]=='S'))
   {

      valid=0;
      return;

   }
   if((str[7]=='S')&&(str[4]=='S'))
   {

      valid=0;
      return;

   }
   if((str[8]=='S')&&(str[3]=='S'))
   {

      valid=0;
      return;

   }
   if((str[9]=='S')&&(str[2]=='S'))
   {

      valid=0;
      return;

   }
   if((str[10]=='S')&&(str[1]=='S'))
   {

      valid=0;
      return;

   }

    valid=1;
    return;

}
void generatestring(int j,vector<char>v[12],char str[12])
{
    if(j==11)
    {

        checkstring(str);
           if(valid==1)
              {
                   //cout<<str<<endl;
                  max1++;
                  //cout<<"value of max"<<max1<<endl;
              }
        return;
    }
    for(int i=0;i<v[j].size();i++)
    {
        //cout<<"i is"<<i<<endl;
        //cout<<"size of j is"<<j<<"----->"<<v[j].size()<<endl;
        //cout<<"hello "<<v[j][i]<<" "<<endl;
        str[j]=v[j][i];
        generatestring(++j,v,str);
         j=j-1;
        //cout<<"j is"<<j<<"  i is "<<i<<endl;
    }
    //cout<<"hi---"<<endl;
    return;
}

int main() {
	int t=0;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
       {
        char str[5];
        char s[12];
        s[11]= '\0';
        max1=0;
       valid=0;
       vector<char> v[12];
       for(int i=0;i<11;i++)
       {
           cin>>str;
           for(int j=0;j<strlen(str);j++)
           {
               // cout<<str[j]<<" ";
                v[i].push_back(str[j]);
           }
       }
       //cout<<endl;

       generatestring(0,v,s);
       cout<<"Case #"<<i1<<": "<<max1;
        cout<<"\n";

	}
return 0;
}


