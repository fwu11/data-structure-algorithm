//inqueue 从deque右侧进来
//右侧来一个比deque back小的，直接存进
//右侧来一个比deque back大的，pop back 直到空或者有一个不比要进来的小
//outqueue从deque左侧出去，只有要删的和deque front的那个数字一样才会出队
//维护一个候选可能的最大值集合

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    if(n < k) return vector<int>();
    vector<int> ans;
    deque<int> dq;

    for(int i = 0; i < n; i++){
        // out queue
        if(!dq.empty() && dq.front()==(i-k)){
            dq.pop_front();
        }
        // enqueue
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        // get result
        if(i >= k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}
