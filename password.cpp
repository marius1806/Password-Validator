#include "password.hpp"

Password::Password()
{
    password = NULL;
}

Password::Password(char *input)
{
    if (password)
        delete[] password;
    password = new char[strlen(input) + 1];
    strcpy(password, input);
}

Password::~Password()
{
    delete[] password;
}

void Password::modify(char *input)
{
    if (password)
        delete[] password;
    password = new char[strlen(input) + 1];
    strcpy(password, input);
}

bool Password::hasLowercases(char *input, int index)
{
    if (index == strlen(input))
        return 0;
    if (input[index] >= 'a' && input[index] <= 'z')
        return 1;
    return hasLowercases(input, index + 1);
}

bool Password::hasUppercases(char *input, int index)
{
    if (index == strlen(input))
        return 0;
    if (input[index] >= 'A' && input[index] <= 'Z')
        return 1;
    return hasUppercases(input, index + 1);
}

bool Password::hasNumericCharacters(char *input, int index)
{
    if (index == strlen(input))
        return 0;
    if (input[index] >= '0' && input[index] <= '9')
        return 1;
    return hasNumericCharacters(input, index + 1);
}

bool Password::hasSpecialCharacters(char *input, int index)
{
    if (index == strlen(input))
        return 0;
    if (strchr("!@#$%^&*()_+=-{}[]';:/?.><,`~|", input[index]))
        return 1;
    return hasSpecialCharacters(input, index + 1);
}

bool Password::validate() const
{
    if (strlen(password) < 5 || strlen(password) > 51 || strchr(password, ' '))
        return 0;
    return 1;
}

void analyzePassword(Password input)
{
    int sum = input.hasLowercases(input.password, 0) + input.hasUppercases(input.password, 0) + input.hasNumericCharacters(input.password, 0) + input.hasSpecialCharacters(input.password, 0);
    if (sum == 4)
        std::cout << "Strong password" << std::endl;
    else if (sum == 3)
        std::cout << "Good password" << std::endl;
    else if (sum == 2)
        std::cout << "Average password" << std::endl;
    else if (sum == 1)
        std::cout << "Weak password" << std::endl;
}