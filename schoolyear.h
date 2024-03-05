#include "semester.h"

struct Schoolyear {
    char year[16];
    Semester *listSemester = nullptr;
};

void loadSchoolyear(const char *inputFileName, Schoolyear *&schoolyearList);

void saveSchoolyear(const char *outputFileName, Schoolyear *schoolyearList);

void push_back(Schoolyear *&head, Schoolyear newyear);

Schoolyear find(Schoolyear *head, char *year);

void deleteList(Schoolyear *&head);
