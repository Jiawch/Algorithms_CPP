/*! Author: Jiawch
 *! Date: 2021-11-25
 * 滑动窗口问题解题模版
初始化窗口左右边界
保存窗口内部信息（求和用整型、计数用字典、数组等）
初始化返回值 = 最小值 or 最大值 (满足题目要求的区间最值)
// 移动有边界
for 右边界 in 可迭代对象:
    更新窗口内部信息（增加当前右指针的数字、字符的计数）
    // 找到合适的左边界，此条件可以通过思考什么情况需要左移推断
    while 区间[左，右]不符合要求：（此时需要一直移动左指针，直至找到一个符合要求的区间）
        更新返回值（最小值时）
        更新窗口内部信息（移动左边界前需要将其从窗口内剔除）
        移动左边界
    // while 结束时，我们找到一个符号题意要求的取件
    更新返回值（最大值时）
返回
*/


// 008. 和大于等于 target 的最短子数组
// 给定一个含有n个正整数的数组和一个正整数 target。
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;

        int sum = 0;
        int ret = ~(1 << 31);
        for (int i = 0, j = 0; j < n; j++) {
            sum += nums[j];
            while (i <= j && sum >= target) {
                ret = min(ret, j - i + 1);
                sum -= nums[i++];
            }
        }
        return ret == ~(1 << 31) ? 0 : ret;
    }
}


// 438. 找到字符串中所有字母异位词
// 给定两个字符串s和 p，找到s中所有p的异位词的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
// 链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLength = s.size();
        int pLength = p.size();
        if (sLength < pLength)  return {};        

        vector<int> pArray(26);  // 每个字母还需要匹配的字符数
        for (int i = 0; i < pLength; i++) {
            pArray[p[i] - 'a']++;
        }

        vector<int> sArray(26);  
        vector<int> ret;
        for (int i = 0, j = 0; j < sLength; j++) {
            sArray[s[j] - 'a']++;
            while (i <= j && sArray[s[j] - 'a'] > pArray[s[j] - 'a']) {
                sArray[s[i] - 'a']--;
                i++;
            }
            if (j - i + 1 == pLength)
                ret.push_back(i);
        }
        return ret;
    }
};


// 76. 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。
// 返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 注意：
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。
// s 和 t 由英文字母组成

class Solution {
public:
    string minWindow(string s, string t) {
        int sLength = s.size();
        int tLength = t.size();
        if (sLength < tLength)  return "";

        vector<int> tArray(83);
        for (int i = 0; i < tLength; i++)
            tArray[t[i] - 'A']++;

        vector<int> sArray(83);
        string ret(sLength+1, '0');
        for (int i = 0, j = 0; j < sLength; j++) {
            sArray[s[j] - 'A']++;
            while (i <= j && vectorMinus(sArray, tArray)) {
                ret = ret.size() > (j - i + 1) ? s.substr(i, j - i + 1) : ret;
                cout << ret << endl;
                sArray[s[i] - 'A']--;
                i++;
            }
        }
        return ret.size() > sLength ? "" : ret;
    }

    bool vectorMinus(vector<int> a, vector<int> b) {
        assert(a.size() == b.size());
        int sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] - b[i] < 0)
                return false;
        }
        return true;
    }

};


// 3. 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLength = s.size();
        if (sLength <= 0)   return 0;

        unordered_map<char, int> sCount;
        unordered_map<char, int> winCount;
        for (int i = 0; i < sLength; i++) {
            sCount[s[i]] += 1;
            winCount[s[i]] = 0;
        }

        int ret = 0;
        for (int i = 0, j = 0; j < sLength; j++) {
            winCount[s[j]]++;
            while (i <= j && winCount[s[j]] > 1) {
                winCount[s[i]]--;
                i++;
            }
            ret = max(ret, j - i + 1);
        }

        return ret;
    }
};
