#ifndef COMMON_H
#define COMMON_H

#include <algorithm> // TODO why required?
#include <fstream> // ifstream
#include <iostream> // cout, endl
#include <string> // string
#include <sstream> // istringstream

/**
Read file at `path`. It's format should be as of `data/sort`.
*/
std::vector<int> parse_array(std::string path) {
    int i, size, value;
    std::ifstream infile(path);
    std::string inputS;
    std::string sizeS;
    std::vector<int> input;

    std::getline(infile, sizeS);
    size = std::stoi(sizeS);
    input.reserve(size);

    std::getline(infile, inputS);
    std::istringstream iss(inputS);
    for (int i = 0; i < size; ++i) {
        iss >> value;
        input.push_back(value);
    }
    return input;
}

/**
Print the vector to stdout space separated.
*/
void print_array(std::vector<int> output) {
    for (unsigned int i = 0; i < output.size() - 1; ++i) {
        std::cout << output[i] << ' ';
    }
    std::cout << output[output.size() - 1] << '\n';
}

#endif
