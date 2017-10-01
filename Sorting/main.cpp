#include "sort.h"
#include "Graph.h"

int main() {
	Graph<int> G;
	//G.addEdge(1004, 3134);
	//G.addEdge(3134, 3157);
	//G.addEdge(3203, 3261);
	//G.addEdge(3134, 4231);
	//G.addEdge(3136, 4231);
	//G.addEdge(1101, 1102);
	//G.addEdge(1102, 1207);
	//G.addEdge(1207, 1208);
	//G.addEdge(1208, 3951);
	//G.addEdge(3951, 3952);
	//G.addEdge(1208, 2500);
	//G.addEdge(1208, 4041);
	//G.addEdge(4041, 4042);
	//G.addEdge(1208, 4061);
	//G.addEdge(1208, 4051);
	//G.addEdge(4041, 4051);

	int MAXVALUE = 15;
	int MAXEDGES = 10;
	std::cout << "Dependencies: " << std::endl;
	for (int i = 0; i < MAXEDGES; ++i) {
		int u = rand() % MAXVALUE + 1;
		int v = rand() % MAXVALUE + 1;
		while (v == u)
			v = rand() % MAXVALUE + 1;
		std::cout << '(' << u << ", " << v << ')' << std::endl;
		G.addEdge(u, v);
	}
	try {
		sort::topologicalSort(G);
	}
	catch (CyclicGraphException& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}