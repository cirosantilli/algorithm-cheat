/*
Standard library-like LinkedList. Implementation choices:

-   single linked. It is likely worth it to have doubly linked,
    and it makes the implementation simpler, and some operations faster,
    at the cost of a little extra memory.

-   last element is cached

-   hidden nodes: end users never manipulate nodes, only the values of nodes.

    This has the advantage of abstracting away the list implementation.
    E.g., ArrayList does not have a `.next` for each element.

    Consequences of this:

    - there must be a differentiated LinkedList parent object. This adds complexity, but is worth it. 
    - an iterator abstraction is needed to iterate and modify the middle of the list.
        We can't do `node.next` or `node.value` anywhere.
*/

import java.util.ListIterator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedList implements Iterable<Integer> {

    private class Node {
        public Integer value;
        public Node next;
        Node(Integer value) {
            this.next = null;
            this.value = value;
        }
        Node(Integer value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    private Node first;
    /*
    This is not mandatory, but it speeds last operations a lot.
    It is a cache.
    */
    private Node last;
    private int size;

    LinkedList() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }

    public boolean isEmpty() {
        return this.size() == 0;
    }

    public boolean add(Integer i) {
        if (this.isEmpty()) {
            this.first = new Node(i);
            this.last = this.first;
        } else {
            last.next = new Node(i);
            last = last.next;
        }
        this.size++;
        return true;
    }

    public boolean addFirst(Integer i) {
        if (this.isEmpty()) {
            this.first = new Node(i);
            last = this.first;
        } else {
            this.first = new Node(i, this.first);
        }
        this.size++;
        return true;
    }

    public Integer peekFirst() {
        if (this.isEmpty()) {
            return null;
        } else {
            return this.first.value;
        }
    }

    public Integer peekLast() {
        if (this.isEmpty()) {
            return null;
        } else {
            return last.value;
        }
    }

    public Integer pollFirst() {
        if (this.isEmpty()) {
            return null;
        } else {
            Integer output = this.first.value;
            /*
            TODO I think we can get away without this check,
            because we have isEmpty checks all over, and those only
            consider the first element, which will be set to null properly.

            But I'd rather leave the List in a saner canonical state.

            Also if we don't do this,
            we hold one element in memory for longer than needed.
            A space time tradeoff.

            Symmetrically, if we used last `this.last == null` as the definition
            of emptiness, then we could remove the check for pollLast instead.
            */
            if (this.first == this.last)
                this.last = null;
            this.first = this.first.next;
            this.size--;
            return output;
        }
    }

    /*
    This can be made much more efficient with a doubly linked list,
    as we wouldn't need to loop all the way to the end.
    This is a space/time tradeoff.
    */
    public Integer pollLast() {
        if (this.isEmpty()) {
            return null;
        } else {
            /*
            If we had chosen to allow this.last != null for the empty list,
            a null check would be needed here.
            */
            Integer output = this.last.value;
            if (this.first == this.last) {
                this.first = null;
                this.last = null;
            } else {
                Node beforeLast = this.first;
                while (beforeLast.next != this.last)
                    beforeLast = beforeLast.next;
                this.last = beforeLast;
                this.last.next = null;
            }
            this.size--;
            return output;
        }
    }

    /* size implementation without cache. O(n). */
    public int sizeNoCache() {
        Node current = this.first;
        int size = 0;
        while (current != null) {
            current = current.next;
            size++;
        }
        return size;
    }

    /*
    Size implementation with cache: O(1).

    This is what major implementations do:
    http://stackoverflow.com/questions/863469/what-is-the-time-complexity-of-a-size-call-on-a-linkedlist-in-java

    This can be used to efficiently iterate the linked list.
    */
    public int size() {
        return this.size;
    }

    class LinkedListIterator implements Iterator<Integer> {
        private Node last;
        /*
        current == null means that we either:

        - haven't called next() yet
        - have already called remove() once
        */
        private Node current;
        private Node next;

        LinkedListIterator(Node first) {
            this.last = null;
            this.current = null;
            this.next = first;
        }

        @Override
        public boolean hasNext() {
            return this.next != null;
        }

        @Override
        public Integer next() {
            if (!hasNext())
                throw new NoSuchElementException();
            this.last = this.last;
            this.current = this.next;
            this.next = this.current.next;
            return this.current.value;
        }

        @Override
        public void remove() {
            if (current == null) {
                throw new IllegalStateException();
            } else if (this.last == null) {
                LinkedList.this.pollFirst();
            } else {
                this.last = this.next;
                this.current = null;
                LinkedList.this.size--;
            }
        }
    }

    @Override
    public Iterator<Integer> iterator() {
        return new LinkedListIterator(first);
    }

    /* TODO also implement listIterator() */
    /*
    class LinkedListListIterator extends LinkedListIterator implements ListIterator<Integer> {
        @Override
        public void remove() {
        }
        LinkedListListIterator() {
        }
    }
    */

    public static void main(String[] args) {
        LinkedList l, l1, l2;
        Iterator<Integer> it;

        /* isEmpty */
        l = new LinkedList();
        assert l.isEmpty();

        /* add and peekLast */
        l = new LinkedList();
        assert l.peekLast() == null;
        assert l.add(1);
        assert l.add(2);
        assert l.peekLast() == 2;

        /* addFirst and peekFirst */
        l = new LinkedList();
        assert l.peekFirst() == null;
        assert l.addFirst(2);
        assert l.addFirst(1);
        assert l.peekFirst() == 1;

        /* pollFirst */
        l = new LinkedList();
        assert l.pollFirst() == null;
        assert l.add(1);
        assert l.add(2);
        assert l.pollFirst() == 1;
        assert l.pollFirst() == 2;
        assert l.peekFirst() == null;
        assert l.peekLast() == null;
        assert l.isEmpty();

        /* pollLast */
        l = new LinkedList();
        assert l.pollLast() == null;
        assert l.add(1);
        assert l.add(2);
        assert l.pollLast() == 2;
        assert l.pollLast() == 1;
        assert l.peekFirst() == null;
        assert l.peekLast() == null;
        assert l.isEmpty();

        /* sizeNoCache */
        l = new LinkedList();
        assert l.sizeNoCache() == 0;
        assert l.add(1);
        assert l.sizeNoCache() == 1;
        assert l.add(2);
        assert l.sizeNoCache() == 2;
        assert l.pollLast() == 2;
        assert l.sizeNoCache() == 1;
        assert l.pollLast() == 1;
        assert l.sizeNoCache() == 0;

        /* size */
        l = new LinkedList();
        assert l.size() == 0;
        assert l.add(1);
        assert l.size() == 1;
        assert l.add(2);
        assert l.size() == 2;
        assert l.pollLast() == 2;
        assert l.size() == 1;
        assert l.pollLast() == 1;
        assert l.size() == 0;

        /* iterator */
        {
            /* Enhanced for. */
            l1 = new LinkedList();
            l2 = new LinkedList();
            l1.add(1);
            l1.add(2);
            for (int i : l1) {
                assert l2.add(i);
            }
            assert l2.pollFirst() == 1;
            assert l2.pollFirst() == 2;

            /* Raw */
            l1 = new LinkedList();
            l2 = new LinkedList();
            l1.add(1);
            l1.add(2);
            it = l1.iterator();
            while (it.hasNext()) {
                int i = it.next();
                assert l2.add(i);
            }
            assert l2.pollFirst() == 1;
            assert l2.pollFirst() == 2;

            /* remove */
            l = new LinkedList();
            assert l.add(1);
            assert l.add(2);
            it = l.iterator();
            assert it.next() == 1;
            it.remove();
            assert l.pollFirst() == 2;
            assert l.isEmpty();
            assert l.size() == 0;
        }
    }
}
