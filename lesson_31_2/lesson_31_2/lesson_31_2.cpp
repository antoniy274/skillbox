#include <vector>
#include <iostream>

// 31.2

class IGraph {

public:
    virtual ~IGraph() {}

    IGraph() {};

    IGraph(IGraph* _oth) {};

    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро

    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной

    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
};

class ListGraph : public IGraph {
    std::vector<std::vector<int>> graphData;
    int nodesNumber{ 0 };

public:
    ListGraph() {};

    ListGraph(int _nodesNumber)
        : nodesNumber(_nodesNumber) {
        if (nodesNumber > 0) {
            std::cout << "ListGraph initialization\n";
            graphData.resize(nodesNumber);
            for (int node1Index = 0; node1Index < nodesNumber; node1Index++) {
                for (int node2Index = 0; node2Index < nodesNumber; node2Index++) {
                    if (node1Index == node2Index)
                        continue;

                    int connection{ 0 };
                    std::cout << "connection from #" << node1Index << " to #" << node2Index << ": ";
                    std::cin >> connection;
                    if (connection != 0) {
                        graphData[node1Index].push_back(node2Index);
                    }
                }
            }
        }
    };

    ListGraph(IGraph* _oth) {
        nodesNumber = _oth->VerticesCount();
        if (nodesNumber > 0) {
            graphData.resize(nodesNumber);
            for (int nodeIndex = 0; nodeIndex < nodesNumber; nodeIndex++) {
                _oth->GetNextVertices(nodeIndex, graphData[nodeIndex]);
            }
        }
    };

    virtual ~ListGraph() {};

    void AddEdge(int from, int to) override // Метод принимает вершины начала и конца ребра и добавляет ребро
    {
        if (from < 0 || from >= nodesNumber || to < 0 || to >= nodesNumber)
            return;

        bool found{ false };
        for (int i{ 0 }; i < graphData[from].size() && !found; i++) {
            if (graphData[from][i] == to) {
                found = true;
            }
        }

        if (!found)
            graphData[from].push_back(to);
    };

    int VerticesCount() const override { return graphData.size(); }; // Метод должен считать текущее количество вершин

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    {
        if (vertex < 0 || vertex >= nodesNumber)
            return;

        vertices.clear();
        for (int i{ 0 }; i < graphData[vertex].size(); i++) {
            vertices.push_back(graphData[vertex][i]);
        }
    };

    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    {
        if (vertex < 0 || vertex >= nodesNumber)
            return;

        vertices.clear();
        for (int i{ 0 }; i < nodesNumber; i++) {
            if (i == vertex)
                continue;

            for (int j{ 0 }; j < graphData[i].size(); j++) {
                if (graphData[i][j] == vertex) {
                    vertices.push_back(i);
                    break;
                }
            }
        }
    };
};

class MatrixGraph : public IGraph {
    std::vector<std::vector<int>> graphData;
    int nodesNumber{ 0 };

public:
    MatrixGraph() {};

    MatrixGraph(int _nodesNumber)
        : nodesNumber(_nodesNumber) {
        if (nodesNumber > 0) {
            std::cout << "MatrixGraph initialization\n";
            graphData.resize(nodesNumber);
            for (int nodeIndex = 0; nodeIndex < nodesNumber; nodeIndex++) {
                graphData[nodeIndex].resize(nodesNumber, 0); // preparing matrix
            }

            for (int node1Index = 0; node1Index < nodesNumber; node1Index++) {
                for (int node2Index = 0; node2Index < nodesNumber; node2Index++) {
                    if (node1Index == node2Index)
                        continue;

                    int connection{ 0 };
                    std::cout << "connection from #" << node1Index << " to #" << node2Index << ": ";
                    std::cin >> connection;
                    if (connection != 0) {
                        graphData[node1Index][node2Index] = 1;
                    }
                }
            }
        }
    };

    MatrixGraph(IGraph* _oth) {
        nodesNumber = _oth->VerticesCount();
        if (nodesNumber > 0) {
            graphData.resize(nodesNumber);
            for (int nodeIndex = 0; nodeIndex < nodesNumber; nodeIndex++) {
                graphData[nodeIndex].resize(nodesNumber);
                std::vector<int> currentConnections;
                _oth->GetNextVertices(nodeIndex, currentConnections);
                for (int connectIndex = 0; connectIndex < currentConnections.size(); connectIndex++) {
                    graphData[nodeIndex][currentConnections[connectIndex]] = 1;
                }
            }
        }
    };

    virtual ~MatrixGraph() {}

    void AddEdge(int from, int to) override // Метод принимает вершины начала и конца ребра и добавляет ребро
    {
        if (from < 0 || from >= nodesNumber || to < 0 || to >= nodesNumber)
            return;

        graphData[from][to] = 1;
    };

    int VerticesCount() const override { return graphData.size(); }; // Метод должен считать текущее количество вершин

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    {
        if (vertex < 0 || vertex >= nodesNumber)
            return;

        vertices.clear();
        for (int i{ 0 }; i < nodesNumber; i++) {
            if (graphData[vertex][i] != 0)
                vertices.push_back(i);
        }
    };

    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    {
        if (vertex < 0 || vertex >= nodesNumber)
            return;

        vertices.clear();
        for (int i{ 0 }; i < nodesNumber; i++) {
            if (graphData[i][vertex] != 0)
                vertices.push_back(i);
        }
    };
};

int main() {
    ListGraph L(4);
    MatrixGraph M(4);

    std::vector<int> someVector;

    L.AddEdge(0, 2);
    L.GetNextVertices(2, someVector);
    L.GetPrevVertices(3, someVector);

    M.AddEdge(0, 2);
    M.GetNextVertices(1, someVector);
    M.GetPrevVertices(2, someVector);

    ListGraph* someL = new ListGraph(&M);
    MatrixGraph* someM = new MatrixGraph(&L);

    delete someL;
    delete someM;
}