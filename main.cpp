#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Global variables to store the current user's username and password
string g_usr;
string g_pwd;

// Function prototypes
void login();
void register_user();
void main_menu();
void quit();
void delete_user();
void menu();

// Main menu function to provide options to the user
void main_menu()
{
    string option; // Variable to store the user's choice

    while (true)
    {
        // Display the main menu options
        cout << "Welcome to my password manager... How can I help you? Please select one of the options:" << endl
             << "[1] Login with user" << endl
             << "[2] Create new user" << endl
             << "[3] Delete user" << endl
             << "[4] Exit the password manager" << endl;
        
        getline(cin >> ws, option);

        if (option == "1")
        {
            login(); // Call login function
            break;
        }
        else if (option == "2")
        {
            register_user(); // Call register_user function
            break;
        }
        else if (option == "3")
        {
            delete_user(); // Call delete_user function
            break;
        }
        else if (option == "4")
        {
            quit(); // Call quit function
            break;
        }
        else
        {
            cout << "Invalid option... Please choose from 1 to 4!" << endl;
            continue; // Prompt the user again if the option is invalid
        }
    }
}

// Function to handle user login
void login()
{
    string username;
    string password;
    string stored_name;
    string stored_password;
    bool reading_password = false;

    // Prompt user for username and password
    cout << "[?] What is your username?" << endl;
    getline(cin >> ws, username);

    cout << "[?] What is your password?" << endl;
    getline(cin >> ws, password);

    ifstream account_file("users.pmd"); // Open the file to read user data

    string line;
    while (getline(account_file, line))
    {
        // Parse the line to extract stored username and password
        for (char& c : line)
        {
            if (c != ',' && !reading_password)
                stored_name += c;
            else if (c == ',' && !reading_password)
            {
                reading_password = true;
                continue;
            }

            if (reading_password)
                stored_password += c;
        }
    }
    account_file.close();

    if (username == stored_name && password == stored_password)
    {
        // If username and password match, set global variables and proceed to the menu
        cout << "Username and password are correct. You are logged in!" << endl;
        g_usr = username;
        g_pwd = password;
        menu(); // Go to the menu function
    }
    else
    {
        cout << "Incorrect username and/or password... Returning to main menu..." << endl;
        main_menu(); // Return to the main menu
    }
}

// Function to handle user registration
void register_user()
{
    string username;
    string password;

    // Prompt user for new username and password
    cout << "[?] What will be your new username?" << endl;
    getline(cin >> ws, username);

    cout << "[?] What will be your new password?" << endl;
    getline(cin >> ws, password);

    ofstream account_file("users.pmd", ios::app); // Open file in append mode to add new user
    account_file << username << "," << password << endl; // Write new user data to the file
    account_file.close();

    cout << "[+] Successfully created new user! Returning to main menu..." << endl;
    main_menu(); // Return to the main menu
}

// Function to handle user deletion
void delete_user()
{
    string username;
    string password;
    string stored_name;
    string stored_password;
    bool reading_password = false;
    bool user_found = false;

    // Prompt user for username and password to delete
    cout << "[?] What is your username?" << endl;
    getline(cin >> ws, username);

    cout << "[?] What is your password?" << endl;
    getline(cin >> ws, password);

    ifstream account_file("users.pmd"); // Open file to read user data
    ofstream temp_file("temp.pmd"); // Create a temporary file to store updated data

    string line;
    while (getline(account_file, line))
    {
        // Parse the line to extract stored username and password
        for (char& c : line)
        {
            if (c != ',' && !reading_password)
                stored_name += c;
            else if (c == ',' && !reading_password)
            {
                reading_password = true;
                continue;
            }

            if (reading_password)
                stored_password += c;
        }

        if (username == stored_name && password == stored_password)
        {
            // Skip writing this line to the temporary file if the user is found
            user_found = true;
            continue;
        }
        else
        {
            temp_file << line << endl; // Write other lines to the temporary file
        }
    }
    account_file.close();
    temp_file.close();

    remove("users.pmd"); // Delete the original file
    rename("temp.pmd", "users.pmd"); // Rename the temporary file to the original file name

    if (user_found)
    {
        cout << "[!] Successfully deleted user " << username << " from the file!" << endl;
    }
    else
    {
        cout << "[!] Could not delete user because the username and/or password is incorrect" << endl;
    }

    main_menu(); // Return to the main menu
}

// Function to quit the application
void quit()
{
    exit(0); // Terminate the program
}

// Function to display the user's menu after login
void menu()
{
    string help_option;

    while (true)
    {
        cout << "Welcome, " << g_usr << ". How can we help you?" << endl;
        getline(cin >> ws, help_option);
        cout << "Okay, helping you with: " << help_option << endl;
        // Additional functionality can be added here based on user's input
    }
}

// Main function to start the program
int main()
{
    main_menu(); // Show the main menu when the program starts
    return 0;
}
