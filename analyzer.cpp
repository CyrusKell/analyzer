// Title: Software Engineering
// Name: Cyrus Kell
// Partner: Timothy Macias
// Date: 10/11/23

#include <iostream>
#include <vector>
#include <array>
#include "StringData.h"

int linearSearch(std::vector<std::string> container, std::string element) {
    for (int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}


int binarySearch(std::vector<std::string> container, std::string element) {
    int lowIndex = 0;
    int highIndex = container.size() - 1;

    if (container[0] == element) return 0;
    else if (container[container.size() - 1] == element) return container.size() - 1;
    else {
        while (container[lowIndex] <= container[highIndex]) {
            int midIndex = (lowIndex + highIndex) / 2;
            if (container[midIndex] == element) return midIndex;
            else if (container[midIndex] > element) highIndex = midIndex - 1;
            else if (container[midIndex] < element) lowIndex = midIndex + 1;
        }
        return -1;
    }
}

void compareSearch(std::vector<std::string> data, std::string search) {
    using namespace std::chrono;

    // Get time to perform linear search
    system_clock::time_point lSearchStart = system_clock::now();
    int linear = linearSearch(data, search);
    system_clock::time_point lSearchFinish = std::chrono::system_clock::now();
    double lSearchTime = std::chrono::duration<double, std::milli>(lSearchFinish-lSearchStart).count();

    // Get time to perform binary search
    auto bSearchStart = system_clock::now();
    int binary = binarySearch(data, search);
    auto bSearchFinish = system_clock::now();
    double bSearchTime = std::chrono::duration<double, std::milli>(bSearchFinish-bSearchStart).count();

    std::cout << search << " : (" << lSearchTime << ", " << linear << ", " << bSearchTime << ", " << binary << ") \n";
}


int main() {
    std::vector<std::string> data = getStringData();
    std::cout << "SEARCH_VALUE : (LINEAR_SEARCH_TIME, LINEAR_SEARCH_INDEX, BINARY_SEARCH_TIME, BINARY_SEARCH_INDEX) \n";
    compareSearch(data, "not_here");
    compareSearch(data, "mzzzz");
    compareSearch(data, "aaaaa");
    return 0;
}