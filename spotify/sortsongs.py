import sys


def sort_songs():
    arguments = raw_input()
    import pdb;pdb.set_trace()
    in_count, out_count = arguments[0].split()
    songs = []
    for i in xrange(1, int(in_count) + 1):
        (freq, name) = arguments[i].split()
        songs.append((name, long(freq), i, i * long(freq)))

    songs.sort(key=lambda song: song[3],  reverse=True)

    print "\n".join(songs[:out_count])


if __name__ == "__main__":
    sort_songs();
