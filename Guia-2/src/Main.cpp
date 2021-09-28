#include <iostream>
using namespace std;

class Aluno {
    double nota1, nota2, projeto;
  
    public:
        void setNotas(double,double,double,double, double);
        double getNotaFinal(){
            return (nota1 * 0.2) + (nota2 * 0.2) + (projeto * 0.6);
        } 

};

void Aluno::setNotas (double n11, double n12, double n21, double n22, double np) {
  nota1 = (n11 + n12) / 2;
  nota2 = (n21 + n22) / 2;
  projeto = np;
}


int main(int argc, char const *argv[]){

    Aluno aluno;

    aluno.setNotas(10,10,10,10,0);

    cout << "nota final: " << aluno.getNotaFinal() << "\n";  
    
    return 0;
}
