#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono> // για καταμετρηση χρονου
#include "Minheap.h"
#include "Maxheap.h"
#include "Hashtable.h"

int main() {
    std::ifstream inputFile("commands.txt");
    std::ofstream outputFile("output.txt");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening input or output file." << std::endl;
        return 1;
    }

    std::string line;
    Minheap minheap;
    Maxheap maxheap;
    Hashtable hashtable;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string command, structure;
        iss >> command >> structure;

        if (command == "BUILD") {
            std::string filename;
            if (structure == "HASHTABLE") { //εδω τσεκαρει αν εχω min/max heap ή hashtable γιατι διαβαζει διαφορετικα αρχεια
                filename = "data2.txt"; //αν η εντολη build Καλειται για hashtable
            } else {
                filename = "data.txt"; //αν η εντολη build Καλειται για min/max heap
            }
            std::ifstream dataFile(filename);
            if (!dataFile.is_open()) {
                std::cerr << "Error opening data file: " << filename << std::endl;
                outputFile << "Error opening data file: " << filename << std::endl;
            } else {
                auto start = std::chrono::high_resolution_clock::now();
                if (structure == "MINHEAP") {
                    int num;
                    while (dataFile >> num) {
                        minheap.insert(num);
                    }
                } else if (structure == "MAXHEAP") {
                    int num;
                    while (dataFile >> num) {
                        maxheap.insert(num);
                    }
                } else if (structure == "HASHTABLE") {
                    int key;
                    std::string value;
                    while (dataFile >> key && std::getline(dataFile, value)) {
                        // Remove the leading space and quotes from the value
                        value.erase(0, value.find_first_not_of(" \""));
                        value.erase(value.find_last_not_of("\"") + 1);
                        hashtable.insert(key, value);
                    }
                }
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
                outputFile << "BUILD, Building " << structure << " Time taken: " << duration.count() << " nanoseconds." << std::endl;
            }
            dataFile.close();
        } else if (command == "GETSIZE") {
            auto start = std::chrono::high_resolution_clock::now();
            int size = 0;
            if (structure == "MINHEAP") {
                size = minheap.getSize();
            } else if (structure == "MAXHEAP") {
                size = maxheap.getSize();
            } else if (structure == "HASHTABLE") {
                size = hashtable.getSize();
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            outputFile << "GETSIZE, size of " << structure << " is: " << size << " (Time taken: " << duration.count() << " nanoseconds)" << std::endl;
        } else if (command == "FINDMIN" && structure == "MINHEAP") {
            auto start = std::chrono::high_resolution_clock::now();
            int min = minheap.getMin();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            outputFile << "FINDMIN, min in heap is: " << min << " (Found in " << duration.count() << " nanoseconds). Time taken: " << duration.count() << " nanoseconds." << std::endl;
        } else if (command == "FINDMAX" && structure == "MAXHEAP") {
            auto start = std::chrono::high_resolution_clock::now();
            int max = maxheap.getMax();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            outputFile << "FINDMAX, max in heap is: " << max << " (Found in " << duration.count() << " nanoseconds). Time taken: " << duration.count() << " nanoseconds." << std::endl;
        } else if (command == "SEARCH" && structure == "HASHTABLE") {
            int key;
            iss >> key;
            auto start = std::chrono::high_resolution_clock::now();
            std::string value;
            bool found = hashtable.search(key, value);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            if (found) {
                outputFile << "SEARCH, key " << key << " found in hashtable with value " << value << ". Time taken: " << duration.count() << " nanoseconds." << std::endl;
            } else {
                outputFile << "SEARCH, key " << key << " not found in hashtable. Time taken: " << duration.count() << " nanoseconds." << std::endl;
            }
        } else if (command == "INSERT") {
            int num;
            iss >> num;
            auto start = std::chrono::high_resolution_clock::now();
            if (structure == "MINHEAP") {
                minheap.insert(num);
            } else if (structure == "MAXHEAP") {
                maxheap.insert(num);
            } else if (structure == "HASHTABLE") {
                std::string value;
                std::getline(iss, value);
                // Remove the leading space and quotes from the value
                value.erase(0, value.find_first_not_of(" \""));
                value.erase(value.find_last_not_of("\"") + 1);
                hashtable.insert(num, value);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            outputFile << "INSERT, (" << num << ") in " << structure << ". Time taken: " << duration.count() << " nanoseconds." << std::endl;
        } else if (command == "DELETEMIN" && structure == "MINHEAP") {
            auto start = std::chrono::high_resolution_clock::now();
            int min = minheap.getMin();
            minheap.deleteMin();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            outputFile << "DELETEMIN, (" << min << ") in Minheap. Time taken: " << duration.count() << " nanoseconds." << std::endl;
        } else if (command == "DELETEMAX" && structure == "MAXHEAP") {
            auto start = std::chrono::high_resolution_clock::now();
            int max = maxheap.getMax();
            maxheap.deleteMax();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            outputFile << "DELETEMAX, (" << max << ") in Maxheap. Time taken: " << duration.count() << " nanoseconds." << std::endl;
        }
    }

    outputFile.close();
    return 0;
}







