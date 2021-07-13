#include <bits/stdc++.h>
using namespace std;

vector<int> v;

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        int originalPos;
        int nowPos;
        int nowEle, lastEle;
        originalPos = nowPos = 0;
        lastEle = nums[(0 + nums.size() - k) % nums.size()];
        do {
            nowEle = nums[nowPos];
            nums[nowPos] = lastEle;
            lastEle = nowEle;
            nowPos = (nowPos + k) % nums.size();
        } while (nowPos != originalPos);
    }
} s;

int main() {
    for (int i = 1; i <= 7; ++i) {
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); ++i) {
        printf("%d  ", v[i]);
    }
    puts("");
    s.rotate(v, 3);
    for (int i = 0; i < v.size(); ++i) {
        printf("%d  ", v[i]);
    }
    puts("");
    return 0;
}