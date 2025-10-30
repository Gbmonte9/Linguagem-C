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