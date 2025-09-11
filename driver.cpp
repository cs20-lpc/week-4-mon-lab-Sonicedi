#include "LinkedList.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    LinkedList<string> myList;

    cout << "=== Initial List ===" << endl;
    cout << myList << endl;

    // Append elements
    cout << "--- Appending elements ---" << endl;
    myList.append("Alpha");
    myList.append("Beta");
    myList.append("Gamma");
    cout << myList;

    // Insert at front
    cout << "--- Inserting at position 0 ---" << endl;
    myList.insert(0, "Zero");
    cout << myList;

    // Insert in middle
    cout << "--- Inserting at position 2 ---" << endl;
    myList.insert(2, "Middle");
    cout << myList;

    // Replace an element
    cout << "--- Replacing element at position 3 ---" << endl;
    myList.replace(3, "Replaced");
    cout << myList;

    // Get an element
    try {
        cout << "--- Getting element at position 2 ---" << endl;
        cout << "Element at position 2: " << myList.getElement(2) << endl;
    } catch (const string& e) {
        cout << e << endl;
    }

    // Remove an element
    try {
        cout << "--- Removing element at position 1 ---" << endl;
        myList.remove(1);
        cout << myList;
    } catch (const string& e) {
        cout << e << endl;
    }

    // Error test: remove out of bounds
    try {
        cout << "--- Attempting remove at invalid position 10 ---" << endl;
        myList.remove(10);
    } catch (const string& e) {
        cout << e << endl;
    }

    // Clear list
    cout << "--- Clearing list ---" << endl;
    myList.clear();
    cout << myList;

    return 0;
}
