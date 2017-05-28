//Remove chars given in mask from the current string inline
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    string maskstr;
    cin>>maskstr;
    int count[256];
    memset(count,0,sizeof(count));
    for(int i = 0; maskstr[i]!= '\0'; i++)
    {
        count[maskstr[i] -'a']++;

    }
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(count[str[i]-'a'] > 0)
            continue;
        else
            str[j++] = str[i];
    }
    str[j] = '\0';
    cout<<str;
    return(0);
}
