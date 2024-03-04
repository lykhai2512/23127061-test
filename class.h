#include "student.h"

struct Class {
    char className[16];
    Student *students = nullptr;
    Class *next = nullptr;
};

void loadClasses(const char *inputFileName, Class *&classList);

void saveClasses(const char *outputFileName, Class *classList);

void push_back(Class *&head, Class newClass);

Class find(Class *head, char *className);

void deleteList(Class *&head);
