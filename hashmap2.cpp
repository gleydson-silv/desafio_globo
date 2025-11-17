#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;

unordered_map<long long, long long> memo;

long long collatz_hashmap(long long n) {
    if (n == 1) return 1;

    if (memo.count(n))
        return memo[n];

    long long result;
    if (n % 2 == 0)
        result = 1 + collatz_hashmap(n / 2);
    else
        result = 1 + collatz_hashmap(3*n + 1);

    memo[n] = result;
    return result;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    
    long long max_num = 1;
    long long max_len = 1;

    for (long long i = 1; i < 1000000; i++) {
        long long len = collatz_hashmap(i);
        if (len > max_len) {
            max_len = len;
            max_num = i;
        }
    }

    cout << "VERSAO HASHMAP (unordered_map)" << endl;
    cout << "Numero: " << max_num << endl;
    cout << "Tamanho da sequencia: " << max_len << endl;

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;
    cout << "Tempo: " << duracao.count() << " segundos\n";
    

    return 0;
}
