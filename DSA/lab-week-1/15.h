int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    int len = nums.size();
    if (len == 1) return 0;
    vector<int> a1(len);
    vector<int> a2(len);
    a1[0] = nums[0];
    a2[0] = nums[len - 1];
    for (int i = 1; i < len; i++) {
        a1[i] = a1[i - 1] + nums[i];
    }
    for (int i = 1; i < len; i++) {
        a2[i] = a2[i - 1] + nums[len - 1 - i];
    }
    for (int i = 1; i < len - 1; i++) {
        if (a1[i - 1] == a2[len - 1 - (i + 1)]) return i;
    }
    return -1;
}