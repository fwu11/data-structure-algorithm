// O(nlogn)
class Solution {
private:
    void siftup(vector<int> A, int k) {
        while (k != 0) {
            int father = (k - 1) / 2;
            if (A[k] > A[father]) {
                break;
            }
            swap(A[k],A[father]);            
            k = father;
        }
    }
public:
    void heapify(vector<int> A) {
        for (int i = 0; i < A.size(); i++) {
            siftup(A, i);
        }
    }
}