#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initMovies();
void viewMovies();
void viewShowtimes(int m);
void viewSeatMap(int m, int t);
void bookTicket(const char *movie, const char *showtime, int seatNumber, float price);
void printTickets();
void saveTicketsToFile(const char *filename);
void loadTicketsFromFile(const char *filename);
void generateReport();

int main() {
    int choice;
    char filename[50] = "tickets_db.txt";

    while (1) {
        printf("\n===== MOVIE SEAT BOOKING SYSTEM =====\n");
        printf("1. Setup Movies & Showtimes (Member 1)\n");
        printf("2. Display Seat Map & Prices (Member 2)\n");
        printf("3. Book Ticket (Member 3)\n");
        printf("4. Print Tickets (Member 3)\n");
        printf("5. Save Tickets to File (Member 4)\n");
        printf("6. Load Tickets from File (Member 4)\n");
        printf("7. Generate Report (Member 5)\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: setupMovies(); break;
            case 2: displaySeatMap(); break;
            case 3: bookTicket("MovieName","Showtime",1,500.0); break; // example
            case 4: printTickets(); break;
            case 5: saveTicketsToFile(filename); break;
            case 6: loadTicketsFromFile(filename); break;
            case 7: generateReport(); break;
            case 8: printf("Exiting system...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
