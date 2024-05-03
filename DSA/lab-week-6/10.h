/*
There are n people, each person has a number between 1 and 100000 (1 ≤ n ≤ 100000). Given a number target. Two people can be matched as a perfect pair if the sum of numbers they have is equal to target. A person can be matched no more than 1 time.

Request: Implement function:

int pairMatching(vector<int>& nums, int target);
Where nums is the list of numbers of n people, target is the given number. This function returns the number of perfect pairs can be found from the list.

Example:

The list of numbers is {1, 3, 5, 3, 7} and target = 6. Therefore, the number of perfect pairs can be found from the list is 2 (pair (1, 5) and pair (3, 3)).

Note:

In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.
*/

int pairMatching(vector<int>& nums, int target) {
    int res = 0;
    sort(nums.begin(), nums.end());
    
    int start = 0;
    int end = nums.size() - 1;
    while(start < end)
    {
        if(nums[start] + nums[end] > target)
        {
            end--;
        }
        else if(nums[start] + nums[end] < target)
        {
            start++;
        }
        else
        {
            res++;
            start++;
            end--;
        }
    }
    return res;
}

void implement() {
    vector<int>items{1, 3, 5, 3, 7};
    int target = 6;
    cout << pairMatching(items, target);
}