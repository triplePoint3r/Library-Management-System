#include "LoginOrSignUpOrGuest.h"

LoginOrSignUpOrGuest::LoginOrSignUpOrGuest() {
    system("cls");
    ConsolePgaes page(
        "Main page",
        50,
        105,
        1,
        5,
        6,
        12
    );
    auto position = page.PositionsOfPage();

    vector<SwitchMenu::Action> actions = {

        {
            1,
            "Login",
            []() {
                Login login;
            }
        },

        {
            2,
            "Sign up",
            []() {
                Signup signup;
            }
        },

        {
            3,
            "Guest",
            []() {
                Guest guest;
            }
        }
    };
    SwitchMenu menu(
        actions,
        actions.size(),
        position.centerOfPw,
        position.StartHightPage,
        position.EndHightPage
    );
}
