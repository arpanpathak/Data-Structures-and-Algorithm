#include <bits/stdc++.h>
using namespace std;
class HashTable
{
    list<int> H[10];
    public:
        void add(int val) { H[val%10].push_front(val); }
        friend ostream& operator<<(ostream &out,HashTable &obj)
        {
            for(int i=0;i<10;i++)
            {
                out<<"|"<<i<<"|==>";
                for(auto j: obj.H[i])
                    out<<j<<",";
                out<<endl;
            }
            return out;
        }
};
int main()
{
    HashTable H;
    H.add(1);
    H.add(11); H.add(22);
    H.add(88); H.add(108); H.add(208);
    cout<<H;
}
