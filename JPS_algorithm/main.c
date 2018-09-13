//
//  main.c
//  JPS_algorithm
//
//  Created by Joonhee Lee on 01/09/2018.
//  Copyright © 2018 Joonhee Lee. All rights reserved.
//
#include <stdio.h>

int a, d;

#define map_size 12
/*
 --------미리설정해줘야할 것--------
 n : 아무것도 아닌것
 W : 벽
 S : 시작점
 D : 도착점
 
 --------컴퓨터가 정의할 것--------
 P : Primary Jump Point
 
*/

//10 X 10 map
char map[map_size][map_size] = {
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    
    {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
    
    {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
    
    {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
    
    {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
    
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    
    {'W', ' ', ' ', 'W', ' ', ' ', ' ', 'W', 'D', ' ', 'W', 'W'},
    
    {'W', ' ', ' ', ' ', ' ', ' ', ' ', 'W', ' ', ' ', 'W', 'W'},
    
    {'W', ' ', 'W', 'W', ' ', ' ', ' ', 'W', 'W', ' ', 'W', 'W'},
    
    {'W', ' ', ' ', 'W', ' ', ' ', ' ', ' ', ' ', ' ', 'W', 'W'},
    
    {'W', 'S', ' ', 'W', ' ', ' ', ' ', 'W', ' ', ' ', 'W', 'W'},
    
    {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
};

//information to each node
struct nodes{ 
    int left;
    int left_up;
    int up;
    int right_up;
    int right;
    int right_down;
    int down;
    int left_down;
};

//printing out map status
void MapStatus(){
    int x, y;
    
    x = 0;
    y = 0;
    for(y =0; y <= map_size-1; y++){
        for(x = 0; x <= map_size-1; x++)
            printf(" %c", map[x][y]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    int x, y;
    //making array of node
    struct nodes p[map_size][map_size];
    
    y = map_size-2;
    x = 0;
    //initializing nodes
    for(y = map_size; y >= 0; y--){
        for(x = 0; x <= map_size; x++){
            p[x][y].left = 0;
            p[x][y].left_up = 0;
            p[x][y].up = 0;
            p[x][y].right_up = 0;
            p[x][y].right = 0;
            p[x][y].right_down = 0;
            p[x][y].down = 0;
            p[x][y].left_down = 0;
        }
    }
    
    //printing out map status
    MapStatus();
    
    y = 1;
    x = 1;
    
    int xx, yy;
    for(y = 1; y <= map_size-2; y++){
        for(x = 1; x <= map_size-2; x++){
            //setting PJP(Primary Jump Point)
            //setting left PJP
            if(map[x-1][y] == 'W' && map[x-1][y+1] == ' ' && map[x][y+1] != 'W' && map[x][y] != 'W'){
                map[x][y+1] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].down = d;
                    d++;
                    yy--;
                }
            }
            
            if(map[x-1][y] == 'W' && map[x-1][y-1] == ' ' && map[x][y-1] != 'W' && map[x][y] != 'W'){
                map[x][y-1] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].up = d;
                    d++;
                    yy++;
                }
            }
            
            //setting right PJP
            if(map[x+1][y] == 'W' && map[x+1][y+1] == ' ' && map[x][y+1] != 'W' && map[x][y] != 'W'){
                map[x][y+1] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].down = d;
                    d++;
                    yy--;
                }
            }
            
            if(map[x+1][y] == 'W' && map[x+1][y-1] == ' ' && map[x][y-1] != 'W' && map[x][y] != 'W'){
                map[x][y-1] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].up = d;
                    d++;
                    yy++;
                }
            }
            
            //setting down PJP
            if(map[x][y-1] == 'W' && map[x-1][y-1] == ' ' && map[x-1][y] != 'W' && map[x][y] != 'W'){
                map[x-1][y] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].left = d;
                    d++;
                    xx++;
                }
            }
            
            if(map[x][y-1] == 'W' && map[x+1][y-1] == ' ' && map[x+1][y] != 'W' && map[x][y] != 'W'){
                map[x+1][y] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].right = d;
                    d++;
                    xx--;
                }
            }
                
            //setting up PJP
            if(map[x][y+1] == 'W' && map[x-1][y+1] == ' ' && map[x-1][y] != 'W' && map[x][y] != 'W'){
                map[x-1][y] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].left = d;
                    d++;
                    xx++;
                }
            }
                
            if(map[x][y+1] == 'W' && map[x+1][y+1] == ' ' && map[x+1][y] != 'W' && map[x][y] != 'W'){
                map[x+1][y] = 'P';
                
                xx = x;
                yy = y;
                d = 1;
                while(map[xx][yy] != 'W'){
                    p[xx][yy].right = d;
                    d++;
                    xx--;
                }
            }
        }
    }
    
            
    //printing out map status
    MapStatus();
    
    for(y  = 1; y <= map_size-2; y++){
        for(x = 1; x <= map_size-2; x++){
            printf("%d ", p[x][y].left_up);
            printf("%d ", p[x][y].up);
            printf("%d  ", p[x][y].right_up);
        }
        printf("\n");
        
        for(x = 1; x <= map_size-2; x++){
            printf("%d ", p[x][y].left);
            printf("%c ", map[x][y]);
            printf("%d  ", p[x][y].right);
        }
        printf("\n");
        
        for(x = 1; x <= map_size-2; x++){
            printf("%d ", p[x][y].left_down);
            printf("%d ", p[x][y].down);
            printf("%d  ", p[x][y].right_down);
        }
        printf("\n");
        printf("\n");
    }
    
    return 0;
}
