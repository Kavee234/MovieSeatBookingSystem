#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TICKETS 50

//----------------------------------------------
// MEMBER 3 : BOOKING, DISCOUNTS, TICKET PRINTING
//----------------------------------------------

typedef struct {
    char movie[50];
    char showtime[20];
    int seatNumber;
    float price;
    float discount;
    float finalPrice;
} Ticket;

Ticket tickets[MAX_TICKETS];
int ticketCount = 0;

// Function to book a ticket
void bookTicket(const char *movie, const char *showtime, int seatNumber, float price) {
    if (ticketCount >= MAX_TICKETS) {
        printf("Booking limit of %d tickets reached!\n", MAX_TICKETS);
        return;
    }

    Ticket t;
    strcpy(t.movie, movie);
    strcpy(t.showtime, showtime);
    t.seatNumber = seatNumber;
    t.price = price;

    // Discount rule: even seats get 10% off
    if (seatNumber % 2 == 0) {
        t.discount = 0.10 * price;
    } else {
        t.discount = 0.0;
    }

    t.finalPrice = price - t.discount;
    tickets[ticketCount++] = t;

    printf("\nTicket booked successfully!\n");
    printf("Movie: %s\n", t.movie);
    printf("Showtime: %s\n", t.showtime);
    printf("Seat: %d\n", t.seatNumber);
    printf("Price: %.2f\n", t.price);
    printf("Discount: %.2f\n", t.discount);
    printf("Final Price: %.2f\n", t.finalPrice);
}

// Function to print all booked tickets
void printTickets() {
    printf("\n================= BOOKED TICKETS =================\n");
    for (int i = 0; i < ticketCount; i++) {
        printf("Ticket %d:\n", i+1);
        printf("  Movie: %s\n", tickets[i].movie);
        printf("  Showtime: %s\n", tickets[i].showtime);
        printf("  Seat: %d\n", tickets[i].seatNumber);
        printf("  Price: %.2f\n", tickets[i].price);
        printf("  Discount: %.2f\n", tickets[i].discount);
        printf("  Final Price: %.2f\n", tickets[i].finalPrice);
        printf("---------------------------------------------\n");
    }
}

//----------------------------------------------
// MAIN FUNCTION FOR MEMBER 3 TESTING
//----------------------------------------------

int main() {
    int choice;
    while (1) {
        printf("\n===== MEMBER 3 MENU =====\n");
        printf("1. Book Ticket\n");
        printf("2. Print Tickets\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char movie[50], showtime[20];
            int seat;
            float price;

            printf("Enter movie name: ");
            scanf(" %[^\n]", movie);
            printf("Enter showtime: ");
            scanf(" %[^\n]", showtime);
            printf("Enter seat number: ");
            scanf("%d", &seat);
            printf("Enter price: ");
            scanf("%f", &price);

            bookTicket(movie, showtime, seat, price);
        } else if (choice == 2) {
            printTickets();
        } else if (choice == 3) {
            printf("\nExiting Member 3 module...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
