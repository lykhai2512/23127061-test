#include "class.h"
#include <fstream>
#include <cstring>

void loadClasses(const char *inputFileName, Class *&classList){
    std::ifstream inputFile(inputFileName);
    if(!inputFile.is_open()) return;
    Class inputClass;
    while (inputFile.getline(inputClass.className, 15)){
        push_back(classList, inputClass);
    }
    inputFile.close();
}

void saveClasses(const char *outputFileName, Class *classList){
    std::ofstream outputFile(outputFileName);
    while (classList != nullptr){
        outputFile.write(classList->className, strlen(classList->className));
        outputFile << "\n";
        classList = classList->next;
    }
    outputFile.close();
}

void push_back(Class *&head, Class newClass) {
    Class* backClass = new Class;
    strcpy(backClass->className, newClass.className);
    if (head == nullptr) {
        head = backClass;
        return;
    }
    Class* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = backClass;
}

Class find(Class *head, char *className){
    while(head != nullptr && strcmp(head->className, className)){
        head = head->next;
    }
    if (head != nullptr)
        return *head;
}

void deleteList(Class *&head){
    if (head == nullptr)
        return;
    Class* cur = head;
    while (cur->next != nullptr){
        Class* temp = cur;
        cur = cur -> next;
        delete temp;
    }
    delete cur;
}
