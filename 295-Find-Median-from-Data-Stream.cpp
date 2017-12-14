class MedianFinder 
{
public:
	MedianFinder()
	{
		_maxPriorityQueue.push(INT_MIN);
		_minPriorityQueue.push(INT_MAX);
	}

    // Adds a number into the data structure.
    void addNum(int num) 
    {
		if (num <= _maxPriorityQueue.top())
		{
			if (_maxPriorityQueue.size() > _minPriorityQueue.size())
			{
				_minPriorityQueue.push(_maxPriorityQueue.top());
				_maxPriorityQueue.pop();
			}
                
			_maxPriorityQueue.push(num);
		}
		else if (num > _minPriorityQueue.top())
		{
			if (_maxPriorityQueue.size() == _minPriorityQueue.size())
			{
				_maxPriorityQueue.push(_minPriorityQueue.top());
				_minPriorityQueue.pop();
			}
                
			_minPriorityQueue.push(num);
		}
		else
		{
			if (_maxPriorityQueue.size() > _minPriorityQueue.size())
			{
				_minPriorityQueue.push(num);
			}
			else
			{
				_maxPriorityQueue.push(num);
			}
		}
    }

    // Returns the median of current data stream
    double findMedian() 
    {
        if (_maxPriorityQueue.size() > _minPriorityQueue.size())
        {
            return _maxPriorityQueue.top();
        }
        else
        {
            return (_maxPriorityQueue.top() + _minPriorityQueue.top()) / 2.0;
        }
    }
    
private:
    priority_queue<int> _maxPriorityQueue;
    
    priority_queue<int, vector<int>, greater<int> > _minPriorityQueue;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();