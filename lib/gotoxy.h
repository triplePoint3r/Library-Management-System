#ifndef gotoxy_H
#define gotoxy_H
#include <Windows.h>

/**
 * @file gotoxy.h
 * @brief Provides a utility function for positioning the console cursor.
 */

 /**
  * @brief Moves the console cursor to the specified coordinates.
  *
  * @param x The horizontal position of the cursor.
  * @param y The vertical position of the cursor.
  */

inline void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif