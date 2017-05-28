#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)

class Trie {
    public:
        int words;
        int prefixes;
        Trie* edges[26];
        Trie();
        void addWord(string word);
        int countWords(string word);
        int countPrefixes(string prefix);
};

Trie::Trie() {
    words = 0;
    prefixes = 0;
    for(int i=0;i<26;++i){
        edges[i] = NULL;}
}

void Trie::addWord(string word) {
    if (word.size()==0)
        words = words+1;
    else {
        prefixes = prefixes+1;
        char k = word[0];
        if (edges[k-'A']==NULL) {
            edges[k-'A'] = new Trie();
        }
        edges[k-'A']->addWord(word.substr(1));
    }
}

int Trie::countPrefixes(string prefix) {
    if (prefix.size()==0)
        return prefixes;
    else {
        char k = prefix[0];
        if (edges[k-'A']==NULL)
            return 0;
        else {
            return edges[k-'A']->countPrefixes(prefix.substr(1));
        }
    }
}

int main() {
    cout<<"helloz    1";
    Trie *root=new Trie();
    int t=0;
	//long n;


	cin>>t;

 cout<<"helloz    8";
	for(int i1=1;i1<=t;i1++)
	{
	    //cin>>n;
	    /*string a[10001];

	    for(int i=0;i<n;i++)
        {
           getline (cin, a[i]);
            root.addWord(a[i]);
           cout<<"hi";
        }
    */
    cout<<"helloz";
    root->addWord("Bob");
    cout<<"helloz";
    root->addWord("Bobbby");
    root->addWord("Boba");
    root->addWord("charles");
    root->addWord("charly");
    root->addWord("julia");
    root->addWord("julian");
   cout<<"helllloooo";

	    cout<<"Case #"<<i1<<": ";
     //for(int i=0;i<n;i++)
       // {
           cout<<root->countPrefixes("Bob");
             cout<<"\n";


       // }


	    cout<<"\n";

	}

	return 0;
}
