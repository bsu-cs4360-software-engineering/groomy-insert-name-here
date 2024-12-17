#define USERINFO_H
#ifndef USERINFO_H


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
	static bool login(const string& username, const string& password) {
        string user_data_file = username + ".json";

        if (!fs::exists(user_data_file)) {
            cout << "Username not found." << endl;
            return false;
        }
        

        ifstream file(user_data_file);
        json user_data;
        file >> user_data;
        file.close();

        string stored_password = user_data["password"];

        if (hashMe(password, 11) != stored_password)
        {
            cout << "Error! Username or Password invalid.\nPlease verify correct username and password before trying again.";
            return false;
        }
        else if (hashMe(password, 11) == stored_password)
        {
            cout << "Login Successful.";
            return true;
        }
        else {
            cout << "Unkown error occured. Please retry.";
            return false;
        }
        
        

        
    }
    bool register_User()
    {
        if(fs::exists(user_file)) 
        {
            cout << "User already exists." << endl;
            return false;
        }

        string hashed_pass = hashMe(password, 11);

        json user_data = {{"username", username}, 
        {"password", hashed_pass},
        {"email", email}, 
        {"first_name", first_name},
        {"last_name", last_name}
        };

        ofstream file(user_file);
        file << user_data.dump(4);
        file.close();

        cout << "User created successfully." << endl;
        return true;

    }
        static bool create_account(const string& username, const string& password, const string& email, const string& first_name, const string& last_name) {
        UserInfo user(username, password, email, first_name, last_name);
        return user.register_User();
    }

};

#endif // USERINFO_H