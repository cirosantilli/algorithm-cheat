import lib.Sort;
import lib.IntArrayConsumer;

/** Naive quicksort recursive implementation. */
public class QuickSort implements IntArrayConsumer {

    public void accept(final int[] in) {
        acceptRecursive(in, 0, in.length - 1);
    }

    private static void acceptRecursive(
            final int[] in,
            final int leftI,
            final int rightI) {
        if (leftI < rightI) {
            int smallI = leftI;
            int bigI = leftI;
            final int pivot = in[rightI];
            while (bigI < rightI) {
                final int big = in[bigI];
                if (big < pivot) {
                    int smallBuf = in[smallI];
                    in[smallI] = big;
                    in[bigI] = smallBuf;
                    smallI++;
                }
                bigI++;
            }
            in[rightI] = in[smallI];
            in[smallI] = pivot;
            acceptRecursive(in, leftI, smallI - 1);
            acceptRecursive(in, smallI + 1, rightI);
        }
    }

    public static void main(String[] args) throws Throwable {
        Sort.test(args[0], new QuickSort());
    }
}
