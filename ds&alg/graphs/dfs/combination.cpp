// n choose k
// input: a collection of numbers, the size of the combination
// output: return all possible combination
// O(2^n)

vector<vector<int>> combination(vector<int>& nums, int k) {
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(nums, k, 0, cur,result);
    return result;
}

void dfs(vector<int> &nums,
        int k,
        int start,
        vector<int> &cur,
        vector<vector<int>> &ans){

    if(cur.size() == k){
        ans.push_back(cur);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        // backtrack
        cur.push_back(nums[i]);
        dfs(nums,k,i+1,cur,ans); 
        cur.pop_back();
    }
}