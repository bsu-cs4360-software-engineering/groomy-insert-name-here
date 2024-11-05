
#include "CommonIncludes.h"

using json = nlohmann::json;
namespace fs = std::filesystem;

class UserInfo
{
private:
	string username;
	string password;
    string email;
    string first_name;
    string last_name;
    string user_file;

public:
	string usernameEntry;
	string passwordEntry;
    UserInfo(const string& username, const string& password, const string& email = "", const string& first_name = "", const string& last_name = ""):
        username(username), password(password), email(email), first_name(first_name), last_name(last_name)
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
