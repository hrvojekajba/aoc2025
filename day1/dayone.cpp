#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// necessary global variables
std::string INPUT_PATH =
    "./dayoneinput.txt"; // get input case and name it dayoneinput.txt
int PASSWORD = 0;
int POSITION = 50;

void check_turn(std::string line) {
    char direction;
    int move_distance;
    std::istringstream line_stream(line);

    // get direction and distance from the file line
    line_stream >> direction;
    line_stream >> move_distance;

    if (direction == 'L')
        POSITION = (POSITION - move_distance + 100) % 100;
    else if (direction == 'R')
        POSITION = (POSITION + move_distance) % 100;
    else
        return;

    if (POSITION == 0)
        PASSWORD++;
}

int main() {
    // open file
    std::ifstream file(INPUT_PATH);

    // check if file is opened
    if (!file.is_open()) {
        std::cout << "File doesn't exist...\n";
        exit(EXIT_FAILURE);
    }

    std::string file_line;
    while (!file.eof() && getline(file, file_line))
        check_turn(file_line);

    std::cout << "Password: " << PASSWORD << "\n";

    return 0;
}
