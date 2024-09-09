#include <stdio.h>

int main() {
    int senhaCorreta = 99999;  //senha para teste
    

    for (int testeSenha = 0; testeSenha <= 9999999999; testeSenha++) {
        if (testeSenha == senhaCorreta) {
            printf("Senha encontrada: %d\n", testeSenha);
            break;
        }
    }

    return 0;
}

//1 + 10^n * 1
//O(10^n)