//Reverse words in a strin with new strig not inline
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "";
    char a[10]= "";
    a[0] = '5';
    a[1] = '6';
    cout<<a<<endl;
    stringstream ss;
   while(getline(cin,str))
   {
       string str1;
       ss<<str;
       while(getline(ss,str,' '))
       {
//           if(str1 == '')str1 = str1 + str;
          cout<<str<<endl;

           str1 = str + ' ' +str1;
           cout<<"newstr";
           cout<<str1<<endl;

       }

     str1.erase(str1.end()-1);
     cout<<str1<<endl;
   }

return(0);

}


