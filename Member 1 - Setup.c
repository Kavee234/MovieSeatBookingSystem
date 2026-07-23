#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10

typedef struct {
    char movieName[50];
    char showtime[20];
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

int main() {
    initMovies();
    int choice, m;

    while (1) {
        clearScreen();
        printf("--------------------------------\n");
        printf("======  KDTIG MOVIE LAND  ======\n");
        printf("--------------------------------\n");
        printf("1. View Movies\n");
        printf("2. View Showtimes\n");
        printf("3. Exit\n");
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
