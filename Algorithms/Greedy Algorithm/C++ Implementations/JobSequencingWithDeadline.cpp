/** Job Sequencing with deadline using greedy approach, implemented by Arpan Pathak
 ** Time Complexity O(N X max_deadline) **/
#include <bits/stdc++.h>
using namespace std;
template<class T>
class Jobs
{
    public: T no; int deadline,profit;
    Jobs(T no,int deadline,int profit): no(no),deadline(deadline),profit(profit) { }
    bool operator < (Jobs<T> &obj) { return profit>obj.profit; }
    friend ostream& operator <<(ostream &out,Jobs<T> &o) {
        out<<"\t[Job : "<<o.no<<"\n\tProfit :"<<o.profit<<"\n\tDeadline : "<<o.deadline<<"]\n\n";
        return out;
    }
};
void jobSequencing(vector<Jobs<string>> jobs,int max_deadline)
{
    int feasible[max_deadline+1],max_profit=0;
    fill_n(feasible,max_deadline+1,-1);
    for(int i=0;i<jobs.size();i++)
    {
        for(int j=jobs[i].deadline; j>0;j-- )
            if(feasible[j]==-1) {  feasible[j]=i; max_profit+=jobs[i].profit; break;  }
    }
    for(auto x: feasible) if(x!=-1) cout<<jobs[x];
    cout<<"Maximum Profit ="<<max_profit;
 }
int main()
{
    vector<Jobs<string>> jobs; string job_name; int deadline,profit,n,max_deadline=0;
    cout<<"Enter Number of jobs=";   cin>>n;
    cout<<"Enter job name, deadline, profit of each job in a new line :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>job_name>>deadline>>profit; cin.ignore();
        max_deadline=max(max_deadline,deadline);
        jobs.push_back(Jobs<string>(job_name,deadline,profit));
    }
    sort(jobs.begin(),jobs.end()); // sort in desreasing order of profit
    jobSequencing(jobs,max_deadline);
    return 0;
}
