/*A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
             0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
Input: S = " a b a b c b a c a d  e  f  e  g  d  e  h  i  j  h  k  l  i  j"

Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
?
Note:

S will have length in range [1, 500].
S will consist of lowercase English?letters ('a' to 'z') only.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     vector<int> partitionLabels(string S) {
        int end[26] = {0}, st = 0, ed = 0, len = S.size();
        vector<int> res;
        for (int i = 0; i < len; ++i)
            end[S[i] - 'a'] = i;
        // end[S[i] - 'a'] = max(end[S[i] - 'a'], i);
        // for (int i = 1; i < len; ++i) {
            for (int i(0); i < len; ++i) {
            ed = max(end[S[i - 1] - 'a'], ed);
            // if (i > ed) {
                if (i== ed) {
                res.push_back(ed - st + 1);
                // st = i;
                st = i+1;
                // ed = end[S[st] - 'a'];
            }
        }
        // res.push_back(len - st);
        return res;
    }
};

class Solution {
  public:
     vector<int> partitionLabels(string S) {
    
    }
};

int main() {
    Solution so;
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = so.partitionLabels(s);
    for (int a : res) {
        cout << a << endl;
    }
    return 0;
}