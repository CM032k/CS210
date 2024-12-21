/*
 * GroceryTracker.h
 *
 *  Created on: Dec 19, 2024
 *      Author: christionmart_snhu
 */


#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency; // Map to store item and its frequency

public:
    // Method to read data from the input file and populate itemFrequency map
    void readDataFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (inputFile.is_open()) {
            std::string item;
            int frequency;
            while (inputFile >> item >> frequency) {
                itemFrequency[item] = frequency;
            }
            inputFile.close();
        } else {
            std::cerr << "Error opening file: " << filename << std::endl;
        }
    }
