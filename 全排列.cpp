#include <iostream>
#include <vector>

using namespace std;


void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
    if (first == len) {
        res.emplace_back(output);
        return;
    }
    for (int i = first; i < len; ++i) {
        swap(output[i], output[first]);
        backtrack(res, output, first + 1, len);
        swap(output[i], output[first]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
}

int main() {
    vector<int> a;
    a = { 1,2,3 };
    vector<vector<int>> res;
    res = permute(a);
    for (int m = 0; m < res.size(); m++) {
        for (int n = 0; n < res[m].size(); n++)
            cout << res[m][n] << ' ';
        cout << endl;
    }

    return 0;
}