// monotone chain
// O(nlogn)
// best in clearness and complexity

class Solution {
public:
    int orientation(vector<int> p, vector<int> q, vector<int> r){
        return (q[0]-p[0])*(r[1]-q[1]) - (q[1] - p[1]) * (r[0]-q[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int>> ans;
        
        //sort point array by x axis, if there is a tie, sort by y axis
        sort(points.begin(),points.end(),[&](vector<int> p, vector<int> q){
            return p[0] == q[0] ? p[1] < q[1] : p[0] < q[0];
        });
        
        // use vector to simulate the stack
        vector<vector<int>> stk;
        // start from left to right
        for(int i= 0; i < points.size(); i++){
            while(stk.size() >= 2 && orientation(stk[stk.size()-2],stk[stk.size()-1],points[i])<0){
                stk.pop_back();
            }
            stk.push_back(points[i]);
        }
        
        // start from right to left
        for(int i = points.size() -1; i >= 0; i--){
            while(stk.size() >= 2 && orientation(stk[stk.size()-2],stk[stk.size()-1],points[i])<0){
                stk.pop_back();
            }
            stk.push_back(points[i]);
        }
        
        // still need to avoid the case when top and bottom boundary has common points
        // remove duplicates
        sort( stk.begin(), stk.end() );
        stk.erase( unique( stk.begin(), stk.end() ), stk.end() );
        
        return stk;
    }
};