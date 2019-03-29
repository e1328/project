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

public class CreateGroup implements ActionListener {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private JFrame frame = new JFrame("创建群聊");
    private JLabel groupLab = new JLabel("群聊名");
    private JButton create = new JButton("创建");
    private JTextField groupText = new JTextField();
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,22);
    private String account;
    public CreateGroup(String account) {
        this.account = account;
        frame.setLayout(null);
        groupLab.setFont(font1);
        groupLab.setBounds(100,60,80,35);
        frame.add(groupLab);
        groupText.setFont(font1);
        groupText.setBounds(165,60,200,35);
        frame.add(groupText);
        create.setFont(font2);
        create.setBounds(180,160,160,40);
        create.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.add(create);
        frame.setSize(500,300);
        frame.setLocation(300,400);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == create) {
            String groupname = groupText.getText();
            FindGroup fg = new FindGroup(groupname);
            if(fg.hasGroup == false) {
                try {
                    Connection conn = null;
                    PreparedStatement pstmt = null;
                    String sql = "insert into groupchat(group_name,user_qq)" + "values(?,?)";
                    Class.forName(DBDRIVER);
                    conn = DriverManager.getConnection(DBURL, DBUSER, DBPASS);
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1, groupname);
                    pstmt.setString(2, account);
                    pstmt.executeUpdate();
                    pstmt.close();
                    conn.close();
                    new CreateGroupSuccess();
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            } else {
                new CreateGroupFail();
            }
        }
    }
    public static void main(String[] args) {
        new CreateGroup("123");
    }
}
