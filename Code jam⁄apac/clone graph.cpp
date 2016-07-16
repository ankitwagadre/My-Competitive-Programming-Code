/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

vector< pair<UndirectedGraphNode *, UndirectedGraphNode *> > totalnodes;
UndirectedGraphNode* findNode(UndirectedGraphNode* node)
{
    for(vector< pair<UndirectedGraphNode *, UndirectedGraphNode *> > ::iterator it = totalnodes.begin();
        it!=totalnodes.end(); ++it)
    {
        if ((*it).second == node)
            return (*it).first;
    }

    UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
    totalnodes.push_back(make_pair(head, node));
    return head;
}

UndirectedGraphNode* solve(UndirectedGraphNode *node) {
     UndirectedGraphNode* head = findNode(node);
     if (head->neighbors.size() == node->neighbors.size())
        return head;

     for(vector<UndirectedGraphNode *>::iterator  it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
     {
         UndirectedGraphNode* neighbor = findNode(*it);
         head->neighbors.push_back(neighbor);
     }

     for(vector<UndirectedGraphNode *>::iterator  it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
     {
        solve(*it);
     }

     return head;
 }

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    totalnodes.clear();
    return solve(node);
}
