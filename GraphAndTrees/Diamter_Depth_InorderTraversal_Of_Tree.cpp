#include <bits/stdc++.h>
using namespace std;
struct node
{
   int info;
   struct node *left;
   struct node *right;
};

int depth(struct node *root)
{
   if(root == NULL)
   {
       return 0;
   }
   else
    return(1+max(depth(root->left),depth(root->right)));
}
int diameter(struct node *root)
{
   if(root == NULL)
   {
       return 0;
   }
   else
   {
        int ldia = diameter(root->left);
        int rdia = diameter(root->right);
        return(max(max(rdia, ldia),depth(root->left)+depth(root->right)+1));


    }
}

void inorder(struct node *root)
{
    cout<<"inorder traversal"<<endl;
    if(root == NULL)return;
    else
    {
        if(root->left)inorder(root->left);
        cout<<root->info;
        if(root->right)inorder(root->right);
        return;
    }
}

int main()
{

        struct node *temp,*ptr;
        struct node *root;
        string s;
        int data;
        int n,x;
        //ptr = NULL;

        cin>>n>>x;
        root = (struct node*)malloc(sizeof(struct node));
        root->info = x;
        root->left = NULL;
        root->right = NULL;
        n--;
    while(n)
    {

        cin>>s;
        cin>>data;

        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = data;
        temp->left = NULL;
        temp->right = NULL;
        int len = s.size();
        char ch[len+1];
        ptr = root;
        int i = 1;
        strcpy(ch,s.c_str());
        char c = ch[0];
        while(c !='\0')
            {
                if(c=='L' )
                   {  if(ptr->left == NULL)
                       {ptr->left = (struct node*)malloc(sizeof(struct node));
                       ptr->left->info = 0;ptr->left->left = NULL;
                       ptr->left->right = NULL;}
                       ptr = ptr->left;}
               else
                    {  if(ptr->right == NULL)
                       {ptr->right = (struct node*)malloc(sizeof(struct node));
                       ptr->right->info = 0;ptr->right->left = NULL;
                       ptr->right->right = NULL;}
                       ptr = ptr->right;}

                    c = ch[i++];
            }
            ptr->info = data;
        n--;
    }

  //printtree
  inorder(root);
  cout<<"depth of tree is "<<depth(root);
   cout<<"diameter of tree is "<<diameter(root);
return(0);
}

