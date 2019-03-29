package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class ModifyUserSuccess implements ActionListener {
    public JFrame frame = new JFrame("ModifyUserSuccess");
    private Font font1 = new Font("Serief",Font.PLAIN,22);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private JLabel infoLab = new JLabel("修改信息成功，请重新登录");
    private JButton login = new JButton("重新登录");
    private JButton close = new JButton("关闭");
    public ModifyUserSuccess() {
        frame.setLayout(null);
        infoLab.setFont(font1);
        close.setFont(font2);
        login.setFont(font2);
        infoLab.setBounds(100,50,280,40);
        login.setBounds(90,170,100,30);
        close.setBounds(285,170,100,30);
        close.addActionListener(this);
        login.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.add(infoLab);
        frame.add(login);
        frame.add(close);
        frame.setSize(500,280);
        frame.setLocation(610,430);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == login) {
            frame.setVisible(false);
            new Login();
        } else if(e.getSource() == close) {
            frame.setVisible(false);
        }
    }
    public static void main(String[] args) {
        new ModifyUserSuccess();
    }
}
