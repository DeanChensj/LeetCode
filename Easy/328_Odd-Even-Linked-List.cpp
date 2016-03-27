#include "../Header.h"
#include "../ListNode.h"

using namespace std;
ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode *even = head->next, *odd = head, *evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
int main(int argc, char const *argv[])
{
	ListNode *head = genOrderList(9);
	cout << "Origin : " <<  toString(head) << endl;
	head = oddEvenList(head);
	cout << "OddEven : " << toString(head) << endl;

	head = genOrderList(10);
	cout << "Origin : " <<  toString(head) << endl;
	head = oddEvenList(head);
	cout << "OddEven : " << toString(head) << endl;

	return 0;
}