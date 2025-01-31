import java.util.*;

class PlayfairCipher {

    private static char[][] charTable;
    private static String keyword;
    private static char padChar = 'X';

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the keyword:");
        keyword = sc.next().toUpperCase().replaceAll("[^A-Z]", "").replace('J', 'I');
        charTable = createTable(keyword);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(charTable[i][j] + "  ");
            }
            System.out.println();
        }

        System.out.println("Enter the text to encrypt:");
        String text = sc.next().toUpperCase().replaceAll("[^A-Z]", "").replace('J', 'I');
        
        String encryptedText = encrypt(text);
        System.out.println("Encrypted Text: " + encryptedText);

        String decryptedText = decrypt(encryptedText);
        System.out.println("Decrypted Text: " + decryptedText);
    }

    private static String encrypt(String text) {
        return processText(text, true);
    }

    private static String decrypt(String text) {
        return processText(text, false);
    }

    private static String processText(String text, boolean encrypt) {
        StringBuilder processedText = new StringBuilder();

        for (int a = 0; a < text.length(); a += 2) {
            char a1 = text.charAt(a);
            char b = (a + 1 < text.length()) ? text.charAt(a + 1) : padChar;

            if (a1 == b) {
                b = padChar;
                a--;
            }

            processedText.append(processPair(a1, b, encrypt));
        }

        return processedText.toString();
    }

    private static String processPair(char a, char b, boolean encrypt) {
        int[] posA = findTable(a);
        int[] posB = findTable(b);
        int rowShift = encrypt ? 1 : -1;
        int colShift = encrypt ? 1 : -1;

        if (posA[0] == posB[0]) {
            return String.valueOf(getChar(posA[0], (posA[1] + colShift + 5) % 5)) +
                   getChar(posB[0], (posB[1] + colShift + 5) % 5);
        } else if (posA[1] == posB[1]) {
            return String.valueOf(getChar((posA[0] + rowShift + 5) % 5, posA[1])) +
                   getChar((posB[0] + rowShift + 5) % 5, posB[1]);
        } else {
            return String.valueOf(getChar(posA[0], posB[1])) +
                   getChar(posB[0], posA[1]);
        }
    }

    private static int[] findTable(char a) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (a == charTable[i][j]) {
                    return new int[]{i, j};
                }
            }
        }
        return null;
    }

    private static char[][] createTable(String keyword) {
        char[][] table = new char[5][5];
        String key = keyword + "ABCDEFGHIKLMNOPQRSTUVWXYZ";

        Set<Character> used = new HashSet<>();
        int k = 0;

        for (char c : key.toCharArray()) {
            if (!used.contains(c)) {
                table[k / 5][k % 5] = c;
                used.add(c);
                k++;
            }
        }
        return table;
    }

    private static char getChar(int row, int col) {
        return charTable[row][col];
    }
}
