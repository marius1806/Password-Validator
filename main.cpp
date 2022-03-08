#include "password.hpp"

int main()
{
    char input[51];
    std::cout << "Create your password (at least 5 characters)" << std::endl;
    std::cin.getline(input, 51);
    Password pw(input);
    while (true)
    {
        switch (pw.validate())
        {
        case 1:
            analyzePassword(pw);
            break;

        default:
            std::cout << "Invalid password! Try typing another password..." << std::endl;
            std::cin.getline(input, 51);
            pw.modify(input);
            continue;
            break;
        }
        std::cout << "Save the password? (y/n) ";
        char ans = getche();
        std::cout << std::endl;
        if (ans != 'y' && ans != 'Y')
        {
            std::cout << "Type another password" << std::endl;
            std::cin.getline(input, 51);
            pw.modify(input);
        }
        else
        {
            std::cout << std::endl << "Password succesfully created. Your Password is: " << input << "\nDo not share it with anyone!";
            break;
        }
    }
    return 0;
}