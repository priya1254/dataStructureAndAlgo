//Find first non repeating character in a string
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int count[26];
    memset(count,0,sizeof(count));

    for(int i = 0; str[i]!= '\0';i++)
    {
        count[str[i]-'a']++;
    }
     for(int i = 0; str[i]!= '\0';i++)
    {
        if(count[str[i]-'a'] == 1)
            cout<<str[i]<<endl;
    }


    return(0);
}
