/** Knuth Morris Pattern Matching, Time Complexity : O(m+n)
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
void suffix_prefix(vector<int> &spa,string pattern){

    for(int i=0,j=1;j<pattern.length();){
        if(pattern.at(i)==pattern.at(j)) spa[j++]=++i;
        else if(i!=0) i=spa[i-1];
        else          j++;
    }
}
void kmp(vector<int> &spa,string str,string pattern){
    bool c=false;
    for(int i=0,j=0;i<str.length() && j<str.length();)
    {
        if(str.at(i)==pattern.at(j))
        {
            if(j==pattern.length()-1)
            {
                 cout<<"Pattern found at "<<i-j<<endl;
                 c=true; j=0; i++;
            }
             else{  i++; j++; }
        }
        else if(j!=0) j=spa[j-1];
        else          i++;
    }
    if(!c) cout<<"Not Found"<<endl;
}
int main(){
    string str="abcddddabcfffddabcafafkfknabc",pattern="abc";
    vector<int> spa(pattern.length());
    suffix_prefix(spa,pattern);
    kmp(spa,str,pattern);
    return 0;
}
