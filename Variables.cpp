#include <iostream>
#include <fstream>
#include <chrono>
#include "Menu.cpp"
#include "SearchData.cpp"

// Number of emails
int n = 0;

// Option determines combination n and fileName
int option = 0;

// Text file name
std::string fileName = "";

// Variable to write file. Only used to generate data in GenerateData.cpp
std::ofstream writeFile;

// Variable to open text file - fileName.txt
std::fstream readFile;

// Difference between start and end time of a specific function
std::chrono::duration<double> duration;

// Time taken to search searchable 10 emails
std::chrono::duration<double> searchableDuration;

// Time taken to search unsearchable 10 emails
std::chrono::duration<double> unsearchableDuration;

// Total of duration
double totalDuration = 0;

// Total of searchableDuration
double totalSeachableTime = 0;

// Total of unsearchableDuration
double totalUnsearchableTime = 0;

// Stores line from fileName.txt one line at a time
std::string line = "";

// Email to be searched
std::string target = "";
