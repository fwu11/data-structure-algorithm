// input is a linked list

class Solution {
  private:
    ListNode* cur;
  public:
    Solution(ListNode* head){
      cur = head;
    }
  
    int getRandom(){
      int count = 1;
      int ans;
      srand(time(NULL));
      ListNode *start = cur;
      while(start){
        if(rand()%count==0) ans = start -> val;
        count++;
        start = start->next;
      }
      return ans;
    }
};
      
      
