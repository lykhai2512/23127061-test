#include "date.h"
#include "course.h"

struct Student {
    int no;
    char studentID[10];
    char firstName[16];
    char lastName[16];
    char gender[7];
    Date birth;
    char socialID[13];
    Student *next = nullptr;

    CourseInfo* allCourses();
};

void loadStudents(const char *inputFileName, Student *&studentList);

void saveStudents(const char *outputFileName, Student *studentList);

void push_back(Student *&head, Student student);

void remove(Student *&head, char *studentID);

void find(Student *head, char *studentID);

void deleteList(Student *&head);
