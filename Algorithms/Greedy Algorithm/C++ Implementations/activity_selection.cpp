/** Activity Selection ,Greedy Algorithm
 ** Time Complexity: O(N log N), @author: Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
template<class T> struct Activity{
    T name; int start,finish;
    Activity(T name,int start,int finish): name(name),start(start),finish(finish) { }
    bool operator <(Activity<T> &o) { return finish<o.finish; }
};
int main(){
    vector<Activity<string>> l; // list of activities
    int n,s,f; string name;
    cout<<"Enter number of activities="; cin>>n;
    cout<<"Enter all activities (name,start,finish) :\n";
    while(n--){
        cin>>name>>s>>f; l.push_back(Activity<string>(name,s,f)); cin.ignore();
    }
    sort(l.begin(),l.end());
    cout<<"Selected Activities are : "<<l[0].name<<",";
    for(int m=1,k=0; m<l.size(); m++){
        if(l[m].start>=l[k].finish){
            cout<<l[m].name<<",";   k=m;
        }
    }
}
