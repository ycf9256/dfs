class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> marked(numCourses, false), onStack(numCourses, false);
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        for(int i = 0; i < numCourses; i++)
            if(!marked[i] && hasCycle(graph, i, marked, onStack))
                return false;
        return true;
    }
    
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>> &prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites) graph[pre.second].insert(pre.first);
        return graph;
    }
    bool hasCycle(vector<unordered_set<int>> &graph, int i, vector<bool> &marked, vector<bool> &onStack){
        onStack[i] = marked[i] = true;
        for(auto j: graph[i])
            if(onStack[j] || hasCycle(graph, j, marked, onStack))  return true;
        return onStack[i] = false;
    }
};
