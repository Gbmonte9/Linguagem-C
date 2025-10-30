#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "transacoes.h"

int main() {
    int opcao;

    carregarDoArquivo();

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                adicionarTransacao();
                break;

            case 2:
                listarTransacoes();
                break;

            case 3:
                buscarTransacao();
                break;

            case 4:
                excluirTransacao();
                break;

            case 5:
                exportarRelatorio(); 
                break;

            case 6:
                printf("\nSaindo do sistema... Até logo!\n");
                salvarEmArquivo(); 
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while (opcao != 6); 

    return 0;
}
