package alfred.apps;

import java.net.*;
import java.io.*;
import alfred.core.runnable.AlfredCoreRunnable;

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
            pr.println("alfredApp");
            pr.flush();
            pr.println("<a>");
            pr.flush();
            pr.println("<aw>");
            pr.flush();
            writeWelcomeMessage_(pr);
            pr.println("</aw>");
            pr.flush();
            pr.println("</a>");
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

    private static void writeWelcomeMessage_(PrintWriter pr) {
        for (int i = 0; i < ALPHA_STRING.length; i++) {
            pr.println(ALPHA_STRING[i]);
            pr.flush();
        }
    }
}
