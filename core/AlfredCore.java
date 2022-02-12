import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AlfredCore {

    public static void main(String []args) {
        playDemo_();
    }

    private static void playDemo_() {
        System.out.println("Welcome to the Alfred Core demo!!!\n");
        System.out.println("Sit back, relax, and enjoy the show :)");
        Process p;
        try {
            String[] cmd = {"sh", "./alfred_core_demo_script.sh"};
            p = Runtime.getRuntime().exec(cmd);
            p.waitFor();
            BufferedReader reader = new BufferedReader(new InputStreamReader(
                p.getInputStream()));
            String line;
            while((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("bad");
            e.printStackTrace();
        } catch (InterruptedException e) {
            System.out.println("also bad");
        }
    }
}
