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

public class AddGroup implements ActionListener {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private JFrame frame = new JFrame("添加群聊");
    private Font font1 = new Font("Serief",Font.PLAIN,22);
    private Font font2 = new Font("Serief",Font.PLAIN,18);
    private Font font3 = new Font("Serief",Font.PLAIN,16);
    private Font font4 = new Font("Serief",Font.PLAIN,14);
    private JTextField text = new JTextField();
    private JButton search = new JButton("查找");
    private JButton add = new JButton();
    private JLabel groupLab = new JLabel();
    private String account;
    public AddGroup(String account) {
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
            add.setVisible(false);
            groupLab.setVisible(false);
            String groupname = text.getText();
            System.out.println(groupname);
            FindGroup fg = new FindGroup(groupname);
            if(fg.hasGroup) {
                System.out.println("find!");
                groupLab = new JLabel(groupname);
                groupLab.setFont(font2);
                groupLab.setBounds(100,180,120,30);
                add = new JButton("加入群聊");
                add.setFont(font4);
                add.setBounds(400,180,100,30);
                frame.add(add);
                frame.add(groupLab);
                frame.setVisible(false);
                frame.setVisible(true);
                add.addActionListener(this);
            }
        } else if(e.getSource() == add) {
            boolean isAdd = true;
            String group_name = text.getText();
            FindGroupByAccount fgba = new FindGroupByAccount(account);
            for(int i=0;i<fgba.groupNum;i++) {
                if(group_name.equals(fgba.groupName[i])) {
                    isAdd = false;
                    break;
                }
            }
            if(isAdd == true) {
                try {
                    Connection conn = null;
                    PreparedStatement pstmt = null;
                    String sql = "insert into groupchat(group_name,user_qq)" + "values(?,?)";
                    Class.forName(DBDRIVER);
                    conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1,group_name);
                    pstmt.setString(2,account);
                    pstmt.executeUpdate();
                    pstmt.close();
                    conn.close();
                    new AddGroupSuccess();
                } catch (Exception e1) {
                    e1.printStackTrace();
                }
            } else {
                new AddGroupFail();
            }
        }
    }
    public static void main(String[] args) {
        new AddGroup("1");
    }
}
