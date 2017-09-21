#pragma once
#include <list>

template <class T>
class Vertex {
public:
	Vertex(const T d);
	const T getData() const { return data; };
	const int getInDegree() const { return inDegree; };
	void addVertex(Vertex* v);
	std::list<Vertex*>& getAdjList() { return adjList; };
	Vertex& operator++() { ++inDegree; return *this; };
	Vertex& operator--() { --inDegree; return *this; };
private:
	const T data;
	int inDegree;
	std::list<Vertex*> adjList;
};

template <class T>
Vertex<T>::Vertex(const T d)
	: data(d), inDegree(0), adjList() {}

template <class T>
void Vertex<T>::addVertex(Vertex* v) {
	adjList.push_back(v);
}



