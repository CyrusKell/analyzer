/* Lab 05 - Software Engineering
Author: Timothy Macias
Version: 2023.10.11
Lab Partner: Cyrus K
*/

#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"

using namespace std;

/* Linear search algorithm, O(n)
 * Parameters:
 *      container: an array containing strings as elements
 *      element: a value (string) to search for in the container parameter
 * Returns: the index of element, if found, otherwise returns -1
*/
int linearSearch(vector<string> container, const string& element)
{
    for (int i = 0; i < container.size(); i++)
        if (container[i] == element)
            return i;
    return -1;
}

/* Binary search algorithm, O(log n)
 * Parameters:
 *      container: an array containing strings as elements
 *      element: a value (string) to search for in the container parameter
 * Returns: the index of element, if found, otherwise returns -1
*/
int binarySearch(vector<string> container, const string& element)
{
    int low = 0;
    int high = int(container.size()) - 1;
    int mid;

    while (high >= low) {
        mid = (high + low) / 2;
        if (container[mid] < element)
            low = mid + 1;
        else if (container[mid] > element)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main() {
    // Populate the data variable with a tuple of over 17,000 elements
    vector<string> data = getStringData();
    // Contains the values that will be searched for in the dataset
    vector<string> keys = {"not_here", "mzzzz", "aaaaa"};

    // Try finding each key specified above using both linear and binary search
    for (const string& key : keys) {
        long long initialTime, finalTime;
        int index;

        // Linear search testing
        initialTime = systemTimeNanoseconds();
        index = linearSearch(data, key);
        finalTime = systemTimeNanoseconds();
        printf("Linear Search"
               "\n-------------"
               "\nSearching for: %s"
               "\nIndex: %d"
               "\nTime: %lld\n\n",
               key.c_str(), index,  finalTime - initialTime);

        // Binary search testing
        initialTime = systemTimeNanoseconds();
        index = binarySearch(data, key);
        finalTime = systemTimeNanoseconds();
        printf("Binary Search"
               "\n-------------"
               "\nSearching for: %s"
               "\nIndex: %d"
               "\nTime: %lld\n\n",
               key.c_str(), index,  finalTime - initialTime);
    }

    return 0;
}
