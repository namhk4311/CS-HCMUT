bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    int len = nums.size();
    if (len == 0) return true;
    int toggle = -1;
    for (int i = 0; i < len; i++) {
        if (nums[i] == 1 && toggle == -1) toggle = 1;
        else if (nums[i] != 1 && toggle != -1) toggle = 0;
        if (nums[i] == 1 && toggle == 0) return false;
    }
    return true;
}