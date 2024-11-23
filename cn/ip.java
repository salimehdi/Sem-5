import java.util.Scanner;

public class SimpleIPAddressDetails {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your IP: ");
        String ip = scanner.nextLine();

        if (!isValidIP(ip)) {
            System.out.println("Invalid IP address");
        } else {
            String[] details = getClassDetails(ip);
            System.out.println("Class: " + details[0]);
            System.out.println("Subnet Mask: " + details[1]);
            System.out.println("First IP: " + details[2]);
            System.out.println("Last IP: " + details[3]);
        }

        scanner.close();
    }

    public static boolean isValidIP(String ip) {
        String[] octets = ip.split("\\.");
        if (octets.length != 4) return false;

        for (String octet : octets) {
            try {
                int num = Integer.parseInt(octet);
                if (num < 0 || num > 255) return false;
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }

    public static String[] getClassDetails(String ip) {
        int firstByte = Integer.parseInt(ip.split("\\.")[0]);
        String ipClass = "";
        String subnetMask = "";
        String firstIP = "N/A";
        String lastIP = "N/A";

        if (firstByte >= 0 && firstByte <= 127) {
            ipClass = "A";
            subnetMask = "255.0.0.0";
        } else if (firstByte >= 128 && firstByte <= 191) {
            ipClass = "B";
            subnetMask = "255.255.0.0";
        } else if (firstByte >= 192 && firstByte <= 223) {
            ipClass = "C";
            subnetMask = "255.255.255.0";
        } else if (firstByte >= 224 && firstByte <= 239) {
            ipClass = "D";
            subnetMask = "none";
            return new String[]{ipClass, subnetMask, firstIP, lastIP};
        } else if (firstByte >= 240 && firstByte <= 255) {
            ipClass = "E";
            subnetMask = "none";
            return new String[]{ipClass, subnetMask, firstIP, lastIP};
        }

        firstIP = calculateFirstIP(ip, subnetMask);
        lastIP = calculateLastIP(ip, subnetMask);

        return new String[]{ipClass, subnetMask, firstIP, lastIP};
    }

    public static String calculateFirstIP(String ip, String subnetMask) {
        String[] ipOctets = ip.split("\\.");
        String[] maskOctets = subnetMask.split("\\.");
        StringBuilder firstIP = new StringBuilder();

        for (int i = 0; i < 4; i++) {
            int result = Integer.parseInt(ipOctets[i]) & Integer.parseInt(maskOctets[i]);
            firstIP.append(result).append(i < 3 ? "." : "");
        }

        return firstIP.toString();
    }

    public static String calculateLastIP(String ip, String subnetMask) {
        String[] ipOctets = ip.split("\\.");
        String[] maskOctets = subnetMask.split("\\.");
        StringBuilder lastIP = new StringBuilder();

        for (int i = 0; i < 4; i++) {
            int invertedMask = ~Integer.parseInt(maskOctets[i]) & 0xFF;
            int result = Integer.parseInt(ipOctets[i]) | invertedMask;
            lastIP.append(result).append(i < 3 ? "." : "");
        }

        return lastIP.toString();
    }
}
