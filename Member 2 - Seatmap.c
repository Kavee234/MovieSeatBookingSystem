#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10

typedef struct {
    char movieName[50];
    char showtime[20];
    int booked[ROWS][COLS];   // 0 = free, 1 = booked
} MovieShowtime;

MovieShowtime showtimes[3][2];

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void initMovies() {
    char movies[3][50] = {"THE ODYSSEY", "AVATAR : FIRE AND ASH", "THE SPIDER-MAN : BRAND NEW DAY"};
    char times[2][20] = {"10:00 AM", "5:00 PM"};

    for (int m = 0; m < 3; m++) {
        for (int t = 0; t < 2; t++) {
            strcpy(showtimes[m][t].movieName, movies[m]);
            strcpy(showtimes[m][t].showtime, times[t]);
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    showtimes[m][t].booked[i][j] = 0;
                }
            }
        }
    }
}

void viewMovies() {
    printf("\n");
    printf("--------------------------------------\n");
    printf("=======    AVAILABLE MOVIES    =======\n");
    printf("--------------------------------------\n");
    for (int m = 0; m < 3; m++) {
        printf("    %d. %s\n", m+1, showtimes[m][0].movieName);
    }
    printf("--------------------------------------\n");
}

void viewShowtimes(int m) {
    printf("\n");
    printf("----------------------------------------------\n");
    printf(" SHOWTIMES FOR %s\n", showtimes[m][0].movieName);
    printf("----------------------------------------------\n");
    for (int t = 0; t < 2; t++) {
        printf("    %d. %s\n", t+1, showtimes[m][t].showtime);
    }
    printf("----------------------------------------------\n");
}

void viewSeatMap(int m, int t) {
    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("====== SEAT MAP FOR %s (%s) ======\n", showtimes[m][t].movieName, showtimes[m][t].showtime);
    printf("--------------------------------------------------------------------\n\n");

    for (int i = 0; i < ROWS; i++) {
        printf("           ROW %c: ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (showtimes[m][t].booked[i][j])
                printf("X ");
            else
                printf(". ");
        }
        printf("\n\n");
    }

    printf("--------------------------------------------------------------------\n");
    printf("\n");
    printf("------------------------------\n");
    printf("=====     PRICE LIST     =====\n");
    printf("------------------------------\n");
    printf(" ROWS A-B (Regular): Rs. 500\n");
    printf(" ROWS C-D (Premium): Rs. 750\n");
    printf(" ROW E (VIP)       : Rs. 1000\n");
    printf("------------------------------\n\n");
}

int main() {
    initMovies();
    int choice, m, t;

    while (1) {
        clearScreen();
        printf("--------------------------------\n");
        printf("======  KDTIG MOVIE LAND  ======\n");
        printf("--------------------------------\n");
        printf("1. View Movies\n");
        printf("2. View Showtimes\n");
        printf("3. View Seat Map\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewMovies();
                break;
            case 2:
                viewMovies();
                printf("SELECT MOVIE (1-3): ");
                scanf("%d", &m);
                m--;
                viewShowtimes(m);
                break;
            case 3:
                viewMovies();
                printf("SELECT MOVIE (1-3): ");
                scanf("%d", &m);
                m--;
                viewShowtimes(m);
                printf("SELECT SHOWTIME (1-2): ");
                scanf("%d", &t);
                t--;
                viewSeatMap(m, t);
                break;
            case 4:
                printf("\nThank you for visiting KDTIG MOVIE LAND!\n");
                return 0;
            default:
                printf("[X] INVALID CHOICE! [X]\n");
                break;
        }

        printf("\nPRESS ENTER TO CONTINUE...");
        getchar();
        getchar();
    }

    return 0;
}
