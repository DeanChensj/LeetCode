#include "../Header.h"

using namespace std;
unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return node;
    if (hash.find(node) == hash.end()) {
        hash[node] = new UndirectedGraphNode (node->label);
        for (auto neighbor : node->neighbors) {
            (hash[node]->neighbors).push_back(cloneGraph(neighbor));
        }
    }
    return hash[node];
}

