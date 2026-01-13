#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin() , arr.end());
        temp = head;
        int i = 0;
        while(temp!= NULL){
            temp->val = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};
int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution obj;
    ListNode* sortedHead = obj.sortList(head);

    cout << "Sorted Linked List: ";
    ListNode* temp = sortedHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
    
