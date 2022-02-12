import java.net.*;
import java.io.*;

public class AlfredAppAlpha {

    private static final String[] ALPHA_STRING = {
        "Hello. I am Alfred App Alpha. I am the first",
        "Alfred Application to be operated by Alfred Core.",
        "These words are my own, and do not come from Alfred",
        "Core. Have a good day!",
    };

    public static void main(String args[]) {
        try {
            Socket s = new Socket("localhost", 4999);

            PrintWriter pr = new PrintWriter(s.getOutputStream());
            pr.println("hello I am the client");
            pr.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void start() {
        for (int i = 0; i < ALPHA_STRING.length; i++) {
            System.out.println(ALPHA_STRING[i]);
        }
    }
}
