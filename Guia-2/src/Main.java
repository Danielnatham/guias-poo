class Aluno {
    private Integer nota1;
    private Integer nota2;
    private Integer projeto;

    public Aluno(int guia11, int guia12,int guia21, int guia22, int projeto) {
        this.nota1 = (guia11 + guia12) / 2;
        this.nota2 = (guia21 + guia21) / 2;
        this.projeto = projeto;
    }
    public Double getNotaFinal(){
        Double notaFinal = this.nota1 * 0.2 + this.nota2 * 0.2 + this.projeto * 0.6;
        return notaFinal;
    }
}

public class Main {
    public static void main(String[] args) {
        Aluno aluno = new Aluno(10,10,10,10,0);

        System.out.println("Nota Final = " + aluno.getNotaFinal());
    }
}
