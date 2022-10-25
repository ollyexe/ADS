package minHeap;

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

    @Before
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
    @Test
    public void testHeapSizeEmpty(){
        assertEquals(0, heapMin.HeapSize());
    }
    @Test
    public void testAddnullElement() throws MinimusHeapException{
        heapMin.HeapInsert(null);
    }
    @Test
    public void testSizeOneEl() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        assertEquals(1, heapMin.HeapSize());
    }

    @Test
    public void testAddOneEl() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        Object[] expObjects = {1};
        Object[] aObjects = heapMin.toArray();
        assertArrayEquals(expObjects, aObjects);
    }

    @Test
    public void testAddSevenEl() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expObjects = {1, 0, 2, 7, 6, 4, 3};
        Object[] aObjects = heapMin.toArray();
        assertArrayEquals(expObjects, aObjects);
    }

    @Test
    public void testParentOne() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expObjects = {1, 0, 2, 7, 6, 4, 3};
        assertEquals(expObjects[1], heapMin.HeapParent(i1));
    }

    @Test
    public void testLeftSonTwo() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expObjects = {1, 0, 2, 7, 6, 4, 3};
        assertEquals(expObjects[5], heapMin.HeapLeftSon(i3));
    }

    @Test
    public void testRightSonTwo() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        Object[] expObjects = {1, 0, 2, 7, 6, 4, 3};
        assertEquals(expObjects[6], heapMin.HeapRightSon(i3));
    }

    @Test
    public void testAddOneElRemoveRoot() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapExtract();
        Object[] expObjects = {};
        Object[] aObjects = heapMin.toArray();
        assertArrayEquals(expObjects, aObjects);
    }

    @Test
    public void testAddSevenElRemoveRoot() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapInsert(i5);
        heapMin.HeapInsert(i6);
        heapMin.HeapInsert(i7);
        heapMin.HeapExtract();
        Object[] expObjects = {1, 2, 7, 6, 4, 3};
        Object[] aObjects = heapMin.toArray();
        assertArrayEquals(expObjects, aObjects);
    }

    @Test
    public void testAddFourElDecreaseSevenToThree() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapElDecrease(i4, 3);
        Object[] exObjects = {1, 0, 2, 3};
        Object[] aObjects = heapMin.toArray();
        assertArrayEquals(exObjects, aObjects);
    }

    @Test(expected = MinimusHeapException.class)
    public void testAddFourElDecreaseTwoToNull() throws MinimusHeapException{
        heapMin.HeapInsert(i1);
        heapMin.HeapInsert(i2);
        heapMin.HeapInsert(i3);
        heapMin.HeapInsert(i4);
        heapMin.HeapElDecrease(i3, null);
    }
}