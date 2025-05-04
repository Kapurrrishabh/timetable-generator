#include "csv_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

std::vector<std::vector<std::string>> CSVReader::readCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        vector<string> row;

        while (getline(ss, item, ',')) {
            row.push_back(item);
        }
        data.push_back(row);
    }
    return data;
}