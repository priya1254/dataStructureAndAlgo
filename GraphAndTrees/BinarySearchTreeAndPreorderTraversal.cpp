//binary search tree and preorder traversal of a tree
#include <bits/stdc++.h>
using namespace std;
struct node
{
   long info;
   struct node *left;
   struct node *right;
};

void preorder(struct node *root)
{
  if(root == NULL) return;
  cout<<root->info<<endl;
  preorder(root->left);
  preorder(root->right);
}

void find_loc(struct node *root, struct node **par, struct node ** loc, long item)
{
   if(root == NULL) return;
   struct node *ptr, *ptrsave;
   ptr = ptrsave = root;
   while(ptr!= NULL)
   {
   ptrsave = ptr;
   if(item == ptr->info) { *loc = ptr; *par = ptrsave; return;}
   if(item < ptr->info)   ptr = ptr->left;
   else ptr = ptr->right;
   }
    *par = ptrsave;
}
int main()
{
 long n,q,data;
 cin>>n;
 struct node *root, *par,*loc;
 root = NULL;
 for(long i = 0; i < n; i++)
 {
        cin>>data;
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = data;
        temp->left = NULL;
        temp->right = NULL;
        par = loc = NULL;
        find_loc(root, &par, &loc, data);
        if(par == NULL) {root =  temp; continue;}
        if(data < par->info) {par->left = temp; }
        else{par->right = temp;}

 }
        cin>>q;
        find_loc(root,&par,&loc,q);
        //cout<<par->info;
        preorder(loc);
return(0);
}

