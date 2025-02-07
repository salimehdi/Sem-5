
public class vernam_cipher {

    public static void main(String[] args) {
        String plainText = "HELLO";
        String key = "efnfgbbL";
        System.out.println("Plain text: " + plainText);
        System.out.println("Key: " + key);
        String encrypted = encrypt_decrypt(plainText, key);
        System.out.println("Encrypted text: " + encrypted);
        String decrypted = encrypt_decrypt(encrypted, key);
        System.out.println("Decrypted text: " + decrypted);
    }

    private static String encrypt_decrypt(String plainText, String key ){
        StringBuilder cipheredText = new StringBuilder();
        for (int i = 0; i < plainText.length(); i++) {
            char temp = (char) (plainText.charAt(i) ^ key.charAt(i % key.length()));
            cipheredText.append((char) temp);
        }
        return cipheredText.toString();
    }
}
