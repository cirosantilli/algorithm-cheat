import java.util.Arrays;
import java.util.Collections;

import lib.Searcher;
import lib.StringSearch;

public class KnuthMorrisPratt implements Searcher {
    private int[] pattern;

    /**
    Skip table generated at preprocessing time.

    <p>This version of the algorithm uses forward skips instead of backtracking distances,
    as that is more direct to view on the search.

    <p>The disadvantages are:

    <ul>
    <li>the backtrack representation has lots of zeroes,
        so it is more direct to represent it with a sparse array.

    <li>the backtrack calculation is more elegant, as you can do `currentMatch = skip[currentMatch]`
    </ul>

    <p>but I'd rather have an elegant search loop rather than skip table.
    */
    private int[] skip;

    // With an all ones skip array, we fall back to the naive search.
    public void preProcessNaive(int[] pattern) {
        final int patternLength = pattern.length;
        this.skip = new int[patternLength];
        for (int i = 0; i < patternLength; i++)
            this.skip[i] = 1;
    }

    /**
    Naive pre-processor calculation that checkes all suffixes.
    <p>
    This has 3 nested loops because it does not reuse previously
    calculated information to calculate new table positions.
    */
    public void preProcessNaiveSkip(int[] pattern) {
        this.pattern = pattern;
        final int patternLength = pattern.length;
        this.skip = new int[patternLength];
        for (int i = 0; i < patternLength; i++) {
            int j;
            findprefix:
            for (j = 1; j < i; j++) {
                final int substringLengh = i - j;
                for (int k = 0; k < substringLengh; k++) {
                    if (pattern[k] != pattern[j + k]) {
                        continue findprefix;
                    }
                }
                break;
            }
            this.skip[i] = j;
        }
    }

    /**
    Dynamic programming preprocessor version in O(n).
    <p>
    Uses previously calculated skip table values to calculate new values.
    */
    public void preProcess(int[] pattern) {
        this.pattern = pattern;
        final int patternLength = pattern.length;
        this.skip = new int[patternLength];
        int i;
        // i == 0 is an special case: there is nothing to compatere with.
        int currentMatch = 0;
        if (patternLength > 0) {
            this.skip[0] = 1;
            if (patternLength > 1)
                this.skip[1] = 1;
        }
        for (i = 2; i < patternLength; i++) {
            while (true) {
                if (pattern[currentMatch] == pattern[i - 1]) {
                    currentMatch++;
                    break;
                }
                if (currentMatch == 0)
                    break;
                currentMatch -= this.skip[currentMatch];
            }
            this.skip[i] = i - currentMatch;
        }
    }

    public int search(int[] text) {
        int lastPatternI = this.pattern.length;
        int lastTextI = text.length - lastPatternI;
        int j = 0;
        // Adding the skip is the only difference between KMP and the naive search.
        outer:
        for (int i = 0; i <= lastTextI; i += this.skip[j]) {
            // We must treat the case 0 specially. Even though the skip is 1,
            // j cannot go back by 1 or it would be -1.
            if (j > 0)
                j -= this.skip[j];
            for (; j < lastPatternI; j++) {
                if (text[i + j] != this.pattern[j])
                    continue outer;
            }
            return i;
        }
        return -1;
    }

    public static void main(String[] args) throws Throwable {
        StringSearch.test(new KnuthMorrisPratt());
    }
}
