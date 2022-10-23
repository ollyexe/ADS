import java.util.Hashtable;
import java.util.HashSet;
import java.util.Set;

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

    public int getNrVertici(){  // OK
        return vertici.size();
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
    
    // RECUPERO VERTICI ADIACENTI
    public Set<Vertice<T, S>> getVerticiAdiacenti(T vlabel){   // OK Con riserva O(1)
        Vertice<T,S> v = getVertice(vlabel);
        if(!vertici.containsKey(vlabel))
            return null;
        
        Set<T> adiacentlabel = v.getVerticiAdiacenti();
        Set<Vertice<T, S>> adiacentVert = new HashSet<>();

        for(T adLabel : adiacentlabel)
            adiacentVert.add(getVertice(adLabel));

        return adiacentVert;
    }

    public Set<Vertice<T, S>> getVerticiGrafo(){   //OK
        Set<Vertice<T, S>> allv = new HashSet<>();
        for(T l : getVerticiEtichette())
            allv.add(getVertice(l));
        return allv;
    }

    public Set<T> getVerticiEtichette(){    // OK solo etichette 
        Set<T> allv = new HashSet<>();      
        for(T l : vertici.keySet())
            allv.add(l);
        return allv;
    }

    public void verticeDelete(T vlabel){  // OK
        
        Vertice<T,S> ris = vertici.remove(vlabel);

        if (ris != null) {
            Set<T> verticesLabel = getVerticiEtichette();

            for (T vLabel : verticesLabel) {
                Vertice<T, S> curr = this.vertici.get(vLabel);
                if (curr.hasAdiacente(vlabel)) {
                    curr.removeArco(vlabel);
                }
            }
        }
    }

    public void addArco(T verticeFrom, T verticeTo, S arcEtichetta){    // OK
        Vertice<T, S> fVertice = getVertice(verticeFrom);
        fVertice.addAdiacente(verticeTo, arcEtichetta);
        if(!isDiretto()){
           Vertice<T, S> sVertice = getVertice(verticeTo); 
           sVertice.addAdiacente(verticeFrom, arcEtichetta);
        }
    }

    
    public boolean arcoExist(S etichetta){// ????????????????????????
        return getArchi().contains(etichetta);
    }
    
    public void arcoDelete(T vlabelA, T vlabelB){
        
        Vertice<T,S> primoVertice = getVertice(vlabelA);
        Arco<S> arcoRimosso = primoVertice.removeArco(vlabelB);
        if(!isDiretto()){
            Vertice<T, S> secondoVertice = getVertice(vlabelB);
            Arco<S> arco2Rimosso = secondoVertice.removeArco(vlabelA);
            
        }
    }




    public int getNrArchi(){    // OK
        int sum = 0;
        for(T a : vertici.keySet()){
            sum += vertici.get(a).getNrArchi();
        }
        if(isDiretto())
            return sum;
        else
            return sum/2;
    }

    public Set<Arco<S>> getArchi(){//OK
        
        Set<Arco<S>> archi = new HashSet<>();

        for(T etichetta : this.vertici.keySet()){
            for (Arco<S> b : getVertice(etichetta).getArchi()) {
                archi.add(b);
            }
        }
        return archi;
    }

    public Arco<S> getArco(T fvlabel, T svlabel){   // OK
        Vertice<T, S> v = getVertice(fvlabel); 
        return v.getArco(svlabel);
    }
    

}
