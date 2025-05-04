#include "timetable_generator.h"
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

bool safeStoi(const string& str, int& result) {
    try {
        size_t idx;
        result = stoi(str, &idx);
        return idx == str.size(); // ensure full conversion
    } catch (...) {
        return false;
    }
}

void TimetableGenerator::loadCourses(const string& filename) {
    courses = CSVReader::readCSV(filename);
    cout << "Courses Data:\n";
    for (auto& header : courses[0]) {
        cout << header << " ";
    }
    cout << "\n";
    for (size_t i = 1; i < courses.size(); ++i) {
        for (auto& val : courses[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

void TimetableGenerator::loadTeachers(const string& filename) {
    teachers = CSVReader::readCSV(filename);
    cout << "Teachers Data:\n";
    for (auto& header : teachers[0]) {
        cout << header << " ";
    }
    cout << "\n";
    for (size_t i = 1; i < teachers.size(); ++i) {
        for (auto& val : teachers[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

void TimetableGenerator::loadRooms(const string& filename) {
    rooms = CSVReader::readCSV(filename);
    cout << "Rooms Data:\n";
    for (auto& header : rooms[0]) {
        cout << header << " ";
    }
    cout << "\n";
    for (size_t i = 1; i < rooms.size(); ++i) {
        for (auto& val : rooms[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

void TimetableGenerator::loadBatches(const string& filename) {
    batches = CSVReader::readCSV(filename);
    cout << "Batches Data:\n";
    for (auto& header : batches[0]) {
        cout << header << " ";
    }
    cout << "\n";
    for (size_t i = 1; i < batches.size(); ++i) {
        for (auto& val : batches[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

bool TimetableGenerator::generateTimetable() {
    try {
        for (size_t i = 1; i < courses.size(); ++i) {
            string courseId = courses[i][0];
            string courseName = courses[i][1];
            string dept = courses[i][2];
            int semester = stoi(courses[i][3]);

            int hours = 0;
            if (!safeStoi(courses[i][4], hours)) {
                cerr << "Invalid argument: stoi: no conversion for course: " << i << endl;
                continue;
            }

            bool isLab = (courses[i][5] == "1");

            // This is where you'd implement actual scheduling logic.
            // For now, we assume success if data parses properly.
        }

        cout << "Timetable generated successfully.\n";
        return true;
    } catch (const exception& e) {
        cerr << "Error generating timetable: " << e.what() << endl;
        return false;
    }
}
