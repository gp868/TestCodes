#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(nullptr){}
};

ListNode* quickSort(ListNode* head){
	if(!head || !head->next) return head;
	ListNode* pivot = head;
	ListNode* p = head->next;
	ListNode* small = new ListNode(0);
	ListNode* large = new ListNode(0);
	ListNode* p1 = small, * p2 = large;
	while(p){
		if(p->val < pivot->val){
			p1->next = p;
			p1 = p1->next;
		}else{
			p2->next = p;
			p2 = p2->next;
		}
		p = p->next;
	}
	p1->next = nullptr;
	p2->next = nullptr;
	ListNode* left = quickSort(small->next);
	ListNode* right = quickSort(large->next);

	ListNode* res = left;
	if(!left){
		res = pivot;
		pivot->next = right;
	}else{
		ListNode* node = left;
		while(node->next){
			node = node->next;
		}
		node->next = pivot;
		pivot->next = right;
	}
	return res;
}

void printList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) { // 遍历链表
        cout << p->val << " "; // 打印节点值
        p = p->next;
    }
    cout << endl;
}

int main() {
    // 创建链表
    ListNode* head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    // 打印原始链表
    cout << "Original list: ";
    printList(head);
    // 快速排序
    ListNode* sortedHead = quickSort(head);
    // 打印排序后的链表
    cout << "Sorted list: ";
    printList(sortedHead);
    return 0;
}
