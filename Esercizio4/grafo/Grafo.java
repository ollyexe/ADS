import java.util.Hashtable;

public class Grafo<T, S>{
    private Hashtable<T, Vertice<T, S>> vertici = null;
    private GrafoTipo type = GrafoTipo.DIREZIONATO;

    public Grafo(){ // CREAZIONE GRAFO VUOTO O(1)
        this.vertici = new Hashtable<>();
        
    }


    public Grafo(GrafoTipo tipo){
        this.type = tipo;
        this.vertici = new Hashtable<>();
    
        
    }

    public boolean isDiretto(){ // VERIFICA SE GRAFO DIRETTO O(1)
        return this.type == GrafoTipo.DIREZIONATO;
    }

    public int getNrVertici(){
        return vertici.size();
    }
    
    public int getNrArchi(){
        int sum = 0;
        for(T a : vertici.keySet()){
            sum += vertici.get(a).getNrArchi();
        }
        if(isDiretto())
            return sum;
        else
            return sum/2;
    }

    public void addVertice(T vetichetta){
        Vertice<T, S> v = new Vertice<>(vetichetta);
        vertici.putIfAbsent(vetichetta,v);
    }

    public boolean verticeExist(T etichetta){
        return vertici.containsKey(etichetta);
    }

    public Vertice<T, S> getVertice(T etichetta){
        return vertici.get(etichetta);
    }
    
    
    


}
