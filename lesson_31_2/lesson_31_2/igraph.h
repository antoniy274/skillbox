#pragma once
#include <iostream>
#include <vector>


class IGraph
{
public:
	virtual ~IGraph() {};

	// Метод принимает вершины начала и конца ребра и добавляет ребро
	virtual void AddEdge(size_t from, size_t to) = 0;

	// Метод должен считать текущее количество вершин
	virtual void VerticesCount() const = 0;
	
	virtual void ShowGraph() const = 0;

	// Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
	virtual void GetNextVertices(size_t vertex, std::vector<size_t>& vertices)const = 0;

	// Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
	virtual void GetPrevVertices(size_t vertex, std::vector<size_t>& vertices) const = 0;
};