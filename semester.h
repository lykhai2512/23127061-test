#include "class.h"
#include "course.h"

struct Semester {
    Date startDate, endDate;
    Class *listClass = nullptr;
    Course *listCorse = nullptr;
};

void saveSemesters(const char *outputFileName, Semester *semesters);
