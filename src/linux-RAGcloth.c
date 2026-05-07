// Headers
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <signal.h>
// touching \/ unmodified will break the ammount saving when the window is closed.
FILE *fp;
// Runs if window is closed
void handle_hup(int sig) {
    endwin();
    fclose(fp);
    exit(0);
}

int main() {
    // Runs the code above
    signal(SIGHUP, handle_hup); 
    // init and etc for ncurses
    initscr();
    cbreak();
    noecho();
    // makes buffer 
    char buffer[256];
    // opens file
    fp = fopen(".RAG.2SDAT", "r");
    // makes file if it doesnt exist.
    if (fp == NULL) {
        fp = fopen(".RAG.2SDAT", "w");
    }
    //Sets the buffer to the contents of fp.
    fgets(buffer, sizeof(buffer), fp);
    // Sets amm (ammount) to the contents of fp from the buffer
    int amm = atoi(buffer);
    // i dont remember what this does.
    int thisamm = 0;
    srand(time(NULL));   // sets the rand key to the time.
    int r = rand();  
    char ranla = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
    char ranlb = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
    char ranlc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
    char fuckit[6] = {'|', ranla, ranlb, ranlc, '|', '\0'};
    char crapp = 'a';
    while(crapp != 'n') {
        // Increaces thisamm and amm by 1.
        thisamm++;
        amm++;
        char buffera[100];
        remove(".RAG.2SDAT");
        fp = fopen(".RAG.2SDAT", "w");
        sprintf(buffera, "%d\n", amm);
        fputs(buffera, fp);
        char crapp = 'a';
        int cold = (COLS - strlen("+---+")) / 2;
        int row = LINES / 2;
        
        int col = (COLS - strlen(fuckit)) / 2;
        

        mvprintw(row-1, cold, "+---+");
        mvprintw(row, col, "%s", fuckit);
        mvprintw(row+1, cold, "+---+");
        
        mvprintw(LINES - 1, 0, "| press n to exit. | press m to loop. | TOTAL:%d | Session:%d | 2soup | https://github.com/iam2soup/RAGcloth/ |", amm, thisamm);
        refresh();
        while(crapp != 'm') {
            crapp = getch();
            if (crapp == 'n') {
                goto exit;
            }
        }
        clear();
        ranla = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
        ranlb = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
        ranlc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
        fuckit[1] = ranla;
        fuckit[2] = ranlb;
        fuckit[3] = ranlc;
    }
    exit:
        endwin();
        fclose(fp);
        return 0;
    endwin();
    fclose(fp);
    return 0;
    //remind me to add more documentation later.
}
