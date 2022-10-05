//package library;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Hashtable;

public class MinimunHeap <T>{

    private ArrayList <T> array = null;
    private Comparator <T> comparator = null;
    private Hashtable <T, Integer> table = null;        // use hash table so access to elements is faster 
                                                // T element's type - Integer index

    public MinimunHeap (Comparator <T> comparator) throws MinimusHeapException{ // create MinimunHeap O(1)
        if(comparator == null) throw new MinimusHeapException("comparator null");
        this.comparator = comparator;
        this.array = new ArrayList<>();
        this.table = new Hashtable<>();
    }

    public void HeapInsert(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");
    }

    // ok!

    public int HeapSize(){ // return Heap size O(1)
        return this.array.size();
    }

    // ok!

    public T HeapParent(T x) throws MinimusHeapException{  
        if(x == null) throw new MinimusHeapException("x is null");
        if(!this.table.containsKey(x)) // method is used to check if a key is present in the Hashtable.
            return x;
        int i = this.table.get(x);
        if(i == 0){
            return x;
        }else{
            return this.array.get(i/2);
        }  
    }

    // ok!

    public T HeapLeftSon(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");
        if(!this.table.containsKey(x))
            return x;
        int i = this.table.get(x);
        if(2*i <= this.array.size()){
            return this.array.get(2*i);
        }else{
            return this.array.get(i);
        }
    }

    // ok!

    public T HeapRightSon(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");
        if(!this.table.containsKey(x))
            return x;
        int i = this.table.get(x);  // get x position
        if((2*i)+1 <= this.array.size()){
            return this.array.get((2*i)+1);
        }else{
            return this.array.get(i);
        }
    }

    
}