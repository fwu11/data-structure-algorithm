// 完全背包,每个物品无限可用
// f[i][j]前i个物品中组成容量不超过j的最大价值
// f[i][j] = max(f[i-1][j],f[i-1][j-A[i-1]]+V[i-1]) for A[i-1] <= j <= m
// ans = max(dp[n][*])
 
//O(nm^2)
class Solution {
public:
    int knapsack(int m, vector<int> &cap, vector<int> &val) {
        int n = A.size();
        vector<int> f(m+1,0);
        
        for(int i = 0; i < N; i++)
            for(int k = 1; k * cap[i] <= m;k++)
                for(int j = m; j >= cap[i]; j--)
                    f[j] = max(f[j],f[j-cap[i]]+val[i])
 
        return [m];
    }
};
 
//时间优化O(mn)
for(int i = 0; i < N; i++)
    for(int j = cap[i]; j <= m; j++)
        f[j] = max(f[j],f[j-cap[i]]+val[i])