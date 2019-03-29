package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class RegisterSuccess implements ActionListener {
    private JFrame frame = new JFrame("RegisterSuccess");
    private JLabel infoLab = new JLabel("申请成功,您获得号码:");
    private JButton close = new JButton("关闭");
    private JButton login = new JButton("登录");
    private JTextField accountText = new JTextField();
    public RegisterSuccess(String account) {
        Font font1 = new Font("Serief",Font.PLAIN,20);
        Font font2 = new Font("Serief",Font.PLAIN,16);
        frame.setLayout(null);
        infoLab.setFont(font1);
        accountText.setFont(font2);
        accountText.setFont(font2);
        login.setFont(font2);
        close.setFont(font2);
        infoLab.setBounds(65,50,200,40);
        accountText.setBounds(270,50,140,40);
        login.setBounds(90,170,100,30);
        close.setBounds(285,170,100,30);
        accountText.setText(account);
        accountText.setEnabled(false);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                //System.exit(1);
                frame.setVisible(false);
            }
        });
        frame.add(infoLab);
        frame.add(accountText);
        frame.add(login);
        frame.add(close);
        login.addActionListener(this);
        close.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setSize(500,280);
        frame.setLocation(450,380);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == login) {
            new Login();
        } else if(e.getSource() == close) {
            frame.setVisible(false);
        }
    }
    public static void main(String[] args) {
        new RegisterSuccess("123456");
    }
}
