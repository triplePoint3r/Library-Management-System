#ifndef SwitchMenu_H
#define SwitchMenu_H

#include "gotoxy.h"
#include "color-console/color.hpp"
#include <iostream> 
#include <vector> // for vectors of alternativ of arrays
#include <functional> // for make the function to send it parameter or make veriable function
#include <conio.h>

using namespace std;
using namespace hue;
using namespace dye;

// this for make switch between the functions use arrow of keybord
class SwitchMenu 
{

public:
    struct Action {
        int id = 0;
        string NameOfAction;
        function <void()> action;
    };

private:    
    int numberOfActions = 0;
    int currentSelection = 1;
    // the vectors of functions 
    vector<Action> actions = {};
    // the positions of displayNames
    int centerWPage, startHightp;
    // the ascii of keyybord
    int key = 0;


public:

    // to print a names of functions in the center of page
    void DisplayNames(int centerWP, int startH, int endH) 
    {
        //              equal id of func           
        centerWPage = centerWP;
        startHightp = startH + 1;        
        for (int i = currentSelection; i <= numberOfActions; i++) 
        {
            if (startHightp <= endH) 
            {
                gotoxy(centerWPage - (actions[i - 1].NameOfAction.length() / 2)   , startHightp + i);
                std::cout << actions[i - 1].NameOfAction;
            }
        }
        
    }

    void currentFunction(int Shight) 
    {
        int hight_of_name;
        int temphight;
        hight_of_name = Shight + 1;
        temphight = Shight + 1;
        gotoxy(centerWPage - (2.5 + actions[currentSelection - 1].NameOfAction.length() / 2), hight_of_name + currentSelection);
        std::cout << light_red("->");
        while (true) {
            key = _getch();
            if (key == 72 && currentSelection <= numberOfActions && currentSelection != 1) 
            {
                currentSelection -= 1;
                temphight += 1;
            }
            if (key == 80 && currentSelection >= 1 && currentSelection != numberOfActions) 
            {
                currentSelection += 1;
                temphight -= 1;
            }
            if (currentSelection == actions[currentSelection - 1].id) 
            {
                gotoxy(centerWPage - (2.5 + actions[currentSelection - 1].NameOfAction.length() / 2), hight_of_name + currentSelection);
                std::cout << light_red("->");
                for (int i = 1; i <= numberOfActions; i++) 
                {
                    if (actions[i - 1].id != currentSelection) 
                    {
                        gotoxy(centerWPage - (3 + actions[i - 1].NameOfAction.length() / 2), hight_of_name + i);
                        std::cout << "  ";
                    }
                }
                if (key == 13) 
                {
                    actions[currentSelection - 1].action();
                    break;
                }
            }
        }
    }

    SwitchMenu(vector<Action> actionsPage, int NumOFactions, int centerPage, int startHight, int endHight) 
    {
        numberOfActions = NumOFactions;        
        actions = actionsPage;

        DisplayNames(centerPage, startHight, endHight);
        currentFunction(startHight);
    }
    
    ~SwitchMenu() 
    {
        actions.clear();
    }
};

#endif