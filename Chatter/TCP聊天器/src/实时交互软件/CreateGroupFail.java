package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class CreateGroupFail {
    private JFrame frame = new JFrame("创建群聊失败");
    private JLabel lab = new JLabel("群聊存在，不能重复创建");
    private Font font = new Font("Serief",Font.PLAIN,20);
    public CreateGroupFail() {
        frame.setLayout(null);
        lab.setBounds(35,35,260,40);
        lab.setFont(font);
        frame.add(lab);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setSize(320,180);
        frame.setLocation(600,500);
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        new CreateGroupFail();
    }
}
