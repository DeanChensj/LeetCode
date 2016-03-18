#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

  ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k) return head;
        int size = 1, cnt = 1;
        ListNode *tail = head, *tmp, *newHead;
        while (tail->next) {
            size++;
            tail = tail->next;
        }
        
        if (size == k) return head;
        for (tmp = head; cnt < size - (k % size);tmp = tmp->next, cnt++);
        tail->next = head;
        newHead = tmp->next;
        tmp->next = NULL;
        
        return newHead;
    }


int main(int argc, char const *argv[])
{
	ListNode *t = new ListNode(0);
	ListNode *q = t;
	for (int i = 0; i < 10; ++i)
	{
		q->next = new ListNode(10-i);
		q = q->next;
	}

	rotateRight(t, 3);

	while(t){
		cout << t->val << " ";
		t = t->next;
	}
	return 0;
}
