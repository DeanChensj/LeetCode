#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void reverseNode(ListNode *head, ListNode *tail) {

    ListNode *q = tail, *p = head;
    stack<ListNode*> Stack;
    while(q != head) {
        Stack.push(q);
        q = q->next;
    }
    while(!Stack.empty()) {
        p->next = Stack.top();
        Stack.pop();
        p = p->next;
    }
    p->next = NULL;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *newHead, *newTail, *next = head, *tmpHead = new ListNode(0), *tmp = tmpHead;
    tmpHead->next = head;
    while (next) {
        int cnt = k - 1;
        newTail = newHead = next;
        while (newHead && cnt-- > 0) {
            newHead = newHead->next;
        }
        if (!newHead) return tmpHead->next; 
        next = newHead->next;

        reverseNode(newHead, newTail);

        tmp->next = newHead;
        newTail->next = next;
        tmp = newTail;
    }
    return tmpHead->next;
    
}


int main(int argc, char const *argv[])
{
	ListNode *t = new ListNode(1);
	ListNode *q = t;
	for (int i = 2; i < 6; ++i)
	{
		q->next = new ListNode(i);
		q = q->next;
	}

	t = reverseKGroup(t, 2);

	while(t){
		cout << t->val << " ";
		t = t->next;
	}
    cout << endl;
	return 0;
}
