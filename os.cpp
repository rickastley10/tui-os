#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include <ctime>

int main(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    int ch;

    srand(time(NULL));
    //int random = (rand() % 3) + 1;

    int screenW;
    int screenH;
    int currenttime=std::time(nullptr);
    int menu=0;

    while (1==1)
    {
        clear();
        ch = getch();
        if(ch==27){//escape
            break;
        }
        if(ch==' '){//escape
            menu=1;
        }
        
        getmaxyx(stdscr, screenH, screenW);
        
        std::time_t currenttime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currenttime);
        


        mvprintw(screenH/2, screenW/2-4, "CMD|");


        for(int i=0;i<=screenW;i++){    mvprintw(screenH-2, i, "=");    }
        mvprintw(screenH-1, screenW-12, "|");
        mvprintw(screenH-1, screenW-10, "%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);


        mvprintw(screenH-1, 1, "CMD|");

        refresh();
        napms(100);
    }
    

    getch();
    endwin();
    return 0;
}
