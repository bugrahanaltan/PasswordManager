# Password Manager

This project is a basic password manager implemented in C++. It allows users to create accounts, log in, delete accounts, and manage user interactions through a simple text-based interface.

## Features

- **User Login**: Allows users to log in with an existing username and password.
- **User Registration**: Enables new users to create accounts with a username and password.
- **User Deletion**: Provides the option to delete a user account from the system.
- **Text File Storage**: Stores user credentials in a text file (`users.pmd`).

## Requirements

- C++ compiler (e.g., g++, clang++)
- C++ Standard Library

## Files

- `main.cpp`: The main script that manages the password manager's functionality.
  - **`main_menu()`**: Displays the main menu and handles user choices.
  - **`login()`**: Handles user login by verifying credentials against stored data.
  - **`register_user()`**: Manages user registration and appends new user data to the text file.
  - **`delete_user()`**: Facilitates user account deletion by removing credentials from the text file.
  - **`quit()`**: Exits the application.
  - **`menu()`**: Displays a menu for the logged-in user and processes their input.

## Installation

1. Ensure you have a C++ compiler installed on your system.
2. Download or clone the repository containing the `main.cpp` file.

## Compilation and Execution

To compile and run the application:

1. Open a terminal and navigate to the directory containing `main.cpp`.

2. Compile the code using a C++ compiler:

   ```bash
   g++ main.cpp -o password_manager
   ```

3. Run the compiled executable:

   ```bash
   ./password_manager
   ```

## Data Storage

User credentials are stored in a text file named `users.pmd`. Each line in the file consists of a username and password separated by a comma.

## Usage

- **Login**: Choose option 1 from the main menu, enter your username and password to log in.
- **Register**: Choose option 2 from the main menu, provide a new username and password to create a new account.
- **Delete User**: Choose option 3 from the main menu, enter the username and password of the account you wish to delete.
- **Quit**: Choose option 4 from the main menu to exit the application.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions or feedback, please reach out to the project author at bugrahanaltan@gmail.com.
