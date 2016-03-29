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

void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *fast = head, *slow = head, *r;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    fast = reverseList(fast);
    
    while (head) {
        r = head->next;
        head->next = fast;
        head = fast;
        fast = r;
    }
}
int main(int argc, char const *argv[])
{
    ListNode *head = genRandList(10, 10), *t = head;
    cout << "Origin List: " <<  toString(t) << endl;
    reorderList(head);
    cout << "reorderList: " << toString(t) << endl;

    head = genListFromStr("1 2 3 2 1");
    cout << "Origin List: " <<  toString(head) << endl;
    t = head;
    reorderList(head);
    cout << "reorderList: " << toString(t) << endl;

    return 0;
}