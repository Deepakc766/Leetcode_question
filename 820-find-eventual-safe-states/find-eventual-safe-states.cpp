class Solution {
public:
    bool dfscycle(vector<vector<int>>& graph, int src,
                  unordered_map<int,bool>& visited,
                  unordered_map<int,bool>& inrecursion) {

        visited[src] = true;
        inrecursion[src] = true;

        for (auto ng : graph[src]) {

            if (!visited[ng]) {
                if (dfscycle(graph, ng, visited, inrecursion))
                    return true;
            }
            else if (inrecursion[ng]) { 
                return true;
            }
        }

        inrecursion[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        unordered_map<int,bool> visited;
        unordered_map<int,bool> inrecursion;

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                dfscycle(graph, i, visited, inrecursion);
            }
        }

        vector<int> safestate;

        for (int i = 0; i < graph.size(); i++) {
            if (inrecursion[i] == false)
                safestate.push_back(i);
        }

        return safestate;
    }
};