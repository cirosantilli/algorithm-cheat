import java.util.Arrays;

import lib.Searcher;
import lib.StringSearch;

/** Naive quicksort recursive implementation. */
public class StringSearchNaive implements Searcher {

    int[] pattern;

    public void preProcess(int[] pattern) { this.pattern = pattern; }

    public int search(int[] text) {
        int lastPatternI = this.pattern.length;
        int lastTextI = text.length - lastPatternI;
    outer:
        for (int i = 0; i <= lastTextI; i++) {
            for (int j = 0; j < lastPatternI; j++) {
                if (text[i + j] != this.pattern[j])
                    continue outer;
            }
            return i;
        }
        return -1;
    }

    public static void main(String[] args) throws Throwable {
        StringSearch.test(new StringSearchNaive());
    }
}
