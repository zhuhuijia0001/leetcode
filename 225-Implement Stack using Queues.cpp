class Stack {
public:
    // Push element x onto stack.
    void push(int x) 
    {
        _queue1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        while (_queue1.size() > 1)
        {
            _queue2.push(_queue1.front());
            
            _queue1.pop();
        }
        
        _queue1.pop();
        
        _queue1.swap(_queue2);
    }

    // Get the top element.
    int top() 
    {
        return _queue1.back();
    }

    // Return whether the stack is empty.
    bool empty() 
    {
        return _queue1.empty() && _queue2.empty();    
    }
    
private:
    queue<int> _queue1;
    
    queue<int> _queue2;
};