#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Limite máximo do cache (pode aumentar se quiser)
const int MAXN = 10000000;

vector<long long> cache(MAXN, 0);

long long collatz_hash(long long n) {
    if (n < MAXN && cache[n] != 0)
        return cache[n];

    long long result;

    if (n == 1) result = 1;
    else if (n % 2 == 0)
        result = 1 + collatz_hash(n / 2);
    else
        result = 1 + collatz_hash(3*n + 1);

    if (n < MAXN)
        cache[n] = result;

    return result;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();

    long long max_num = 1;
    long long max_len = 1;

    for (long long i = 1; i < 1000000; i++) {
        long long len = collatz_hash(i);
        if (len > max_len) {
            max_len = len;
            max_num = i;
        }
    }

    cout << "VERSAO HASH (Vetor)" << endl;
    cout << "Numero: " << max_num << endl;
    cout << "Tamanho da sequencia: " << max_len << endl;

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;
    cout << "Tempo: " << duracao.count() << " segundos\n";
    

    return 0;
}
