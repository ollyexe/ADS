import java.util.Enumeration;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Set;

//arco<t>
public class Vertice <T,S>{

    private T etichetta = null;
    private Hashtable<T,Arco<S>> adiacenti = null;


    public T getEtichetta(){
        return this.etichetta;
    }

    public Vertice(T etichetta){   // CREAZIONE VERTICE O(1)
        this.etichetta = etichetta;
        this.adiacenti = new Hashtable<>();
    }
    
    public void addAdiacente(T verticAdiEtichetta,S arcEtichetta ){     // OK
            //crea un arco e aggiunge l elemento alla hash table delle adiacenze
            Arco<S> arco = new Arco<>(arcEtichetta);
            adiacenti.putIfAbsent(verticAdiEtichetta, arco);
        }

    //ritorna l arco che collega un altro nodo in base al etichetta del nodo presa in ingresso
    public Arco<S> getArco(T etichetta){
        return adiacenti.get(etichetta);
    }

    //ritorna il peso di un arco in base alla sua etichetta
    public double getPeso(T etichetta){
        Arco<S> arco = getArco(etichetta);
        return arco.getPeso();
    }

    public void clearAdiacenti() {
        adiacenti.clear();
    }

    public int getNrArchi(){
        return adiacenti.size();
    }

    public Set<Arco<S>> getArchi(){

        Set<Arco<S>> tot = new HashSet<>();
        Enumeration <Arco<S>> archi = adiacenti.elements();

        while ( archi.hasMoreElements()){
            Arco<S> act = archi.nextElement();
            tot.add(act);
        }

        return tot;
    }


    public Set<T>getVerticiAdiacenti(){
        Set<T> adi  = new HashSet<>();
        //O(1) adi = adiacenti.keySet();
        for(T a : adiacenti.keySet())
            adi.add(a);
        return adi;
    }

    public Arco<S> removeArco(T etichetta){
        return adiacenti.remove(etichetta);
    }

    public boolean hasAdiacente(T vLabel){
        return adiacenti.containsKey(vLabel);
    }

    @Override
    public String toString(  ){
        return "" + this.etichetta.toString();
    }

}