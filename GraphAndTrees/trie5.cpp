//Trie implementation
#include <bits/stdc++.h>
using namespace std;
long visited[100005];
long rep[100005][2];
#define FALSE 0
#define TRUE 1

struct trie
{
    int words;
    int prefixes;
    bool bwin;
    bool lwin;
    struct trie* edges[26];
};

void initialize(struct trie* vertex)
{
    vertex->words=0;
    vertex->prefixes=0;
     vertex->bwin=FALSE;
      vertex->lwin=FALSE;

    for(int i=0;i<26;i++)

    {
        vertex->edges[i]= NULL;
    }



}

void addWord(struct trie* vertex,string word,bool bwin,bool lwin) {

    if (word.size()==0)
    {
        vertex->bwin=bwin;
        vertex->lwin=lwin;
        vertex->words = vertex->words+1;

        return;

    }

    else {

        vertex->prefixes = vertex->prefixes+1;
        vertex->bwin=bwin;
        vertex->lwin=lwin;

        char k = word[0];
      if (vertex->edges[k-'A']==NULL) {


                                    struct trie* temp=new trie();
                                    initialize(temp);
                                vertex->edges[k-'A'] =temp ;


                                 if(word.size()>1)
             addWord(vertex->edges[k-'A'],word.substr(1),bwin,lwin);
              else
                 addWord(vertex->edges[k-'A'],"",bwin,lwin);

                                }
                        else
                        {
                            if(word.size()>1)
                                 addWord(vertex->edges[k-'A'],word.substr(1),bwin,lwin);
                                  else
                                     addWord(vertex->edges[k-'A'],"",bwin,lwin);
                        }
        }

return;
}

void func(struct trie* vertex,bool lea)
{
    int flag=0;
    for(int i=0;i<26;i++){
    if(vertex->edges[i]!=NULL)
    {
        flag=1;
     if(vertex->edges[i]->lwin==TRUE &&  vertex->edges[i]->bwin==FALSE)
      {
          func(vertex->edges[i],lea);
          return;
      }
    else if(vertex->edges[i]->lwin==TRUE &&  vertex->edges[i]->bwin==TRUE)
      {
          func(vertex->edges[i],lea);
          return;
      }
    else if (vertex->edges[i]->lwin==FALSE )
      {
          func(vertex->edges[i],lea);
          return;
      }
  }
    }
    if(flag==0)
    {
        lea=vertex->lwin;
        return;
    }
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
	int t=0,n,w;
	cin>>t;
for(int i1=1;i1<=t;i1++)
	{   cin>>n>>w;
	    int count=0;
	    struct trie *root=new trie();
	    initialize(root);

	   string a[100005];
       bool bwin,lwin;
	 for(int i=0;i<w;i++)
        {
           cin>>a[i];
           if(a[i].length()%2==0){
           bwin=FALSE;
           lwin=TRUE;
           }
           else{
               bwin=TRUE;
           lwin=FALSE;
           }


          for (int j=0; j<a[i].length(); ++j){
            a[i][j]=toupper(a[i][j]);}

            addWord(root,a[i],bwin,lwin);

        }
        //scenario1




	    cout<<"Case #"<<i1<<": ";
	    bool lea;
        func(root,lea);
           cout<<lea;
             cout<<"\n";

       }
	return 0;
}


