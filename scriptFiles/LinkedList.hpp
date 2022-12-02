#include <iostream>
#include <vector>

using std::vector;
using std::ostream;

class LinkedList{

    public:
        LinkedList(const vector<short>& = {});
        LinkedList(const LinkedList&);
        LinkedList& operator= (const LinkedList&);
        ~LinkedList();
        //plus
        void afficher();
        short& operator[](int index);
        const short operator[](int index) const;
        
        bool operator==(const LinkedList& l);
        void push_back(short);
        void push_front(short);
        // int getSize()const;
        ostream& toOstream(ostream& out) const;

    private:
        struct ListNode {
        ListNode(short val, ListNode* next=nullptr)
        :val(val), next(next) {}
        short val;
        ListNode* next;                 
     };
        ListNode* head;
        int size;
        friend void swap(LinkedList& l1, LinkedList& l2){
           ListNode* tmp=l1.head;
           l1.head=l2.head;
           l2.head=tmp;
        };
    friend ostream& operator<<(ostream& out, const LinkedList& l);
};