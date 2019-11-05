// 0-1背包
// f[i][j]前i个物品中组成容量不超过j的最大价值
// f[i][j] = max(f[i-1][j],f[i-1][j-A[i-1]]+V[i-1]) for A[i-1] <= j <= m
// ans = max(dp[n][*])
 
class Solution {
public:
    int knapsack(int m, vector<int> &A, vector<int> &V) {
        int n = A.size();
        int maximum = INT_MIN;
        vector<vector<int>>f(n+1,vector<int>(m+1,0));
        
        for(int i =1; i <=n;i++){
            for(int j = 1; j<=m;j++){
                if(j>=A[i-1]){
                    f[i][j] = max(f[i-1][j],f[i-1][j-A[i-1]]+V[i-1]);
                }else{
                    f[i][j] = f[i-1][j];
                }
            }
        }
        return f[n][m];
    }
};
 
// O(n) space
for(int i = 0; i < n; i++)
    for(int j = m; j >= cap[i]; j--)
        dp[j] = max(dp[j],dp[j-cap[i]] + val[i]);