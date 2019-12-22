// O(n)
class Solution {
private:
    void siftdown(vector<int> A, int k) {
        while (k * 2 + 1 < A.size()) {
            int son = k * 2 + 1;   // A[i] 的左儿子下标。
            if (k * 2 + 2 < A.size() && A[son] > A[k * 2 + 2])
                son = k * 2 + 2;     // 选择两个儿子中较小的。
            if (A[son] >= A[k])      
                break;
            swap(A[son], A[k]);
            k = son;
        }
    }
public:
     void heapify(vector<int> A) {
        //从较浅深度的父节点开始
        for (int i = (A.size()- 1) / 2; i >= 0; i--) {
            siftdown(A, i);
        }
    }
}