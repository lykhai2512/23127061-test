#include "session.h"
#include "student.h"

struct CourseInfo {
    char courseID[16];
    char courseName[32];
    char className[32];
    char teacher[32];
    int number_of_credits;
    int maxStudent = 50;
    int day_of_week;
    Session session;
    CourseInfo *next = nullptr;
};

struct Course {
    CourseInfo info;
    Student *students = nullptr;
    Score *scoreboard = nullptr;
    Course *next = nullptr;
};

struct Score {
    int no;
    int studentID;
    char fullName[32];
    double midtermMark, finalMark, otherMark, totalMark;
};

void loadCourses(const char *inputFileName, Course *&courseList);

void saveCourses(const char *outputFileName, Course *courseList);

void push_back(Course *&head, Course newCourse);

void remove(Course *&head, char *courseID);

Course find(Course *head, char *courseID);

void deleteList(Course *&head);
