/**
*Definition for an interval
*struct Interval {
*    int start;
*    int end;
*    Interval():start(0), end(0) {}
*    Interval(int s, int e): start(s), end(e){}
*}
**/

class Solution {
  public:
    int sweepLine(vector<Interval> &intervals){
      int ans = 0;
      int count = 0;
      vector<pair<int,int>> v;
      
      for(Interval interval : intervals){
        v.push_back(make_pair(interval.start,1));
        v.push_back(make_pair(interval.end,-1));
      }
      
      sort(v.begin(),v.end());
      
      for(auto i : v){
        if(i.second == 1){
          count++;
        }else{
          count--;
        }
        ans = max(ans,count);
      }
      
      return ans;
    }
};
