#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void partition(ListNode* head, int pivot, ListNode* smallList, ListNode* equalList, ListNode* greatList){
    ListNode* tmpNode = head;
    ListNode *tmpSmall = smallList, *tmpEqual = equalList, *tmpGreat = greatList;
    while(tmpNode){
        if(tmpNode->val < pivot){
            tmpSmall->next = tmpNode;
            tmpSmall = tmpSmall->next;
            tmpNode = tmpNode->next;
            tmpSmall->next = NULL;
        } else if(tmpNode->val == pivot) {
            tmpEqual->next = tmpNode;
            tmpEqual = tmpEqual->next;
            tmpNode = tmpNode->next;
            tmpEqual->next = NULL;
        } else {
            tmpGreat->next = tmpNode;
            tmpGreat = tmpGreat->next;
            tmpNode = tmpNode->next;
            tmpGreat->next = NULL;
        }
    }
}

ListNode* sortList(ListNode* head) {
    if(!head) return NULL;
    ListNode *smallList, *equalList, *greatList;
    smallList = new ListNode(0);
    equalList = new ListNode(0);
    greatList = new ListNode(0);
    partition(head, head->val, smallList, equalList, greatList);

    smallList = sortList(smallList->next);
    greatList = sortList(greatList->next);
     
    ListNode *newHead = new ListNode(0);
    ListNode *tmpNode = newHead;

    while(smallList){
        tmpNode->next = smallList;
        smallList = smallList->next;
        tmpNode = tmpNode->next;
    }
    while(equalList->next){
        tmpNode->next = equalList->next;
        equalList = equalList->next;
        tmpNode = tmpNode->next;
    }
    
    tmpNode->next = greatList;
	
    return newHead->next;
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

	sortList(t);

	while(t){
		cout << t->val << " ";
		t = t->next;
	}
	return 0;
}
