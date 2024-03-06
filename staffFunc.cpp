#include "staff.h"
#include <fstream>
#include <cstring>
#include <iomanip>

void loadStaff(const char *inputFileName, Staff *&staffList){
    std::ifstream inputFile(inputFileName);
    if(!inputFile.is_open()) return;
    Staff inputStaff;
    char big[81];
    while(inputFile.getline(big, 80)){
        char *ptrChr;
        ptrChr = strtok(big, ",");
        inputStaff.no = atoi(ptrChr);
        ptrChr = strtok(nullptr, ",");
        strcpy(inputStaff.firstName,ptrChr);
        ptrChr = strtok(nullptr, ",");
        strcpy(inputStaff.lastName,ptrChr);
        ptrChr = strtok(nullptr, ",");
        strcpy(inputStaff.gender,ptrChr);
        ptrChr = strtok(nullptr, "/");
        inputStaff.birth.day = atoi(ptrChr);
        ptrChr = strtok(nullptr, "/");
        inputStaff.birth.month = atoi(ptrChr);
        ptrChr = strtok(nullptr, ",");
        inputStaff.birth.year = atoi(ptrChr);
        ptrChr = strtok(nullptr, ",");
        strcpy(inputStaff.email,ptrChr);
        push_back(staffList, inputStaff);
    }
    inputFile.close();
}

void push_back(Staff *&head, Staff newStaff) {
    Staff* backStaff = new Staff;
    (*backStaff) = newStaff;
    if (head == nullptr) {
        head = backStaff;
        return;
    }
    Staff* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = backStaff;
}

void remove(Staff *&head, char *name){
    //W.I.P
}

Staff find(Staff *head, char *name){
    if (head != nullptr){
        char* check;
        do{
            strcpy(check, head->firstName);
            strcat(check, " ");
            strcat(check, head->lastName);
            if (!strcmp(check, name))
                return *head;
            head = head->next;
        } while (head != nullptr);
    }
}

void deleteList(Staff *&head){
    if (head == nullptr)
        return;
    Staff* cur = head;
    while (cur->next != nullptr){
        Staff* temp = cur;
        cur = cur -> next;
        delete temp;
    }
    delete cur;
}

void saveStaff(const char *outputFileName, Staff *staffList){
    std::ofstream outputFile(outputFileName);
    while (staffList != nullptr){
        outputFile << staffList->no << ",";
        outputFile.write(staffList->firstName, strlen(staffList->firstName));
        outputFile << ",";
        outputFile.write(staffList->lastName, strlen(staffList->lastName));
        outputFile << ",";
        outputFile.write(staffList->gender, strlen(staffList->gender));
        outputFile << "," << std::setw(2) << std::setfill('0') << staffList->birth.day << "/" << std::setw(2) << std::setfill('0') << staffList->birth.month << "/" << staffList->birth.year << ",";
        outputFile.write(staffList->email, strlen(staffList->email));
        outputFile << "\n";
        staffList = staffList->next;
    }
    outputFile.close();
}
