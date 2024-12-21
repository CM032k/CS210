/*
 * GroceryTracker.cpp
 *
 *  Created on: Dec 19, 2024
 *      Author: christionmart_snhu
 */

#include "GroceryTracker.h"

namespace GroceryTracker {

GroceryTracker::GroceryTracker() {
	// TODO Auto-generated constructor stub

}

 /* namespace GroceryTracker */
void displayMenu() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Individual Frequency\n";
        std::cout << "2. Display Frequency List\n";
        std::cout << "3. Display Frequency Histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                individualFrequency();
                break;
            case 2:
                displayFrequencyList();
                break;
            case 3:
                displayFrequencyHistogram();
                break;
            case 4:
                saveDataToFile("frequency.dat");
                std::cout << "Data saved to frequency.dat. Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);
}

// Method to get frequency of a specific item
void individualFrequency() {
    std::string item;
    std::cout << "Enter the item you wish to look for: ";
    std::cin >> item;
	int itemFrequency;
    if (itemFrequency.find(item) != itemFrequency.end()) {
        std::cout << "Frequency of " << item << ": " << itemFrequency[item];
    } else {
        std::cout << "Item not found in the records.\n";
    }
}

// Method to display frequency list
void displayFrequencyList() {
	int itemFrequency;
    for (const auto& entry : itemFrequency) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }
}

// Method to display frequency histogram
void displayFrequencyHistogram() {
	int itemFrequency;
    for (const auto& entry : itemFrequency) {
        std::cout << entry.first << " ";
        for (int i = 0; i < entry.second; ++i) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

// Method to save data to a file
void saveDataToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
	int itemFrequency;
    for (const auto& entry : itemFrequency) {
        outputFile << entry.first << " " << entry.second << std::endl;
    }
    outputFile.close();
}
};

int main() {
GroceryTracker tracker;
tracker.readDataFromFile("CS210_Project_Three_Input_File.txt");
tracker.displayMenu();

return 0;
}
