#ifndef Design_H
#define Design_H

#include "gotoxy.h"
#include <iostream> 
#include "color-console/color.hpp"
#include <vector> // for vectors of alternativ of arrays
#include <functional> // for make the function to send it parameter or make veriable function

using namespace std;
using namespace dye;

// top left corner char(201)
// width char(205)
// top right corner char(187)

// wall char(186);
// down left corner char(200) 
// down right corner char(188)

class ConsolePgaes {
private:
    // the start and end  of hight and width of header        
    int StartWidthHeader, EndWidthHeader, StartHightHeader, EndHightHeader;
    // the start and end  of hight and width of page        
    int StartWidthPage, EndWidthPage, StartHightPage, EndHightPage;
    // the centers of header 
    int centerOfWidthHeader = 0;
    int centerOfHightHeader = 0;

    // the centers of page
    int centerOfWidthPage = 0;
    int centerOfHightPage = 0;

    
    

public:
    // for the position of page 
    struct position {
        int StartHightPage, EndHightPage;
        int centerOfPw;
    };
    position Positions;

    ConsolePgaes(string titleOFheader, int SWH, int EWH, int SHH, int EHH, int SHP, int EHP) {
        // values of header 
        StartWidthHeader = SWH, EndWidthHeader = EWH, StartHightHeader = SHH, EndHightHeader = EHH;
        // values of page
        StartWidthPage = SWH, EndWidthPage = EWH, StartHightPage = SHP, EndHightPage = EHP;
        system("cls");
        centerOfWidthHeader = (StartWidthHeader + EndWidthHeader) / 2;
        centerOfHightHeader = (StartHightHeader + EndHightHeader) / 2;

        centerOfWidthPage = (StartWidthPage + EndWidthPage) / 2;
        centerOfHightPage = (StartHightPage + EndHightPage) / 2;
        // header
        printHeader(titleOFheader);
        // page
        printPage();
    }
    // header    
    void printHeader(string title) {
        if (!title.empty()) {
            for (int i = StartWidthHeader; i <= EndWidthHeader; i++) {
                //top left corner 
                if (i == StartWidthHeader) {
                    gotoxy(StartWidthHeader, StartHightHeader);
                    std::cout << char(201);
                }
                // width top border
                if (i < EndWidthHeader && i > StartWidthHeader) {
                    gotoxy(i, StartHightHeader);
                    std::cout << char(205);
                }
                // top right corner 
                if (i == EndWidthHeader) {
                    gotoxy(EndWidthHeader, StartHightHeader);
                    std::cout << char(187);
                }

                //down left corner 
                if (i == StartWidthHeader) {
                    gotoxy(StartWidthHeader, EndHightHeader);
                    std::cout << char(200);
                }
                // width under border 
                if (i < EndWidthHeader && i > StartWidthHeader) {
                    gotoxy(i, EndHightHeader);
                    std::cout << char(205);
                }
                // down right corner 
                if (i == EndWidthHeader) {
                    gotoxy(EndWidthHeader, EndHightHeader);
                    std::cout << char(188);
                }

                for (int i = StartHightHeader + 1; i < EndHightHeader; i++) {
                    gotoxy(StartWidthHeader, i);
                    std::cout << char(186);

                    gotoxy(EndWidthHeader, i);
                    std::cout << char(186);
                }
            }
        }
        gotoxy(centerOfWidthHeader - (title.length() / 2), 3);
        std::cout << red(title);
    }


    // page
    void printPage() {
        for (int i = StartWidthPage; i <= EndWidthPage; i++) {
            //top left corner 
            if (i == StartWidthPage) {
                gotoxy(StartWidthPage, StartHightPage);
                std::cout << char(201);
            }
            // width top border
            if (i < EndWidthPage && i > StartWidthPage) {
                gotoxy(i, StartHightPage);
                std::cout << char(205);
            }
            // top right corner 
            if (i == EndWidthPage) {
                gotoxy(EndWidthPage, StartHightPage);
                std::cout << char(187);
            }

            //down left corner 
            if (i == StartWidthPage) {
                gotoxy(StartWidthPage, EndHightPage);
                std::cout << char(200);
            }
            // width under border 
            if (i < EndWidthPage && i > StartWidthPage) {
                gotoxy(i, EndHightPage);
                std::cout << char(205);
            }
            // down right corner 
            if (i == EndWidthPage) {
                gotoxy(EndWidthPage, EndHightPage);
                std::cout << char(188);
            }
            for (int i = StartHightPage + 1; i < EndHightPage; i++) {
                gotoxy(StartWidthPage, i);
                std::cout << char(186);

                gotoxy(EndWidthPage, i);
                std::cout << char(186);
            }
        }
    }


    position PositionsOfPage() {
        //center of width page        
        Positions.centerOfPw = centerOfWidthPage;
        Positions.StartHightPage = StartHightPage; // the start of hight of page 
        Positions.EndHightPage = EndHightPage; // the end of hight of page        
        return Positions;
    }
};

#endif