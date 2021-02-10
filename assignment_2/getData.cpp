#include <cmath>

#define Edge std::pair<char, char>

// A subroutine that add edges distances to vector of edges
void setEdges (std::vector<std::pair<int, Edge>> &edges, char planetOne,
               char planetTwo, int distance) {	
	// Set edge weight
	if ((planetOne == 'A' && planetTwo == 'D')
	|| (planetOne == 'D' && planetTwo == 'A'))
		edges[0].first = distance;
	else if ((planetOne == 'A' && planetTwo == 'J')
	|| (planetOne == 'J' && planetTwo == 'A'))
		edges[1].first = distance;
	else if ((planetOne == 'A' && planetTwo == 'H')
	|| (planetOne == 'H' && planetTwo == 'A'))
		edges[2].first = distance;
	else if ((planetOne == 'A' && planetTwo == 'F')
	|| (planetOne == 'F' && planetTwo == 'A'))
		edges[3].first = distance;
	else if ((planetOne == 'D' && planetTwo == 'B')
	|| (planetOne == 'B' && planetTwo == 'D'))
		edges[4].first = distance;
	else if ((planetOne == 'J' && planetTwo == 'G')
	|| (planetOne == 'G' && planetTwo == 'J'))
		edges[5].first = distance;
	else if((planetOne == 'H' && planetTwo == 'I')
	|| (planetOne == 'I' && planetTwo == 'H'))
		edges[6].first = distance;
	else if ((planetOne == 'F' && planetTwo == 'C')
	|| (planetOne == 'C' && planetTwo == 'F'))
		edges[7].first = distance;
	else if ((planetOne == 'B' && planetTwo == 'E')
	|| (planetOne == 'E' && planetTwo == 'B'))
		edges[8].first = distance;
	else if ((planetOne == 'G' && planetTwo == 'E')
	|| (planetOne == 'E' && planetTwo == 'G'))
		edges[9].first = distance;
	else if ((planetOne == 'I' && planetTwo == 'E')
	|| (planetOne == 'E' && planetTwo == 'I'))
		edges[10].first = distance;
	else if ((planetOne == 'C' && planetTwo == 'E')
	|| (planetOne == 'E' && planetTwo == 'C'))
		edges[11].first = distance;
	else if ((planetOne == 'D' && planetTwo == 'J')
	|| (planetOne == 'J' && planetTwo == 'D'))
		edges[12].first = distance;
	else if ((planetOne == 'J' && planetTwo == 'H')
	|| (planetOne == 'H' && planetTwo == 'J'))
		edges[13].first = distance;
	else if ((planetOne == 'H' && planetTwo == 'F')
	|| (planetOne == 'F' && planetTwo == 'H'))
		edges[14].first = distance;
	else if((planetOne == 'B' && planetTwo == 'G')
	|| (planetOne == 'G' && planetTwo == 'B'))
		edges[15].first = distance;
	else if ((planetOne == 'G' && planetTwo == 'I')
	|| (planetOne == 'I' && planetTwo == 'G'))
		edges[16].first = distance;
	else
		edges[17].first = distance;
}

// A subroutine to calculate the distance of connected planets
void calculateDistance (std::vector<Planet> &vecPlanet) {
	for (Planet &planetOne: vecPlanet) { // Access each planet 1 
		for (Connection connection: planetOne.con) { // Access each connection of planet 1
			if (connection.isConnected == true) { // Check which planet is directly connected
				int index = 0;
				for (Planet planetTwo: vecPlanet) { // Access planet 2
					if (planetTwo.name == connection.name) { // Calculated distance if directly connected
						int x = pow (planetOne.x-planetTwo.x,2);
						int y = pow (planetOne.y-planetTwo.y,2);
						int z = pow (planetOne.z-planetTwo.z,2);
						int distance = sqrt (x + y + z);
						planetOne.setDistance (connection.name, distance);
					}
					index++;
				}
			}
		}
	}
}

// A subroutine to calculate the distance of connected planets
void calculateDistance (std::vector<Planet> &vecPlanet,
                        std::vector<std::pair<int, Edge>> &edges) {
	for (Planet &planetOne: vecPlanet) { // Access each planet 1
		for (Connection connection: planetOne.con) { // Access each connection of planet 1
			if (connection.isConnected == true) { // Check which planet is directly connected
				int index = 0;
				for (Planet planetTwo: vecPlanet) { // Access planet 2
					if (planetTwo.name == connection.name) { // Calculated distance if directly connected
						int x = pow (planetOne.x-planetTwo.x,2);
						int y = pow (planetOne.y-planetTwo.y,2);
						int z = pow (planetOne.z-planetTwo.z,2);
						int distance = sqrt (x + y + z);
						planetOne.setDistance (connection.name, distance);
						setEdges (edges, planetOne.initial, planetTwo.initial, distance);
					}
					index++;
				}
			}
		}
	}
}

// A subroutine to create planet instances
void createPlanet (std::vector<Planet> &vecPlanet, std::string planetData) {
	std::istringstream iss (planetData);
    std::string planetDataWord;
    
    // Store planet data to array
    std::string arr[6];
    int i = 0;
    while (iss >> planetDataWord) {
        arr[i] = planetDataWord;
        ++i;
    }
    
    // Create instance of planet
    Planet planet (arr);
    
    // Put planet to vector
    vecPlanet.push_back (planet);
}

// A subroutine to get planet data from text file
void getPlanetData (std::vector<Planet> &vecPlanet) {
	std::fstream readFile;
	readFile.open("A2planets.txt", std::ios::in);
	
	std::string planet = "";

	while (true) {
		getline (readFile, planet);
		
		if (readFile.eof()) {
			break;
		}
		
		createPlanet(vecPlanet, planet);
	}

	readFile.close();
}
