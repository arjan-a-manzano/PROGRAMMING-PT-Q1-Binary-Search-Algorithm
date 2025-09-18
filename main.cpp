#include <string> // import libraries
#include <iostream>
#include <array>
#include <conio.h>

using std::cout; // namespace aliases
using std::cin;
using std::string;
using std::endl;
using std::array;

array<int, 10> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // search through this array
int targetValue = 0; // user inputs value that he or she wants to find

template <size_t n> // deduce the .size() type
void performBinarySearch(int low, int high, const array<int, n>& searchArray, int targetValue) { // low and high parameters are trackers for array indices
    if (low > high) { // tracker exceeds the search space
        cout << "Value not found in array" << endl;
        return;
    }
    
    int middle = low + ((high-low)/2); // reassign the position of the middle tracker in this recursive iteration
    
    cout << searchArray[middle] << endl;
    
    if (searchArray[middle] < targetValue) { // current searched number is smaller than the target number
        low = middle + 1; // adjust search space towards the right
        performBinarySearch(low, high, searchArray, targetValue); // recursive call using the recalculated low position
    }
    else  if (searchArray[middle] > targetValue) { // current searched number is bigger than the target number
        high = middle - 1; // adjust search space towards the left
        performBinarySearch(low, high, searchArray, targetValue); // recursive call using the recalculated high position
    }
    else  if (searchArray[middle] == targetValue) { // current searched number matches the target number
        cout << endl;
        cout << "Target value " << targetValue << " found at index " << middle; // output which index the target number can be found
        return;
    }
}

int main() {
    cout << "List of sorted numbers: ";
    for (int i = 0; i < static_cast<int>(sortedArray.size()); i++) { // list all array values in one line
        if (i < static_cast<int>(sortedArray.size())-1) {
            cout << sortedArray[i] << ", ";
        }
        else if (i == static_cast<int>(sortedArray.size())-1) { // prevent inserting comma at the end of the last array number
            cout << sortedArray[i];
        }
    }
    cout << endl;
    
    cout << "Enter your target value to locate its index: " << endl; // user will input an existing number he or she wants to find in the array
    cin >> targetValue;
    cout << endl;
    
    cout << "Binary search space result:" << endl;
    performBinarySearch(0, sortedArray.size()-1, sortedArray, targetValue); // either no value would be found or index containing that number would be displayed

    _getch();

    return 0;
}