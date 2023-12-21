#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode* quicksort(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* pivot = head;
    ListNode* small = new ListNode(0);
    ListNode* large = new ListNode(0);
    ListNode* p1 = small, * p2 = large, * p = head->next;
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
    ListNode* left = quicksort(small->next);
    ListNode* right = quicksort(large->next);
    ListNode* res = left;
    if(!left){
        res = pivot;
        pivot->next = right;
    }else{
        p = left;
        while(p->next){
            p = p->next;
        }
        p->next = pivot;
        pivot->next = right;
    }
    return res;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    ListNode* res = quicksort(head);
    ListNode* p = res;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}