
public class vignere_cipher {

    public static void main(String[] args) {
        String plainText = "HELLO";
        String key = "PIL";
        System.out.println("Plain text: " + plainText);
        System.out.println("Key: " + key);
        String encrypted = encrypt(plainText, key);
        System.out.println("Encrypted text: " + encrypted);
        String decrypted = decrypt(encrypted, key);
        System.out.println("Decrypted text: " + decrypted);
    }

    private static String encrypt(String plainText, String key) {
        StringBuilder cipheredText = new StringBuilder();
        for (int i = 0; i < plainText.length(); i++) {
            char temp = (char) (plainText.charAt(i) + key.charAt(i % key.length()) % 26);
            cipheredText.append((char) temp);
        }
        return cipheredText.toString();
    }

    private static String decrypt(String plainText, String key) {
        StringBuilder cipheredText = new StringBuilder();
        for (int i = 0; i < plainText.length(); i++) {
            char temp = (char) (plainText.charAt(i) - key.charAt(i % key.length()) % 26);
            cipheredText.append((char) temp);
        }
        return cipheredText.toString();
    }
}
