public class Arco<S>{
    private S etichetta = null;

    private double peso= 0;

    public Arco(S etichetta){ this.etichetta = etichetta;}

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public S getEtichetta() {
        return etichetta;
    }

    public String toString() {
        return "" + this.peso;
    }

}