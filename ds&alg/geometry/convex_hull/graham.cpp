// graham scan
// O(nlogn)
// not yet correct

class Solution {
public:
	// cross product, positive value for p->q anticlockwise to q->r
    int orientation(vector<int> p, vector<int> q, vector<int> r){
        return (q[0]-p[0])*(r[1]-q[1]) - (q[1] - p[1]) * (r[0]-q[0]);
    }
    
    int distance(vector<int> p, vector<int> q){
        return (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1]) * (p[1]-q[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int>> ans;
        
        if(points.size() < 4){
            for(auto p : points){
                ans.push_back(p);
            }
            return ans;
        }
        
        // start with the left most point
        int left_most = 0;
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] < points[left_most][0]){
                left_most = i;
            }
        }
        vector<int> start = points[left_most];
        
        //sort point array by polar angles
        sort(points.begin(),points.end(),[&](vector<int> p, vector<int> q){
            int diff = orientation(start,p,q);
            if(diff == 0){
                return distance(start,p) < distance(start,q); 
            }else{
                return diff > 0;
            }
        });
        
        // colinear from the last element -> reverse order
        int i = points.size()-1;
        while(i>=0 && orientation(start,points[points.size()-1],points[i])==0)
            i--;
        
        for(int l = i+1, h = points.size()-1; l < h; l++, h--){
            swap(points[l],points[h]);
        }
        
        //start traversing and push into the stack
        stack<vector<int>> stk;
        stk.push(points[0]);
        stk.push(points[1]);
        
        for(int j = 2; j < points.size(); j++){
            vector<int> top = stk.top();
            stk.pop();
            while(orientation(stk.top(),top,points[j])<0){
                top = stk.top();
                stk.pop();
            }
            stk.push(top);
            stk.push(points[j]);
        }
        
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};