bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> myMap;
    for (auto num : nums) {
        if (myMap.find(num) != myMap.end())
            return true;
        else
            myMap[num] = true;
    }
    return false;
}