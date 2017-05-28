#include <bits/stdc++.h>
using namespace std;
struct node
{
   int info;
   struct node *left;
   struct node *right;
};
struct node *root;
int depth(struct node *root)
{
   if(root == null)
   {
       return 0;
   }
   else
    return(1+max(depth(root->left),depth(root->right)));
}
int diameter(struct node *root)
{
   if(root == null)
   {
       return 0;
   }
   else
   {
        ldia=diamter(root->left);
        rdia=diameter(root->right);
        return(max(max(ldia,rdia),depth(root)));
    }
}
int main()
{


return(0);
}

