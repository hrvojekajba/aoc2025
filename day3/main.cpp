#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

void part_one(std::string line) {
    int TOTAL_JOLTAGE_P1 = 0;

    int first_index = 0;
    for (int i = 0; i < line.length() - 1;i++) {
        if (line[i] > line[first_index])
            first_index = i;
    }

    int second_index = first_index + 1;
    for (int i = first_index + 1; i < line.length(); i++) {
        if (line[i] > line[second_index])
            second_index = i;
    }

    std::string line_joltage = std::string(1, line[first_index]) + line[second_index];
    TOTAL_JOLTAGE_P1 += std::stoi(line_joltage);
}

int main(int argv, char *argc[]) {
    std::ifstream file(argc[1]);

    if (!file.is_open()) {
        std::cout << "\nError while opening file\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    while(!file.eof() && getline(file, line)) {
        part_one(line);
    }

    std::cout << "TOTAL JOLTAGE - PART 1: " << TOTAL_JOLTAGE_P1 << "\n";

    return 0;
}
