#include <iostream>
#include <vector>
#include "LinkedList.hpp"

using namespace std;

LinkedList ::LinkedList(const vector<short> &vect)
{
    size = vect.size();
    if (size == 0)
    {
        head = nullptr;
    }
    else
    {
        head = new ListNode(vect[0]);
        ListNode *current;
        current = head;
        for (int i = 1; i < size; ++i)
        {
            current->next = new ListNode(vect[i]);
            current = current->next;
        }
    }
}
LinkedList ::LinkedList(const LinkedList& l )
{
    size=l.size;
    if (size == 0)
    {
        head = nullptr;
    }
    else
    {
        head = new ListNode(l.head->val);
        ListNode *current;
        ListNode *current_l;
        current_l = l.head->next;
        current=head;
        for (int i = 1; i < size; ++i)
        {
            current->next = new ListNode(current_l->val);
            current = current->next;
            current_l=current_l->next;
            
        }
    }
}
LinkedList :: ~LinkedList(){
    ListNode* ptr=head;
    ListNode* tmp;
    while (ptr !=nullptr){
        tmp= ptr->next;
        delete ptr;
        ptr= tmp;
    }
}
void LinkedList ::afficher()
{
    ListNode* tmp=head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    
}

LinkedList& LinkedList::operator=(const LinkedList& l){
    LinkedList l1(l);
    swap(*this,l1);
    return *this;
}
ostream& LinkedList:: toOstream(ostream& out )const{
    if(size==0){
        out<<"the list is empty\n";
    }
    else{
         ListNode* tmp=head;
         out << tmp->val << " ";
         for (int i=0;i<size-1;++i){
            out<<tmp->next->val<<" ";
            tmp=tmp->next;
         }
    return out;
    }
}
ostream& operator<<(ostream& os, const LinkedList& l){
    return l.toOstream(os);
}
bool LinkedList::operator==(const LinkedList& l){
    if (size!=l.size){
        return false;
        };
        ListNode* tmp1= head;
        ListNode* tmp2= l.head;
    for (int i=0;i<size;i++){
        if(tmp1->val!=tmp2->val) return false;
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    return true;

}

short & LinkedList:: operator[] (int index){
    ListNode* tmp=head;
    for(int i=0;i<index;++i){
        tmp=tmp->next;
    }
    return tmp->val;
}
const short LinkedList :: operator[] (int index) const{
    ListNode* tmp=head;
    for(size_t i=0;i<index;++i){
        tmp=tmp->next;
    }
    return tmp->val;
}