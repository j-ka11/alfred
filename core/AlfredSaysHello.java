public class AlfredSaysHello {

    private static String[] faceString = {
    "                                    ",
    "           0               0        ",
    "|                                  |",
    "|                                  |",
    "\\                    >             /",
    " \\                                / ",
    "  \\                             /   ",
    "    \\                          /    ",
    "      * ______________________*     ",
    };

    public static void main(String []args) {
        System.out.println("hello!");
        for (int i = 0; i < faceString.length; i++) {
            System.out.println(faceString[i]);
        }
    }
}
