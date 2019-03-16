#include <ncurses.h>
#include <signal.h>
#include <stdio.h>

#include "fn.h"

int main(){
    reset();
    game.print_info();
    while(1){
        system("clear");
        frame();
        for(int i=0;i<400-(game.level);++i){
            if(kbhit()){
                char ch = getchar();
                switch((int)ch){
                    case 100://d
                        now.moveLR(1);
                        system("clear");
                        frame();
                        break;
                    case 115://s
                        if(!now.is_touched()){
                            now.decend();
                        }
                        system("clear");
                        frame();
                        break;
                    case 97://a
                        now.moveLR(0);
                        system("clear");
                        frame();
                        break;
                    case 119://w
                        now.nextmodel();
                        system("clear");
                        frame();
                        break;
                }
                i+=15;
            }
            usleep(1000);
        }
        if(now.is_touched()){
            slash();
            nextblock();
            game.print_info();
        }else{
            now.decend();
        }
    }
    return 0;
}
