package grafo;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Enumeration;
import java.util.HashSet;
import java.util.Set;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import org.junit.Before;
import org.junit.Test;

public class GrafoTest {
    private Grafo<Integer, Character> grafo = null;
    private int v1, v2, v3;
    private char a1, a2, a3;

    @Before
    public void grafoCreate(){
        grafo = new Grafo<>(GrafoTipo.DIREZIONATO);
        v1 = 6;
        v2 = 14;
        v3 = -2;
        a1 = 'A';
        a2 = 'B';
        a3 = 'C';
    }

    @Test
    public void testAddOneVertice(){
        assertTrue(grafo.addVertice(v1));
    }

    @Test
    public void testAddTwoVertici(){
        boolean res = grafo.addVertice(v1) && grafo.addVertice(v2);
        assertTrue(res);
    }

    @Test
    public void testIfDirected(){
        assertTrue(grafo.isDiretto());
    }

    @Test
    public void testGetNrVerticiEmpty(){
        assertEquals(grafo.getNrVertici(), 0);
    }

    @Test
    public void testgetNrVerticiEmpty(){
        assertEquals(grafo.getNrVertici(), 0);
    }

    @Test
    public void testgetNrVerticiOne(){
        grafo.addVertice(v1);
        assertEquals(grafo.getNrVertici(), 1);
    }

    @Test
    public void testgetNrVerticiTwo(){
        grafo.addVertice(v1);
        grafo.addVertice(v2);
        assertEquals(grafo.getNrVertici(), 2);
    }

    @Test
    public void testContainsVertice(){
        grafo.addVertice(v1);
        grafo.addVertice(v2);
        assertTrue(grafo.verticeExist(v2));
    }

    @Test
    public void testGetOneVerticeLabel(){
        grafo.addVertice(v1);
        Set<Integer> es = new HashSet<>();
        es.add(v1);
        assertThat(grafo.getVerticiEtichette(), is(es));
    }

    @Test
    public void testGetTwoVerticeLabel(){
        grafo.addVertice(v1);
        grafo.addVertice(v2);
        Set<Integer> es = new HashSet<>();
        es.add(v1);
        es.add(v2);
        assertThat(grafo.getVerticiEtichette(), is(es));
    }

    @Test
    public void testRemoveVertice(){
        grafo.addVertice(v1);
        grafo.verticeDelete(v1);
        assertEquals(grafo.getNrVertici(), 0);
    }

    @Test
    public void testAddOneArco(){
        grafo.addVertice(v1);
        grafo.addVertice(v2);
        grafo.addArco(v1, v2, a1);
        assertEquals(grafo.getNrArchi(), 1);
    }

    @Test
    public void testAddThreeVerticiTwoArchi(){
        grafo.addVertice(v1);
        grafo.addVertice(v2);
        grafo.addVertice(v3);
        grafo.addArco(v1, v2, a1);
        grafo.addArco(v1, v3, a2);        
        assertEquals(grafo.getNrArchi(), 2);
    }

    @Test 
    public void testGetArco(){
        grafo.addVertice(v1);
        grafo.addVertice(v2);
        grafo.addArco(v1, v2, a1);
        assertThat(grafo.getArco(v1, v2).getEtichetta(), is('A'));
    }
}
