#include <iostream>
using namespace std;

long long func_sequencia_metodo_trivial(long long n) {
    long long length = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        length++;
    }
    return length;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    
    long long maior_numero = 0;
    long long maior_tamanho = 0;

    for (long long i = 1; i < 1000000; i++) {
        long long tamanho = func_sequencia_metodo_trivial(i);
        if (tamanho > maior_tamanho) {
            maior_tamanho = tamanho;
            maior_numero = i;
        }
    }

    cout << "Numero com maior sequencia: " << maior_numero << endl;
    cout << "Tamanho da sequencia: " << maior_tamanho << endl;

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;
    cout << "Tempo: " << duracao.count() << " segundos\n";
    
    return 0;
}
