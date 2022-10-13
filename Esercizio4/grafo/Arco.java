public class Arco<T>{
    private T etichetta = null;

    private double peso= 0;

    public Arco(T etichetta){ this.etichetta = etichetta;}

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public T getEtichetta() {
        return etichetta;
    }

    public String toString() {
        return "" + this.peso;
    }

}