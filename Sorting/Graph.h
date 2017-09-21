#pragma once
#include "Vertex.h"
#include <unordered_map>
#include <vector>
#include <queue>
#include "CyclicGraphException.h"
#include <iostream>

template <class T>
class Graph {
public:
	Graph(const int vNum);
	void addEdge(Vertex<T>& u, Vertex<T>& v);
	
private:
	const int vNum;
	std::unordered_map<T, Vertex<T>*> VertexMap;
};

template <class T>
Graph<T>::Graph(const int vNum)
	: vNum(vNum), VertexMap() {}

template <class T>
void Graph<T>::addEdge(Vertex<T>& u, Vertex<T>& v) {
	(u).addVertex(&v);
}

template <>
class Graph<int> {
public:
	Graph(const int vNum);
	void addVertex(const int u);
	void addEdge(const int u, const int v);
	void toposort();
private:
	int vNum;
	int activeVnum;
	std::vector<Vertex<int>*> VertexMap;
	void printOrder(std::vector<Vertex<int>*>& vec) const;
};

Graph<int>::Graph(const int vNum)
	: vNum(vNum), activeVnum(0), VertexMap(vNum + 1, nullptr) {}

void Graph<int>::addVertex(const int u) {
	if (u > vNum) {
		throw std::out_of_range("Data not within the specified range.");
	}
	if (VertexMap[u] == nullptr) {
		VertexMap[u] = new Vertex<int>(u);
		++activeVnum;
	}
}
void Graph<int>::addEdge(const int u, const int v) {
	if (VertexMap[u] == nullptr)
		addVertex(u);
	if (VertexMap[v] == nullptr)
		addVertex(v);
	(*VertexMap[u]).addVertex(VertexMap[v]);
	++(*VertexMap[v]);
}

void Graph<int>::printOrder(std::vector<Vertex<int>*>& vec) const {
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << (**it).getData() << ' ';
	}
	std::cout << std::endl;
}
void Graph<int>::toposort() {
	std::queue<Vertex<int>* > q;
	std::vector<Vertex<int>*> sorted;
	int counter = 0;
	for (auto it = VertexMap.begin(); it != VertexMap.end(); ++it) {
		if (*it != nullptr && (**it).getInDegree() == 0) {
			q.push(*it);
		}
	}

	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		sorted.push_back(v);
		for (auto u : (*v).getAdjList()) {
			if ((--(*u)).getInDegree() == 0) {
				q.push(u);
			}
		}
		++counter;
	}
	if (counter != activeVnum) {
		throw CyclicGraphException();
	}

	printOrder(sorted);
}