package lib;

public interface Searcher {
    public void preProcess(int[] pattern);
    public int search(int[] text);
}
