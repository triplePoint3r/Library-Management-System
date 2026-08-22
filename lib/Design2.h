#ifndef Design2_H
#define Design2_H

#include <iostream>

inline void drawRectangle(int width, int height) {
    std::cout << "\t\t\t\t\t\t" << char(201);
    for (int i = 0; i < width; i++) {
        std::cout << char(205);
    }
    std::cout << char(187) << std::endl;

    for (int i = 0; i < height; i++) {
        std::cout << "\t\t\t\t\t\t" << char(186);
        for (int j = 0; j < width; j++) {
            std::cout << char(32);
        }
        std::cout << char(186) << std::endl;
    }

    std::cout << "\t\t\t\t\t\t" << char(200);
    for (int i = 0; i < width; i++) {
        std::cout << char(205);
    }
    std::cout << char(188) << std::endl;
}

#endif