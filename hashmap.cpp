#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;

unordered_map<long long, long long> memo;

long long funcao_hash(long long n) {
    if (n == 1) return 1;
    if (memo.count(n)) return memo[n];

    long long resultado;
    if (n % 2 == 0)
        resultado = 1 + funcao_hash(n / 2);
    else
        resultado = 1 + funcao_hash(3 * n + 1);

    memo[n] = resultado;
    return resultado;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    
    long long maior_numero = 0;
    long long maior_tamanho = 0;

    for (long long i = 1; i < 1000000; i++) {
        long long tamanho_atual = funcao_hash(i);
        if (tamanho_atual > maior_tamanho) {
            maior_tamanho = tamanho_atual;
            maior_numero = i;
        }
    }

    cout << "Maior sequencia abaixo de 1.000.000: " << maior_numero << endl;
    cout << "Tamanho da sequencia: " << maior_tamanho << endl;

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;
    cout << "Tempo: " << duracao.count() << " segundos\n";
    
    return 0;
}
