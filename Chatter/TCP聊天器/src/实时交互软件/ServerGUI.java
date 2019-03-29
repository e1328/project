package 实时交互软件;

import javax.swing.*;

public class ServerGUI {
    private JFrame frame = new JFrame("服务器");
    public ServerGUI() {
        frame.setSize(600,400);
        frame.setLocation(400,400);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        new ServerGUI();
    }
}
