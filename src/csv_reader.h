#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>

class CSVReader {
public:
    static std::vector<std::vector<std::string>> readCSV(const std::string& filename);
};

#endif