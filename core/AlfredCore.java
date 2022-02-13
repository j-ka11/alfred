package alfred.core;

import alfred.core.runnable.AlfredCoreRunnable;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class AlfredCore {

    private static enum CoreElement {
        WELCOME
    };

    private static int WELCOME_OFF = 1;

    public static void main(String[] args) {
        System.out.println("Hello there. I am the Core server.\n");
        try {
            ServerSocket ss = new ServerSocket(4999);
            Socket s = ss.accept();

            System.out.println("Client connected.\n");

            InputStreamReader in = new InputStreamReader(s.getInputStream());
            BufferedReader br = new BufferedReader(in);
            parseAlfredApplicationConnection_(br);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void parseAlfredApplicationConnection_(
            BufferedReader br) throws Exception {
        if (!br.readLine().equals("alfredApp")) {
            throw new Exception();
        }
        while (br.ready()) {
            if (!br.readLine().equals("<a>")) {
                throw new Exception();
            }
            List<String> alfredTemplate = new ArrayList<String>();
            String templateLine;
            while (!(templateLine = br.readLine()).equals("</a>")) {
                alfredTemplate.add(new String(templateLine));
            }

            // Play welcome message.
            System.out.println("Playing the Alfred App's welcome message:\n");
            parseOpeningTag(alfredTemplate.get(0), CoreElement.WELCOME);
            List<String> welcomeMessage = new ArrayList<String>();
            welcomeMessage.add("alfredAppWelcomeMessage");
            for (int i = WELCOME_OFF; !alfredTemplate.get(i).equals("</aw>"); i++) {
                welcomeMessage.add(new String(alfredTemplate.get(i)));
            }
            playWelcomeMessage_(welcomeMessage);
        }
    }

    private static void parseOpeningTag(
            String tag, CoreElement element) throws Exception {
        switch(element) {
            case WELCOME:
                if (!tag.equals("<aw>")) {
                    throw new Exception();
                }
                break;
        }
    }

    private static void playWelcomeMessage_(List<String> welcomeMessage) {
        if (!welcomeMessage.get(0).equals("alfredAppWelcomeMessage")) {
            return;
        }
        welcomeMessage = welcomeMessage.subList(1, welcomeMessage.size());
        for (int i = 0; i < welcomeMessage.size(); i++) {
            System.out.println(welcomeMessage.get(i));
        }
    }
}
