#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "planet.cpp"
#include "getData.cpp"

template <typename T>
// A function that returns index
int getIndex (T object, std::string name) {
	auto itCon = find_if (object.begin(), object.end(),
						  [name](auto member) {
							  return member.name == name;});
	auto index = std::distance(object.begin(), itCon);
	
	return index;
}

// A subroutine that performs Dijkstra's algorithm
void dijkstra (std::vector<Planet> &vecPlanet) {
	// Set all connections of A to false/disconnected
	for (Connection &connections: vecPlanet[0].con) {
		if (connections.initial != 'A') {
			connections.isConnected = false;
		}
		else {
			connections.isConnected = true;
		}
	}
	
	int counter = 10;
	while (--counter) {
		// Make pair for vertex name, distance
		std::vector<std::pair<int, std::string>> distances;
		
		// Push all planets that are not connected to Planet A yet
		// to vector distances
		for (Connection &connections: vecPlanet[0].con) {
			if (connections.isConnected == false) {
				distances.push_back(std::make_pair(connections.distance,
									connections.name)); 
			}
		}
		
		// Sort in distances ascending order
		std::sort (distances.begin(), distances.end());
		
		// Planet with shortest distance to Planet A and is not
		// connected to Planet A
		std::string nearestPlanetName = distances[0].second;
		int nearestPlanetDist = distances[0].first;
		
		// Get planet index in connections
		int indexCon = getIndex (vecPlanet[0].con, nearestPlanetName);
		
		// Set connection status of planet with shortest distance to planet
		// A as connected
		vecPlanet[0].con[indexCon].isConnected = true;
		
		// Get planet index in vecPlanet	
		int indexPlanet = getIndex(vecPlanet, nearestPlanetName);
		
		// Relaxation method
		Planet relaxPivot = vecPlanet[indexPlanet];
		
		for (Connection connections: relaxPivot.con) { // Connections of pivot planet
			if (connections.isConnected) { // Planet connected to pivot
				for (Connection &con: vecPlanet[0].con) { // Access planet profile in Planet A's connections
					if (con.name == connections.name && !con.isConnected) {
						if (con.distance > connections.distance+nearestPlanetDist) {
							con.distance = connections.distance + nearestPlanetDist;
						}
					}
				}
			}
		}
		distances.clear();
	}
}

int main () {
	// Planet vector
	std::vector<Planet> vecPlanet;
	
	// Get planet data and create planet instances
	getPlanetData (vecPlanet);
	
	// Calculate distance
	calculateDistance (vecPlanet);
	
	// Apply Dijkstra's algorithm
	dijkstra (vecPlanet);
	
	// Display shortest path to every planet from Planet A
	std::cout << "Shortest distance from Planet_A:\n\n";
	
	for (size_t i = 1; i < vecPlanet[0].con.size(); i++) {
		std::cout << vecPlanet[0].con[i].name << " "
				  << vecPlanet[0].con[i].distance << std::endl;
	}

	return 0;
}

