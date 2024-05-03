/*
The relationship between a group of people is represented by an adjacency-list friends. If friends[u] contains v, u and v are friends.Friendship is a two-way relationship. Two people are in a friend group as long as there is some path of mutual friends connecting them.

Request: Implement function:

int numberOfFriendGroups(vector<vector<int>>& friends);
Where friends is the adjacency-list representing the friendship (this list has between 0 and 1000 lists). This function returns the number of friend groups.

Example:

Given a adjacency-list: [[1], [0, 2], [1], [4], [3], []]

There are 3 friend groups: [0, 1, 2], [3, 4], [5]

Note:

In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm have been included and namespace std is used. You can write helper functions and class. Importing other libraries is allowed, but not encouraged.
*/

void dfs(int v, vector<vector<int>>& friends, vector<bool>& visted){
    if(visted[v] == false){
        visted[v] = true;
        for(int i : friends[v]){
            dfs(i,friends,visted);
        }
    }
}

int numberOfFriendGroups(vector<vector<int>>& friends) {
    // STUDENT ANSWER
    vector<bool> visted(friends.size(), false);
    int n = friends.size();
    int count = 0;
    for(int i = 0 ; i < n; i++){
        if(visted[i] == false){
            dfs(i,friends,visted);
            count ++;
        }
    }
    return count;
}

void implement() {
    vector<vector<int>> graph {
    \t{1},
    \t{0, 2},
    \t{1},
    \t{4},
    \t{3},
    \t{}
    };
    cout << numberOfFriendGroups(graph);
}