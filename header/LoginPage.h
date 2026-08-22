#pragma once
#include <iostream>
#include "DataBase.h"
#include "Design.h"
#include "LoginOrSignUpOrGuest.h"
#include "MainPage.h"

using namespace std;

class Login 
{
private:
	string UserName;
	string PassWord;
public:
	Login();	
	void login_page();
	bool CheckLogin(string user, string pass);	
};
