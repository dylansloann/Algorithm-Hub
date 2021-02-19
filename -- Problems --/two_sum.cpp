vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> returnVector(2);
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                returnVector[0] = i;
                returnVector[1] = j;
                return returnVector;
            }
        }
    }
    return returnVector;
}