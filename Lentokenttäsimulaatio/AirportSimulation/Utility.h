#pragma once
#include <iostream>

enum Error_code {
    success,
    fail,
    overflow,
    underflow,
    range_error,
    not_present
};

#include <iostream>
bool user_says_yes();
int create_rand(int, int);
