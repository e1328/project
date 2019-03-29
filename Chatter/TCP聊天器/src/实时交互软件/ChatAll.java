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
import java.sql.ResultSet;

public class ChatAll implements ActionListener {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private JFrame frame = new JFrame("Talk");
    private Container cont = frame.getContentPane();
    private JSplitPane split1;
    private JSplitPane split2;
    private JPanel pan1;
    private JPanel pan2;
    private JPanel pan3;
    public static JTextArea text1;
    public static JTextArea text2;
    private JButton send;
    private JButton close;
    private JButton show = new JButton("显示聊天记录");
    //public static String show = "";
    public static String msg1;
    public static String msg2;
    public static String msg3 = "";
    public static String name;
    public static String groupname;
    public ChatAll(String groupname,String name) {
        this.groupname = groupname;
        this.name = name;
        Font font1 = new Font("Serief",Font.PLAIN,24);
        Font font2 = new Font("Serief",Font.PLAIN,16);
        Font font3 = new Font("Serief",Font.PLAIN,28);
        frame.setLayout(null);
        pan1 = new JPanel();
        pan2 = new JPanel();
        pan3 = new JPanel();
        pan1.setLayout(null);
        pan2.setLayout(null);
        split1 = new JSplitPane(JSplitPane.VERTICAL_SPLIT,pan1,pan2);
        split1.setBounds(0,20,770,750);
        split1.setDividerLocation(525);
        split1.setDividerSize(8);
        split1.setOneTouchExpandable(true);
        split2 = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,split1,pan3);
        split2.setBounds(770,20,200,750);
        split2.setDividerLocation(770);
        split2.setDividerSize(8);
        split2.setOneTouchExpandable(true);
        text1 = new JTextArea();
        text1.setBounds(0,0,770,525);
        text1.setFont(font3);
        //text1.setEnabled(false);
        text2 = new JTextArea();
        text2.setBounds(0,0,770,135);
        text2.setFont(font1);
        send = new JButton("发送");
        send.setFont(font2);
        send.setBounds(660,140,70,28);
        close = new JButton("关闭");
        close.setFont(font2);
        close.setBounds(555,140,70,28);
        show.setBounds(330,0,120,20);
        pan1.add(text1);
        pan2.add(text2);
        pan2.add(send);
        pan2.add(close);
        cont.add(split1);
        cont.add(split2);
        frame.add(show);
        send.addActionListener(this);
        close.addActionListener(this);
        show.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setTitle(groupname+"("+name+")");
        frame.setSize(970,770);
        frame.setLocation(400,150);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == close) {
            frame.setVisible(false);
        } else if(e.getSource() == send) {
            ChatAll.msg3 = "";
            ChatAll.text1.setText(Chat.msg3);
            ChatAll.msg1 = text2.getText();
            ChatAll.msg2 = "all,"+name+","+text2.getText();
            new SaveGroupRecord(groupname,name,msg1);
            text2.setText("");
        } else if(e.getSource() == show) {
            ChatAll.msg3 = "";
            try {
                Connection conn = null;
                PreparedStatement pstmt = null;
                ResultSet rs = null;
                String sql = "select groupname,send,content from grouprecord where groupname=?";
                Class.forName(DBDRIVER);
                conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1,groupname);
                rs = pstmt.executeQuery();
                while (rs.next()) {
                    String tsend = rs.getString("send");
                    String tcontent = rs.getString("content");
                    System.out.println(tsend+":"+tcontent);
                    if(tsend.equals(name)) {
                        ChatAll.msg3 = ChatAll.msg3 + "                                                                                 " + tsend + ":" + tcontent + "\n";
                        System.out.println(ChatAll.msg3);
                        ChatAll.text1.setText(ChatAll.msg3);
                    } else {
                        ChatAll.msg3 = ChatAll.msg3 + tsend + ":" + tcontent + "\n";
                        System.out.println(ChatAll.msg3);
                        ChatAll.text1.setText(ChatAll.msg3);
                    }
                }
                rs.close();
                pstmt.close();
                conn.close();
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        new ChatAll("we","1c");
    }
}
