#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char movie[50];
    char showtime[20];
    int seatNumber;
    float price;
    float discount;
    float finalPrice;
} Ticket;

Ticket tickets[50];   // shared ticket array
int ticketCount = 0;

// Function to save tickets to file
void saveTicketsToFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }

    for (int i = 0; i < ticketCount; i++) {
        fprintf(fp, "%s,%s,%d,%.2f,%.2f,%.2f\n",
                tickets[i].movie,
                tickets[i].showtime,
                tickets[i].seatNumber,
                tickets[i].price,
                tickets[i].discount,
                tickets[i].finalPrice);
    }

    fclose(fp);
    printf("Tickets saved successfully to %s\n", filename);
}

// Function to load tickets from file
void loadTicketsFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for loading!\n");
        return;
    }

    ticketCount = 0;
    while (fscanf(fp, "%49[^,],%19[^,],%d,%f,%f,%f\n",
                  tickets[ticketCount].movie,
                  tickets[ticketCount].showtime,
                  &tickets[ticketCount].seatNumber,
                  &tickets[ticketCount].price,
                  &tickets[ticketCount].discount,
                  &tickets[ticketCount].finalPrice) == 6) {
        ticketCount++;
    }

    fclose(fp);
    printf("Tickets loaded successfully from %s\n", filename);
}


int main() {
    int choice;
    char filename[50] = "tickets_db.txt";

    while (1) {
        printf("\n===== MEMBER 4 MENU =====\n");
        printf("1. Save Tickets to File\n");
        printf("2. Load Tickets from File\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            saveTicketsToFile(filename);
        } else if (choice == 2) {
            loadTicketsFromFile(filename);
        } else if (choice == 3) {
            printf("\nExiting Member 4 module...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
