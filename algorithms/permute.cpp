#include<iostream>
#include<string>
#include<vector>

using namespace std;


void permute(string str, int index) {
    int length = str.length();
    if (index == length)
        cout << str << endl;
    for (int i = index; i < length; i++) {
        string str2 = str;
        swap(str2[index], str2[i]);
        permute(str2, index + 1);
    }
}


// Steinhaus Algorithm
vector<string> permute2(string str) {
    int length = str.length();
    vector<string> v_str;
    vector<string>::iterator it;
    if (length == 1) {
        v_str.push_back(str);
    } else {
        vector<string>temp = permute2(str.substr(0, length - 1));
        for(it = temp.begin(); it != temp.end(); it++) {
            string str2 = *it;
            int len2 = str2.length();
            for(int i = 0; i <= len2; i++) {
                v_str.push_back(str2.substr(0, i) +
                                str.substr(length - 1, length) +
                                str2.substr(i, len2));
            }
        }
    }
    return v_str;
}

int main() {
    //permute("abcd", 0);
    vector<string> temp = permute2("abcd");
    vector<string>::iterator it;
    for(it = temp.begin(); it != temp.end(); it++) {
        cout << *it << endl;
    }
}
