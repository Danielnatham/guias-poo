#include<iostream>
 
using namespace std;
 
class Avaliacao{
    string  nomeDoAluno,
            matricula;
    double u1_guialab1,
    u1_guialab2,
    u2_guialab1,
    u2_guialab2,
    projetofinal,
    p1,
    p2,
    p3,
    unidade1,
    unidade2,
    notafinal;
 
   public:
   Avaliacao(){
       p1 = 0.2;
       p2 = 0.2;
       p3 = 0.6;      
   }

   void setNomeAluno(string nome){
       nomeDoAluno = nome;
    };
   void setMatricula(string matricula){
       matricula = matricula;
    };
    string getNomeAluno(){
       return nomeDoAluno;
    };
   string getMatricula(){
       return matricula;
    };
   double getNotaFinal(){
       return notafinal;
    };
 
   double AvaliacaoUnidade1(){
       unidade1 = (u1_guialab1 + u1_guialab2)/2;
       return unidade1;
   }
 
   double AvaliacaoUnidade2(){
       unidade2 = (u2_guialab1 + u2_guialab2)/2;
       return unidade2;
   }
 
   void NotaFinal(){
       notafinal = ( AvaliacaoUnidade1()*p1 +
                     AvaliacaoUnidade2()*p2 +
                     projetofinal*p3 )/(p1+p2+p3);
   }
 
   void MostrarNotaFinal(){
       cout << notafinal << endl;
   }
 
   void EntradaNotas(){
       cout << "Digite o nome do aluno:" << endl;
       cin >> nomeDoAluno;
       cout << "Guia Lab 1 Unidade 1" << endl;
       cin >> u1_guialab1;
       cout << "Guia Lab 2 Unidade 1" << endl;
       cin >> u1_guialab2;
       cout << "Guia Lab 1 Unidade 2" << endl;
       cin >> u2_guialab1;
       cout << "Guia Lab 2 Unidade 2" << endl;
       cin >> u2_guialab2;
       cout << "Projeto Final" << endl;
       cin >> projetofinal;
   }
 
   
 
 
};
 
class Turma {
   string nomeDaTurma;
   int codigoDaTurma;
   Avaliacao avaliaAluno1,
             avaliaAluno2,
             avaliaAluno3;
   double mediaTurma;
   double maior;
   double menor;
   string menorNome,
          maiorNome;   
 
   public:
       Turma(){

       }
       void setNomeTurma(string nome){
           nomeDaTurma = nome;
        };
       void setCodigoTurma(int codigo){
           codigoDaTurma = codigo;
        };
       void registraEntradaNotasDosAlunos(){
            avaliaAluno1.EntradaNotas();
            avaliaAluno2.EntradaNotas();
            avaliaAluno3.EntradaNotas();
        };
       void calculaMediaDaTurma(){
            avaliaAluno1.NotaFinal();
            avaliaAluno2.NotaFinal();
            avaliaAluno3.NotaFinal();
            mediaTurma = (avaliaAluno1.getNotaFinal() + avaliaAluno2.getNotaFinal() + avaliaAluno3.getNotaFinal()) / 3;
        };
       void calculaNotaMaiorTurma(){
           if(avaliaAluno1.getNotaFinal() > avaliaAluno2.getNotaFinal() && avaliaAluno1.getNotaFinal() > avaliaAluno3.getNotaFinal()){
               maior = avaliaAluno1.getNotaFinal();
               maiorNome = avaliaAluno1.getNomeAluno();
               return;
           }
           if(avaliaAluno2.getNotaFinal() > avaliaAluno1.getNotaFinal() && avaliaAluno2.getNotaFinal() > avaliaAluno3.getNotaFinal()){
               maior = avaliaAluno2.getNotaFinal();
               maiorNome = avaliaAluno2.getNomeAluno();
               return;
           }
           else {
               maior = avaliaAluno3.getNotaFinal();
               maiorNome = avaliaAluno3.getNomeAluno();
           }
        };
       void calculaNotaMenorTurma(){
           if(avaliaAluno1.getNotaFinal() < avaliaAluno2.getNotaFinal() && avaliaAluno1.getNotaFinal() < avaliaAluno3.getNotaFinal()){
               menor = avaliaAluno1.getNotaFinal();
               menorNome = avaliaAluno1.getNomeAluno();
               return;
           }
           if(avaliaAluno2.getNotaFinal() < avaliaAluno1.getNotaFinal() && avaliaAluno2.getNotaFinal() < avaliaAluno3.getNotaFinal()){
               menor = avaliaAluno2.getNotaFinal();
               menorNome = avaliaAluno2.getNomeAluno();
               return;
           }
           else {
               menor = avaliaAluno3.getNotaFinal();
               menorNome = avaliaAluno3.getNomeAluno();
           }
        };
       double getMediaDaTurma(){
           return mediaTurma ;
        };
       double getNotaMaiorTurma(){
           return maior;
        };
       double getNotaMenorTurma(){
           return menor;
        };
        string getNomeMenorTurma(){
            return menorNome;
        }
        string getNomeMaiorTurma(){
            return maiorNome;
        }
};
 
 
int main(int argc, char const *argv[])
{
   Turma turmaPOO;
 
    turmaPOO.setNomeTurma("Turma");
    turmaPOO.setCodigoTurma(01);
    turmaPOO.registraEntradaNotasDosAlunos();
    turmaPOO.calculaMediaDaTurma();
    turmaPOO.calculaNotaMaiorTurma();
    turmaPOO.calculaNotaMenorTurma();
    cout << "Media da turma eh: " << turmaPOO.getMediaDaTurma() << endl;
    cout << "Aluno com manior nota eh: "<< turmaPOO.getNomeMaiorTurma() << endl;
    cout << "Maior nota da turma eh: "<< turmaPOO.getNotaMaiorTurma() << endl;
    cout << "Aluno com menor nota da turma: "<< turmaPOO.getNomeMenorTurma() << endl;
    cout << "Menor nota do turma eh: "<< turmaPOO.getNotaMenorTurma() << endl;
 
   return 0;
}