
#include "CommonIncludes.h"

class UserInfo
{
private:
	string username;
	string password;

public:
	string usernameEntry;
	string passwordEntry;
	UserInfo()
	{
	
	}
	bool login() 
	{
		if (usernameEntry == username && passwordEntry == password)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};
