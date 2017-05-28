//Check any anagram of string is a palindrome or not
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int count[26];
    memset(count,0,sizeof(count));
    memset(count,0,sizeof(count));
    for(int i = 0; str[i]!= '\0'; i++)
    {
        count[str[i]-'a']++;

    }
    int oddocuurance = 0,flag = 1;
    for(int i = 0;i < 26; i++)
    {
        if(count[i] % 2 != 0)
        {
            oddocuurance++;
            if(oddocuurance > 1)
                {
                    cout<<"false";
                    flag = 0;
                    break;

                }
        }

    }

    if(flag == 1)
        cout<<"true";
    return(0);
}
