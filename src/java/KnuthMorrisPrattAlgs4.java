import lib.Searcher;
import lib.StringSearch;

/*
Knuth-Morris-Pratt algorithm, initially taken from Sedgewick - Algorithms 4th edition
http://algs4.cs.princeton.edu/53substring/KMPplus.java
*/
public class KnuthMorrisPrattAlgs4 implements Searcher {
    private int[] pattern;
    private int[] skip;

    public void preProcess(int[] pattern) {
        this.pattern = pattern;
        int M = pattern.length;
        skip = new int[M];
        int j = -1;
        for (int i = 0; i < M; i++) {
            if (i == 0)
                skip[i] = -1;
            else if (pattern[i] != pattern[j])
                skip[i] = j;
            else
                skip[i] = skip[j];
            while (j >= 0 && pattern[i] != pattern[j]) {
                j = skip[j];
            }
            j++;
        }
    }

    public int search(int[] text) {
        int M = pattern.length;
        int N = text.length;
        int i, j;
        for (i = 0, j = 0; i < N && j < M; i++) {
            while (j >= 0 && text[i] != pattern[j])
                j = skip[j];
            j++;
        }
        if (j == M)
            return i - M;
        return -1;
    }

    public static void main(String[] args) throws Throwable {
        StringSearch.test(new KnuthMorrisPrattAlgs4());
    }
}
