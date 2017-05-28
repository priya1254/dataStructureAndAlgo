//make a table of all the unique string, each string has a list of anagrams of string present in the set
#include<bits/stdc++.h>
using namespace std;
int main()
{

    vector<string>s;
        map<string,list<string> > anagrams;
    int n;
    cin>>n;
    string str;
    string str1[] = {"cat","dog","ogd","act","tca","ofg"};
    for(int i = 0 ; i<6; i++)
    {

        s.push_back(str1[i]);
    }

   vector<string> v;
   for(int i = 0; i <s.size(); i++)
   {
     v.push_back(s[i]);
   }

  for(int i = 0; i <s.size(); i++)
   {
     sort(v[i].begin(),v[i].end());
   }

    for(int i = 0; i <v.size(); i++)
   {
     if(anagrams.find(v[i]) == anagrams.end())
     {
         list<string> l1;
         l1.push_back(s[i]);
         anagrams.insert(make_pair(v[i],l1));
     }
     else
     {

     anagrams.find(v[i])->second.push_back(s[i]);
     }


  }


  for(map<string,list<string> >::iterator itr = anagrams.begin(); itr != anagrams.end(); itr++)
  {


   cout<<itr->first<<" ";
   list<string> l2 = itr->second;

   for(list<string>::iterator it = l2.begin(); it != l2.end(); it++ )
   {
       cout<< *it<<" ";
   }
      cout<<endl;
  }


    return(0);
}
