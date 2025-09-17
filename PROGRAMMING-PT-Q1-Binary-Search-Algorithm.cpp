#include <string>
#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::array;

array<int, 10> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
int targetValue = 0;

template <size_t n>
void performBinarySearch(int low, int high, const array<int, n>& searchArray, int targetValue) {
    if (low > high) {
        cout << "Value not found in array" << endl;
        return;
    }
    
    int middle = low + ((high-low)/2);
    
    cout << searchArray[middle] << endl;
    
    if (searchArray[middle] < targetValue) {
        low = middle + 1;
        performBinarySearch(low, high, searchArray, targetValue);
    }
    else  if (searchArray[middle] > targetValue) {
        high = middle - 1;
        performBinarySearch(low, high, searchArray, targetValue);
    }
    else  if (searchArray[middle] == targetValue) {
        cout << endl;
        cout << "Target value " << targetValue << " found at index " << middle;
        return;
    }
}

int main() {
    cout << "List of sorted numbers: ";
    for (int i = 0; i < sortedArray.size(); i++) {
        if (i < sortedArray.size()-1) {
            cout << sortedArray[i] << ", ";
        }
        else if (i == sortedArray.size()-1) {
            cout << sortedArray[i];
        }
    }
    cout << endl;
    
    cout << "Enter your target value to locate its index: " << endl;
    cin >> targetValue;
    cout << endl;
    
    cout << "Binary search space result:" << endl;
    performBinarySearch(0, sortedArray.size()-1, sortedArray, targetValue);
    
    return 0;
}