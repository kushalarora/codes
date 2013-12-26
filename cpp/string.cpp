#include<iostream>
#include<algorithm> // for replace
#include<string>
#include<cassert>
using namespace std;

void replaceChars(string& modifyMe, const string findMe, const string newChars) {
    // search findMe
    // Find first occurance of findMe starting from position 0.
    int i = modifyMe.find(findMe, 0);

    // npos is end of string marker in c++ string lib.
    if (i != string::npos) {
        // start pos, no. of chars to replace, substitute chars
        modifyMe.replace(i, findMe.size(), newChars);
    }
}

void lstrip(string& modifyMe) {
    int pos = modifyMe.find_first_not_of(" ");
    if (pos != string::npos) {
        modifyMe.erase(0, pos);
    }
}

void rstrip(string& modifyMe) {
    int pos = modifyMe.find_last_not_of(" ");
    int len = modifyMe.size();
    if (pos != string::npos) {
        modifyMe.erase(pos + 1, len);
    }
}

// Case insensitive comparison
// to show of iterator
int stringCmpi(const string& s1, const string& s2) {
    string::const_iterator p1 = s1.begin(), p2 = s2.begin();

    while(p1 != s1.end() && p2 != s2.end()) {
        if (toupper(*p1) != toupper(*p2))
            return (toupper(*p1) < toupper(*p2) ? -1 : 1);
        p1++;
        p2++;
    }

    return (s2.size() - s1.size());
}


// Reverse Iterator
string reverseStr(const string& s) {
    string s1;
    string::reverse_iterator rev = s.rbegin();
    while(rev != s.rend()) {
        s1.push_back(*rev);
        rev++;
    }
    return s1;
}

int main() {
    string song("Hello, Hello, Hello is anybody out there");
    string to_find("Hello");
    string to_replace("Hi");

    cout << "Song Unmodified: " + song << endl;
    // Replaces just one occurance.
    replaceChars(song, to_find, to_replace);
    cout << "Song Modified: " + song << endl;

    // To replace all occurance,(But limited only to replacing chars, what a shame).
    // Not supported by String class
    // Using STL replace from algorithm library
    replace(song.begin(), song.end(), 'H', 'h');
    cout << "Song Modified(char replace): " + song << endl;



    // String Find

    // Basic find shown above
    // Reverse Find
    string s("Unlock Sherlock");

    int  pos = s.rfind("lock");
    assert(pos != string::npos);
    assert(pos > 6);

    s = "       HelloWorld";
    lstrip(s);
    assert(s.find_first_of(" ") > 0);


    s = "HelloWorld                  ";
    rstrip(s);
    assert(s.find_last_of(" ") < s.size() - 1 || s.find_last_of(" ") == string::npos);


    // Iterators
    assert(stringCmpi(s,"helloworld") == 0);

    s = "123456789";
    //assert(reverse(s) == "987654321");

    return 0;

}
