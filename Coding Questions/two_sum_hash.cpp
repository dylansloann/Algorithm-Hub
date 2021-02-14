vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> returnVector;
    unordered_map<int, int> store;
    
    for (int i = 0; i < nums.size(); i++) {
        int targetRemain = target - nums[i];
        if (store.find(targetRemain) != store.end() && store[targetRemain] != i) {
            returnVector.push_back(store[targetRemain]);
            returnVector.push_back(i);
            return returnVector;
        }
        store.insert({ nums[i], i });
    }
    
    return returnVector;
}