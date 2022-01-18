#include "Scrambler.h"

// Кодирование файла
void Scrambler::encode_file()
{
    std::cout << "Print a way to file to encode: ";
    std::string file;
    std::cin >> file;
    char ch;
    std::ifstream infile(file, std::ios::binary);
    std::ofstream ofile("encoded.file", std::ios::binary);
    
    while (infile)
    {
        infile.get(ch);
        ofile << static_cast<char>(ch ^ bit_mask);
    }
    infile.close();
    ofile.close();
}


Scrambler::Scrambler(std::pair<ull, ull> publ_key) : public_key(publ_key)
{
    srand(time(0));
    bit_mask = rand() % 256; // Получение случайной маски байта
    this->encode_file();
    bit_mask = exp_mod(bit_mask, 257, public_key.second); // Кодирование маски

}

