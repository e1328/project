package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class RetrieveFail implements ActionListener {
    private JFrame frame = new JFrame("RetrieveFail");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private JLabel infoLab = new JLabel("验证失败：密保问题和密保答案不一致");
    private JButton close = new JButton("关闭");
    private JButton again = new JButton("重试");
    public RetrieveFail() {
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
                System.exit(1);
            }
        });
        frame.setSize(500,280);
        frame.setLocation(620,330);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == close) {
            frame.setVisible(false);
        } else if(e.getSource() == again) {
            frame.setVisible(false);
        }
    }
    public static void main(String[] args) {
        new RetrieveFail();
    }
}
