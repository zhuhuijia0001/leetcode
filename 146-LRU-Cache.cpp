class LRUCache{
public:
	LRUCache(int capacity)
	:_capacity(capacity) {
	}

	int get(int key) {
		auto itr = _map.find(key);
		if (itr != _map.end()) {
		    _lst.splice(_lst.begin(), _lst, itr->second);
		    
			return itr->second->value;
		} else {
			return -1;
		}
	}

	void set(int key, int value) {
		auto itr = _map.find(key);
		if (itr != _map.end()) {
			_lst.splice(_lst.begin(), _lst, itr->second);
			itr->second->value = value;
		} else {
			if (_map.size() >= _capacity) {
				_map.erase(_map.find(_lst.back().key));
				_lst.pop_back();
			} 
			_lst.insert(_lst.begin(), Node(key, value));
			_map.insert(pair<int, list<Node>::iterator>(key, _lst.begin()));
		}
	}

private:
	struct Node {
		int key;

		int value;

		Node(int k, int v)
			:key(k), value(v) {

		}
	};

	int _capacity;

	list<Node> _lst;

	unordered_map<int, list<Node>::iterator> _map;
};