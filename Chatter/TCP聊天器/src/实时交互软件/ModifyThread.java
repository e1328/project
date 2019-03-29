package 实时交互软件;

public class ModifyThread implements Runnable {
    public void run() {
        try {
            Thread.sleep(3000);
            System.exit(1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
