package alfred.core.runnable;

public class AlfredCoreRunnable {

    private String[] welcomeMessage;
    private Boolean setWelcomeMessage = false;

    public String[] getWelcomeMessage() {
        return welcomeMessage;
    }

    public void setWelcomeMessage(String[] welcomeMessage) {
        this.welcomeMessage = welcomeMessage;
        this.setWelcomeMessage = true;
    }
}
