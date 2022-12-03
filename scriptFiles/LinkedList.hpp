#include <iostream>
#include <vector>
#include <memory>
using std::vector;
using std::ostream;
using std::shared_ptr;
class LinkedList{

    public:
        LinkedList(const vector<short>& = {});
        LinkedList(const LinkedList&);
        LinkedList& operator= (const LinkedList&);
        short& operator[](int index);
        const short operator[](int index) const;
        
        bool operator==(const LinkedList& l);
        void push_back(short);
        void push_front(short);
        int getSize()const;
        ostream& toOstream(ostream& out) const;

    private:
        struct ListNode {
        ListNode(short val, shared_ptr<ListNode> next = nullptr) : val(val), next(next) {}
        short val;
        shared_ptr<ListNode> next;                 
     };
        shared_ptr<ListNode> head;
        int size;
        friend void swap(LinkedList& l1, LinkedList& l2){
           shared_ptr<ListNode> temp = l1.head;
           l1.head=l2.head;
           l2.head=temp;
        };
    friend ostream& operator<<(ostream& out, const LinkedList& l);
};