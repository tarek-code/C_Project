#include <stdio.h>
#include "SDB.h"

void SDB_APP() {
    uint8 choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID is existed\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");
        scanf("%hhu", &choice);

        if (choice == 0) {
            break;
        }

        SDB_action(choice);
    }
}
#define MAX_STUDENTS 10
uint32 id;
uint8 count;
uint32 list[MAX_STUDENTS];
uint32 checkId;
uint32 deleteId;
void SDB_action(uint8 choice) {
    switch (choice) {
        case 1:
            if (SDB_AddEntry()) {
                printf("Data added successfully.\n");
            } else {
                printf("Failed to add data.\n");
            }
            break;
        case 2:
            printf("Used size in database: %u\n", SDB_GetUsedSize());
            break;
        case 3:

            printf("Enter student ID: ");
            scanf("%u", &id);
            if (!SDB_ReadEntry(id)) {
                printf("Student not found.\n");
            }
            break;
        case 4:


            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (int i = 0; i < count; i++) {
                printf("%u ", list[i]);
            }
            printf("\n");
            break;
        case 5:

            printf("Enter ID to check: ");
            scanf("%u", &checkId);
            if (SDB_IsIdExist(checkId)) {
                printf("ID exists.\n");
            } else {
                printf("ID not found.\n");
            }
            break;
        case 6:

            printf("Enter ID to delete: ");
            scanf("%u", &deleteId);
            SDB_DeleteEntry(deleteId);
            break;
        case 7:
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    SDB_APP();
    return 0;
}
