#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


const int max_cache = 10000000;

vector<long long> cache(max_cache, 0);

long long funcao_hash(long long n) {
    if (n < max_cache && cache[n] != 0)
        return cache[n];

    long long result;

    if (n == 1) result = 1;
    else if (n % 2 == 0)
        result = 1 + funcao_hash_hash(n / 2);
    else
        result = 1 + funcao_hash(3*n + 1);

    if (n < max_cache)
        cache[n] = result;

    return result;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();

    long long maior_numero = 1;
    long long maior_tamanho = 1;

    for (long long i = 1; i < 1000000; i++) {
        long long tamanho_atual = collatz_hash(i);
        if (tamanho_atual > maior_tamanho) {
            maior_tamanho = tamanho_atual;
            maior_numero = i;
        }
    }
    cout << "Numero: " << maior_numero << endl;
    cout << "Tamanho da sequencia: " << maior_tamanho << endl;

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;
    cout << "Tempo: " << duracao.count() << " segundos\n";
    

    return 0;
}
