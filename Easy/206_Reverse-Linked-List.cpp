#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *tmp = head, *newHead = new ListNode(0);
        stack<ListNode*> Stack;
        while (tmp->next) {
            Stack.push(tmp);
            tmp = tmp->next;
        }
        newHead->next = tmp;
        while (!Stack.empty()) {
            tmp->next = Stack.top();
            Stack.pop();
            tmp = tmp->next;
        }
        tmp->next = NULL;
        return newHead->next;
    }
int main(int argc, char const *argv[])
{
	ListNode *t = new ListNode(0);
	ListNode *q = t;
	for (int i = 1; i < 10; ++i)
	{
		q->next = new ListNode(i);
		q = q->next;
	}

	t = reverseList(t);

	while(t){
		cout << t->val << " ";
		t = t->next;
	}
	return 0;
}
