# 🧾 Mini Sistema de Gerenciamento Financeiro (CLI)

## 📖 Descrição do Projeto
O **Mini Sistema de Gerenciamento Financeiro (CLI)** é uma aplicação desenvolvida em **linguagem C** com interface via **linha de comando (terminal)**.  
O objetivo do projeto é permitir que o usuário **registre, consulte e gerencie suas receitas e despesas** de forma simples e rápida, armazenando os dados em **arquivos locais**.  

O sistema foi criado para demonstrar **conceitos fundamentais da linguagem C**, como:
- Manipulação de arquivos (`fopen`, `fread`, `fwrite`, `fprintf`, etc.);
- Uso de **structs** para representar entidades;
- Controle de fluxo e menus interativos;
- Tratamento de strings e ponteiros.

---

## 🧩 Funcionalidades Principais

✅ **1. Adicionar transação**
- Permite registrar uma nova transação financeira.  
- Campos:
  - Tipo: Receita ou Despesa  
  - Descrição  
  - Valor  
  - Data (ex: 28/10/2025)

✅ **2. Listar transações**
- Mostra todas as transações cadastradas no terminal.  
- Exibe total de receitas, despesas e saldo final.  

✅ **3. Buscar por descrição**
- Permite o usuário digitar um termo e visualizar apenas as transações correspondentes.  

✅ **4. Excluir transação**
- Remove um registro com base no índice ou ID.  

✅ **5. Exportar relatório**
- Gera um arquivo `.txt` com todas as transações e o resumo financeiro.  

✅ **6. Sair do sistema**
- Encerra o programa com mensagem de confirmação.

---

## 🗂️ Estrutura do Projeto
```
/finance-cli
│
│── main.c               # Ponto de entrada do sistema
│── transacoes.c         # Funções de CRUD de transações
│── transacoes.h         # Header com structs e funções
│── menu.c               # Funções relacionadas ao menu
│
├── data/
│   └── transacoes.txt       # Arquivo com os dados salvos
│
├── docs/
│   └── estrutura_logica.md  # Explicação do funcionamento interno
│
└── README.md
```

---

## 🧠 Estrutura Lógica
O programa funciona com base em **structs** e **listas em memória**, que são salvas em arquivo após cada modificação.  

```c
typedef struct {
    int id;
    char tipo[10];       // "Receita" ou "Despesa"
    char descricao[100];
    float valor;
    char data[11];       // formato DD/MM/AAAA
} Transacao;
```
As funções principais são:
- `adicionarTransacao()`  
- `listarTransacoes()`  
- `buscarTransacao()`  
- `excluirTransacao()`  
- `salvarEmArquivo()`  
- `carregarDoArquivo()`
- `exportarRelatorio()`

---

## ⚙️ Tecnologias Utilizadas
- Linguagem C  
- Manipulação de arquivos (`stdio.h`)  
- Structs e arrays dinâmicos  
- Ponteiros e funções  
- Compilador GCC  

---

## 💡 Possíveis Melhorias Futuras
- Converter o armazenamento de `.txt` para **arquivo binário**.  
- Adicionar **filtros por mês ou tipo de transação**.  
- Implementar **ordenação por valor ou data**.  
- Criar um **modo gráfico** com `ncurses`.  
- Exportar relatório em **CSV** para uso no Excel.  

---

## 🧰 Como Compilar e Executar
```bash
# Compilar
gcc src/main.c src/transacoes.c src/menu.c -o finance

# Executar
./finance
```

---

## 📊 Exemplo de Uso
```
==============================
  SISTEMA FINANCEIRO - CLI
==============================

1. Adicionar transação
2. Listar transações
3. Buscar transação
4. Excluir transação
5. Exportar relatório
6. Sair

Escolha uma opção: 1
Digite o tipo (Receita/Despesa): Receita
Descrição: Salário
Valor: 2500.00
Data: 28/10/2025
Transação adicionada com sucesso!
```

---

## 👨‍💻 Autor
**Gabriel Monte**  
Desenvolvedor Fullstack | Estudante de Engenharia de Software  
📍 Rio de Janeiro, Brasil  
📧 gabrielmonte485@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/gabriel-rodrigues-mt/)
