#include <stdlib.h>
#include <iostream>

using namespace std;

class Lamp{
    private:
        int voltage;
        bool on;
        bool burned;
        string name;
        int power;
    public:

    void on_Off(){
        if (on){
            on = false;
        } else {
            on = true;
        }
    }

    void burned_out(){
        burned = !burned;
    }

    bool get_on(){
        return on;
    }

    int get_voltage(){
        return voltage;
    }

    bool get_burned(){
        return burned;
    }

    void set_voltage(int volt){
        if(volt == 110 || volt == 220){
            voltage = voltage;
        }      
    }

    void show(){
        cout << "voltage: " << voltage << endl;
        if(on == true){
            cout << "on: Ligada" << endl;
        } else {
            cout << "on: Desligada" << endl;
        }
        if(burned == true){
            cout <<  "Esta Lamp esta queimada" << endl;
        }
    }

    Lamp(int volt, int pot, string tip){

        voltage = volt;
        power = pot;
        name = tip;
        on = false;
        burned = false;

         if (volt == 110 || volt == 220){
             voltage = volt;
         }
         else{
             voltage = 110;
         }
     }
};

class Room{
    private: string nome;
             Lamp lamp;
             int redeEletrica;
    public:
        Room(string nom, Lamp lamp_obj): lamp(lamp_obj){
            nome = nom;
            lamp = lamp_obj;
        };

        string get_nome() {
            return nome;
        }

        Lamp get_Lamp(){
            return lamp;
        }

        void ligarDesligarLamp(){

            cout << "LIGANDO A LAMPADA DA " << Room::get_nome() << endl;

            lamp.on_Off();

            if(Room::get_Lamp().get_burned() == true){
                cout << "A lampada esta queimada" << endl;
                return;
            }
            if(Room::get_Lamp().get_on() == false){
                cout <<  "A Lamp agora esta desligada" << endl;
            } else {
                cout <<  "A Lamp agora esta ligada" << endl;
            }
        }

        void install(){

            int rede;

            cout<<"\n=======COLOCANDO A LAMPADA EM "<< Room::get_nome() << "=====" <<endl;
            cout << "\nQual a voltage da rede eletrica?" << endl;
            cin >> rede;
            cout << "voltage DA LAMPADA: "<< lamp.get_voltage() << endl;
            redeEletrica = rede;

            cout << "REDE ELETRICA: "<< redeEletrica << endl;

            if (rede > Room::get_Lamp().get_voltage()){
                lamp.burned_out();
                cout << "Voce queimou a lampada" << endl;
            }
            cout<<"=================================\n"<<endl;        
        }
       
};

int main(int argc, char const *argv[]){

    int voltage, power;
    string name; 

    cout<<"=======COMPRANDO LAMPADA========="<<endl;
    cout<<"Qual o name da lampada"<<endl;
    cout<<"Incadescente"<<endl;
    cout<<"Fluorescente"<<endl;
    cin>>name;
    cout<<"Qual a voltage (220 ou 110) da Lamp"<<endl;
    cin>>voltage;
    cout<<"Qual a power da Lamp"<<endl;
    cin>>power;
    cout<<"=================================\n"<<endl;    

    Lamp Lamp(voltage,power,name);

    Lamp.show();

    Room Sala("SALA", Lamp),Cozinha("COZINHA",Lamp),Escritorio("ESCRITORIO", Lamp);
    
    Sala.install();
    Cozinha.install();
    Escritorio.install();
    
    Sala.ligarDesligarLamp();
    Cozinha.ligarDesligarLamp();
    Escritorio.ligarDesligarLamp();
    Sala.ligarDesligarLamp();
       

    return 0;
}