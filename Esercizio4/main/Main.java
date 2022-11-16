import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Iterator;
import java.util.Set;

import Dijkstra.dijkstra;
import grafo.Arco;
import grafo.Grafo;
//import Grafo.GrafoException;
import grafo.GrafoTipo;
import grafo.Vertice;

public class Main {

    private static void loadGrafo(String path, Grafo<String, String> grafo) throws IOException{
        Path inputPath = Paths.get(path);
        System.out.println(inputPath.toAbsolutePath());

        System.out.println("Loading Data in Graph...");

        // ADD ALL VERTICI
        try(BufferedReader fileInputReader = Files.newBufferedReader(inputPath)){
            String line = null;
            while((line = fileInputReader.readLine()) != null){ // until the end file
                String[] lineElements = line.split(",");    // divide gli elementi per "," e li inserisce in un array
                grafo.addVertice(lineElements[0]);
                grafo.addVertice(lineElements[1]);
            }
        }catch(Exception e){
            e.printStackTrace(System.err);
        }

        try(BufferedReader fileInputReader = Files.newBufferedReader(inputPath)){
            String line = null;
            while((line = fileInputReader.readLine()) != null){
                String[] lineElements = line.split(",");
                try {
                    grafo.addArco(lineElements[0], lineElements[1], lineElements[0] + "-" + lineElements[1]);
                    grafo.addArco(lineElements[1], lineElements[0], lineElements[1] + "-" + lineElements[0]);
                    grafo.getArco(lineElements[0], lineElements[1]).setPeso(Double.parseDouble(lineElements[2]));
                    grafo.getArco(lineElements[1], lineElements[0]).setPeso(Double.parseDouble(lineElements[2]));

                } catch(Exception e){
                    e.printStackTrace(System.err);
                }
            }
        }
        System.out.println("Data loaded!");
    }

 

    public static void trovaDistanza(Set<Vertice<String,String>> risultato,
                                     String srcEtichetta,String destEtichetta){
    Iterator<Vertice<String,String>> iter = risultato.iterator();
    while (iter.hasNext()){
        Vertice<String,String> v = iter.next();
        if(v.getEtichetta().equals(destEtichetta)){
            int citta = path(v);
            System.out.println("Il numero di citta attraversate: "+ citta);
            System.out.println("La distanza tra "+srcEtichetta +" e "+ destEtichetta + " è "+ (v.getDistance()/1000)+ "km");
        }
    }


    }

    public static int path_aux(Vertice<String, String> v){
        if(v.getP() == null){
            return 1;
        }else {
            int c = path_aux(v.getP());
            System.out.println( v.getEtichetta());
            return c + 1;
        }
    }

    public static int path(Vertice<String, String> v){
        int c = path_aux(v.getP());
        System.out.println(v.getEtichetta());
        return c + 1;
    }

    public static void main(String [] args){
        Grafo<String, String> grafo = new Grafo<>();

        String csv = args[0];
        try{
            loadGrafo(csv, grafo);
            String startLabel = "torino";
            String endLabel = "catania";
            Set<Vertice<String, String>> res = dijkstra.dijkstra(grafo, startLabel);
            trovaDistanza(res, startLabel, endLabel);
        }catch(Exception e){
            e.printStackTrace(System.err);
        }
    }
}