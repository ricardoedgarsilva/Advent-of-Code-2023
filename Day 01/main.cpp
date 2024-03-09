// Combine the first and last digits of each line

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int findcalval(const std::string& line) {
    std::string firstDigit = "", lastDigit = "";
    
    // find the first number
    for (char ch : line) {
        if (isdigit(ch)) {
            firstDigit = ch;
            break;
        }
    }

    // find the last number
    for (int i = line.size() - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            lastDigit = line[i];
            break;
        }
    }

    // merge the two number strings into a integer
    std::string merged = firstDigit + lastDigit; 

    return std::stoi(merged);
}


int main() {
    
    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> calvals;
    int calval;

    while (getline(file, line)) {
        calval = findcalval(line); 
        calvals.push_back(calval);
    }

    // sum all the calvals
    int sum = 0;
    for (int i : calvals) {
        sum += i;
    }

    std::cout << "Sum: " << sum << std::endl;


    return 0;
}
