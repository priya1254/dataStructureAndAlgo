//String Operations
#include<bits/stdc++.h>
using namespace std;
int main()
{

map<string,int> cnt;
string str;
getline(cin,str);
stringstream ss(str);
map<string,int>:: iterator it;
string s1;
while(getline(ss,s1,','))
{


    if(cnt.find(s1)!= cnt.end())
    {
        it = cnt.find(s1);
        it->second = it->second +1;
    }
    else
        cnt.insert(make_pair(s1,1));

}
string word;
cout<<"enter word whose frequency need to be calculated"<<endl;
cin>>word;
if(cnt.find(word)!= cnt.end())
    cout<<"frequency of the word"<<cnt[word]<<endl;
else
    cout<<"word not found"<<endl;
string word1,word2;
word1 = "rajsrikumarsrivastava";
word2= "sri";
//std::transform(word.begin(), word.end(),word.begin(),  [](unsigned char c) { return std::toupper(c); });
//cout<<"string in upper"<<word<<endl;
string wordconcat = word1+word2;
cout<<"concatenated strings"<<wordconcat<<endl;
int count1 = 0;
size_t found = word1.find(word2);
if(found)count1++;
size_t f1 = word1.find("sri",found+1,3);
if(f1)count1++;
cout<<"string found"<<count1<<endl;

int len = word1.length();
char chrarray[len+1];
char chrarray2[len +1];
cout<<"copying hiii"<<endl;
word1.copy(chrarray,len-1,1);
cout<<"hiii"<<endl;
chrarray[len] = '\0';
cout<<"copied string to array"<<chrarray<<endl;
if(word2.compare("sri")==0)
    cout<<"strig comparison :word found"<<endl;
word1.append(word2,0,2);
cout<<"strig append"<<word1<<endl;
string newstr = "sri";
word1.insert(5,newstr);
cout<<"strig insert"<<word1<<endl;
word1.erase(2,5);
cout<<"strig erase"<<word1<<endl;
string str3 = word1.substr(2,3);
cout<<"strig substring"<<str3<<endl;
strcpy(chrarray2,chrarray);
cout<<" cstring copy"<<chrarray2<<endl;
int i = strcmp(chrarray,chrarray2);
cout<<"two chararray are equal greater smaller"<<i<<endl;
cout<<"length is chrarray "<<strlen(chrarray);
char *chrconcat = strcat(chrarray,chrarray2);
cout<<"cstrig concat"<<chrconcat<<endl;
int k = strtol("16",NULL,16);
cout<<"hex--"<<k<<endl;
char ints[10] = "15";
int integer = atoi(ints);
cout<<"atoi integer"<<integer<<endl;
string str4 = "abc,ewfij,frfr.erf.erg:efe:";
str4.replace(3,3,"def");
cout<<"strig replace"<<str4<<endl;
int len2 = str4.length();
char chr[len2+1];
strcpy(chr,str4.c_str());
char *pch=strtok(chr,",.:");
while(pch!=NULL)
{
    cout<<"string without tokens"<<pch<<endl;
    pch =strtok(NULL,",.:");

}

//strrep(chr,"dfg");
//cout<<"replaces charray with character is "<<chr<<endl;
int val = 15;
//string tostr = std::to_string(val);
//cout<<"to_string function"<<tostr<<endl;


return(0);
}
