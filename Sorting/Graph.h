#pragma once
#include "Vertex.h"
#include <unordered_map>
#include <vector>
#include <queue>
#include "CyclicGraphException.h"

template <class T>
class Graph {
public:
	Graph();
	void addEdge(T u, T v);
	std::unordered_map<T, Vertex<T>*>& getvMap() { return vMap; };
private:
	std::unordered_map<T, Vertex<T>*> vMap;
};

template <class T>
Graph<T>::Graph()
	: vMap() {}

template <class T>
void Graph<T>::addEdge(T u, T v) {
	Vertex<T>* U = new Vertex<T>(u);
	Vertex<T>* V = new Vertex<T>(v);
	auto it_u = std::get<0>(vMap.emplace(u, U));
	auto it_v = std::get<0>(vMap.emplace(v, V));
	(*it_u->second).addVertex(it_v->second);
	++(*it_v->second);
}

namespace sort {
	template <class T>
	void topologicalSort(Graph<T>& G) {
		std::vector<T> ordered;
		std::queue<Vertex<T>*> q;
		unsigned int counter = 0;
		auto vMap = G.getvMap();
		// Get Vertices with 0 inDegree
		for (auto it = vMap.begin(); it != vMap.end(); ++it) {
			if ((*it->second).getinDegree() == 0) {
				q.push(it->second);
			}
		}
		
		while (!q.empty()) {
			auto v = q.front();
			q.pop();
			ordered.push_back((*v).getData());
			for (auto u : (*v).getAdjList()) {
				if ((--(*u)).getinDegree() == 0) {
					q.push(u);
				}
			}
			++counter;
		}
		if (counter != vMap.size()) {
			throw CyclicGraphException();
		}
		sort::print(ordered.begin(), ordered.end());
	}
};