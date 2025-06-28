int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int p = 0, q = nums.size() - 1;
    int res = 0;
    while(q > p){
        if (nums[p] + nums[q] == k){
            res++;
            p++;
            q--;
        }else if (nums[p] + nums[q] > k){
            q--;
        }else{
            p++;
        }
    }
    return res;
}