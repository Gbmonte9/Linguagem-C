#ifndef TRANSACOES_H
#define TRANSACOES_H

typedef struct {
    int id;
    char tipo[10];       
    char descricao[100];
    float valor;
    char data[11];       
} Transacao;

// Funções principais
void adicionarTransacao();
void listarTransacoes();
void buscarTransacao();
void excluirTransacao();
void salvarEmArquivo();
void carregarDoArquivo();
void exportarRelatorio(); 

#endif
