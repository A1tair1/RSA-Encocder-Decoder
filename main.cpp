#include <iostream>
#include "Scrambler.h"
#include "Decoder.h"

// Вычисление выражения вида (a^b)%n;
ull exp_mod(ull a, ull b, ull n)
{
    ull r = 1;
    while (b) {
        if (b & 1)r = (a * r) % n;
        a = (a * a) % n;
        b >>= 1;
    }
    return r;
}

int main()
{
    Decoder dec;

    Scrambler a(dec.get_key());
    dec.decode(a.get_mask());


}