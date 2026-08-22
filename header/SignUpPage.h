#pragma once
#include <iostream>
#include <regex>
#include "Design.h"
#include "DataBase.h"
#include "LoginOrSignUpOrGuest.h"

class Signup 
{

private:
	User sUser;

public:
	Signup();	
	void SetVisitorName();
	void SetVisitorAge();
	void SetVisitorEmail();
	void SetVisitorPassword();
	void SetVisitorPermission();
	void backtoMainpage();
	void printHeaderSignup();
	void doneSignup();	
};

