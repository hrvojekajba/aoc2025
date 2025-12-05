#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>

int PASSWORD_PT1 = 0;
int PASSWORD_PT2 = 0;
int POSITION = 50;

void part_one(std::string file_line) {
    char direction;
    int move;

    std::istringstream line_stream(file_line);
    line_stream >> direction;
    line_stream >> move;

    if (direction == 'L')
        POSITION = (POSITION - move + 100) % 100;
    else
        POSITION = (POSITION + move) % 100;

    if (POSITION == 0)
        PASSWORD_PT1++;
}

void part_two(std::string file_line) {
    char direction;
    int move;

    std::istringstream line_stream(file_line);
    line_stream >> direction;
    line_stream >> move;

    for (int i = 1; i <= move; i++) {
        if (direction == 'L')
            POSITION = (POSITION - 1 + 100) % 100;
        else
            POSITION = (POSITION + 1) % 100;

        if (POSITION == 0)
            PASSWORD_PT2++;
    }
}

int main(int argv, char *argc[]) {
    std::ifstream file(argc[1]);

    std::string file_line;

    if (!file.is_open()) {
        std::cout << "\nCan't open file\n";
        exit(EXIT_FAILURE);
    }

    while (!file.eof() && getline(file, file_line))
        part_one(file_line);
    std::cout << "\nPassword - PART 1: " << PASSWORD_PT1 << "\n";

    POSITION = 50;
    file.clear();
    file.seekg(0, std::ios::beg);
    while(!file.eof() && getline(file, file_line))
        part_two(file_line);
    std::cout << "\nPassword - PART 2: " << PASSWORD_PT2 << "\n";

    return 0;
}
