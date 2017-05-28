#include <bits/stdc++.h>
using namespace std;
long visited[100005];
long rep[100005][2];

struct trie
{
    int words;
    int prefixes;
    struct trie* edges[26];
};

void initialize(struct trie* vertex)
{
    vertex->words=0;
    vertex->prefixes=0;
    for(int i=0;i<26;i++)

    {
        vertex->edges[i]= NULL;
    }



}

void addWord(struct trie* vertex,string word) {

    if (word.size()==0)
    {
        vertex->words = vertex->words+1;

        return;

    }

    else {

        vertex->prefixes = vertex->prefixes+1;

        char k = word[0];
      if (vertex->edges[k-'A']==NULL) {


                                    struct trie* temp=new trie();
                                    initialize(temp);
                                vertex->edges[k-'A'] =temp ;


                                 if(word.size()>1)
             addWord(vertex->edges[k-'A'],word.substr(1));
              else
                 addWord(vertex->edges[k-'A'],"");

                                }
                        else
                        {
                            if(word.size()>1)
                                 addWord(vertex->edges[k-'A'],word.substr(1));
                                  else
                                     addWord(vertex->edges[k-'A'],"");
                        }
        }

return;
}
int countPrefixes(struct trie* vertex , string prefix) {


    if (prefix.size()==0)
    {

        return vertex->prefixes;}
    else {
        char k = prefix[0];
        if (vertex->edges[k-'A']==NULL)
            return 0;
        else {
                if(prefix.size()>1)
                {
               if(vertex->edges[k-'A']->prefixes==1)
               {
                   return 0;
               }
            return countPrefixes(vertex->edges[k-'A'],prefix.substr(1));


            }
              else
              {

                return countPrefixes(vertex->edges[k-'A'],"");

              }
        }
    }
}


int main() {
	int t=0,n;
	cin>>t;
for(int i1=1;i1<=t;i1++)
	{int count=0;
	    struct trie *root=new trie();
	    initialize(root);
	    cin>>n;
	   string a[100005];

	 for(int i=0;i<n;i++)
        {
           cin>>a[i];

          for (int j=0; j<a[i].length(); ++j){
            a[i][j]=toupper(a[i][j]);}

            addWord(root,a[i]);

        }


	    cout<<"Case #"<<i1<<": ";

         for(int i=0;i<n;i++)
        {

          int r=countPrefixes(root,a[i]);
          if(r>0)
          {count++;}

        }
           cout<<count;
             cout<<"\n";

       }
	return 0;
}


