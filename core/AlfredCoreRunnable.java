package alfred.core;

public class AlfredCoreRunnable {

    private String[] imgString;
    private bool setImgString = false;

    public String[] getImgString() {
        return imgString;
    }

    public void setImgString(String[] imgString) {
        this.imgString = imgString;
        this.setImgString = true;
    }
}
