#include "sort.h"
#include "Graph.h"

int main() {
	//Graph<int> graph;
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
	srand(0);
	int MAXVALUE = 5e5;
	int MAXTRIALS = 10;

	for (int i = 0; i < MAXTRIALS; ++i) {
		int MAXEDGES = rand() % 20000 + 1;
		Graph<int> graph;
		std::cout << "Dependencies: " << std::endl;
		for (int j = 0; j < MAXEDGES; ++j) {
			int u = rand() % MAXVALUE + 1;
			int v = rand() % MAXVALUE + 1;
			while (v == u)
				v = rand() % MAXVALUE + 1;
			std::cout << '(' << u << ", " << v << ')' << std::endl;
			graph.addEdge(u, v);
		}
		try {
			sort::topologicalSort(graph);
		}
		catch (CyclicGraphException& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}