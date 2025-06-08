//Position this line where user code will be pasted.
class Solution {
private:
    stack<int> topoSort;
    unordered_map<int, bool> visited;

    void dfs(int node, unordered_map<int, list<int>>& adjList) {
        visited[node] = true;
        for (auto const& neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList);
            }
        }
        topoSort.push(node);
    }

    void reverseDfs(int node, unordered_map<int, list<int>>& revAdjList) {
        visited[node] = true;
        for (auto const& neighbor : revAdjList[node]) {
            if (!visited[neighbor]) {
                reverseDfs(neighbor, revAdjList);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>>& adj) {
        int n = adj.size();
        unordered_map<int, list<int>> adjList;
        unordered_map<int, list<int>> revAdjList;

        // Step 1: Build graph and its reverse
        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                adjList[i].push_back(neighbor);
                revAdjList[neighbor].push_back(i);
            }
        }

        // Step 2: Topo sort all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adjList);
            }
        }

        // Step 3: Process in reverse order and count components
        visited.clear();
        int count = 0;

        while (!topoSort.empty()) {
            int top = topoSort.top();
            topoSort.pop();

            if (!visited[top]) {
                count++;
                reverseDfs(top, revAdjList);
            }
        }

        return count;
    }
};
