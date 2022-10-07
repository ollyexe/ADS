import java.util.Comparator;
 
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class MinimumHeapTestInt{
    class CompareInteger implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o1.compareTo(o2);
        }
    }

    private Integer i1, i2, i3, i4, i5, i6, i7;
    private MinimunHeap<Integer> heapMin;

    public void createMinimumHeap() throws MinimusHeapException{
        i1 = 1;
        i2 = 0;
        i3 = 2;
        i4 = 7;
        i5 = 6;
        i6 = 4;
        i7 = 3;

        heapMin = new MinimunHeap<>(new CompareInteger());
    }
 
    public void testHeapSizeEmpty(){
        assertEquals(0, heapMin.HeapSize());
    }

    public void testAddnullElement() throws MinimusHeapException{
        heapMin.HeapInsert(null);
    }

    public void testSizeOneEl() throws MinimusHeapException{
        heapMin.add(i1);
        assertEquals(1, heapMin.HeapSize());
    }

    public void testAddOneEl() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        Object[] expected = {1};
        Object[] actual = heapMin.toString();
        assertArrayEquals(expected, actual);
    }

    public void testAddSixEl() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expected = {1, 0, 2, 7, 6, 4, 3};
        Object[] actual = heapMin.toString();
        assertArrayEquals(expected, actual);
    }

    public void testParentOne() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expected = {1, 0, 2, 7, 6, 4, 3};
        assertEquals(expected[0], heapMin.HeapParent(i1));
    }

    public void testLeftFive() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expected = {1, 0, 2, 7, 6, 4, 3};
        assertEquals(expected[0], heapMin.HeapParent(i1));
    }
}