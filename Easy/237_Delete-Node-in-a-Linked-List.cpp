#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
        *node = *(node->next);
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

	deleteNode(t->next);

	while(t){
		cout << t->val << " ";
		t = t->next;
	}
	return 0;
}
