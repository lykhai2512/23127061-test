#include "date.h"
#include "schoolyear.h"
#include "semester.h"
#include "class.h"
#include "course.h"
#include "student.h"

struct Staff {
    int no;
    char firstName[16];
    char lastName[16];
    char gender[7];
    Date birth;
    char email[32];
    Staff *next = nullptr;

    // Functions

    // Beginning of a semester
    void CreateSchoolYear(Schoolyear *&listSchoolyear, char *year);

    void CreateClass(Schoolyear *schoolyear, char *className);

    void AddStudentsToClass(const char *inputFileName, Class *classToAdd);

    void CreateSemester(Schoolyear *schoolyear, Date startDate, Date endDate);

    void AddCourse(Semester *semester, CourseInfo courseInfo);

    void AddStudentsToCourse(const char *inputFileName, Course *course);

    void UpdateCourseInfo(Course *course, CourseInfo courseInfo);

    void RemoveStudentFromCourse(Course *course, char studentID);

    void DeleteCourse(Course *&course);

    // End of semester
    void ExportStudentsInCourse(char *outputFileName, Course *course);

    void ImportScoreBoard(char *inputFileName, Course *course); 

    void UpdateStudentResult(Course *course, Score newScore);
};

void loadStaff(const char *inputFileName, Staff *&staffList);

void push_back(Staff *&head, Staff newStaff);

void remove(Staff *&head, char *name);

Staff find(Staff *head, char *name);

void deleteList(Staff *&head);
