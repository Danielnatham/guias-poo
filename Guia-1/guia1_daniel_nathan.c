#include <stdio.h>

typedef struct Aluno
{
    int nota1;
    int nota2;
    int projeto;
    double (*notaFinal)(struct Aluno*)
} Aluno;

double calculaNotaFinal(struct Aluno *);

Aluno setAluno(int g11, int g12, int g21, int g22, int projeto)
{
    Aluno novoAluno;

    novoAluno.nota1 = (g11 + g12) / 2;
    novoAluno.nota2 = (g21 + g22) / 2;
    novoAluno.projeto = projeto;
    novoAluno.notaFinal = calculaNotaFinal;

    return novoAluno;
}

double calculaNotaFinal(struct Aluno *aluno)
{
    double notaFinal = (aluno->nota1 * 0.2) + (aluno->nota2 * 0.2) + aluno->projeto * 0.6;
    return notaFinal;
}

int main(int argc, char const *argv[])
{
    Aluno carlos = setAluno(10, 10, 10, 10, 10);
    double notaRealmenteFinal = calculaNotaFinal(&carlos);

    printf("%g\n",notaRealmenteFinal);

    return 0;
}
