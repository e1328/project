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

public class AddFriend implements ActionListener {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private JFrame frame = new JFrame("添加好友");
    private Font font1 = new Font("Serief",Font.PLAIN,22);
    private Font font2 = new Font("Serief",Font.PLAIN,18);
    private Font font3 = new Font("Serief",Font.PLAIN,16);
    private Font font4 = new Font("Serief",Font.PLAIN,14);
    private JTextField text = new JTextField();
    private JButton search = new JButton("查找");
    private JButton headicon = new JButton();
    private Icon icon;
    private JButton add = new JButton();
    private JLabel signLab = new JLabel();
    private JLabel nameLab = new JLabel();
    private JTextField signText = new JTextField();
    private String account;
    public AddFriend(String account) {
        this.account = account;
        frame.setLayout(null);
        text.setBounds(110,60,300,40);
        text.setFont(font1);
        search.setBounds(410,60,80,40);
        search.setFont(font2);
        frame.add(text);
        frame.add(search);
        search.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setSize(620,420);
        frame.setLocation(400,300);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == search) {
            headicon.setVisible(false);
            signLab.setVisible(false);
            signText.setVisible(false);
            nameLab.setVisible(false);
            add.setVisible(false);
            String account1 = text.getText();
            FindByAccount fba = new FindByAccount(account1);
            if(fba.hasFriend) {
                System.out.println("find!");
                icon = new ImageIcon(fba.headicon);
                headicon = new JButton(icon);
                nameLab = new JLabel(fba.name);
                nameLab.setFont(font3);
                nameLab.setBounds(160,140,60,60);
                signLab = new JLabel("Sign:");
                signLab.setFont(font3);
                signText = new JTextField();
                signText.setFont(font3);
                signText.setText(fba.sign);
                add = new JButton("加好友");
                add.setFont(font4);
                headicon.setBounds(100,160,45,45);
                signLab.setBounds(160,180,60,40);
                signText.setBounds(210,180,120,30);
                add.setBounds(415,180,80,30);
                frame.add(headicon);
                frame.add(signLab);
                frame.add(signText);
                frame.add(nameLab);
                frame.add(add);
                System.out.println("add");
                frame.setVisible(false);
                frame.setVisible(true);
                add.addActionListener(this);
                headicon.addActionListener(this);
            }
        } else if(e.getSource() == headicon) {
            String account = text.getText();
            FindByAccount fba = new FindByAccount(account);
            new DisplayInformation(fba.name,fba.account,fba.password,fba.sex,fba.birthday,fba.place,fba.question1,
                    fba.question2,fba.question3,fba.sign,fba.headicon);
        } else if(e.getSource() == add) {
            boolean isAdd = true;
            String account1 = text.getText();
            FindByAccount fba = new FindByAccount(account1);
            FindFriendByAccount ffba = new FindFriendByAccount(account);
            for(int i=0;i<ffba.friendNum;i++) {
                if(ffba.friensList[i].equals(fba.account)) {
                    isAdd = false;
                }
            }
            if(account.equals(account1)) {
                isAdd = false;
            }
            if(isAdd) {
                try {
                    Connection conn = null;
                    PreparedStatement pstmt = null;
                    String sql = "insert into friend(friend_qq,user_qq)" + "values(?,?)";
                    Class.forName(DBDRIVER);
                    conn = DriverManager.getConnection(DBURL, DBUSER, DBPASS);
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1, account1);
                    pstmt.setString(2, account);
                    pstmt.executeUpdate();
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1, account);
                    pstmt.setString(2, account1);
                    pstmt.executeUpdate();
                    pstmt.close();
                    conn.close();
                    new AddSuccess();
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            } else {
                new AddFail();
            }
        }
    }
    public static void main(String[] args) {
        new AddFriend("1");
    }
}
