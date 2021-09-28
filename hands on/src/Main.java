
public class Main {
    public static void main(String[] args) {

        Emprestimo emprestimo1 = new Emprestimo(200, 5, 0.01);
        Emprestimo emprestimo2 = new Emprestimo(500, 7, 0.02);

        for (int i = 0; i < emprestimo2.parcelas.size(); i++){
            if(i < emprestimo1.parcelas.size()){
            System.out.println("Emprestimo 1: Parcela " + (i + 1) + " eh " + emprestimo1.parcelas.get(i));
            }
            if(i < emprestimo2.parcelas.size()){
                System.out.println("Emprestimo 2: Parcela " + (i + 1) + " eh " + emprestimo2.parcelas.get(i));
            }

        }

    }
}