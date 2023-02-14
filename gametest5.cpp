#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int numbers[8] = {0};
    int count = 0;
    int pickedNumber = 0;
    int decreaseAmount = 0;
    
    // Get the user input as a string and store it in the "input" variable
    string input;
    cout << "Please input 8 non-negative integers: ";
    getline(cin, input);
    
    // Extract the intergers from the string
    istringstream ss(input);
    while (ss >> numbers[count]) {
        // Check if the current number is negative
        while (numbers[count] < 0) {
            cout << "Invalid input: negative number." << endl;
            cout << "Please input a non-negative integer: ";
            cin >> numbers[count];
        }
        count++;
        // Break out of the loop if we have already read 8 numbers
        if (count == 8) {
            break;
        }
    }
    
    // Fill in the rest of the array with zeros if the user input less than 8 numbers
    for (int i = count; i < 8; i++) {
        numbers[i] = 0;
    }

    while (true) {
        // Output the 8 numbers
        cout << "The 8 numbers are: ";
        for (int i = 0; i < 8; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;

        // Check if all numbers are zero
        bool allZero = true;
        for (int i = 0; i < 8; i++) {
            if (numbers[i] != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) {
            cout << "You are lost." << endl;
            break;
        }

        // Prompt the user to pick a number to decrease
        cout << "Please pick a number to decrease: ";
        cin >> pickedNumber;

        // Check if the user picked 0
        if (pickedNumber == 0) {
            cout << "You can't pick 0." << endl;
            continue;
        }

        // Check if the picked number is in the array of numbers
        bool numberNotFound = true;
        for (int i = 0; i < 8; i++) {
            if (numbers[i] == pickedNumber) {
                numberNotFound = false;
                break;
            }
        }
        if (numberNotFound) {
            cout << "The number you picked is not found." << endl;
            continue;
        }

        // Prompt the user to input the amount to decrease
        cout << "Please input the amount to decrease: ";
        cin >> decreaseAmount;
        // Check if the decrease amount is less than or equal to 0
        if (decreaseAmount <= 0) {
            cout << "You need to decrease the number by at least 1." << endl;
            continue;
        }
        // Check if the decrease amount will result in a negative number
        if (pickedNumber - decreaseAmount < 0) {
            cout << "Error: You can't decrease to a negative number." << endl;
        continue;
        }
        // Decrease the picked number by the specified amount
        for (int i = 0; i < 8; i++) {
            if (numbers[i] == pickedNumber) {
            numbers[i] -= decreaseAmount;
            break;
            }
        }
    }
    return 0;
}
