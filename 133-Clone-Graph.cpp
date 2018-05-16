//solution 1
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if (node == nullptr) {
            return nullptr;
        }
        
		unordered_map<int, UndirectedGraphNode *> map;

		queue<UndirectedGraphNode *> q;
		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		map[node->label] = newNode;
		q.push(node);

		while (!q.empty()) {
			UndirectedGraphNode *n = q.front(); q.pop();

			int size = n->neighbors.size();
			for (int i = 0; i < size; i++) {
				auto it = map.find(n->neighbors[i]->label);
				if (it == map.end()) {
					newNode = new UndirectedGraphNode(n->neighbors[i]->label);
					map[n->neighbors[i]->label] = newNode;

					q.push(n->neighbors[i]);

					map[n->label]->neighbors.push_back(newNode);	
				}
				else {
					map[n->label]->neighbors.push_back(it->second);
				}
			}
		}

		return map[node->label];
	}
};

//solution 2
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if (node == nullptr) {
            return nullptr;
        }
        
        return clone(node);
	}
    
private:
    UndirectedGraphNode *clone(UndirectedGraphNode *node) {
        
        auto it = _map.find(node);
        if (it != _map.end()) {
            return it->second;
        }
        
       UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        _map[node] = newNode;
        
        for (auto n : node->neighbors) {
            newNode->neighbors.push_back(clone(n));
        }
        
        return newNode;
    }
    
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> _map;
};
