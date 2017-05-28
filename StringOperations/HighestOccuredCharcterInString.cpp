//Find te character which occured most number of times in a string
#include<bits/stdc++.h>
using namespace std;
int main()
{

string str;
getline(cin,str);
int freq[26];
memset(freq,0,sizeof(freq));
int i = 0,max1 = 0;
char ch;
while(str[i] != '\0')
{
    freq[str[i]-'a']++;
    if (freq[str[i]-'a'] > max1)
    {
         max1 = freq[str[i]-'a'];
         ch = str[i];
    }
    i++;
}
cout<<ch<<" "<<max1;
return(0);
}

