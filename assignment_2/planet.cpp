#include <climits> // INT_MAx

struct Connection {
	std::string name; // Planet name
	char initial;     // Planet initial
	bool isConnected; // Connection status
	int distance;     // Connection distance
};

class Planet {
	public:
	
	// Attributes
    std::string name;            // Planet name
    char initial;                // Planet initial
    int x, y, z;                 // Planet coordinates
    int weight, profit, value;   // Planet weight, profit and value
	std::vector<Connection> con; // Connections of planet
    
    // Constructor
    Planet (std::string arr[]) {
		name = arr[0];           // Planet name
		initial = arr[0].at(7);  // Planet initial         
		x = stoi(arr[1]);        // x-coordinate
		y = stoi(arr[2]);        // y-coordinate
		z = stoi(arr[3]);        // z-coordinate
		weight = stoi(arr[4]);   // Planet weight
		profit = stoi(arr[5]);   // Planet profit
		
		// Planet value
		if (weight == 0 || profit == 0) {
			value = 0;
		}
		else {
			value = profit / weight;

		}
		
		// Set planet connections
		setConnections (name);
	}
	
	// A subroutine that sets the distance of a connection
	void setDistance (std::string name, int distance) {	
		for (Connection &c: con) {
			if (c.name == name) {
				c.distance = distance;
			}
		}
	}
	
	// A subroutine that sets which planets are directly connected
	// to the current planet and which are not
	void setConnections (std::string name) {
		// Manual string array for planet names is needed because planets
		// are still being instantiated at this point
		std::string planetNames[10] = {
			"Planet_A", "Planet_B", "Planet_C", "Planet_D", "Planet_E",
			"Planet_F", "Planet_G", "Planet_H", "Planet_I", "Planet_J"};
		
		// Access each planet name
		for (std::string nameArr : planetNames) {
			Connection c;            // Create Connection instance
			c.name = nameArr;        // Set planet name of connection
			c.isConnected = false;   // Initialize connection as not connected
			c.distance = INT_MAX;    // Limit of integer to represent infinity
			
			// Initialize initials
			if (nameArr == "Planet_A") c.initial = 'A';
			else if (nameArr == "Planet_B") c.initial = 'B';
			else if (nameArr == "Planet_C") c.initial = 'C';
			else if (nameArr == "Planet_D") c.initial = 'D';
			else if (nameArr == "Planet_E") c.initial = 'E';
			else if (nameArr == "Planet_F") c.initial = 'F';
			else if (nameArr == "Planet_G") c.initial = 'G';
			else if (nameArr == "Planet_H") c.initial = 'H';
			else if (nameArr == "Planet_I") c.initial = 'I';
			else c.initial = 'J';
			
			// Set directly connected planets
			if (name == "Planet_A") {
				if (nameArr == "Planet_D" || nameArr == "Planet_F"
				|| nameArr == "Planet_H" || nameArr == "Planet_J") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_B") {
				if (nameArr == "Planet_D" || nameArr == "Planet_E"
				|| nameArr == "Planet_G") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_C") {
				if (nameArr == "Planet_E" || nameArr == "Planet_F"
				|| nameArr == "Planet_I") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_D") {
				if (nameArr == "Planet_A" || nameArr == "Planet_B"
				|| nameArr == "Planet_J") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_E") {
				if (nameArr == "Planet_C" || nameArr == "Planet_B"
				|| nameArr == "Planet_G" || nameArr == "Planet_I") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_F") {
				if (nameArr == "Planet_A" || nameArr == "Planet_C"
				|| nameArr == "Planet_H") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_G") {
				if (nameArr == "Planet_B" || nameArr == "Planet_E"
				|| nameArr == "Planet_I" || nameArr == "Planet_J") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_H") {
				if (nameArr == "Planet_A" || nameArr == "Planet_F"
				|| nameArr == "Planet_I" || nameArr == "Planet_J") {
					c.isConnected = true;
				}
			}
			else if (name == "Planet_I") {
				if (nameArr == "Planet_C" || nameArr == "Planet_E"
				|| nameArr == "Planet_G" || nameArr == "Planet_H") {
					c.isConnected = true;
				}
			}
			else {
				if (nameArr == "Planet_A" || nameArr == "Planet_D"
				|| nameArr == "Planet_G" || nameArr == "Planet_H") {
					c.isConnected = true;
				}
			}
			// Add connection instance to con vector
			con.push_back (c);
		}
	}
};
