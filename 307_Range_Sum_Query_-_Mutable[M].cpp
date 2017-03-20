class NumArray {
public:
    NumArray(vector<int> nums) {
       size = nums.size();
       num = vector<int>(size + 1, 0);
       sum = vector<int>(size + 1, 0);
       for(int i = 0;i < size; i++)
           update(i, nums[i]); 
    }
    
    void update(int i, int val) {
        int old = num[i+1];
        for(int j = i + 1;j <= size; j += (j & (-j)))
            sum[j] = sum[j] - old + val;
        num[i+1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
private:
    int getSum(int k) {
        int result = 0;
        for(int i = k;i > 0;i -= (i & (-i)))
            result += sum[i];
        return result;
    }
    int size;
    vector<int> sum, num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */