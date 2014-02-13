#include<iostream>
#include<string>
#include<set>

using namespace std;

string& toLower(const string& s) {
    char arr[s.length() + 1];
    int i = 0;
    for (i = 0; i < s.length(); i++) {
        arr[i] =  s[i] + ((s[i] > 64 && s[i] < 91) ? 32 : 0);
    }
    arr[i] = '\0';
    string *newstr = new string(arr);
    return *newstr;
}

string& deleteVowels(const string& s) {
    char arr[s.length() + 1];
    int i = 0, j = 0;
    char vowel_arr[6] = {'a', 'i', 'e', 'o', 'u', 'y'};
    set<char> vowels(vowel_arr, vowel_arr + 6);

    for (i = 0; i < s.length(); i++) {
        if (vowels.find(s[i]) == vowels.end()) {
            arr[j++] = s[i];
        }
    }
    arr[j] = '\0';

    string *newstr = new string(arr);
    return *newstr;
}

string& insertDots(const string& s) {
    char arr[s.length() * 2 - 1];
    int i = 0, j = 0;
    for (i = 0; i < s.length(); i++) {
        arr[j++] = '.';
        arr[j++] = s[i];
    }
    arr[j] = '\0';
    string *new_str = new string(arr);
    return *new_str;
}
int main() {
    string word;
    cin >> word;

    word = toLower(word);
    word = deleteVowels(word);
    word = insertDots(word);
    cout << word;
    return 0;
}
