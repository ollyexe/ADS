public class Main {
    public static void main(String[] args) {
         Grafo<Integer, Character> grafo = null;
        int i1 , i2 , i3;
        char c1, c2, c3;
        
        i1 = 5;
        i2 = 14;
        i3 = -7;
        c1 = 'A';
        c2 = 'B';
        c3 = 'C';

        grafo= new Grafo<>(GrafoTipo.DIREZIONATO);

        grafo.addVertice(i1);
        grafo.addVertice(i2);
        grafo.addVertice(i3);
        grafo.addArco(i1,i2,c1);
        grafo.addArco(i2,i3,c2);
    /*    
    for (TypeKey name: example.keySet()) {
        String key = name.toString();
        String value = example.get(name).toString();
        System.out.println(key + " " + value);
    }*/
        System.out.println(grafo.getNrVertici());
        System.out.println(grafo.getNrArchi());
        System.out.println(grafo.arcoExist(c2));

    }
}
