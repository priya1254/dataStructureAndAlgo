//break given string into dictionary words stored in dict.
#include<bits/stdc++.h>
using namespace std;
set<string> dict;
void breakinwords(string str, string out)
{
    int n = str.size();
    for(int i= 0; i <n; i ++ )
    {
        string prefix = str.substr(0,i+1);
        cout<<prefix<<endl;
        if(dict.find(prefix) != dict.end())
        {

            if(i == n-1)
            {
                out = out +prefix;
                cout<<out<<endl;
                return;
            }
            string suffix = str.substr(i+1,n-i-1);
            breakinwords(suffix,out+ prefix + " ");
        }

    }


    return;
}

int main()
{
    string str;
    cin>>str;

     string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    for(int i = 0; i < 13;i ++)
    {
        dict.insert(dictionary[i]);
    }
    breakinwords(str,"");



    return(0);
}
