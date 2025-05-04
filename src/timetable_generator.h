#ifndef TIMETABLE_GENERATOR_H
#define TIMETABLE_GENERATOR_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

class TimetableGenerator {
public:
    void generateTimetable(const std::vector<std::vector<std::string>>& courses,
                           const std::vector<std::vector<std::string>>& teachers,
                           const std::vector<std::vector<std::string>>& rooms,
                           const std::vector<std::vector<std::string>>& batches);
private:
    bool isSafe(int course, int timeSlot, const std::vector<std::vector<int>>& timetable,
                const std::vector<std::vector<std::string>>& courses,
                const std::vector<std::vector<std::string>>& teachers,
                const std::vector<std::vector<std::string>>& rooms,
                const std::vector<std::vector<std::string>>& batches,
                std::unordered_map<int, int>& teacherAssignments);
    bool backtrack(int courseIndex, std::vector<std::vector<int>>& timetable,
                   const std::vector<std::vector<std::string>>& courses,
                   const std::vector<std::vector<std::string>>& teachers,
                   const std::vector<std::vector<std::string>>& rooms,
                   const std::vector<std::vector<std::string>>& batches,
                   std::unordered_map<int, int>& teacherAssignments);
};

#endif