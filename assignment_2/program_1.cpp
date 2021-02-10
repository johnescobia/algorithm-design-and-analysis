#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm> // radom_shuffle
#include "planet.cpp"
#include "getData.cpp"

#define Edge std::pair<char, char>

// A subroutine that merges two halves from mergeSort()
void merge (std::vector<std::pair<int, Edge>> &A,
			std::vector<std::pair<int, Edge>> &Temp,
			int p, int m, int r, std::string type) {
	int i, j;
	
	for (i = m + 1; i > p; i--)
		Temp[i - 1] = A[i - 1];
		
	for (j = m; j < r; j++)
		Temp [r + m - j] = A[j + 1];
		
	for (int k = p; k <= r; k++) {
		if (type == "ascending") { // Ascending order
			if (Temp[j] < Temp[i]) A[k] = Temp[j--];
			else A[k] = Temp[i++];
		}
		else { // Descending order
			if (Temp[j] > Temp[i]) A[k] = Temp[j--];
			else A[k] = Temp[i++];
		}
	}
}

// A subroutine that does merge sort
void mergeSort (std::vector<std::pair<int, Edge>> &A,
			   std::vector<std::pair<int, Edge>> &Temp,
			   int p, int r, std::string type) {
	// Stop if only one element
	if (p < r) {
		// Divide: divide a into two nearly equal parts
		int m = (p + r) / 2;
		
		// Recur: sort left half
		mergeSort (A, Temp, p, m, type);
		
		// Recur: sort right half
		mergeSort (A, Temp, m + 1, r, type);
		
		// Conquer: merge the two sorted halves
		merge (A, Temp, p, m, r, type);
	 }

}

// A subroutine that initializes edges of directly connected planets
// with distance zero
void storeEdges (std::vector<std::pair<int, Edge>> &edges) {
	edges.push_back(std::make_pair(0, Edge('A', 'D')));
	edges.push_back(std::make_pair(0, Edge('A', 'J')));
	edges.push_back(std::make_pair(0, Edge('A', 'H')));
	edges.push_back(std::make_pair(0, Edge('A', 'F')));
	edges.push_back(std::make_pair(0, Edge('D', 'B')));
	edges.push_back(std::make_pair(0, Edge('J', 'G')));
	edges.push_back(std::make_pair(0, Edge('H', 'I')));
	edges.push_back(std::make_pair(0, Edge('F', 'C')));
	edges.push_back(std::make_pair(0, Edge('B', 'E')));
	edges.push_back(std::make_pair(0, Edge('G', 'E')));
	edges.push_back(std::make_pair(0, Edge('I', 'E')));
	edges.push_back(std::make_pair(0, Edge('C', 'E')));
	edges.push_back(std::make_pair(0, Edge('D', 'J')));
	edges.push_back(std::make_pair(0, Edge('J', 'H')));
	edges.push_back(std::make_pair(0, Edge('H', 'F')));
	edges.push_back(std::make_pair(0, Edge('B', 'G')));
	edges.push_back(std::make_pair(0, Edge('G', 'I')));
	edges.push_back(std::make_pair(0, Edge('I', 'C')));		
}

// A subroutine to displays the adjacency list
void displayAdjacencyList (const std::vector<Planet> vecPlanet) {
	// Header label
	std::cout << "-----------  ADJACENCY LIST  ------------\n\n";
		
	int j = 0;
	
	// Access each planet
	for (auto planet: vecPlanet) {
		// Print planet initials at the left most column
		std::cout << planet.initial;
		
		// Check connections with other planets
		for (auto connection : planet.con) {
			// Print planet initial and distance if planet is connected
			if (connection.name == vecPlanet[j].name
			&& connection.isConnected == true) {
				std::cout << " --> " << connection.initial;
				std::cout << "|" << connection.distance;
			}				
			j++;
		}
		j = 0;
		std::cout << "\n\n";
	}
}

// A subroutine to displays the adjacency matrix
void displayAdjacencyMatrix (const std::vector<Planet> vecPlanet) {
	// Header label
	std::cout << "-------------------------------  ADJACENCY MATRIX  ------------------------------\n\n";
	
	std::cout << std::setw(9);
	
	// Print planet initials at the top row
	for (auto planet: vecPlanet) {
		std::cout << planet.initial;
		std::cout << std::setw(8);
	}
	
	std::cout << "\n\n";
	std::string inf = "       ";
	inf += "\u221E";
	int j = 0;
	
	// Access each planet
	for (Planet planet : vecPlanet) {
		std::cout << std::setw(1);
		
		// Print planet initials at the left most column
		std::cout << planet.initial;
		
		// Check connections with other planets
		for (Connection connection : planet.con) {
			std::cout << std::setw(8);
			
			// Print distance if planet is connected, else print infinity
			if (connection.name == vecPlanet[j].name
			&& connection.isConnected == true) {
				 std::cout << connection.distance;
			}
			else {
				
				std::cout << inf;
			}					
			j++;
		}
		j = 0;
		std::cout << "\n\n";
	}
	std::cout << "\n\n\n";	
}

int main () {	
	// Planet vector
	std::vector<Planet> vecPlanet;
	
	// Get planet data and create planet instances
	getPlanetData (vecPlanet);
	
	// Edges vector
	std::vector<std::pair<int, Edge>> edges;
	
	// Create vector of edges in randomized arrangement
	storeEdges (edges);
	
	// Calculate distance
	calculateDistance (vecPlanet, edges);
	
	// Create adjacency matrix
	displayAdjacencyMatrix (vecPlanet);
	
	// Create adjacency list
	displayAdjacencyList (vecPlanet);
	
	// Randomly arrange vector edges
	std::random_shuffle (edges.begin(), edges.end());
	
	// Merge-sort edges distance in ascending order
	std::vector<std::pair<int, Edge>> Temp (18);
	mergeSort (edges, Temp, 0, edges.size()-1, "ascending");

	// List edges in ascending order of distance (merge-sort)
	std::cout << "\n\n\n---PLANET DISTANCE---\n";
	std::cout << " Edge" << "        " << "Distance\n";
	for (auto edge: edges) {
		std::cout << "(" << edge.second.first << ", "
				  << edge.second.second << ")" << "          "
				  << edge.first << std::endl;
	}
	
	// Merge-sort vector values in descending order
	std::vector<std::pair<int, Edge>> values;
	for (auto planet: vecPlanet) {
		values.push_back(std::make_pair(planet.value,
						 Edge(planet.initial, planet.initial)));
	}
	
	std::vector<std::pair<int, Edge>> valTemp (10);
	
	mergeSort (values, valTemp, 0, values.size()-1, "descending");
	
	// List values of planet in descending order
	std::cout << "\n\n\n---PLANET VALUES---\n";
	std::cout << "Planet" << "        " << "Value\n";
	for (auto val: values) {
		std::cout << "  "
				  << val.second.first
				  << "            "
				  << val.first
				  << std::endl;
	}

	return 0;
}
