package minHeap;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Hashtable;

public class MinimunHeap <T>{

    private ArrayList <T> array = null;
    private Comparator <T> comparator = null;
    private Hashtable <T, Integer> table = null;        // use hash table so access to elements is faster 
                                                // T element's type - Integer index

    public MinimunHeap (Comparator <T> comparator) throws MinimusHeapException{ // create minHeap.MinimunHeap O(1)
        if(comparator == null) throw new MinimusHeapException("comparator null");
        this.comparator = comparator;
        this.array = new ArrayList<>();
        this.table = new Hashtable<>();
    }

    public void HeapInsert(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");

        if(this.table.putIfAbsent(x, this.table.size()) != null)        // associa key a x e inserisce x in table.size position (se non esiste return null)
            throw new MinimusHeapException("element already present");

        this.array.add(x);

        while((this.comparator).compare(x , this.HeapParent(x)) < 0){
            swap(x, HeapParent(x));
        }
        
    }

    // ok!

    public int HeapSize(){ // return Heap size O(1)
        return this.array.size();
    }

    // ok!

    public T HeapParent(T x) throws MinimusHeapException{  
        if(x == null) throw new MinimusHeapException("x is null");
        if(!this.table.containsKey(x)) // method is used to check if a key(x) is present in the Hashtable.
            return x;
        int i = this.table.get(x);
        if(i == 0) {
            return x;
        }
        if(i % 2 == 0){
            return this.array.get((i/2)-1);
        }
        return this.array.get(i / 2);
    }

    // ok!

    public T HeapLeftSon(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");
        if(!this.table.containsKey(x))  
            return x;
        int i = this.table.get(x);
        if((2*i)+1 < this.array.size()){
            return this.array.get((2*i) + 1);
        }else{
            return x;
        }
    }

    // ok!

    public T HeapRightSon(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");
        if(!this.table.containsKey(x))
            return x;
        int i = this.table.get(x);  // get x position
        if((2*i)+2 < this.array.size()){
            return this.array.get((2*i)+2);
        }else{
            return x;
        }
    }

    public T HeapRemove() throws MinimusHeapException{
        if(this.array.isEmpty()) throw new MinimusHeapException("heap is empty");

        swap(this.array.get(0), this.array.get(this.array.size() - 1));
        
        this.table.remove(this.array.size()-1);
        T a = this.array.remove(this.array.size()-1);

        if(this.array.size() > 1)
            heapfy(this.array.get(0));

        return a;
    }



    public void HeapElDecrease(T x, T newx) throws MinimusHeapException {
        if (x == null) throw new MinimusHeapException("element is null");
        if (newx == null) throw new MinimusHeapException("amount is null");
        if (!this.table.containsKey(x)) throw new MinimusHeapException("x isn't in the heap");

        /*inizio sostituzione */  
        Integer position  = this.table.get(x);
        System.out.println(position);
        this.table.remove(x);
        this.table.put(newx, position);
        this.array.set(position, newx);
        /*fine sostituzione */  

        /*sposta l elemento riordinando tutto lo heap */
        while ((this.comparator).compare(newx, HeapParent(newx)) < 0)
            swap(newx, HeapParent(newx));
        

        if ((this.comparator).compare(newx, HeapParent(newx)) >= 0)
            heapfy(newx);
    }

   

    private void heapfy(T x) throws MinimusHeapException{
        if(x == null) throw new MinimusHeapException("x is null");
        T i = min(x, min(HeapLeftSon(x), HeapRightSon(x)));
        if((this.comparator).compare(x, i) != 0){
            swap(x, i);
            heapfy(x);
        }
    }

    private T min(T e1, T e2) throws MinimusHeapException{
        if(e1 == null) throw new MinimusHeapException("e1 is null");
        if(e2 == null) throw new MinimusHeapException("e2 is null");

        return (((this.comparator).compare(e1, e2) < 0) ? e1 : e2);
    }

    private void swap(T e1, T e2) throws MinimusHeapException{
        if(e1 == null) throw new MinimusHeapException("e1 is null");
        if(e2 == null) throw new MinimusHeapException("e2 is null");

        int int_e1 = this.table.get(e1);
        int int_e2 = this.table.get(e2);

        T tmp = this.array.get(int_e1); // e1 pos
        
        this.array.set(int_e1, e2);     // insert e2 element in e1 pos
        this.table.put(e2, int_e1);     // put(key, value)

        this.array.set(int_e2, tmp);
        this.table.put(tmp, int_e2);
    }

    public String toString(){
        return this.array.toString();
    }

    public Object[] toArray(){
        return array.toArray();
    }
    
}