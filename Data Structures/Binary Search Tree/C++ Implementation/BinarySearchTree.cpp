/** Binary Search Tree Class Implemented by Arpan Pathak **/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class BST
{
    public: int nodecount=0;
    private:
        class node //Inner Class for creating Nodes
        {
            public:
            int data;
            node *left;
            node *right;
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
        void inorder(node *rootptr)
        {
            if(rootptr==NULL) return;
            inorder(rootptr->left);
            cout<<rootptr->data<<" ";
            inorder(rootptr->right);
        }
        void postorder(node *rootptr)
        {
            if(rootptr==NULL) return;
            inorder(rootptr->left);
            inorder(rootptr->right);
            cout<<rootptr->data<<" ";
        }
        void preorder(node *rootptr)
        {
            if(rootptr==NULL) return;
            cout<<rootptr->data<<" ";
            inorder(rootptr->left);
            inorder(rootptr->right);
        }
        int height(node *rootptr)
        {
            if(rootptr==NULL) return -1;
            int leftHeight=height(rootptr->left); int rightHeight=height(rootptr->right);
            return std::max(leftHeight,rightHeight)+1;
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
        void inorder() { inorder(root); }
        void preorder() { preorder(root); }
        void postorder() { postorder(root); }
        int height(){ height(root); }
        void remove(int val) { root=del(root,val); }
        void clearTree() { root=destroy(root); } // delete the entire tree
        ~BST() { root=destroy(root); }

};
int main()
{
    BST t;
    t.remove(8);
    t.insert(5);
    t.insert(1);
    t.insert(8);
    t.insert(5);
    t.remove(8);
    //t.clearTree();
    t.inorder();
    cout<<endl<<t.min()<<endl<<t.max();
}
