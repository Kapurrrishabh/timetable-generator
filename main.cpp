#include "src/csv_reader.h"
#include "src/timetable_generator.h"
#include <iostream>

using namespace std;

void printCSVData(const vector<vector<string>>& data) {
    for (const auto& row : data) {
        for (const auto& item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
}

int main() {
    auto courses = CSVReader::readCSV("MultipleFiles/courses.csv");
    auto teachers = CSVReader::readCSV("MultipleFiles/teachers.csv");
    auto rooms = CSVReader::readCSV("MultipleFiles/rooms.csv");
    auto batches = CSVReader::readCSV("MultipleFiles/batches.csv");

    cout << "Courses Data:" << endl;
    printCSVData(courses);
    cout << "Teachers Data:" << endl;
    printCSVData(teachers);
    cout << "Rooms Data:" << endl;
    printCSVData(rooms);
    cout << "Batches Data:" << endl;
    printCSVData(batches);

    TimetableGenerator generator;
    generator.generateTimetable(courses, teachers, rooms, batches);

    return 0;
}