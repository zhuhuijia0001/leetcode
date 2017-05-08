class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) 
    {
        stk_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) 
    {
        if (stk_out.empty())
        {
            while (!stk_in.empty())
            {
                int a = stk_in.top();
                stk_in.pop();
                
                stk_out.push(a);
            }
        }
        
        return stk_out.pop();
    }

    // Get the front element.
    int peek(void) 
    {
        if (stk_out.empty())
        {
            while (!stk_in.empty())
            {
                int a = stk_in.top();
                stk_in.pop();
                
                stk_out.push(a);
            }
        }
        
        return stk_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) 
    {
        return stk_out.empty() && stk_in.empty(); 
    }
    
private:
    stack<int> stk_in;
    
    stack<int> stk_out;
};