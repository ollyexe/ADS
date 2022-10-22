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
    
    public void addAdiacente(T verticAdiEtichetta,S arcEtichetta ){
            //crea un arco e aggiunge l elemento alla hash table delle adiacenze
            Arco<S> arco = new Arco<>(arcEtichetta);
            adiacenti.putIfAbsent(verticAdiEtichetta, arco);
        }


    public void remuveAdicente(T verticAdiEtichetta){
        adiacenti.remove(verticAdiEtichetta);
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

     


    //link - altri nodi vicini  //list 
    //arco il collegamento con un peso

    

}