#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "planet.cpp"
#include "getData.cpp"

#define Edge std::pair<char, char>

char fathers[100];

int find (int x) {
	if (fathers[x] == x) {
		return x;
	}
	return find (fathers[x]); // Do recursion until father is found
}

void unite (int x, int y) {
	int fx = find (x);
	int fy = find (y);
	fathers[fx] = fy;
}

// A subroutine that performs Kruskal's algorithm
void kruskal (std::vector<Planet> &vecPlanet) {
	// Vector of edges
	std::vector<std::pair<int, Edge>> edges;
	edges.push_back(std::make_pair(608, Edge('A', 'D')));
	edges.push_back(std::make_pair(584, Edge('A', 'J')));
	edges.push_back(std::make_pair(259, Edge('A', 'H')));
	edges.push_back(std::make_pair(473, Edge('A', 'F')));
	edges.push_back(std::make_pair(541, Edge('D', 'B')));
	edges.push_back(std::make_pair(465, Edge('J', 'G')));
	edges.push_back(std::make_pair(419, Edge('H', 'I')));
	edges.push_back(std::make_pair(625, Edge('F', 'C')));
	edges.push_back(std::make_pair(773, Edge('B', 'E')));
	edges.push_back(std::make_pair(818, Edge('G', 'E')));
	edges.push_back(std::make_pair(435, Edge('I', 'E')));
	edges.push_back(std::make_pair(544, Edge('C', 'E')));
	edges.push_back(std::make_pair(268, Edge('D', 'J')));
	edges.push_back(std::make_pair(580, Edge('J', 'H')));
	edges.push_back(std::make_pair(495, Edge('H', 'F')));
	edges.push_back(std::make_pair(688, Edge('B', 'G')));
	edges.push_back(std::make_pair(919, Edge('G', 'I')));
	edges.push_back(std::make_pair(590, Edge('I', 'C')));
	
	// Sort edges in ascending order according to weight of edge
	sort (edges.begin(), edges.end());
	
	for (int i = 0; i < 100; i++) {
		fathers[i] = i;
	}
	
	int mst_weight = 0, mst_edges = 0, mst_ni = 0;
	int totalVertices = 10;
	
	// Title
	std::cout << "KRUSKAL'S ALGORITHM\n\n"
			  << " Edge" << "       " << "Weight\n";
	
	while (mst_edges < totalVertices-1) {
		char a = edges[mst_ni].second.first;
		char b = edges[mst_ni].second.second;
		int w = edges[mst_ni].first;
		
		if (find(a) != find(b)) {
			unite (a,b);
			mst_weight += w;
			
			std::cout << "(" << a << ", " << b << ")" << "       " << w << std::endl;
			mst_edges++;
		}
		mst_ni++;
	}
	std::cout << "\nMinimum Cost Spanning Tree: " << mst_weight << std::endl;
}

int main () {
	// Planet vector
	std::vector<Planet> vecPlanet;
	
	// Get planet data and create planet instances
	getPlanetData (vecPlanet);
	
	// Calculate distance
	calculateDistance (vecPlanet);
	
	// Apply Kruskal's algorithm
	kruskal (vecPlanet);
	
	return 0;
}


