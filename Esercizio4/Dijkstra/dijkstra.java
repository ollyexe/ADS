package Dijkstra;

import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import grafo.Grafo;
import grafo.Vertice;
import grafo.Arco;
import minHeap.MinimunHeap;
import minHeap.MinimusHeapException;


public class dijkstra{
    
    public static <T, S> Set<Vertice<T, S>> dijkstra(Grafo<T, S> grafo, T startLabel) throws MinimusHeapException{
        GenericComparator<T, S> comparator = new GenericComparator<>();
        MinimunHeap<Vertice<T, S>> minheap = new MinimunHeap<>(comparator);
        Vertice<T, S> start = grafo.getVertice(startLabel);
        Set<Vertice<T, S>> visited = new HashSet<>();

        init(grafo, start, minheap);
        visited.add(start);

        while(minheap.HeapSize() != 0){
            Vertice<T, S> next = minheap.HeapExtract();; // extract vertex with min distance
            visited.add(next);      // add next at visited vertex
            
            for(Vertice<T, S> vis : grafo.getVerticiAdiacenti(next.getEtichetta()))  // for each vertex v which is agjacent of next
                relax(next, vis, minheap);
        }
        return visited;
    }

        private static <T, S> void relax(Vertice<T, S> u, Vertice<T, S> v, MinimunHeap<Vertice<T, S>> Q) throws MinimusHeapException{
            Double alt = u.getDistance() + u.getPeso(v.getEtichetta());
            if(v.getDistance() > alt && u.getDistance() != Double.POSITIVE_INFINITY){
                Vertice<T, S> tmp = v;

                v.setDistance(alt);
                v.setP(u);
                Q.HeapElDecrease(tmp, v);
            }
        }



    //inizializza le distanze dal src a infinito e inizilizza la distanza del nodo di inizio a 0
    public static <T,S> void init(Grafo<T,S> grafo , Vertice<T,S> src, MinimunHeap<Vertice<T,S>> Q) throws MinimusHeapException{
        for (Vertice<T,S> v: grafo.getVerticiGrafo()) {
            if (!v.equals(src)) {
                v.setDistance(Double.POSITIVE_INFINITY);
                v.setP(null);
            }
            Q.HeapInsert(v);
        }
        src.setDistance(0);
    }

}


class GenericComparator<T, S> implements Comparator<Vertice<T, S>> {
    @Override
    public int compare(Vertice<T, S> o1, Vertice<T, S> o2) {
        if (o1.getDistance() > o2.getDistance()) {
            return 1;
        } else if (o1.getDistance() < o2.getDistance()) {
            return -1;
        } else {
            return 0;
        }
    }
}
