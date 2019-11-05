class segmentTreeNode{
public:
    int start, end, count;
    segmentTreeNode *left, *right;
    segmentTreeNode(int start, int end, int count){
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = NULL;
    }
};

class segmentTree{
public:
    segmentTree(){}
    
    segmentTreeNode *buildSegmentTree(int start, int end){
        if(start > end){
            return NULL;
        }
        
        if(start == end){
            segmentTreeNode *node = new segmentTreeNode(start,end,0);
            return node;
        }
        
        int mid = start + (end-start)/2;
        segmentTreeNode *node = new segmentTreeNode(start,end,0);
        node->left = buildSegmentTree(start,mid);
        node->right = buildSegmentTree(mid+1,end);
        node->count = node->left->count + node->right->count;
        return node;
    }

    int querySegmentTree(segmentTreeNode *root, int start, int end){
        if(start > end){
            return 0;
        }
        if(start <= root->start && root->end <= end){
            return root->count;
        }
        
        int mid = root->start + (root->end - root->start)/2;
        int leftSum = 0;
        int rightSum = 0;
        
        if(start <= mid){
            leftSum = querySegmentTree(root->left, start, end);
        }
        if(mid+1 <= end){
            rightSum = querySegmentTree(root->right,start,end);
        }
        
        return leftSum+rightSum;
    }

    void modifySegmentTree(segmentTreeNode *root, int index, int value){
        if(root->start == index && root->end == index){
            root->count += value;
            return;
        }
        
        int mid = root->start + (root->end - root->start)/2;
        
        if(index <= mid){
            modifySegmentTree(root->left,index,value);
        }else{
            modifySegmentTree(root->right,index,value);
        }
        root->count = root->left->count + root->right->count;
    }
};
