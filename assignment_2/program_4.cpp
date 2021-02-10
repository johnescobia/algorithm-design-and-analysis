#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm> // max
#include <iomanip> // setw(8)
#include "planet.cpp"
#include "getData.cpp"

// A subroutine that implements 0/1 knapsack problem
void knapsack (std::vector<Planet> planet) {
	int knapsackTable[11][81];
	int num1, num2;
	
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 80; j++) {
			knapsackTable[i][j] = 0;
		}
	}

    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 80; j++) {
            if (planet[i-1].weight <= j) {
				num1 = knapsackTable[i - 1][j];
				num2 = knapsackTable[i - 1][j - planet[i-1].weight]
									+ planet[i-1].profit;
                knapsackTable[i][j] = std::max(num1, num2);
            }
            else {
                knapsackTable[i][j] = knapsackTable[i - 1][j];
            }
        }
	}
	
	int verticalKnapsackTable[81][11];
	
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 80; j++) {
			verticalKnapsackTable[j][i] = knapsackTable[i][j];
		}
	}
	
	std::cout << std::setw(16);
	
	for (int i = 0; i <= 10; i++) {
		std::cout << i;
		std::cout << std::setw(8);
	}
	
	std::cout << "\n\n\n";
	
	// Print vertical knapsack table
	for (int i = 0; i <= 80; i++) {
		std::cout << std::setw(8);
		std::cout << i;
		std::cout << std::setw(8);

		for (int j = 0; j <= 10; j++) {
			std::cout << verticalKnapsackTable[i][j];
			std::cout << std::setw(8);
		}
		std::cout << "\n";
	}
}

int main () {
	// Planet vector
	std::vector<Planet> vecPlanet;
	
	// Get planet data and create planet instances
	getPlanetData (vecPlanet);
	
	// Calculate distance
	calculateDistance (vecPlanet);
	
	// Implement 0/1 knapsack problem
	knapsack (vecPlanet);
	

	return 0;
}
