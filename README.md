```markdown
# Operações de Matrizes com BLAS (CPU)

Projeto em C que realiza operações com matrizes utilizando a biblioteca **BLAS (Basic Linear Algebra Subprograms)** para otimização em CPU.

Autor: **João Victor Oliveira**

---

## Funcionalidades
- Soma de matrizes (`C = A + B`)
- Multiplicação de matrizes (`C = A × B`)
- Transposta (`T = Aᵀ`)
- Cálculo do traço (`tr(A)`)
- Cálculo do valor mínimo e máximo de uma matriz

---

## Estrutura
```

.
├── main.c               # Programa principal (testes)
├── modulos/
│   ├── matriz_cpu.c     # Implementação das funções
│   └── matriz_cpu.h     # Declarações das funções
└── resultados.txt       # Saída com os resultados (gerado pelo programa)

````

---

## 💻 Compilação e Execução

### Linux
```bash
sudo apt install libopenblas-dev
gcc main.c modulos/matriz_cpu.c -o matriz -lblas -lm
./matriz
````

### Windows (MSYS2)

```bash
pacman -S mingw-w64-ucrt-x86_64-openblas
gcc main.c modulos/matriz_cpu.c -o matriz.exe -lopenblas -lm
.\matriz.exe
```

---

## Saída

O programa gera o arquivo `resultados.txt` contendo:

* Matrizes A e B geradas aleatoriamente
* Resultados das operações (soma, multiplicação, transposta, traço, min e max)
* Tempo de execução de cada operação

---



