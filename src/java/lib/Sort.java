package lib;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

/** Shared sort input parsing. */
public class Sort {
    public static void test(String path, IntArrayConsumer consumer) throws Throwable {
        BufferedReader br = new BufferedReader(new FileReader(path));
        String sizeS = br.readLine();
        String inS = br.readLine();
        int size = Integer.parseInt(sizeS.trim());
        Scanner scanner;
        int i;
        int[] in = new int[size];
        scanner = new Scanner(inS);
        i = 0;
        while (scanner.hasNextInt()) {
            in[i] = scanner.nextInt();
            i++;
        }
        consumer.accept(in);
        for (i = 0; i < in.length - 1; i++) {
            System.out.print(in[i] + " ");
        }
        System.out.print(in[in.length - 1] + "\n");
    }
}
