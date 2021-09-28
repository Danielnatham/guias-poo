import java.util.ArrayList;

public class Emprestimo {

    int saldo;
    int numParcelas;
    double juros;
    ArrayList<Double> parcelas = new ArrayList<Double>();


    public Emprestimo(int saldo, int numParcelas, double juros) {
        this.saldo = saldo;
        this.numParcelas = numParcelas;
        this.juros = juros + 1;
        this.parcelas.add(this.saldo * 1.0);

        Double inserir = this.saldo * 1.0;

        for (int i = 1; i < this.numParcelas; i++){
            inserir = inserir * this.juros;
            parcelas.add(inserir);
        }
    }

}
