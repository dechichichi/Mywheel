#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <utility>
using namespace std;

class Graph {
private:
    int NumVertex;
    vector<vector<pair<int, int>>> adjList; // �ڽӱ��洢�����Ȩ��
    vector<int> Dist; // �洢��̾���
    vector<int> indegree; // �������
    vector<bool> visited; // ���ʱ��

    int findNewVertex() {
        for (int i = 0; i < NumVertex; i++) {
            if (indegree[i] == 0 && !visited[i]) return i;
        }
        return -1;
    }

public:
    Graph(int N) : NumVertex(N), adjList(N), indegree(N, 0), visited(N, false), Dist(N, numeric_limits<int>::max()) {}

    void Insert(int v, int w) {
        adjList[v].push_back(make_pair(w, 0)); // ������Ȩͼ��Ȩ��Ϊ0
        indegree[w]++;
    }

    void Insert(int a, int b, int v) {
        adjList[a].push_back(make_pair(b, v)); // �洢�ߺ�Ȩ��
        indegree[b]++;
    }

    void TopSort() {
        queue<int> Q;
        for (int i = 0; i < NumVertex; i++) {
            if (indegree[i] == 0) Q.push(i);
        }

        vector<int> topOrder;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            topOrder.push_back(u);
            for (auto edge : adjList[u]) {
                int v = edge.first;
                indegree[v]--;
                if (indegree[v] == 0) Q.push(v);
            }
            visited[u] = true;
        }

        if (topOrder.size() != NumVertex) {
            cout << "Graph has cycle" << endl;
        }
        else {
            for (int u : topOrder) {
                cout << u << " ";
            }
            cout << endl;
        }
    }

    void UnWeightedDist(int a, int b) {
        queue<int> Q;
        Q.push(a);
        Dist[a] = 0;
        fill(visited.begin(), visited.end(), false); // ���÷��ʱ��
        visited[a] = true;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto edge : adjList[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    Dist[v] = Dist[u] + 1;
                    Q.push(v);
                    visited[v] = true;
                }
                if (v == b) {
                    cout << "Shortest distance from " << a << " to " << b << " is " << Dist[b] << endl;
                    return;
                }
            }
        }
        if (Dist[b] == numeric_limits<int>::max()) {
            cout << "No path from " << a << " to " << b << endl;
        }
    }

    void Dijkstra(int a, int b) {
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> Q;
        Dist.assign(NumVertex, numeric_limits<int>::max()); // ���þ�������
        Dist[a] = 0;
        Q.push(make_pair(0, a));
        visited.assign(NumVertex, false); // ���÷��ʱ��

        while (!Q.empty()) {
            int u = Q.top().second;
            Q.pop();
            visited[u] = true; // ���Ϊ�ѷ���

            for (auto edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (Dist[u] + weight < Dist[v]) { // �ҵ����̵�·��
                    Dist[v] = Dist[u] + weight;
                    Q.push(make_pair(Dist[v], v));
                }
            }
        }

        if (Dist[b] == numeric_limits<int>::max()) {
            cout << "No path from " << a << " to " << b << endl;
        }
        else {
            cout << "Shortest distance from " << a << " to " << b << " is " << Dist[b] << endl;
        }
    }
    void DijkstraNegative(int a, int b) {
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> Q;
        Dist.assign(NumVertex, numeric_limits<int>::max()); // ���þ�������
        Dist[a] = 0;
        Q.push(make_pair(0, a));
        visited.assign(NumVertex, false); // ���÷��ʱ��

        while (!Q.empty()) {
            int u = Q.top().second;
            Q.pop();
            visited[u] = true; // ���Ϊ�ѷ���

            for (auto edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (!visited[v] && Dist[u] + weight < Dist[v]) { // �ҵ����̵�·��
                    Dist[v] = Dist[u] + weight;
                    Q.push(make_pair(Dist[v], v));
                }
            }
        }

        if (Dist[b] == numeric_limits<int>::max()) {
            cout << "No path from " << a << " to " << b << endl;
        }
        else {
            cout << "Shortest distance from " << a << " to " << b << " is " << Dist[b] << endl;
        }
    }
};

int main() {
    Graph g(6);
    g.Insert(0, 1, 10);
    g.Insert(0, 2, 3);
    g.Insert(1, 3, 5);
    g.Insert(2, 3, 8);
    g.Insert(3, 4, 1000000);
    g.Insert(4, 5, 6);
    g.TopSort();
    g.UnWeightedDist(0, 5); // ������Ȩͼ����̾���
    g.Dijkstra(0, 5); // ������Ȩͼ����̾���

    return 0;
}