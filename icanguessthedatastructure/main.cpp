#include <iostream>
#include <stack>
#include <queue>


using namespace std;



    static string IMPOSSIBLE = "impossible";
    static string STACK = "stack";
    static string QUEUE = "queue";
    static string PRIORITY_QUEUE = "priority queue";
    static string NOT_SURE = "not sure";

    static int ADD = 1;


int main() {

    int input;
    int cmdLines = 0;

    bool isQueue;
    bool isStack;
    bool isPQueue;


    while (cin >> input) {

        queue<int> q;
        priority_queue<int> pq;
        stack<int> s;
        isQueue = true;
        isPQueue = true;
        isStack = true;

        cmdLines = input;

        for (int i = 0; i < cmdLines; i++) {
            int value;
            cin >> input;
            cin >> value;
            if (input == ADD) {
                if (isQueue) q.push(value);
                if (isPQueue) pq.push(value);
                if (isStack) s.push(value);
            } else {
                if (!q.empty() && isQueue) {
                    isQueue = (q.front() == value); q.pop();
                } else {
                    isQueue = false;
                }
                if (!pq.empty() && isPQueue) {
                    isPQueue = (pq.top() == value); pq.pop();
                } else {
                    isPQueue = false;
                }
                if (!s.empty() && isStack) {
                    isStack = (s.top() == value); s.pop();
                } else {
                    isStack = false;
                }
            }
        }

        if ((isQueue + isPQueue + isStack) > 1) {
            cout << NOT_SURE << endl;
        } else if (isQueue) {
            cout << QUEUE << endl;
        } else if (isPQueue) {
            cout << PRIORITY_QUEUE << endl;
        } else if (isStack) {
            cout << STACK << endl;
        } else {
            cout << IMPOSSIBLE << endl;
        }


    }
    return 0;
}
