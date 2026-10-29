#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "contact.h"

void addContact(const char* filename) {
    FILE* fp = fopen(filename, "a");
    if (!fp) {
        printf("Cannot open the file!\n");
        return;
    }

    struct Contact c;
    printf("Enter name: ");
    scanf(" %[^\n]", c.name);
    getchar(); // Clear newline from buffer
    printf("Enter phone: ");
    scanf(" %[^\n]", c.phone);
    getchar(); // Clear newline from buffer

    fprintf(fp, "%s,%s\n", c.name, c.phone);
    fclose(fp);
    printf("Contact Saved\n");
}

void viewContact(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("No Contacts found!\n");
        return;
    }

    char line[100];
    printf("\n--- Contact List ---\n");
    while (fgets(line, sizeof(line), fp)) {
        char* name = strtok(line, ",");
        char* phone = strtok(NULL, "\n");

        if (name && phone) {
            printf("Name: %s, Phone: %s\n", name, phone);
        }
    }
    fclose(fp);  // ✅ moved out of loop
}

static void toLowerStr(const char* src, char* dst, size_t dstSize) {
    size_t i;
    for (i = 0; src[i] != '\0' && i + 1 < dstSize; i++) {
        char c = src[i];
        dst[i] = (c >= 'A' && c <= 'Z') ? (char)(c - 'A' + 'a') : c;
    }
    dst[i] = '\0';
}

void searchContact(const char* filename, const char* targetName) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("No Contacts Found!\n");
        return;
    }

    char targetLower[100];
    toLowerStr(targetName, targetLower, sizeof(targetLower));

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char* name = strtok(line, ",");
        char* phone = strtok(NULL, "\n");

        if (name && phone) {
            char nameLower[100];
            toLowerStr(name, nameLower, sizeof(nameLower));
            if (strstr(nameLower, targetLower) != NULL) {
                printf("Contact found: %s - %s\n", name, phone);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No Contact Found!\n");

    fclose(fp);
}

void editContact(const char* filename, const char* targetName, const char* newPhone) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("No Contacts Found!\n");
        return;
    }

    FILE* temp = fopen("contacts_temp.txt", "w");
    if (!temp) {
        printf("Cannot open the file!\n");
        fclose(fp);
        return;
    }

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char copy[100];
        strcpy(copy, line);
        char* name = strtok(copy, ",");

        if (name && strcmp(name, targetName) == 0) {
            found = 1;
            fprintf(temp, "%s,%s\n", name, newPhone);
            continue;
        }
        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        remove("contacts_temp.txt");
        printf("No Contact Found!\n");
        return;
    }

    remove(filename);
    rename("contacts_temp.txt", filename);
    printf("Contact Updated\n");
}

void deleteContact(const char* filename, const char* targetName) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("No Contacts Found!\n");
        return;
    }

    FILE* temp = fopen("contacts_temp.txt", "w");
    if (!temp) {
        printf("Cannot open the file!\n");
        fclose(fp);
        return;
    }

    char line[100];
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char copy[100];
        strcpy(copy, line);
        char* name = strtok(copy, ",");

        if (name && strcmp(name, targetName) == 0) {
            found = 1;
            continue;  // skip this line so it is not kept
        }
        fprintf(temp, "%s", line);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        remove("contacts_temp.txt");
        printf("No Contact Found!\n");
        return;
    }

    remove(filename);
    rename("contacts_temp.txt", filename);
    printf("Contact Deleted\n");
}
