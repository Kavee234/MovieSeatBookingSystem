#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------
// MEMBER 5 : REPORT GENERATION (SUMMARY & REVENUE)
//----------------------------------------------

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

// Function to generate report
void generateReport() {
    if (ticketCount == 0) {
        printf("\nNo tickets booked yet!\n");
        return;
    }

    float totalRevenue = 0.0;
    float totalDiscount = 0.0;

    printf("\n================= REPORT =================\n");
    printf("Total Tickets Booked: %d\n", ticketCount);

    for (int i = 0; i < ticketCount; i++) {
        totalRevenue += tickets[i].finalPrice;
        totalDiscount += tickets[i].discount;
    }

    printf("Total Discounts Given: %.2f\n", totalDiscount);
    printf("Total Revenue Collected: %.2f\n", totalRevenue);
    printf("==========================================\n");
}

//----------------------------------------------
// MAIN FUNCTION FOR MEMBER 5 TESTING
//----------------------------------------------

int main() {
    int choice;
    while (1) {
        printf("\n===== MEMBER 5 MENU =====\n");
        printf("1. Generate Report\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            generateReport();
        } else if (choice == 2) {
            printf("\nExiting Member 5 module...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
