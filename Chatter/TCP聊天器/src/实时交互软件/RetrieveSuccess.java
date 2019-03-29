package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class RetrieveSuccess implements ActionListener {
    private JFrame frame = new JFrame("RetrieveSuccess");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private JLabel infoLab = new JLabel("验证成功：原密码为");
    private JButton close = new JButton("关闭");
    private JButton login = new JButton("登录");
    private JTextField passwordText = new JTextField();
    public RetrieveSuccess(String password) {
        frame.setLayout(null);
        infoLab.setFont(font1);
        passwordText.setFont(font1);
        login.setFont(font2);
        close.setFont(font2);
        infoLab.setBounds(65,50,180,40);
        login.setBounds(90,170,100,30);
        close.setBounds(285,170,100,30);
        passwordText.setBounds(260,50,140,40);
        passwordText.setText(password);
        passwordText.setEnabled(false);
        frame.add(infoLab);
        frame.add(login);
        frame.add(close);
        frame.add(passwordText);
        close.addActionListener(this);
        login.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setSize(500,280);
        frame.setLocation(620,330);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == close) {
            frame.setVisible(false);
        } else if(e.getSource() == login) {
            frame.setVisible(false);
            new Login();
        }
    }
    public static void main(String[] args) {
        new RetrieveSuccess("112222");
    }
}
