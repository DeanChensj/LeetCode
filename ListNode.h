#ifndef __LISTNODE_H__
#define __LISTNODE_H__

#include "Header.h"
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode * genRandList(int len, int maxVal){
    srand((int)time(0));
    ListNode *head = new ListNode(random(maxVal));
    ListNode *q = head;
    for (int i = 1; i <= len; ++i)
    {
        q->next = new ListNode(random(maxVal));
        q = q->next;
    }
    return head;
}

ListNode * genOrderList(int len){
    ListNode *head = new ListNode(1);
    ListNode *q = head;
    for (int i = 2; i <= len; ++i)
    {
        q->next = new ListNode(i);
        q = q->next;
    }
    return head;
}

string toString(ListNode *head) {
    string res = "[";
    ListNode *t = head;
    while(t->next){
        res += to_string(t->val) + ", ";
        t = t->next;
    }
    res += to_string(t->val) + "]";
    return res;
}
    

#endif 
