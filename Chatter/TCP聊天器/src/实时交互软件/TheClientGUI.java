package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class TheClientGUI extends Thread implements ActionListener {
    private JFrame frame = new JFrame("客户端");
    private Icon icon;
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private Font font3 = new Font("Serief",Font.PLAIN,13);
    private JButton headiconn;
    private Container cont = frame.getContentPane();
    private JTabbedPane tab = new JTabbedPane(JTabbedPane.TOP);
    private JTextField searchText = new JTextField();
    private JTextField signText = new JTextField();
    private JButton searchLab = new JButton("搜索");
    private JButton[] friend = new JButton[10];
    private JLabel[] friendLab = new JLabel[10];
    private JLabel nameLab;
    private JLabel signLab = new JLabel("sign:");
    private JPanel pan1 = new JPanel();
    private JPanel pan2 = new JPanel();
    private JPanel pan3 = new JPanel();
    private String name;
    private static String account;
    private String password;
    private String sex;
    private String birthday;
    private String place;
    private String question1;
    private String question2;
    private String question3;
    private String sign;
    private String headicon;
    public TheClientGUI(String name,String account,String password,String sex,String birthday,String place,
                     String question1,String question2,String question3,String sign,String headicon) {
        this.name = name;
        this.account = account;
        this.password = password;
        this.sex = sex;
        this.birthday = birthday;
        this.place = place;
        this.question1 = question1;
        this.question2 = question2;
        this.question3 = question3;
        this.sign = sign;
        this.headicon = headicon;
    }
    public void run() {
        frame.setLayout(null);
        pan1.setLayout(null);
        pan2.setLayout(null);
        pan3.setLayout(null);
        icon = new ImageIcon(headicon);
        headiconn = new JButton(icon);
        nameLab = new JLabel(name);
        FindFriendByAccount ffba = new FindFriendByAccount(account);
        int y = 30;
        for(int i=0;i<ffba.friendNum;i++) {
            Icon friendIcon = new ImageIcon(ffba.iconList[i]);
            friend[i] = new JButton(friendIcon);
            friend[i].setBounds(10,y,60,60);
            friend[i].addActionListener(this);
            friendLab[i] = new JLabel(ffba.friensList[i]);
            friendLab[i].setBounds(80,y,100,40);
            pan2.add(friendLab[i]);
            pan2.add(friend[i]);
            y+=70;
        }
        tab.setFont(font1);
        searchText.setFont(font2);
        searchLab.setFont(font3);
        nameLab.setFont(font2);
        signLab.setFont(font2);
        signText.setFont(font2);
        tab.addTab("     消息    ",pan1);
        tab.addTab("    联系人    ",pan2);
        tab.addTab("     动态    ",pan3);
        headiconn.setBounds(30,30,60,60);
        tab.setBounds(0,160,400,710);
        searchText.setBounds(60,130,380,30);
        searchLab.setBounds(0,130,60,30);
        nameLab.setBounds(125,20,100,30);
        signLab.setBounds(120,55,40,30);
        signText.setText(sign);
        signText.setBounds(160,55,120,30);
        frame.add(headiconn);
        frame.add(searchText);
        frame.add(searchLab);
        frame.add(nameLab);
        frame.add(signLab);
        frame.add(signText);
        cont.add(tab);
        headiconn.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.setSize(380,860);
        frame.setLocation(500,100);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==headiconn) {
            new DisplayInformation(name,account,password,sex,birthday,place,question1,question2,question3,
                    sign,headicon);
        } else {
            FindFriendByAccount ffba = new FindFriendByAccount(account);
            for(int i=0;i<ffba.friendNum;i++) {
                if(e.getSource() == friend[i]) {
                    FindByAccount fb = new FindByAccount(ffba.friensList[i]);
                    new DisplayInformation(fb.name,fb.account,fb.password,fb.sex,fb.birthday,fb.place,fb.question1,
                            fb.question2,fb.question3,fb.sign,fb.headicon);
                }
            }
        }
    }
}
