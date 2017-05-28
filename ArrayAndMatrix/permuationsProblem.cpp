#include <bits/stdc++.h>
using namespace std;
#define FALSE 0
#define TRUE 1
int n,w;
int arr[5];

struct trie
{
    int words;
    int prefixes;
    int no;
    bool bwin;
    bool lwin;
    bool flag;

    struct trie* edges[26];
};

void initialize(struct trie* vertex)
{
    vertex->no=0;
    vertex->words=0;
    vertex->prefixes=0;
     vertex->bwin=FALSE;
      vertex->lwin=FALSE;
      vertex->flag=FALSE;


    for(int i=0;i<26;i++)

    {
        vertex->edges[i]= NULL;
    }



}

void addWord(struct trie* vertex,string word,int count1) {


    if (word.size()==0)
    {

        vertex->words = vertex->words+1;
        vertex->no= count1++;
        //cout<<vertex->no;

        return;

    }

    else {

        vertex->prefixes = vertex->prefixes+1;
        vertex->no= count1++;
        //cout<<vertex->no;

        char k = word[0];
      if (vertex->edges[k-'A']==NULL) {


                                    struct trie* temp=new trie();
                                    initialize(temp);
                                vertex->edges[k-'A'] =temp ;


                                 if(word.size()>1)
             addWord(vertex->edges[k-'A'],word.substr(1),count1);
              else
                 addWord(vertex->edges[k-'A'],"",count1);

                                }
                        else
                        {
                            if(word.size()>1)
                                 addWord(vertex->edges[k-'A'],word.substr(1),count1);
                                  else
                                     addWord(vertex->edges[k-'A'],"",count1);
                        }
        }

return;
}

void func(struct trie* vertex)
{
    int flag=0;

    for(int i=0;i<26;i++){

    if(vertex->edges[i]!=NULL)
    {
        flag=1;
         // cout<<"calling "<<endl;
        func(vertex->edges[i]);
       if((vertex->edges[i]->bwin==0)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==0)&&(vertex->lwin==0))
        {
              vertex->bwin=0;
            vertex->lwin=0;
            if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 1"<<endl;
             continue;

        }
         if((vertex->edges[i]->bwin==0)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==0)&&(vertex->lwin==0))
        {
              vertex->bwin=1;
            vertex->lwin=0;
           if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}

              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 2"<<endl;
              continue;

        }
         if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==0)&&(vertex->lwin==0))
        {
              vertex->bwin=0;
            vertex->lwin=1;
           if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}

              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 3"<<endl;
               continue;

        }
        if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==0)&&(vertex->lwin==0))
        {
              vertex->bwin=1;
            vertex->lwin=1;
              if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 4"<<endl;
               continue;

        }

         if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==1)&&(vertex->lwin==0)&&((vertex->no %2)==1))
        {
              vertex->bwin=1;
            vertex->lwin=0;
             //cout<<"changing flag"<<vertex->flag<<endl;
             vertex->flag=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}



               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 5"<<endl;
              continue;
        }

         if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==1)&&(vertex->lwin==0)&&((vertex->no %2)==0))
        {
              vertex->bwin=1;
            vertex->lwin=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 6"<<endl;
               continue;

        }
          if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==1)&&(vertex->lwin==0)&&((vertex->no %2)==1))
        {
              vertex->bwin=1;
            vertex->lwin=0;
           if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 7"<<endl;
               continue;

        }
        if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==1)&&(vertex->lwin==0)&&((vertex->no %2)==0))
        {
              vertex->bwin=1;
            vertex->lwin=1;
            if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 8"<<endl;
               continue;

        }
         if((vertex->edges[i]->bwin==0)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==1)&&(vertex->lwin==0))
        {
              vertex->bwin=1;
            vertex->lwin=0;



               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 9"<<endl;
               continue;

        }
         if((vertex->edges[i]->bwin==0)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==0)&&(vertex->lwin==1)&&((vertex->no %2)==1))
        {
              vertex->bwin=1;
            vertex->lwin=0;
            vertex->flag=1;
           // cout<<"changing flag"<<vertex->flag<<endl;

              if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}

              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 10"<<endl;
               continue;

        }
         if((vertex->edges[i]->bwin==0)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==0)&&(vertex->lwin==1)&&((vertex->no %2)==0))
        {
              vertex->bwin=1;
            vertex->lwin=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 11"<<endl;
               continue;

        }
         if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==0)&&(vertex->lwin==1))
        {
              vertex->bwin=1;
            vertex->lwin=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 12"<<endl;
              continue;
        }
        if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==0)&&(vertex->lwin==1))
        {
              vertex->bwin=0;
            vertex->lwin=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 13"<<endl;
               continue;

        }


          if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==1)&&(vertex->lwin==1)&&((vertex->no %2)==1))
        {
              vertex->bwin=1;
            vertex->lwin=0;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 14"<<endl;
               continue;

        }
      if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==0)&&(vertex->bwin==1)&&(vertex->lwin==1)&&((vertex->no %2)==0))
        {
              vertex->bwin=1;
            vertex->lwin=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


              // cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
             // cout<<"hi 15"<<endl;
               continue;

        }
        if((vertex->edges[i]->bwin==0)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==1)&&(vertex->lwin==1))
        {
              vertex->bwin=1;
            vertex->lwin=1;
              if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}



               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 16"<<endl;
              continue;

        }
        if((vertex->edges[i]->bwin==1)&&(vertex->edges[i]->lwin==1)&&(vertex->bwin==1)&&(vertex->lwin==1))
        {
              vertex->bwin=1;
            vertex->lwin=1;
             if(vertex->edges[i]->flag==1)
            {vertex->flag=1;}


               //cout<<vertex->no<<" "<<vertex->bwin<<" "<<vertex->lwin<<" ";
              //cout<<"hi 17"<<endl;
              continue;

        }




    }

    }
    if(flag==1)
    {
        return;
    }
    if(flag==0){

        vertex->bwin=1;
        vertex->lwin=0;
        //cout<<vertex->bwin<<" "<<vertex->lwin;
        //cout<<"\n";
        return;
    }



}

void func1(struct trie* vertex)
{
    int flag=0;
    //cout<<"inside func1"<<endl;
    int rem=0;
    //case 1

    for(int i=0;i<26;i++){
 if(vertex->edges[i]!=NULL)
    {
     if((vertex->edges[i]->lwin==0)&&(vertex->edges[i]->flag==1))
      {
        //cout<<endl<<"hiii"<<endl;
      }
      else
      { rem=1;
          break;
      }
    }
    }
    if(rem==0)
        {

        arr[0]=0;
            return;
        }


    for(int i=0;i<26;i++){
 if(vertex->edges[i]!=NULL)
    {
     if(vertex->edges[i]->lwin==1)
      {
          //cout<<"inside if";
          arr[0]=1;
          flag=1;
          return;
      }
    }
    }
    if(flag==0)
        {
            if(n%2==1){
        arr[0]=0;}
        else
        arr[0]=1;
        return;}
}


void func2(struct trie* vertex)
{
     int rem=0;
    //case 1

    for(int i=0;i<26;i++){
 if(vertex->edges[i]!=NULL)
    {
     if((vertex->edges[i]->lwin==0)&&(vertex->edges[i]->flag==1))
      {

      }
      else
      { rem=1;
          break;
      }
    }
    }
    if(rem==0)
        {

        arr[1]=0;
            return;
        }

    int flag1=0;
    int flag2=0;

    //case 2
    for(int i=0;i<26;i++){
       if(vertex->edges[i]!=NULL)
    {
     if(vertex->edges[i]->lwin==TRUE)
      {
          flag1=1;

      }
    if(vertex->edges[i]->bwin==TRUE)
   {
        flag2=1;

   }
}
}
if((flag1==1)&&(flag2==1))
{
    arr[1]=1;
    return;
}
if((flag1==1)&&(flag2==0))
{
   if(n%2==0)
   {
       arr[1]=0;
       return;
   }
   else{
    arr[1]=1;
    return;
    }

}
if((flag1==0)&&(flag2==1))
{

    arr[1]=0;
    return;
}


}

int main() {
	int t=0;
	cin>>t;
for(int i1=1;i1<=t;i1++)
	{   cin>>n>>w;
	memset(arr,0, sizeof(arr));
	    int count=0;
	    struct trie *root=new trie();
	    initialize(root);

	   string a[100005];
	   int ptr=0;

	 for(int i=0;i<w;i++)
        {
           cin>>a[i];



          for (int j=0; j<a[i].length(); ++j){
            a[i][j]=toupper(a[i][j]);}

            addWord(root,a[i],0);

        }
        //scenario1




	    cout<<"Case #"<<i1<<": ";
	    cout<<"\n";
	    int flagp=0;
	    for(int i=0;i<26;i++)
        {

          if(root->edges[i]!=NULL){
            if((root->edges[i]->words)>0)
            {
                struct trie*temp=root->edges[i];
                root->edges[i]=NULL;
                flagp=1;
            }
            else{
                flagp=0;
                break;}

        }
        }
        if(flagp==1)
        {
            if(n%2==0)
            {
                arr[0]=1;
            }
            else{

                arr[0]=0;
            }
            arr[1]=0;
            if(arr[0]==1)
          {
              arr[2]=0;
          }
          else
            arr[2]=1;
             if(arr[1]==1)
          {
              arr[3]=0;
          }
          else
            arr[3]=1;

          for(int i=0;i<4;i++)
          {
              if(arr[i]==1)
              {
                  cout<<"victory";
                  cout<<"\n";
              }
              else
              {
                 cout<<"defeat";
                  cout<<"\n";
              }
          }
        continue;
        }



        func(root);
      //  cout<<"hello";
        func1(root);
       // cout<<"hello 1";
        func2(root);
      //  cout<<"hello 2";

          if(arr[0]==1)
          {
              arr[2]=0;
          }
          else
            arr[2]=1;

          if(arr[1]==1)
          {
              arr[3]=0;
          }
          else
            arr[3]=1;

          for(int i=0;i<4;i++)
          {
              if(arr[i]==1)
              {
                  cout<<"victory";
                  cout<<"\n";
              }
              else
              {
                 cout<<"defeat";
                  cout<<"\n";
              }
          }



       }
	return 0;
}



