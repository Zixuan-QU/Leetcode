//BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> copy;
        q.push(node);
        copy[node] = new UndirectedGraphNode(node->label);
        while(!q.empty()){
            UndirectedGraphNode* n = q.front();
            q.pop();
            for(auto neighbor : n->neighbors){
                if(copy.find(neighbor)!=copy.end())
                    copy[n]->neighbors.push_back(copy[neighbor]);
                else{
                    UndirectedGraphNode* newNode= new UndirectedGraphNode(neighbor->label);
                    copy[neighbor] = newNode;
                    copy[n]->neighbors.push_back(copy[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return copy[node];
    }
};

//DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        unordered_map<const UndirectedGraphNode *,UndirectedGraphNode *> copy;
        
        return clone(node,copy);
    }
    
private:
    UndirectedGraphNode *clone(UndirectedGraphNode *node,unordered_map<const UndirectedGraphNode *,UndirectedGraphNode *> &copy) {
        if(copy.find(node)!=copy.end()) return copy[node];
        copy[node] = new UndirectedGraphNode(node->label);
        
        for(auto neighbor:node->neighbors){
            clone(neighbor,copy);
            copy[node]->neighbors.push_back(copy[neighbor]);
        }
        
        return copy[node];
    }
};
