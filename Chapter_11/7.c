#include <stdio.h>
#include <string.h>

typedef struct {
    char flightNumber[10];
    char departureCity[20];
    char destinationCity[20];
    char departureTime[20];
    char arrivalTime[20];
    int firstClassAvailable;
    int firstClassSold;
    int coachAvailable;
    int coachSold;
} Flight;

int main() {
    FILE *fp = fopen("flights.bin", "rb+");
    if (!fp) {
        printf("Error opening flight database.\n");
        return 1;
    }

    Flight flight;
    int choice;

    do {
        printf("1. Add Flight\n2. View Flights\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter flight details:\n");
            printf("Flight Number: "); scanf("%s", flight.flightNumber);
            printf("Departure City: "); scanf("%s", flight.departureCity);
            printf("Destination City: "); scanf("%s", flight.destinationCity);
            printf("Departure Time: "); scanf("%s", flight.departureTime);
            printf("Arrival Time: "); scanf("%s", flight.arrivalTime);
            printf("First-Class Seats Available: "); scanf("%d", &flight.firstClassAvailable);
            flight.firstClassSold = 0;
            printf("Coach Seats Available: "); scanf("%d", &flight.coachAvailable);
            flight.coachSold = 0;

            fseek(fp, 0, SEEK_END);
            fwrite(&flight, sizeof(Flight), 1, fp);
            printf("Flight added.\n");
            break;

        case 2:
            rewind(fp);
            printf("Flight Details:\n");
            while (fread(&flight, sizeof(Flight), 1, fp)) {
                printf("Flight Number: %s\nDeparture: %s\nDestination: %s\nDeparture Time: %s\nArrival Time: %s\nFirst-Class (Available/Sold): %d/%d\nCoach (Available/Sold): %d/%d\n\n",
                       flight.flightNumber, flight.departureCity, flight.destinationCity, flight.departureTime, flight.arrivalTime,
                       flight.firstClassAvailable, flight.firstClassSold, flight.coachAvailable, flight.coachSold);
            }
            break;

        case 3:
            printf("Exiting.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 3);

    fclose(fp);
    return 0;
}