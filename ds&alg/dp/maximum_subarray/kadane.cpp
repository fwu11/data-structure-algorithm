// f[i] max subarray until i
// if f[i-1] < 0, ignore the values before i and start with i
// use a variable to record the largest sum
int maxSubArray(vector<int> &nums) {
    vector<int> f(2,0);
    f[0] = nums[0];
    int result = nums[0];
    for(int i = 1; i < nums.size(); i++){
        f[i%2] = max(0,f[(i-1)%2])+nums[i];
        result = max(result,f[i%2]);
    }
    return result;
}