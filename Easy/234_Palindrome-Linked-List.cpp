#include "../Header.h"
#include "../ListNode.h"

using namespace std;
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *prev = NULL, *next = NULL;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return 1;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->next;
    slow = reverseList(slow);
    while (slow) {
        if (slow->val != head->val) return 0;
        slow = slow->next;
        head = head->next;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
	ListNode *head = genOrderList(10);
	cout << "Origin List: " <<  toString(head) << endl;
	cout << "isPalindrome? : " << isPalindrome(head) << endl;

	head = genListFromStr("1 2 3 2 1");
	cout << "Origin List: " <<  toString(head) << endl;
	cout << "isPalindrome? : " << isPalindrome(head) << endl;

	return 0;
}