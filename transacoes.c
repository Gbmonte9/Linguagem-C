#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transacoes.h"

#define ARQUIVO_TRANSACOES "data/transacoes.txt"

Transacao transacoes[100];
int totalTransacoes = 0;

// Remove o '\n' do final da string
void limparNovaLinha(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// ================== CARREGAR ==================
void carregarDoArquivo() {
    FILE *arquivo = fopen(ARQUIVO_TRANSACOES, "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado. Criando novo...\n");
        arquivo = fopen(ARQUIVO_TRANSACOES, "w");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo de transações!\n");
            return;
        }
        fclose(arquivo);
        return;
    }

    totalTransacoes = 0;
    while (fscanf(arquivo, "%d;%9[^;];%99[^;];%f;%10[^\n]\n",
                  &transacoes[totalTransacoes].id,
                  transacoes[totalTransacoes].tipo,
                  transacoes[totalTransacoes].descricao,
                  &transacoes[totalTransacoes].valor,
                  transacoes[totalTransacoes].data) != EOF) {
        totalTransacoes++;
    }

    fclose(arquivo);
}

// ================== SALVAR ==================
void salvarEmArquivo() {
    FILE *arquivo = fopen(ARQUIVO_TRANSACOES, "w");
    int i;
    if (arquivo == NULL) {
        printf("Erro ao salvar as transações!\n");
        return;
    }

    for (i = 0; i < totalTransacoes; i++) {
        fprintf(arquivo, "%d;%s;%s;%.2f;%s\n",
                transacoes[i].id,
                transacoes[i].tipo,
                transacoes[i].descricao,
                transacoes[i].valor,
                transacoes[i].data);
    }

    fclose(arquivo);
}

// ================== ADICIONAR ==================
void adicionarTransacao() {
    if (totalTransacoes >= 100) {
        printf("Limite máximo de transações atingido!\n");
        return;
    }

    Transacao nova;
    nova.id = totalTransacoes + 1;

    printf("\nDigite o tipo (Receita/Despesa): ");
    fflush(stdin);
    fgets(nova.tipo, 10, stdin);
    limparNovaLinha(nova.tipo);

    printf("Descrição: ");
    fgets(nova.descricao, 100, stdin);
    limparNovaLinha(nova.descricao);

    printf("Valor: ");
    scanf("%f", &nova.valor);
    getchar();

    printf("Data (DD/MM/AAAA): ");
    fgets(nova.data, 11, stdin);
    limparNovaLinha(nova.data);

    transacoes[totalTransacoes] = nova;
    totalTransacoes++;
    salvarEmArquivo();

    printf("\n? Transação adicionada com sucesso!\n");
}

// ================== LISTAR ==================
void listarTransacoes() {
    if (totalTransacoes == 0) {
        printf("\nNenhuma transação cadastrada.\n");
        return;
    }

    float totalReceitas = 0.0, totalDespesas = 0.0;
    int i;

    printf("\n===== LISTA DE TRANSAÇÕES =====\n");
    for (i = 0; i < totalTransacoes; i++) {
        printf("%d. [%s] %s - R$ %.2f (%s)\n",
               transacoes[i].id,
               transacoes[i].tipo,
               transacoes[i].descricao,
               transacoes[i].valor,
               transacoes[i].data);

        if (strcmp(transacoes[i].tipo, "Receita") == 0)
            totalReceitas += transacoes[i].valor;
        else if (strcmp(transacoes[i].tipo, "Despesa") == 0)
            totalDespesas += transacoes[i].valor;
    }

    printf("===============================\n");
    printf("Total de Receitas: R$ %.2f\n", totalReceitas);
    printf("Total de Despesas: R$ %.2f\n", totalDespesas);
    printf("Saldo Final:       R$ %.2f\n", totalReceitas - totalDespesas);
    printf("===============================\n");
}

// ================== BUSCAR ==================
void buscarTransacao() {
    if (totalTransacoes == 0) {
        printf("Nenhuma transação para buscar.\n");
        return;
    }

    char termo[100];
    int encontrados = 0;
    int i;

    printf("Digite parte da descrição: ");
    fflush(stdin);
    fgets(termo, 100, stdin);
    limparNovaLinha(termo);

    printf("\nResultados da busca:\n");
    for (i = 0; i < totalTransacoes; i++) {
        if (strstr(transacoes[i].descricao, termo) != NULL) {
            printf("%d. [%s] %s - R$ %.2f (%s)\n",
                   transacoes[i].id,
                   transacoes[i].tipo,
                   transacoes[i].descricao,
                   transacoes[i].valor,
                   transacoes[i].data);
            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("Nenhuma transação encontrada.\n");
}

// ================== EXCLUIR ==================
void excluirTransacao() {
    if (totalTransacoes == 0) {
        printf("Nenhuma transação para excluir.\n");
        return;
    }

    listarTransacoes();

    int id, i;
    printf("Digite o ID da transação a excluir: ");
    scanf("%d", &id);

    if (id < 1 || id > totalTransacoes) {
        printf("ID inválido!\n");
        return;
    }

    for (i = id - 1; i < totalTransacoes - 1; i++) {
        transacoes[i] = transacoes[i + 1];
        transacoes[i].id = i + 1;
    }

    totalTransacoes--;
    salvarEmArquivo();

    printf("Transação excluída com sucesso!\n");
}

// ================== EXPORTAR RELATÓRIO ==================
void exportarRelatorio() {
    if (totalTransacoes == 0) {
        printf("Nenhuma transação para exportar.\n");
        return;
    }

    FILE *relatorio = fopen("data/relatorio.txt", "w");
    if (relatorio == NULL) {
        printf("Erro ao criar o arquivo de relatório!\n");
        return;
    }

    float totalReceitas = 0.0, totalDespesas = 0.0;
    int i;

    fprintf(relatorio, "===== RELATÓRIO DE TRANSAÇÕES =====\n\n");
    for (i = 0; i < totalTransacoes; i++) {
        fprintf(relatorio, "%d. [%s] %s - R$ %.2f (%s)\n",
                transacoes[i].id,
                transacoes[i].tipo,
                transacoes[i].descricao,
                transacoes[i].valor,
                transacoes[i].data);

        if (strcmp(transacoes[i].tipo, "Receita") == 0)
            totalReceitas += transacoes[i].valor;
        else if (strcmp(transacoes[i].tipo, "Despesa") == 0)
            totalDespesas += transacoes[i].valor;
    }

    fprintf(relatorio, "\n===============================\n");
    fprintf(relatorio, "Total de Receitas: R$ %.2f\n", totalReceitas);
    fprintf(relatorio, "Total de Despesas: R$ %.2f\n", totalDespesas);
    fprintf(relatorio, "Saldo Final:       R$ %.2f\n", totalReceitas - totalDespesas);
    fprintf(relatorio, "===============================\n");

    fclose(relatorio);
    printf("\n?? Relatório exportado com sucesso para 'data/relatorio.txt'!\n");
}

