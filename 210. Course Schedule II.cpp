class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        vector<bool> marked(numCourses, false), onStack(numCourses, false);
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        for(int i = 0; i < numCourses; i++)
            if(!marked[i] && dfs(graph, i, marked, onStack, order)) return {};
        reverse(order.begin(), order.end());
        return order;
        
    }
    
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>> &prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites) graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>> &graph, int i, vector<bool> &marked, vector<bool> &onStack, vector<int> &order){
        if(marked[i]) return false;
        onStack[i] = marked[i] = true;
        for(auto j: graph[i])
            if(onStack[j] || dfs(graph, j, marked, onStack, order))  return true;
        order.push_back(i);
        return onStack[i] = false;
    }
    
};
