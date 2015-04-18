#ifndef SORT_H
#define SORT_H

#include <algorithm> // TODO why required?
#include <fstream>   // ifstream
#include <iostream>  // cout, endl
#include <string>    // string
#include <sstream>   // istringstream

std::vector<int> parse_input(std::string path) {
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

void print_output(std::vector<int> output) {
    for (int i = 0; i < output.size() - 1; ++i) {
        std::cout << output[i] << ' ';
    }
    std::cout << output[output.size() - 1] << '\n';
}

#endif
