/*
 * http://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
 * You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
 * Example:
 *
 * Consider the following 6 activities.
 *      start[]  =  {1, 3, 0, 5, 8, 5};
 *           finish[] =  {2, 4, 6, 7, 9, 9};
 *           The maximum set of activities that can be executed
 *           by a single person is {0, 1, 3, 4}
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

struct Point {
    int start;
    int end;
    Point(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool compare(const Point point1, const Point point2) {
    return point1.end < point2.end;
}

void printPoints(vector<Point> vec) {
    vector<Point>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++) {
        cout << "(" << it->start <<", " << it->end << ")\t";
    }
    cout << "\n";
}

int main() {
    int N, start, end;
    cin >> N;
    vector<Point> vec;
    while(N--) {
        cin >> start >> end;
        Point point(start, end);
        vec.push_back(point);
    }
    sort(vec.begin(), vec.end(), compare);

    int task_count = 0;
    int current_end = -INT_MIN;
    for (int i = 0; i < vec.size(); i++) {
        if (current_end < vec[i].start) {
            task_count++;
            current_end = vec[i].end;
            cout << "(" << vec[i].start <<", " << vec[i].end << ")\t";
        }
    }

    cout << "Task Count: " << task_count << "\n";
    return 0;
}
