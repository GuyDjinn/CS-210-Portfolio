#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <limits>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequencyMap;
    std::string inputFileName;
    std::string backupFileName;

public:
    ItemTracker(const std::string& inputFile = "CS210_Project_Three_Input_File.txt",
        const std::string& backupFile = "frequency.dat")
        : inputFileName(inputFile), backupFileName(backupFile) {
    }

    // Reads input file and populates the frequency map
    bool loadData() {
        std::ifstream inFS(inputFileName);
        if (!inFS.is_open()) {
            std::cout << "Error: Could not open input file: " << inputFileName << std::endl;
            return false;
        }

        std::string currentItem;
        while (inFS >> currentItem) {
            itemFrequencyMap[currentItem]++;
        }

        inFS.close();
        return true;
    }

    // Writes accumulated data to frequency.dat without user intervention
    bool writeBackupFile() const {
        std::ofstream outFS(backupFileName);
        if (!outFS.is_open()) {
            std::cout << "Error: Could not create backup file: " << backupFileName << std::endl;
            return false;
        }

        for (const auto& pair : itemFrequencyMap) {
            outFS << pair.first << " " << pair.second << "\n";
        }

        outFS.close();
        return true;
    }

    // Menu Option 1: Return the frequency count for a single item
    int getItemFrequency(const std::string& itemName) const {
        auto it = itemFrequencyMap.find(itemName);
        if (it != itemFrequencyMap.end()) {
            return it->second;
        }
        return 0;
    }

    // Menu Option 2: Print all items and their numeric counts
    void printAllFrequencies() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << " Daily Sales Frequency List\n";
        std::cout << "----------------------------------------\n";
        for (const auto& pair : itemFrequencyMap) {
            std::cout << std::left << std::setw(15) << pair.first
                << " " << pair.second << "\n";
        }
        std::cout << "----------------------------------------\n";
    }

    // Menu Option 3: Print all items with a text-based histogram
    void printHistogram() const {
        std::cout << "\n----------------------------------------\n";
        std::cout << " Daily Sales Histogram\n";
        std::cout << "----------------------------------------\n";
        for (const auto& pair : itemFrequencyMap) {
            std::cout << std::left << std::setw(15) << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                std::cout << "*";
            }
            std::cout << "\n";
        }
        std::cout << "----------------------------------------\n";
    }
};

void displayMenu() {
    std::cout << "\n========== CORNER GROCER ITEM TRACKER ==========\n";
    std::cout << "1. Look up an item's frequency\n";
    std::cout << "2. Print all items and frequencies\n";
    std::cout << "3. Print histogram of item frequencies\n";
    std::cout << "4. Exit program\n";
    std::cout << "Enter your choice (1-4): ";
}

int main() {
    ItemTracker tracker;

    // Load data from input file
    if (!tracker.loadData()) {
        std::cout << "Failed to load input file. Please verify file path." << std::endl;
        return 1;
    }

    // Automatically create frequency.dat backup file
    if (!tracker.writeBackupFile()) {
        std::cout << "Failed to generate frequency.dat backup file." << std::endl;
        return 1;
    }

    int choice = 0;

    while (choice != 4) {
        displayMenu();

        if (!(std::cin >> choice)) {
            // Handle non-numeric input error
            std::cout << "\nInvalid input. Please enter a valid number (1-4).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            std::string searchItem;
            std::cout << "Enter the item name to search: ";
            std::cin >> searchItem;

            int count = tracker.getItemFrequency(searchItem);
            std::cout << "\nFrequency of '" << searchItem << "': " << count << "\n";
            break;
        }
        case 2:
            tracker.printAllFrequencies();
            break;

        case 3:
            tracker.printHistogram();
            break;

        case 4:
            std::cout << "\nExiting Corner Grocer Tracker. Have a good day!\n";
            break;

        default:
            std::cout << "\nInvalid choice. Please select an option between 1 and 4.\n";
            break;
        }
    }

    return 0;
}