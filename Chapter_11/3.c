#include <stdio.h>
#include <string.h>

typedef struct {
    char name[26];
    int max_speed;
    float wingspan;
    float length;
    char type;
    char description[81];
} Aircraft;

void searchByName(FILE *fp, const char *searchName) {
    rewind(fp);
    Aircraft aircraft;
    while (fread(&aircraft, sizeof(Aircraft), 1, fp)) {
        if (strcmp(aircraft.name, searchName) == 0) {
            printf("Name: %s\nSpeed: %d km/h\nWingspan: %.2f m\nLength: %.2f m\nType: %c\nDescription: %s\n",
                   aircraft.name, aircraft.max_speed, aircraft.wingspan, aircraft.length, aircraft.type, aircraft.description);
            return;
        }
    }
    printf("Aircraft not found.\n");
}

int main() {
    FILE *fp = fopen("aircraft.bin", "rb+");
    if (!fp) {
        printf("Error opening database file.\n");
        return 1;
    }

    int choice;
    char searchName[26];

    do {
        printf("1. Search by Name\n2. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter aircraft name: ");
            scanf(" %[^\n]s", searchName);
            searchByName(fp, searchName);
            break;
        case 2:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 2);

    fclose(fp);
    return 0;
}