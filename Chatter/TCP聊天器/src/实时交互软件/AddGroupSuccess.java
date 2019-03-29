package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class AddGroupSuccess {
    private JFrame frame = new JFrame("添加群聊成功");
    private JLabel lab = new JLabel("添加群聊成功");
    private Font font = new Font("Serief",Font.PLAIN,20);
    public AddGroupSuccess() {
        frame.setLayout(null);
        lab.setBounds(85,35,160,40);
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
        new AddGroupSuccess();
    }
}
