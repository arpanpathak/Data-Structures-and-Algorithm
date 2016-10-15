/** Sorted Tree Hash Table implemented using Binary Search Tree                             **
 ** Best and Average Case Time complexity for insertion, deletion, searching is O(1)        **
 ** Worst case Time Complexity for insertion, deletion, searching is O(log N)               **
 ** @author: Arpan Pathak                                                                   **/
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class BST
{
    public: int nodecount=0;
    vector<int> temp_result;
    private:
        class node //Inner Class for creating Nodes
        {
            public:
            int data;
            node *left,*right;
            node(){ left=NULL; right=NULL;}
        };
        node *root=NULL;
        node *Insert(node *rootptr,int data)
        {
            if(rootptr==NULL) {
                    node *newnode=new node;
                    newnode->data=data; nodecount++;
                    return newnode;
            }
            if(data>rootptr->data)
                rootptr->right= Insert(rootptr->right,data);
            else
                rootptr->left=Insert(rootptr->left,data);
            return rootptr;
        }
        bool find(node *ptr,int val)
        {
            if(ptr==NULL) return false;
            if(ptr->data==val) return true;
            return (val<ptr->data? find(ptr->left,val): find(ptr->right,val));
        }
        void inorder(node *rootptr)
        {
            if(rootptr==NULL) return;
            inorder(rootptr->left);
            temp_result.push_back(rootptr->data);
            inorder(rootptr->right);
        }
        node *findMin(node *ptr)
        {
            if(ptr==NULL) { return NULL; }
            node *temp=ptr;
            while(temp->left!=NULL)   temp=temp->left;
            return temp;
        }
        node *findMax(node *ptr)
        {
            if(ptr==NULL) { return NULL; }
            node *temp=ptr;
            while(temp->right!=NULL)   temp=temp->right;
            return temp;
        }
        node *del(node *root1,int val)
        {
            if(root1==NULL) return NULL;
            if(val<root1->data)  root1->left=del(root1->left,val);
            else if(val>root1->data)   root1->right=del(root1->right,val);
            else
            {
                if(root1->left==NULL && root1->right==NULL)
                {
                    delete root1;
                    root1=NULL;
                    return root1;
                }
                else
                if(root1->left==NULL)
                {
                    node *temp=root1;
                    root1=root1->right;
                    delete temp;
                }
                else if(root1->right==NULL)
                {
                    node *temp=root1;
                    root1=root1->left;
                    delete temp;
                }
                else
                {
                    node *temp=findMin(root1->right);
                    root1->data=temp->data;
                    temp->right=del(root1->right,temp->data);
                }
            }
            return root1;
        }
        node *destroy(node *ptr) // clearing all the memory from heap section
        {
            if(ptr==NULL) return NULL;
            destroy(ptr->left);
            destroy(ptr->right);
            delete ptr;
            return NULL;
        }
    public: //call this public method from your object.Don't call any private member
        int min(){ node *ptr=findMin(root); return ptr->data;}
        int max(){ node *ptr=findMax(root); return ptr->data;}
        void insert(int data){ root=Insert(root,data); }
        bool find(int val) { return find(root,val); }
        void inorder() { temp_result.clear(); inorder(root); }
        void remove(int val) { root=del(root,val); }
        void clearTree() { root=destroy(root); } // delete the entire tree
        ~BST() { root=destroy(root); }

};
class HashTable
{
    BST H[10]; // Array of Binary Search Tree is used to represent hash table
    public:
        void add(int val) { H[val%10].insert(val); }
        bool containValue(int val) { return H[val%10].find(val); }
        friend ostream& operator<<(ostream &out,HashTable &obj)
        {
            for(int i=0;i<10;i++)
            {
                out<<"| "<<i<<" |--> (";
                obj.H[i].inorder();
                for(auto j: obj.H[i].temp_result)
                    out<<j<<",";
                out<<")"<<endl;
            }
            return out;
        }
};
int main()
{
    HashTable H;
    H.add(101); H.add(78);
    H.add(1);
    H.add(11); H.add(22);
    H.add(88); H.add(108); H.add(208);
    cout<<H;
}
