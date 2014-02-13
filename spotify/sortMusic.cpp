#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct SONG {
    long long freq;
    int index;
    string name;
    long long quality;
    SONG(long long f, int i, string s, long long q):freq(f), index(i), name(s), quality(q) {};
};

bool compare(SONG song1, SONG song2) {
    if (song1.quality == song2.quality) {
        return song1.index < song2.index;
    }
    return song1.quality > song2.quality;
}

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    vector<SONG> songs;

    int i = 0;
    while (i < N) {
        long long freq;
        string name;
        cin >> freq >> name;
        songs.push_back(SONG(freq, i, name, freq * (i + 1)));
        i++;
    }

    sort(songs.begin(), songs.end(), compare);

    for (int k = 0; k < M; k++) {
        cout << songs[k].name<<endl;
    }
    return 0;
}
