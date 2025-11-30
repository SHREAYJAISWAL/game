#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int x = 1;                  // player position (0 to 2)
    int step = 0;               // obstacle vertical movement
    int obstaclePos = rand() % 3;   // 0,1,2 lane
    int score = 0;              // score counter
    int lives = 3;              // player lives

    // ---- Load High Score ----
    int highScore = 0;
    FILE *f = fopen("highscore.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", &highScore);
        fclose(f);
    }

    while (1) {
        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        // LEFT arrow
                x--;

            if (ch == 77 && x < 2)        // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
        system("cls");
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);
                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);
                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);
            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %c        |\n", 6);
        else if (x == 1)
            printf("|     %c    |\n", 6);
        else if (x == 2)
            printf("|        %c |\n", 6);

        // ---- HUD ----
        printf("Score: %d   Lives: %d   High Score: %d\n", score, lives, highScore);

        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            lives--;
            if (lives == 0) {
                printf("\nGAME OVER!\n");
                break;
            } else {
                printf("\nYou lost a life! Lives left: %d\n", lives);
                step = 0;
                obstaclePos = rand() % 3;
            }
        }

        Sleep(120);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
            score++; // survived one obstacle
        }
    }

    // ---- Save High Score ----
    if (score > highScore) {
        printf("New High Score!\n");
        f = fopen("highscore.txt", "w");
        fprintf(f, "%d", score);
        fclose(f);
    }

    printf("Final Score: %d\n", score);
    printf("High Score: %d\n", (score > highScore ? score : highScore));

    return 0;
}