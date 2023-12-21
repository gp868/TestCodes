#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, str;
    cin >> s >> str;
    vector<string> strs;
    str += ',';
    string tmp;
    for(char ch : str){
        if(ch != ','){
            tmp += ch;
        }else{
            strs.push_back(tmp);
            tmp.clear();
        }
    }
    vector<int> nums;
    unordered_map<char, int> map;
    for(char ch : s){
        map[ch]++;
    }
    int num = 0;
    for(string str : strs){
        for(char ch : str){
            num = num * 10 + map[ch];
        }
        nums.push_back(num);
        num = 0;
    }
    sort(strs.begin(), strs.end(), [](int i, int j){
        return nums[i] < nums[j];
    });
    for(string str : strs){
        cout << str << ", ";
    }

    return 0;
}
// 64 位输出请用 printf("%lld")