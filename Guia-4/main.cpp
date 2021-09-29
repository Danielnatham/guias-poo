#include <stdlib.h>
#include <iostream>

using namespace std;

class Lampada{
    private:
        int voltagem;
        bool estado;
        bool queimada;
        string tipo;
        int potencia;
    public:

    void ligar_desligar(){
        estado = !estado;
    }

    void queimou(){
        queimada = !queimada;
    }

    bool get_estado(){
        return estado;
    }

    int get_voltagem(){
        return voltagem;
    }

    bool get_queimada(){
        return queimada;
    }

    void set_voltagem(int volt){
        if(volt == 110 || volt == 220){
            voltagem = voltagem;
        }      
    }

    void imprime(){
        cout << "VOLTAGEM: " << voltagem << endl;
        if(estado){
            cout << "Estado: Ligada" << endl;
        } else {
            cout << "Estado: Desligada" << endl;
        }
        if(queimada){
            cout <<  "Esta lampada esta queimada" << endl;
        }
    }

    Lampada(int volt, int pot, string tip){

        voltagem = volt;
        potencia = pot;
        tipo = tip;
        estado = false;
        queimada = false;

         if (volt == 110 || volt == 220){
             voltagem = volt;
         }
         else{
             voltagem = 110;
         }
     }
};

class Comodo{
    private: string nome;
             Lampada &lampada;
             int redeEletrica;
    public:
        Comodo(string nom, Lampada lamp): lampada(lamp){
            nome = nom;
            lampada = lamp;
        };

        string get_nome() {
            return nome;
        }

        Lampada get_lampada(){
            return lampada;
        }

        void ligarDesligarLampada(){

            cout << "LIGANDO A LAMPADA DA " << Comodo::get_nome() << endl;

            if(lampada.get_queimada()){
                cout << "A lampada esta queimada" << endl;
                return;
            }

            lampada.ligar_desligar();

            if(lampada.get_estado()){
                cout <<  "A lampada agora esta ligada" << endl;
            } else {
                cout <<  "A lampada agora esta desligada" << endl;
            }
        }

        void instalar(){

            int rede;

            cout<<"\n=======INSTALANDO LAMPADA EM "<< Comodo::get_nome() << "=====" <<endl;
            cout << "\nQual a voltagem da rede eletrica?" << endl;
            cin >> rede;
            cout << "VOLTAGEM DA LAMPADA: "<< lampada.get_voltagem() << endl;
            redeEletrica = rede;

            cout << "REDE ELETRICA: "<< redeEletrica << endl;

            if (rede > Comodo::get_lampada().get_voltagem()){
                lampada.queimou();
                cout << "Voce queimou a lampada" << endl;
            }
            cout<<"=================================\n"<<endl;        
        }
       
};

int main(int argc, char const *argv[]){

    int voltagem, potencia;
    string tipo; 

    cout<<"=======COMPRANDO LAMPADA========="<<endl;
    cout<<"Qual o tipo da lamapda"<<endl;
    cout<<"Incadescente"<<endl;
    cout<<"Fluorescente"<<endl;
    cin>>tipo;
    cout<<"Qual a Voltagem (220 ou 110) da lampada"<<endl;
    cin>>voltagem;
    cout<<"Qual a Potencia da lampada"<<endl;
    cin>>potencia;
    cout<<"=================================\n"<<endl;    

    Lampada lampada(voltagem,potencia,tipo);

    lampada.imprime();

    Comodo Sala("SALA", lampada),Cozinha("COZINHA",lampada),Escritorio("ESCRITORIO", lampada);
    
    Sala.instalar();
    Cozinha.instalar();
    Escritorio.instalar();
    
    Sala.ligarDesligarLampada();
    Cozinha.ligarDesligarLampada();
    Escritorio.ligarDesligarLampada();
       

    return 0;
}