#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
//给定一个字符串s，找出 至多包含 k个不同字符的最长子串 T。
int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() == 0 || k <= 0)
            return 0;
        unordered_map<char, int> m;
        int l = 0, r = 0;   // 滑动窗口左右指针
        int maxLen = 1;     // 最大长度
        int count = 0;
        while(r < s.size()){
            if (m[s[r]] == 0)
                count ++;
            m[s[r]] += 1;
            r++;
            // 左指针移动减小
            while (count > k){
                if(m[s[l]] == 1)
                    count--;
                m[s[l]] -= 1;
                l++;
            }
            maxLen = max(maxLen, r - l);
        }
        return maxLen;

}

int main(){
    string s;
    int k;
    while(cin>>s>>k){
        if(s == "quit")
            break;
        else
            cout << lengthOfLongestSubstringKDistinct(s,k)<<endl;
    }
}

