import java.io.PrintStream;
import java.util.Arrays;

public class Heap {

    public static int child1(int i) {
        return (2 * i) + 1;
    }

    public static int child2(int i) {
        return child1(i) + 1;
    }

    public static int lastParent(int[] arr) {
        return lastParent(arr.length);
    }

    /** Return the index for the last parent node. */
    public static int lastParent(int length) {
        return (length / 2) - 1;
    }

    public static void heapify(int[] arr) {
        for (int i = lastParent(arr); i >= 0; i--) {
            maxHeapify(arr, i);
        }
    }

    public static int maxHeapifyStep(int[] arr, int i) {
        return maxHeapifyStep(arr, i, arr.length);
    }

    /** Make the heap property valid for a parent and its immediate children. */
    public static int maxHeapifyStep(int[] arr, int i, int length) {
        int child1I = child1(i);
        int child2I = child2(i);
        int child1 = arr[child1I];
        int child2;
        int swapWith;
        int swapWithI;
        int cur;
        if (child2I == length) {
            child2 = Integer.MIN_VALUE;
        } else {
            child2 = arr[child2I];
        }
        cur = arr[i];
        if (child1 < child2) {
            swapWith = child2;
            swapWithI = child2I;
        } else {
            swapWith = child1;
            swapWithI = child1I;
        }
        if (cur < swapWith) {
            arr[swapWithI] = cur;
            arr[i] = swapWith;
        } else {
            swapWithI = i;
        }
        return swapWithI;
    }

    public static void maxHeapify(int[] arr) {
        maxHeapify(arr, 0);
    }

    public static void maxHeapify(int[] arr, int i) {
        maxHeapify(arr, i, arr.length);
    }

    public static void maxHeapify(int[] arr, int i, int length) {
        int lastParent = lastParent(length);
        int lastI = -1;
        while ((i != lastI) && (i <= lastParent)) {
            lastI = i;
            i = maxHeapifyStep(arr, i, length);
        }
    }

    public static void main(String[] args) {
        // heapify. The ideal would be to have a `isHeap` method
        // since possible outputs are not unique.
        {
            final int ins[][] = {
                {4, 5, 6, 2, 1, 3, 0, 7},
            };
            final int expected_outs[][] = {
                {7, 5, 6, 4, 1, 3, 0, 2},
            };
            for (int i = 0; i < ins.length; i++) {
                int out[] = ins[i].clone();
                heapify(out);
                if (!Arrays.equals(out, expected_outs[i])) {
                    System.err.println(Arrays.toString(ins[i]));
                    System.err.println(Arrays.toString(expected_outs[i]));
                    System.err.println(Arrays.toString(out));
                    System.exit(1);
                }
            }
        }
    }
}

