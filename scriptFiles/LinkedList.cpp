#include <iostream>
#include <vector>
#include <memory>
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
        head = make_shared<ListNode>(ListNode(vect[0]));
        shared_ptr<ListNode> temp = head;
        temp = head;
        for (int i = 1; i < size; ++i)
        {
            temp->next = make_shared<ListNode>(ListNode(vect[i]));
            temp = temp->next;
        }
    }
}
LinkedList ::LinkedList(const LinkedList &l)
{
    size = l.size;
    if (size == 0)
    {
        head = nullptr;
    }
    else
    {
        head = make_shared<ListNode>(ListNode(l.head->val));
        shared_ptr<ListNode> temp = head;
        shared_ptr<ListNode> ltemp = l.head;
        for (int i = 1; i < size; ++i)
        {
            temp->next = make_shared<ListNode>(ltemp->val);
            temp = temp->next;
            ltemp = ltemp->next;
        }
    }
}

LinkedList &LinkedList::operator=(const LinkedList &l)
{
    LinkedList l1(l);
    swap(*this, l1);
    return *this;
}
ostream &LinkedList::toOstream(ostream &out) const
{
    if (size == 0)
    {
        out << "the list is empty\n";
    }
    else
    {
        shared_ptr<LinkedList::ListNode> temp = head;
        out << temp->val << " ";
        for (int i = 0; i < size - 1; ++i)
        {
            out << temp->next->val << " ";
            temp = temp->next;
        }
        return out;
    }
}
ostream &operator<<(ostream &os, const LinkedList &l)
{
    return l.toOstream(os);
}
bool LinkedList::operator==(const LinkedList &l)
{
    if (size != l.size)
    {
        return false;
    };
    shared_ptr<ListNode> temp = head;
    shared_ptr<ListNode> ltemp = l.head;
    for (int i(0); i < size; ++i)
    {
        if (temp->val != ltemp->val)
            return false;
        temp = temp->next;
        ltemp = ltemp->next;
    }
    return true;
}

short &LinkedList::operator[](int index)
{
    shared_ptr<ListNode> temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->val;
}
const short LinkedList ::operator[](int index) const
{
    shared_ptr<ListNode> temp = head;
    for (size_t i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->val;
}

void LinkedList::push_back(short elt)
{
    shared_ptr<ListNode> temp = head;
    for (size_t i = 0; i < size - 1; ++i)
    {
        temp = temp->next;
    }
    temp->next = make_shared<ListNode>(ListNode(elt));
    size++;
}
void LinkedList ::push_front(short elt)
{
    head = make_shared<ListNode>(ListNode(elt, head));
    size++;
}