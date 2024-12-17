#include <stack>

class MinStack {
public:
    stack<long long int> s;
    long long int mini;
    MinStack() {}

    void push(long long int val) {

        // If we are pushing 1st value
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            // If there is new minimum, then we have to store previous Minimum somehoe
            if (val < mini) {
                s.push(2 * val - mini);     // Here, mini is previous Minimum
                mini = val;
            } else {    // If value >= mini then don’t do anything
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "UnderFlow" << endl;
            return;
        }

        long long int curr = s.top();
        s.pop();
        if (curr > mini) {
            // return curr;
        } else {
            long long int prevMin = mini;
            long long int val = 2 * mini - curr;
            mini = val;
            // return prevMin;  // Popped value
        }
    }

    int top() {
        if (s.empty())
            return -1;

        long long int curr = s.top();
        if (curr < mini) {
            return mini;
        } else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty())
            return -1;

        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */