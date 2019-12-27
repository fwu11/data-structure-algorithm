// jarvis algorithm O(mn)

class Solution {
public:
    // cross product, positive value for p->q anticlockwise to q->r
    int orientation(vector<int> p, vector<int> q, vector<int> r){
        return (q[0]-p[0])*(r[1]-q[1]) - (q[1] - p[1]) * (r[0]-q[0]);
    }
    
    bool inbetween(vector<int> p, vector<int> q, vector<int> i){
        bool a = i[0] >= p[0] && i[0] <= q[0] || i[0] >= q[0] && i[0] <= p[0];
        bool b = i[1] >= p[1] && i[1] <= q[1] || i[1] >= q[1] && i[1] <= p[1];
        return a && b;
    }
    
    vector<vector<int>> convex_hull(vector<vector<int>>& points) {
        vector<vector<int>> ans;
        
        if(points.size() < 4){
            for(auto p : points){
                ans.push_back(p);
            }
            return ans;
        }
        
        // start with the leftmost point
        int left_most = 0;
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] < points[left_most][0]){
                left_most = i;
            }
        }
        int p = left_most;
        do{
            // find the most counterclockwise one
            int q = (p + 1) % points.size();
            for(int i = 0; i < points.size(); i++){
                if(orientation(points[p],points[q],points[i]) > 0){
                    q = i;
                }
            }
            
            // find the colinear ones
            for(int i = 0; i < points.size(); i++){
                if(i != p && i != q && orientation(points[p],points[q],points[i]) == 0 && inbetween(points[p],points[q],points[i])){
                    ans.push_back(points[i]);
                }
            }
            ans.push_back(points[q]);
            p = q;
        
        }
        while(p!=left_most);
        
        return ans;
    }
};