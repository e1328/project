package 实时交互软件;

import javax.swing.*;
import java.awt.*;

public class LoginSuccess {
    public JFrame frame = new JFrame("LoginSuccess");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private JLabel infoLab = new JLabel("登录成功：即将进入主界面");
    public LoginSuccess() {
        frame.setLayout(null);
        infoLab.setFont(font1);
        infoLab.setBounds(65,50,240,40);
        frame.add(infoLab);
        frame.setSize(500,280);
        frame.setLocation(610,430);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        new LoginSuccess();
    }
}
