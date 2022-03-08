#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

class Password
{
    char *password;

public:
    Password();
    Password(char *);
    ~Password();

    void modify(char *);
    bool hasLowercases(char *, int);
    bool hasUppercases(char *, int);
    bool hasNumericCharacters(char *, int);
    bool hasSpecialCharacters(char *, int);
    bool validate() const;
    
    friend void analyzePassword(Password);
};