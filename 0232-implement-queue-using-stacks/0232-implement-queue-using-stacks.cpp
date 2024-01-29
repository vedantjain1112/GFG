class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    void transferStacks() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {

    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (empty())
            return -1; // or throw an exception, depending on requirements

        if (outputStack.empty()) {
            transferStacks();
        }

        int front = outputStack.top();
        outputStack.pop();
        return front;
    }

    int peek() {
        if (empty())
            return -1; // or throw an exception, depending on requirements

        if (outputStack.empty()) {
            transferStacks();
        }

        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */