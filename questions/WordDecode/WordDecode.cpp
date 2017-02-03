/** bits/stdc++.h will not work on Visual C++ compiler **/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> split(string &str){
    stringstream ss(str);
    string tmp;
    vector<string> tokens;
    while( getline(ss,tmp,' ') )
        tokens.push_back(tmp);
    return tokens;
}

int main()
{
    string s,enc,dec="";
    getline(cin,s);
    vector<string> dictionary=split(s);
    getline(cin,enc);
    map<int,string> m;
		for(int i=0;i<dictionary.size();i++)
			for(int j=enc.find(dictionary[i]);j<enc.length() && j!=-1;j=enc.find(dictionary[i],j+1))
				m[j]=dictionary[i];

    for(map<int,string>::iterator i=m.begin();i!=m.end();i++)
        dec+=i->second+" ";
    cout<<dec;
    return 0;
}
