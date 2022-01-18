#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
typedef unsigned long long ull;

ull exp_mod(ull a, ull b, ull n);

class Scrambler
{
private:
    std::pair<ull, ull> public_key;
    void encode_file();
    int bit_mask;

public:
    Scrambler(std::pair<ull, ull> publ_key);
    int get_mask() { return bit_mask; }
};


