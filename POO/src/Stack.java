public class Stack {

    private Vector vector;

    Stack()
    {
        this.vector = new Vector();
    }

    void push(int i)
    {
        this.vector.add(i);
    }

    int pop()
    {
        int res = this.vector.get(vector.size() - 1);
        this.vector.pop(vector.size() - 1);
        return res;
    }

    int peek()
    {
        return vector.get(vector.size() - 1);
    }

    int size()
    {
        return vector.size();
    }

    boolean empty()
    {
        return this.vector.isEmpty();
    }

    public static void main(String argv[])
    {
        Stack stack = new Stack();

        if(stack.empty())
            System.out.println("Tableau vide : OK");
        else
            System.out.println("Tableau vide : FAIL");

        for (int i = 0; i < 25; ++i)
            stack.push(i);

        System.out.println("Taille = " + stack.size());

        System.out.println(stack.peek());

        System.out.println(stack.pop());

        System.out.println(stack.peek());



    }
}
