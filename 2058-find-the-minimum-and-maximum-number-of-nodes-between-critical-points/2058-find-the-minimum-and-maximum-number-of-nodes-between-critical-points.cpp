class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        vector<int> v;
        int index = 1;
        while (curr != NULL && curr->next != NULL) {  
            if (curr->val > prev->val && curr->val > curr->next->val) {
                v.push_back(index);
            }           
            if (curr->val < prev->val && curr->val < curr->next->val) {
                v.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        if (v.size() < 2) {
            return {-1, -1};
        }
        int mini = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            mini = min(mini, v[i] - v[i - 1]);
        }
        int maxi = v.back()- v.front();
        return {mini, maxi};
    }
};