class MinStack 
{
public:
    MinStack(void)
    {
        _stack_val_top = 0;
        
        _stack_min_index_top = 0;
    }
    
    void push(int x) 
    {
        if (_stack_val_top == s_kStackSize)
        {
            return;
        }
        
        _stack_val[_stack_val_top] = x;
        
        if (_stack_val_top == 0 || x < _stack_val[_stack_min_index[_stack_min_index_top - 1]])
        {
            _stack_min_index[_stack_min_index_top++] = _stack_val_top;
        }
        
        _stack_val_top++;
    }

    void pop(void) 
    {
        if (_stack_val_top == 0)
        {
            return;
        }
        
        _stack_val_top--;
        
        int top = _stack_val[_stack_val_top];
        
        if (_stack_val_top ==  _stack_min_index[_stack_min_index_top - 1])
        {
            _stack_min_index_top--;
        }
    }

    int top(void) 
    {
        return _stack_val[_stack_val_top - 1];    
    }

    int getMin(void) 
    {
        if (_stack_val_top == 0)
        {
            return -1;
        }
        
        return _stack_val[_stack_min_index[_stack_min_index_top - 1]];
    }

private:
    static const int s_kStackSize = 10000;
    
    int _stack_val[s_kStackSize];
    int _stack_val_top;
    
    int _stack_min_index[s_kStackSize];
    int _stack_min_index_top;
};