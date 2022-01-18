#include "Decoder.h"


//Проверка числа на простоту
bool check_prime(ull n)
{
    std::vector<char> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
    return prime[n];
}


// Расширенный НОД
long long extended_gcd(int a, int b) // extended_gcd(phi(x), e)
{
    //old_s, old_t - искомые коэффициенты Безу (На последней итерации алгоритма)
    long long old_r = a, r = b;
    long long old_s = 1, s = 0;
    long long old_t = 0, t = 1;

    while (r != 0)
    {
        long long quotient = old_r / r;
        long long tmp;

        tmp = old_r;
        old_r = r; r = tmp - quotient * r;

        tmp = old_s;
        old_s = s; s = tmp - quotient * s;

        tmp = old_t;
        old_t = t; t = tmp - quotient * t;
    }
    // Приводим полученное значение в соответствующее ему значение в поле остатков от деления на функцию Эйлера.
    while (old_t < 0)
    {
        old_t += a;
    }

    return old_t;
}
// Создание асиметричных ключей
void Decoder::create_asym_keys(std::pair<ull, ull>* public_key, std::pair<ull, ull>* private_key)
{
    // Выбор двух случайных простых числа p, q
    srand(time(0));
    ull p, q;
    do
    {
        p = rand();
    } while (!check_prime(p));
    do
    {
        q = rand();
    } while (!check_prime(q) || q == p);

    // Вычисление модуля
    ull n = p * q;

    // Получение значения функции Эйлера от n
    ull Euler_funtcion = (p - 1) * (q - 1);

    // Подбор открытой экспоненты e: 1 < e < Euler_function
    ull e = 257;


  // Подбор скрытой экспоненты 
    ull d = extended_gcd(Euler_funtcion, e);

    public_key->first = e;
    public_key->second = n;

    private_key->first = d;
    private_key->second = n;
}



Decoder::Decoder()
{
    create_asym_keys(&public_key, &private_key);    // Создание ассиметричных ключей шифрования
}

void Decoder::decode(int encoded_mask)
{
    int decoded_mask = exp_mod(encoded_mask, private_key.first, private_key.second);

    char ch;
    std::string file;
    std::cout << "Print a name of decoded file (with extension): ";
    std::cin >> file;
    std::ifstream infile("encoded.file", std::ios::binary);
    std::ofstream result(file, std::ios::binary);
    while (infile)
    {
        infile.get(ch);

        result << static_cast<char>(ch ^ decoded_mask);
    }
    infile.close();
    result.close();
}