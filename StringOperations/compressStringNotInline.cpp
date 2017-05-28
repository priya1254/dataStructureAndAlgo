//Compress string with new string not inline
#include<bits/stdc++.h>
using namespace std;
int main()
{

string str = "aaabbddaabbcc";
string newstr ="";
 char last = str[0];
 int cnt = 1;
for(int i=1;i <str.size(); i++ )
{
   if(str[i]== last)
   {
      cnt++;

   }
   else
   {
        stringstream ss;
        string cnt1;
        ss << cnt;
        cnt1 =ss.str();
        newstr = newstr+last+cnt1;
        last = str[i];
        cnt =1;

   }



}
        stringstream ss;
        string cnt1;
        ss << cnt;
        cnt1 =ss.str();
        newstr = newstr+last+cnt1;

cout<<newstr<<endl;

//inplace changes
cnt = 1;
last = str[0];
int index = 0;
int n = str.size();
for(int i =1;i <str.size();i++)
{
    if(str[i]== last)
   {
      cnt++;

   }
   else
   {
        stringstream ss;
        string cnt1;
        ss << cnt;
        cnt1 =ss.str();
        str = str.substr(0,index)+last+cnt1+str.substr(i,n-cnt);
        last = str[i];
        cnt =1;
        index += 2;

   }



}
stringstream ss1;
string cnt11;
ss1 << cnt;
cnt11 =ss.str();
str = str.substr(0,index)+last+cnt11;


cout<<str<<endl;
str = "aaabbddaabbcc";
last = str[0];
index = 0;
cnt = 1;

for(int i =1;i <str.size();i++)
{
    if(str[i]==last)
        cnt++;
     else
     {
         char curr = str[i];
         str[index] = last;
         string remstr ="";
         while(cnt>0)
         {
             char rem = cnt%10;
             rem = rem + '0';
             cnt = cnt/10;
             remstr = rem +remstr;
         }
         int k = 0;
         while(k < remstr.size())
         {
             str[index+1] = remstr[k];
             k++;
         }
         index+=2;
         last = curr;
         cnt = 1;
     }
}

         str[index] = last;
         string remstr ="";
         while(cnt>0)
         {
             char rem = cnt%10;
             rem = rem + '0';
             cnt = cnt/10;
             remstr = rem +remstr;
         }
         int k = 0;
         while(k < remstr.size())
         {
             str[index+1] = remstr[k];
             k++;
         }

         str.erase(str.begin()+index+2,str.end());
cout<<str<<endl;

}



