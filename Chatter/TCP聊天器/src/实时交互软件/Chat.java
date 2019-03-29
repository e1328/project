package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Chat implements ActionListener {
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
    private JButton show = new JButton("显示聊天记录");
    public static JTextArea text1;
    public static JTextArea text2;
    private JButton send;
    private JButton close;
    private JButton sendFile;
    public static String msg1;
    public static String msg2;
    public static String msg3 = "";
    //public static File file;
    public static String name1;
    public static String name2;
    public Chat(String name1,String name2) {
        this.name1 = name1;
        this.name2 = name2;
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
        text2 = new JTextArea();
        text2.setBounds(0,0,770,135);
        text2.setFont(font1);
        sendFile = new JButton("发送文件");
        sendFile.setFont(font2);
        sendFile.setBounds(400,140,120,28);
        send = new JButton("发送");
        send.setFont(font2);
        send.setBounds(660,140,70,28);
        close = new JButton("关闭");
        close.setFont(font2);
        close.setBounds(555,140,70,28);
        show.setBounds(330,0,120,20);
        pan1.add(text1);
        frame.add(show);
        pan2.add(text2);
        pan2.add(sendFile);
        pan2.add(send);
        pan2.add(close);
        cont.add(split1);
        cont.add(split2);
        //cont.add(scr);
        show.addActionListener(this);
        sendFile.addActionListener(this);
        send.addActionListener(this);
        close.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setTitle(name1+"->"+name2);
        frame.setSize(970,770);
        frame.setLocation(400,150);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == close) {
            frame.setVisible(false);
        } else if(e.getSource() == send) {
            Chat.msg3 = "";
            Chat.text1.setText(Chat.msg3);
            Chat.msg1 = text2.getText();
            Chat.msg2 = "say,"+name2+","+name1+","+text2.getText();
            new SaveChatRecord(name1,name2,msg1);
            text2.setText("");
        } else if(e.getSource() == show) {
            //Chat.text1.setText(Chat.msg3);
            Chat.msg3 = "";
            try {
                Connection conn = null;
                PreparedStatement pstmt = null;
                ResultSet rs = null;
                String sql = "select send,receive,content from chatrecord";
                Class.forName(DBDRIVER);
                conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
                pstmt = conn.prepareStatement(sql);
                rs = pstmt.executeQuery();
                while (rs.next()) {
                    String tsend = rs.getString("send");
                    String treceive = rs.getString("receive");
                    String tcontent = rs.getString("content");
                    System.out.println(tsend+":"+treceive+":"+tcontent);
                    if(tsend.equals(name1)) {
                        Chat.msg3 = Chat.msg3 + "                                                                                 " + tsend + ":" + tcontent + "\n";
                        System.out.println(Chat.msg3);
                        Chat.text1.setText(Chat.msg3);
                    } else if(tsend.equals(name2)){
                        Chat.msg3 = Chat.msg3 + tsend + ":" + tcontent + "\n";
                        System.out.println(Chat.msg3);
                        Chat.text1.setText(Chat.msg3);
                    }
                }
                rs.close();
                pstmt.close();
                conn.close();
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        } else if(e.getSource() == sendFile) {
            new FileChoose(name1,name2);
        }
    }
    public static void main(String[] args) {
        new Chat("s","1c");
    }
}