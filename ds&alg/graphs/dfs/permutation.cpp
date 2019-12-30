// input: a collection of numbers that might contain duplicates
// output: return all possible unique permutations
// O(n!)


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int> p;
    // record the visited number
    vector<int> visited(nums.size(),0);
    
    sort(nums.begin(),nums.end());
    dfs(nums,p,visited,result);
    return result;
}

void dfs(vector<int> &nums,
          vector<int> &p,
          vector<int> &visited,
          vector<vector<int>> &result){

    if(p.size() == nums.size()){
        result.push_back(p);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(visited[i]){
            continue;
        }

        // check if visited[i-1] == 0 to avoid the repetition
        // in this way, if we have 1 1 1 2
        // start from first 1, we have 1 1 1 2
        // start from second 1, we go back to first 1, not visited, so not included, avoid the repetition
        // meaning: only the first of the repeated number can choose all the same numbers, later numbers will be skipped.
        if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]){
            continue;
        }

        // backtrack
        p.push_back(nums[i]);
        visited[i] = 1;
        dfs(nums,p,visited,result); 
        visited[i] = 0;
        p.pop_back();
    }
}
