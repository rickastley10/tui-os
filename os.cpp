#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <ctime>
#include <cstring>

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

    int cmdlen=0;
    char cmd[200] = {0};

    while (1==1)
    {
        clear();
        ch = getch();
        if(ch==27){//escape
            if(menu==1){menu=0;}
            else{menu=1;}
        }
        else if(ch==KEY_BACKSPACE){
            cmdlen--;
            cmd[cmdlen]='\0';
            
        }
        else if(ch=='\n' && menu==1){
            if(strcmp(cmd, "quit")==0){
                break;
            }
            else{
                std::system(cmd);
                for(int i = 0; i <= cmdlen; i++){
                    cmd[i]=0;
                }
                cmdlen=0;
            }
            
        }
        else if(ch!=27 && menu==1 && ch!=ERR && ch != '\n'){
            if(cmdlen<200){
                cmd[cmdlen]=ch;
                cmdlen++;
            }
        }

        
        
        
        getmaxyx(stdscr, screenH, screenW);
        
        std::time_t currenttime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currenttime);
        

        if(menu==1){
            mvprintw(screenH/2, screenW/2-6,   "|");
            for(int i=0; i <= cmdlen; i++){
                
                mvprintw(screenH/2-1, screenW/2-6+i, "-");
                mvprintw(screenH/2+1, screenW/2-6+i, "-");
            }
            mvprintw(screenH/2-1, screenW/2-5+cmdlen, "-");
            mvprintw(screenH/2+1, screenW/2-5+cmdlen, "-");

            mvprintw(screenH/2, screenW/2-5+cmdlen,   "|");

            mvprintw(screenH/2, screenW/2-5, "%s", cmd);
        }
        


        for(int i=0;i<=screenW;i++){    mvprintw(screenH-2, i, "=");    }
        mvprintw(screenH-1, screenW-12, "|");
        mvprintw(screenH-1, screenW-10, "%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);


        mvprintw(screenH-1, 1, "menu |");

        refresh();
        napms(100);
    }
    

    getch();
    endwin();
    return 0;
}
