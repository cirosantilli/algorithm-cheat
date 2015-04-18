import java.io.FileInputStream;
import java.util.Arrays;

/**
 * Implement the two sides strategy for tac.
 * <p>
 * No memory moves are ever done.
 * <p>
 * Disk read happens on the longer remaining buffer space.
 * <p>
 * On a hard drive, it is likely faster to move the buffer around to reduce disk access.
 * <p>
 * On SSD, it really depends, and the ideal thing would be
 * to check for the size of the chunk to move around.
 */
class Tac {

    private static final boolean DEBUG = false;
    private static final int DEFAULT_BUFLEN = 1024;
    private static final byte SEP = '\n';
    private static long fileOff;
    private static boolean found;

    /** Read the file and search on the read segment. Also print older segments. */
    private static int search (
            byte[] b,
            final FileInputStream f,
            int width,
            final int left,
            int oldLeft,
            int oldWidth,
            int oldLeft2,
            int oldWidth2) throws Exception {
        width = (int)Math.min(fileOff, width);
        fileOff -= width;
        f.getChannel().position(fileOff);
        f.read(b, left, width);
        int lastNewline = left + width - 1;
        int i = lastNewline;
        found = false;
        while (i >= left) {
            if (b[i] == SEP) {
                // Print new segment.
                if (i + 1 < b.length) {
                    System.out.write(b, i + 1, lastNewline - i);
                }
                // Print old segments.
                if (!found) {
                    // TODO optimization: assume that the old ends in newline.
                    // This allows reading one extra byte each time.
                    System.out.write(b, oldLeft, oldWidth);
                    System.out.write(b, oldLeft2, oldWidth2);
                    found = true;
                }
                lastNewline = i;
            }
            i--;
        }
        return lastNewline - left + 1;
    }

    public static void main(final String[] args) throws Throwable {

    	// CLI
    	String path = args[0];
    	int buflen;
    	if (args.length > 1) {
    		buflen = Integer.parseInt(args[1]);
    	} else {
    		buflen = DEFAULT_BUFLEN;
    	}

        final byte[] b = new byte[buflen];
        final FileInputStream f = new FileInputStream(args[0]);
        final long fileSize = f.getChannel().size();
        fileOff = fileSize;
        int oldLeft = 0;
        int oldWidth = 0;
        int searchLeft;
        int width;
        int searchLeft2;
        int width2;

        while(fileOff > 0) {

            // TODO optimization:
            // decide what is better: moving the entire old to the left,
            // or reading the disk one extra time.

            // Decide which side to read on and read it.
            int leftWidth = oldLeft;
            int rightWidth = buflen - (oldLeft + oldWidth);
            if (leftWidth > rightWidth) {
                searchLeft = 0;
                width = leftWidth;
                searchLeft2 = oldLeft + oldWidth;
                width2 = rightWidth;
            } else {
                searchLeft = oldLeft + oldWidth;
                width = rightWidth;
                searchLeft2 = 0;
                width2 = leftWidth;
            }

            // First side.
            oldWidth = search(b, f, width, searchLeft, oldLeft, oldWidth, 0, 0);
            if (found) {
                oldLeft = searchLeft;
                continue;
            }

            // Second side.
            oldWidth = search(b, f, width2, searchLeft2, oldLeft, oldWidth, searchLeft, width);
            if (found) {
                oldLeft = searchLeft2;
                continue;
            }

            System.err.println("Line longer than maxium buffer size present: " + buflen);
            System.exit(1);
        }
        // Last old.
        System.out.write(b, oldLeft, oldWidth);
    }
}
