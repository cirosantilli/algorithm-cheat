/*
Non-balanced binary tree:

- without outer container: nodes only.
- no repetitions
*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BinaryTree {

    private Integer value;
    private BinaryTree left;
    private BinaryTree right;

    BinaryTree(Integer value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    public boolean insert(Integer value) {
        if (value < this.value) {
            if (this.left == null) {
                this.left = new BinaryTree(value);
                return true;
            } else {
                return this.left.insert(value);
            }
        } else if (value > this.value) {
            if (this.right == null) {
                this.right = new BinaryTree(value);
                return true;
            } else {
                return this.right.insert(value);
            }
        } else {
            return false;
        }
    }

    public void inOrder(List<Integer> output) {
        if (this.left != null)
            this.left.inOrder(output);
        output.add(this.value);
        if (this.right != null)
            this.right.inOrder(output);
    }

    public void preOrder(List<Integer> output) {
        output.add(this.value);
        if (this.left != null)
            this.left.preOrder(output);
        if (this.right != null)
            this.right.preOrder(output);
    }

    public static void main(String[] args) {
        List<Integer> expected, output;
        BinaryTree t = new BinaryTree(0);
        assert !t.insert(0);
        assert  t.insert(-2);
        assert  t.insert(-1);
        assert  t.insert(-3);
        assert  t.insert(2);
        assert  t.insert(1);
        assert  t.insert(3);

        /* Insert. */
        assert t.value == 0;
        assert t.left.value == -2;
        assert t.left.left.value == -3;
        assert t.left.right.value == -1;
        assert t.right.value == 2;
        assert t.right.left.value == 1;
        assert t.right.right.value == 3;

        /* inOrder */
        expected = new ArrayList<Integer>();
        expected.add(-3);
        expected.add(-2);
        expected.add(-1);
        expected.add(0);
        expected.add(1);
        expected.add(2);
        expected.add(3);
        output = new ArrayList<Integer>();
        t.inOrder(output);
        assert output.equals(expected);

        /* preOrder */
        expected = new ArrayList<Integer>();
        expected.add(0);
        expected.add(-2);
        expected.add(-3);
        expected.add(-1);
        expected.add(2);
        expected.add(1);
        expected.add(3);
        output = new ArrayList<Integer>();
        t.preOrder(output);
        assert output.equals(expected);
    }
}
