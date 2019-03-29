package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.text.SimpleDateFormat;
import java.util.Random;

public class ModifyPassword implements ActionListener {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private JFrame frame = new JFrame("修改密码");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,26);
    private Font font3 = new Font("Serief",Font.ITALIC,26);
    private JLabel lab1 = new JLabel("   原密码");
    private JLabel lab2 = new JLabel("   新密码");
    private JLabel lab3 = new JLabel("确认密码");
    private JLabel lab4 = new JLabel("   验证码");
    private JButton validate = new JButton("验证");
    private JPasswordField pass1 = new JPasswordField();
    private JPasswordField pass2 = new JPasswordField();
    private JPasswordField pass3 = new JPasswordField();
    private JTextField code1 = new JTextField();
    private JTextField code2 = new JTextField();
    private String tpass1;
    private String tpass2;
    private String tpass3;
    private String tcode1;
    private String tcode2 = "";
    private String account;
    public static String msg;
    public ModifyPassword(String account) {
        this.account = account;
        String str = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm";
        for(int i=0;i<4;i++) {
            tcode2 = tcode2 + str.charAt(new Random().nextInt(62));
        }
        frame.setLayout(null);
        lab1.setBounds(100,30,100,40);
        lab1.setFont(font1);
        pass1.setFont(font1);
        pass1.setBounds(195,30,200,40);
        lab2.setBounds(100,75,100,40);
        lab2.setFont(font1);
        pass2.setFont(font1);
        pass2.setBounds(195,75,200,40);
        lab3.setFont(font1);
        lab3.setBounds(100,120,100,40);
        pass3.setFont(font1);
        pass3.setBounds(195,120,200,40);
        lab4.setFont(font1);
        lab4.setBounds(100,175,100,40);
        code1.setFont(font2);
        code1.setBounds(195,175,100,50);
        code2.setFont(font3);
        code2.setBounds(295,175,100,50);
        code2.setText(tcode2);
        code2.setEnabled(false);
        validate.setFont(font2);
        validate.setBounds(190,260,160,44);
        validate.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.add(lab1);
        frame.add(lab2);
        frame.add(lab3);
        frame.add(lab4);
        frame.add(pass1);
        frame.add(pass2);
        frame.add(pass3);
        frame.add(code1);
        frame.add(code2);
        frame.add(validate);
        frame.setSize(550,400);
        frame.setLocation(600,300);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == validate) {
            tpass1 = new String(pass1.getPassword());
            tpass2 = new String(pass2.getPassword());
            tpass3 = new String(pass3.getPassword());
            FindByAccount fba = new FindByAccount(account);
            String initpass = fba.password;
            tcode1 = code1.getText();
            if(tpass1.equals(initpass) && tpass2.equals(tpass3) && tcode1.equals(tcode2)) {
                try {
                    Connection conn = null;
                    PreparedStatement pstmt = null;
                    String sql = "update user set password = ? where account = ?";
                    Class.forName(DBDRIVER);
                    conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1,tpass2);
                    pstmt.setString(2,account);
                    pstmt.executeUpdate();
                    pstmt.close();
                    conn.close();
                    frame.setVisible(false);
                    msg = "success";
                    new ModifyPasswordSuccess();
                    ModifyThread mt = new ModifyThread();
                    new Thread(mt).start();
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            } else {
                new ModifyPasswordFail();
            }
        }
    }
    public static void main(String[] args) {
        new ModifyPassword("123");
    }
}
