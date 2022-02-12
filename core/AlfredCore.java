import java.net.*;
import java.io.*;

public class AlfredCore {

    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(4999);
            Socket s = ss.accept();

            System.out.println("Client connected.");

            InputStreamReader in = new InputStreamReader(s.getInputStream());
            BufferedReader br = new BufferedReader(in);

            String str = br.readLine();
            System.out.println("The client says: " + str);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
