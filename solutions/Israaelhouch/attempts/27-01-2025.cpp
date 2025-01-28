class Solution {
public:

    bool canPartition(vector<int>& nums) {
        return test(nums, 0, 0, 0);
    }
private:

    bool test(vector<int>&t , int i, int sum1, int sum2){
        if (i == t.size()){
            return sum1 == sum2;
        }
        return test(t, i + 1, sum1 + t[i], sum2) || test(t, i + 1, sum1, sum2 + t[i]);
    }
};
