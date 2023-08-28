#include "SDB.h"

#define MAX_STUDENTS 10

static student database[MAX_STUDENTS];
static uint8 studentCount = 0;

bool SDB_IsFull() {
    return studentCount >= MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() {
    return studentCount;
}

bool SDB_AddEntry() {
    if (studentCount >= MAX_STUDENTS) {
        return false;  // Database is full, cannot add more entries
    }

    // Get student data from user
    student newStudent;
    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);
    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);
    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course 1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);
    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course 2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);
    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course 3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    // Add the new student to the database
    database[studentCount] = newStudent;
    studentCount++;

    return true;  // Successfully added the student
}

void SDB_DeleteEntry(uint32 id) {
    int foundIndex = -1;  // Initialize to a value indicating not found

    // Search for the student with the given ID in the database
    for (int i = 0; i < studentCount; i++) {
        if (database[i].Student_ID == id) {
            foundIndex = i;
            break;  // Exit loop once the student is found
        }
    }

    if (foundIndex != -1) {
        // Shift remaining entries to fill the gap
        for (int i = foundIndex; i < studentCount - 1; i++) {
            database[i] = database[i + 1];
        }
        studentCount--;

        printf("Student with ID %u deleted.\n", id);
    } else {
        printf("Student with ID %u not found.\n", id);
    }
}

bool SDB_ReadEntry(uint32 id) {
    for (int i = 0; i < studentCount; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return true;  // Found and printed student data
        }
    }

    return false;  // Student not found
}

void SDB_GetList(uint8 *count, uint32 *list) {
   *count = studentCount;  // Set the count of student IDs

    for (int i = 0; i < studentCount; i++) {
        list[i] = database[i].Student_ID;  // Store each student ID in the list
    }
}

bool SDB_IsIdExist(uint32 id) {
    for (int i = 0; i < studentCount; i++) {
        if (database[i].Student_ID == id) {
            return true;  // ID exists in the database
        }
    }
    return false;  // ID does not exist in the database
}

