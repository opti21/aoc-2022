#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

vector<string> getInput() {
    ifstream inputFile;
    inputFile.open("input.txt");

    string line;
    vector<string> input;

    if (inputFile.is_open()) {
        
        while(getline(inputFile, line)) {
            input.push_back(line);
        }

        inputFile.close();
    }

    return input;
}

int solvePartA(vector<string> input) {
    int max = 0;
    int currentCalories = 0;

    for (string i: input){
        if (!i.empty()) {
            currentCalories += stoi(i);
        } else {
            if (currentCalories > max) {
                max = currentCalories;
                currentCalories = 0;
            } else {
                currentCalories = 0;
            }
        }
    }

    return max;

}

int solvePartB(vector<string> input) {
    int currentCalories = 0;
    vector<int> caloriesUnsorted;

    for (string i: input){
        if (!i.empty()) {
            currentCalories += stoi(i);
        } else {
            caloriesUnsorted.push_back(currentCalories);
            currentCalories = 0;
        }
    }

    sort(caloriesUnsorted.begin(), caloriesUnsorted.end(), greater<int>());

    int result = caloriesUnsorted[0] + caloriesUnsorted[1] + caloriesUnsorted[2];

    return result;

}

int main() {
    vector<string> input = getInput();

    // int result = solvePartA(input);
    int result = solvePartB(input);

    cout << result;

    return 0;

}

