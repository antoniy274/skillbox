#pragma once
#include <map>
#include <vector>
#include "igraph.h"

//
//  ListGraph class
//
class ListGraph : public IGraph
{

    std::map<std::size_t, std::vector<std::size_t>> _graph;

public:
    ListGraph();

    ListGraph(IGraph* oth);

    //ListGraph(const ListGraph &list_g);

    //ListGraph& operator= (const ListGraph &list_g);

    ~ListGraph();

    // ����� ��������� ������� ������ � ����� ����� � ��������� �����
    void AddEdge(size_t from, size_t to) override;

    // ����� ������ ������� ������� ���������� ������
    int VerticesCount() const override;

    // ����� ����� � ������� 
    void ShowGraph() const override;

    // ��� ���������� ������� ����� ������� � ������ ��������� ��� �������, � ������� ����� ����� �� ����� �� ������
    void GetNextVertices(size_t vertex, std::vector<size_t>& vertices) const override;

    // ��� ���������� ������� ����� ������� � ������ ��������� ��� �������, �� ������� ����� ����� �� ����� � ������
    void GetPrevVertices(size_t vertex, std::vector<size_t>& vertices) const override;

    void GetNameVertices(std::vector<std::size_t>& name) const;
};