#include <iostream>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;



    static string IMPOSSIBLE = "impossible";
    static string STACK = "stack";
    static string QUEUE = "queue";
    static string PRIORITY_QUEUE = "priority queue";
    static string NOT_SURE = "not sure";

    static int ADD = 1;


int main() {

    string input;
    int cmdLines = 0;

    bool isQueue;
    bool isStack;
    bool isPQueue;

    ifstream myfile("example.in");
    while (getline(myfile, input)) {

        queue<int> q;
        priority_queue<int> pq;
        stack<int> s;
        isQueue = true;
        isPQueue = true;
        isStack = true;

        if (input.size() == 1) {
            cmdLines = stoi(input);
        }
        if (cmdLines == 0) {
            return 0;
        }

        for (int i = 0; i < cmdLines; i++) {
            getline(myfile, input);

            int value =  stoi(input.substr(2, 3));
            if (stoi(input.substr(0, 1)) == ADD) {
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
    //cout << endl;
    return 0;
}
