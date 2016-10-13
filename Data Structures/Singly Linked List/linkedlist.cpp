/** Generic Linked List Template in C++ implemented by Arpan Pathak **/
#include <bits/stdc++.h>
using namespace std;
template<class T>
class Node
{
    public:
        T data;
        Node *next;
};
template<class T>
class LinkedList
{
    private:
        Node<T> *head;
    public:
        LinkedList() { head=NULL; }
        void push_back(T value)
        {
            Node<T> *ptr=new Node<T>,*iter=head;
            ptr->data=value;
            ptr->next=NULL;
            if(head==NULL) { head=ptr; return; }
            while(iter->next!=NULL && (iter=iter->next));
            iter->next=ptr;
        }
        void display()
        {
            Node<T> *iter=head;
            while(iter!=NULL && (cout<<iter->data<<" ") && (iter=iter->next));
        }
        ~LinkedList() // Deleting the created linked list manually using destructor
        {
            Node<T> *ptr=head,*curr;
            while(ptr!=NULL)
            {
                curr=ptr->next;
                delete ptr;
                ptr=curr;
            }
        }
        Node<T>* begin(){ return head; }

};
template<class T>
class iter // iterator for LinkedList . Always pass the type of linked list as template argument
{
    public:
        Node<T> *current;
        iter(Node<T> *pointer): current(pointer){  }
        //iterator(LinkedList<T> &obj) { current=obj.head; }
        bool end() { return current==NULL? true: false; }
        iter<T> operator ++(int){ if(current!=NULL) current=current->next;}
        iter<T> operator ++(){ if(current!=NULL) current=current->next;}
        T val() { if(current!=NULL) return current->data; }
        friend std::ostream& operator<<(ostream& out,iter<T> &obj)
        {
            out<<obj.val();
            return out;
        }
};

int main()
{
    LinkedList<string> x;
    x.push_back("Delhi");
    x.push_back("Mumbai");
    x.push_back("Kolkata");
    for(iter<string> i=x.begin(); !i.end(); i++)
        cout<<i<<endl;
    //iterator i(x.begin());

}
