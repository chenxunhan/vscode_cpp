/*
Given two?strings?S?and T,?return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after?backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
*/

#include <bits/stdc++.h>
using namespace std;

// 双指针
class Solution {
  public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1, sskip, tskip;
        while (i >= 0 ||
               j >= 0) {
            sskip = tskip = 0;
            while (i >= 0 && (sskip || S[i] == '#'))
                S[i] == '#' ? (++sskip & --i) : (--sskip & --i);

            while (j >= 0 && (tskip || T[j] == '#'))
                T[j] == '#' ? (++tskip & --j) : (--tskip & --j);

            if ((i >= 0 && j >= 0 && (S[i] ^ T[j])) || ((i < 0) xor (j < 0)))
                return 0;

            --i, --j;
        }
        return 1;
    }
};

// //原数组修改
// class Solution {
//   public:
//     int st;
//     int type(string &s) {
//         st = 0;
//         for (auto c : s) {
//             if (c ^ '#') {
//                 s[st++] = c;
//                 continue;
//             }
//             (st > 0 && --st);
//         }
//         return st;
//     }
//     bool backspaceCompare(string S, string T) {
//         int len1 = type(S), len2 = type(T);
//         return len1 == len2 && equal(S.begin(), S.begin() + len1,
//                                      T.begin(), T.begin() + len2);
//     }
// };

int main() {
    string a, b;
    Solution s;
    while (cin >> a >> b) {
        cout << s.backspaceCompare(a, b) << endl;
    }
    return 0;
}