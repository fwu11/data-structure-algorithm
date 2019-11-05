class BIT{
private:
    vector<int> _sum;
    static inline int lowbit(int x){
        return x & (-x);
    }
    
public:
    BIT(int n) {
        _sum(n+1,0);
    }  
    void update(int i, int delta) {
        while(i < _sum.size()){
            _sum[i] += delta;
            i += lowbit(i);
        }
    }
 
    int query(int i){
        int sum = 0;
        while(i>0){
            sum+= _sum[i];
            i -= lowbit(i);
        }
        return sum;
    }
};