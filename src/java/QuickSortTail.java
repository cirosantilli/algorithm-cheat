import lib.Sort;
import lib.IntArrayConsumer;

/**
Quicksort with tail recursion optimization.
<p>
Reduces call stack extra non-input memory worst case from N to log(N).
<p>
For that to be possible, it always does the tail optimization on the longest side.
*/
public class QuickSortTail implements IntArrayConsumer {

    public void accept(final int[] in) {
        acceptRecursive(in, 0, in.length - 1);
    }

    private static void acceptRecursive(
            final int[] in,
            int leftI,
            int rightI) {
        while (leftI < rightI) {

            // Same as the non-optimized version.
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

            // Tail optimize on the longer side.
            if (smallI - leftI > rightI - smallI) {
                acceptRecursive(in, smallI + 1, rightI);
                rightI = smallI - 1;
            } else {
                acceptRecursive(in, leftI, smallI - 1);
                leftI = smallI + 1;
            }
        }
    }

    public static void main(String[] args) throws Throwable {
        Sort.test(args[0], new QuickSortTail());
    }
}
