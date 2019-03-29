package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class RegisterFail implements ActionListener {
    private JFrame frame = new JFrame("RegisterFail");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private JLabel infoLab = new JLabel("申请失败：注册信息填写有误");
    private JButton close = new JButton("关闭");
    private JButton again = new JButton("重试");
    public RegisterFail() {
        frame.setLayout(null);
        infoLab.setFont(font1);
        close.setFont(font2);
        again.setFont(font2);
        infoLab.setBounds(65,50,340,40);
        again.setBounds(90,170,100,30);
        close.setBounds(285,170,100,30);
        frame.add(infoLab);
        frame.add(again);
        frame.add(close);
        again.addActionListener(this);
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
        if(e.getSource() == again) {
            frame.setVisible(false);
        } else if(e.getSource() == close) {
            frame.setVisible(false);
        }
    }
    public static void main(String[] args) {
        new RegisterFail();
    }
}
