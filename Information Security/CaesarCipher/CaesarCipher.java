import java.util.*;

class CaesarCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the text:");
        String text = sc.nextLine();
        System.out.println("Enter the shift value:");
        int shift = sc.nextInt();

        String encryptedText = encrypt(text, shift);
        System.out.println("Encrypted Text: " + encryptedText);

        String decryptedText = decrypt(encryptedText, shift);
        System.out.println("Decrypted Text: " + decryptedText);
    }

    public static String encrypt(String text, int shift) {
        StringBuilder ciphered = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (Character.isLetter(c)) {
                char shifted = c;
                if (Character.isUpperCase(c)) {
                    shifted = (char) ((c - 'A' + shift) % 26 + 'A');
                } else if (Character.isLowerCase(c)) {
                    shifted = (char) ((c - 'a' + shift) % 26 + 'a');
                }
                ciphered.append(shifted);
            } else {
                ciphered.append(c);
            }
        }
        return ciphered.toString();
    }

    public static String decrypt(String text, int shift) {
        return encrypt(text, -shift);
    }
}
