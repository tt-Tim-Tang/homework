//2453805 Ã∆œ»‘Û µÁ–≈

#pragma once

char menu();
void fun(char choice);
void end_judge(int x, int y);
void set_window(int size,char choice);
void game(int size, char* array, int* remind_row, int* remind_col, int width, int height,char choice);
int compare(int size, char* user, int* remind_row, int* remind_col);
char* array_choice(int size, char* a, char* b, char* c);
int area_size();
int row_remind(int* remind_row, char* array, int size);
int col_remind(int* remind_col, char* array, int size);
int* array_remind_choice(int size, int* a, int* b, int* c);
void read_mouse(int size, int x, int y, char choice, int& row, int& col, char& ins,int &mouse_LR);
void draw_array(int size, char* array, int* remind_row, int* remind_col, char choice, int width, int height, int& x, int& y);
void draw_square(int x, int y,int bg_color,int fg_color);
void draw_blank(int x, int y);
void draw_img(int size, char* array, int* remind_row, int* remind_col, char choice, int width, int height, int x, int y);
void draw_x(int x, int y, int bg_color, int fg_color);





