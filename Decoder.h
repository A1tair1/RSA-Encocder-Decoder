#pragma once
typedef unsigned long long ull;
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>



ull exp_mod(ull a, ull b, ull n);

class Decoder
{
private:
    std::pair<ull, ull> private_key;
    std::pair<ull, ull> public_key;

    void create_asym_keys(std::pair<ull, ull>* public_key, std::pair<ull, ull>* private_key); // —генерировать ключи
public:
    Decoder();
    std::pair<ull, ull> get_key()   {   return public_key;  }

    void decode(int encoded_mask); // ƒекодировать файл использу€ закодированную маску


};

