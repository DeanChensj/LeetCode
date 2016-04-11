#include "../Header.h"

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return nullptr;
    // new node finded
    if (hash.find(head) == hash.end()) {
        hash[head] = new RandomListNode(head->label);
        hash[head]->random = copyRandomList(head->random);
        hash[head]->next = copyRandomList(head->next);
    }
    return hash[head];
}
