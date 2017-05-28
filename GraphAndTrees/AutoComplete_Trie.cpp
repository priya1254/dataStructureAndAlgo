//implement auto complete feature trie
#include <bits/stdc++.h>
using namespace std;
struct node
{
   struct node *link[26];
   long weight;
};
struct node *root;
void initialize(struct node *temp , long wt)
{
    for(long i = 0; i < 26; i++){temp->link[i] = NULL;}
    temp->weight = wt;
}
void add_word(struct node *root, string word, long wt)
{
    struct node *ptr = root;

     if( ptr->weight < wt) ptr->weight = wt;

    if(ptr->link[word[0]-'a'] == NULL)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        initialize(temp ,wt);
        ptr->link[word[0]-'a'] = temp;
    }
    else
    {
        if( ptr->weight < wt) ptr->weight = wt;
    }
    if(word.size() == 1) return;
    else add_word(ptr->link[word[0]-'a'], word.substr(1), wt);
}

void check(struct node *root,string word)
{

  if(root->link[word[0]-'a'] == NULL) {cout<<"-1"<<endl;return;}
  if(word.size() == 1) {cout<< root->link[word[0]-'a']->weight<<endl;return;}
  else check(root->link[word[0]-'a'], word.substr(1));
}

int main()
{
long n,q;
cin>>n>>q;
root = (struct node*)malloc(sizeof(struct node));
initialize(root, 0);
 while(n)
 {
     string word;
     long wt;
     cin>>word>>wt;
     add_word(root,word,wt);
     n--;
 }
 while(q)
 {
     string checkword;
     cin>>checkword;
     check(root,checkword);
     q--;
 }
return(0);
}

