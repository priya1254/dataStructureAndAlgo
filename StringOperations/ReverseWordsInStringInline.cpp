//Reverse words in a string inline
#include<bits/stdc++.h>
using namespace std;
void reversestring(char *beg,char *end)
{

    char temp;
    while(beg<end)
    {
        temp = *beg;
        *beg = *end;
        *end = temp;
        beg++;
        end--;
    }



}
int main()
{
    string str1;

    string str2;
    str2[0] = 'p';
    cout<<str2<<endl;
    string str3;
    for(int i = 0; i < 3; i++)
    {
        str3[i] = 'a';
    }
    cout<<str3<<endl;
//    char str4[4];
//    for(int i = 0; i < 2; i++)
//    {
//        str4[i] = 'a';
//    }
//    cout<<str4;
    char str4[4];
    for(int i = 0; i < 2; i++)
    {
        str4[i] = 'a';
    }
 cout<<str4<<endl;
    getline(cin,str1);
    int len = str1.size();
    char str[len+1];
//    //int k = str1.copy(str,len,0);
//    char *p;
//    p = str1.c_str();
    strcpy(str,str1.c_str());

    str[len] = '\0';
    char *beg = str;
    char *end = str;

    while(*end != '\0')
    {

        end++;
        while( *end != '\0'  && *end != ' ')
        {
            end++;

        }
          cout<<str<<endl;
          reversestring(beg,end-1);
          beg = end+1;
          cout<<*end<<endl;

    }
    beg = str;
    end -= 1;
     reversestring(beg,end);
     cout<<str;
    return(0);
}
