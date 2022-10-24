public class Main {
    public static void main(String[] args) {
         Grafo<Character, Integer> grafo = null;
        int i1 , i2 , i3 , i4;
        char c1, c2, c3,c4;
        
        i1 = 5;
        i2 = 14;
        i3 = 7;
        i4 = 0;
        c1 = 'A';
        c2 = 'B';
        c3 = 'C';
        c4  ='D';

        grafo= new Grafo<>(GrafoTipo.DIREZIONATO);


        grafo.addVertice(c1);
        grafo.addVertice(c2);
        grafo.addVertice(c3);
        grafo.addVertice(c4);
        grafo.addArco(c1,c2,i1);
        grafo.addArco(c1,c3,i2);
        grafo.addArco(c1,c4,i3);
    /*    
    for (TypeKey name: example.keySet()) {
        String key = name.toString();
        String value = example.get(name).toString();
        System.out.println(key + " " + value);
    }*/
        //System.out.println(grafo.getNrVertici());
        //System.out.println(grafo.getVertice(i1).getEtichetta());
        //System.out.println(grafo.arcoExist(i1,i3));
        //System.out.println("E' diretto : "+grafo.isDiretto());
        //System.out.println("Nodo esiste : "+grafo.verticeExist(i1));
        //grafo.verticeDelete(i1);
        //System.out.println("Nodo esiste : "+grafo.verticeExist(i1));
        //grafo.arcoDelete(i1,i2);
        //System.out.println(grafo.arcoExist(i1,i2));
        //System.out.println(grafo.getNrArchi());
        //System.out.println(grafo.getNrVertici());
        //System.out.println(grafo.getArchi());
        //System.out.println(grafo.getArchi());
        System.out.println(grafo.getArcoFromVertici(c1, c2));

    }
}
