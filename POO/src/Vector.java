import java.lang.reflect.Array;

public class Vector {
    private int size;
    int[] array;

    Vector() {
        this.array = new int[1];
        size = 0;
    }

    Vector(int i) {
        this.array = new int[i];
        size = 0;
    }

    void ensureCapacity(int c)
    {
        if(array.length < c)
        {
            int[] saveArray = this.array;

            int coeff;

            if(2*array.length > c)
                coeff = 2*array.length;
            else
                coeff = c;

            this.array = new int[coeff];

            for(int i = 0; i < this.array.length; ++i)
            {
                if(i < saveArray.length)
                    this.array[i] = saveArray[i];
                else
                    this.array[i] = 0;
            }
        }
    }

    void resize(int s)
    {
        if(this.array.length < s)
            ensureCapacity(s);
    }

    int size()
    {
        return this.size;
    }

    boolean isEmpty()
    {
        if(this.size == 0)
            return true;

        return false;
    }

    void add(int e)
    {
        if(array.length <= size)
            resize(size + 1);

        this.array[size] = e;
        size++;
    }

    void set(int i, int e)
    {
        if(i <= size)
            this.array[i] = e;
    }

    int get(int i)
    {
        if(i <= size)
         return this.array[i];

        return 0;
    }

    void pop(int i)
    {
        if(i < size)
        {
            this.array[i] = 0;
            size--;
        }

    }

    public static void main(String[] argv)
    {
        Vector vector = new Vector();

        vector.resize(20);

        if(vector.isEmpty())
            System.out.println("Tableau vide : OK");
        else
            System.out.println("Tableau vide : FAIL");

        for(int i = 0; i < 15; ++i)
            vector.add(i);

        System.out.println("");

        /*for(int i = 0; i < vector.size(); ++i)
            System.out.println(vector.get(i));*/

        /*System.out.println("");*/

        vector.set(2, 23);

        for(int i = 0; i < vector.size(); ++i)
            System.out.println(vector.get(i));
    }
}
