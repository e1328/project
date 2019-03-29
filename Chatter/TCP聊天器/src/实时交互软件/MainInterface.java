package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MainInterface extends Thread implements ActionListener {
    private JFrame frame = new JFrame("QQ2018");
    private Icon icon;
    private Icon refreshIcon = new ImageIcon("K:\\icon\\refresh.png");
    private Icon deleteIcon = new ImageIcon("K:\\icon\\delete1.png");
    private Font font1 = new Font("Serief",Font.PLAIN,17);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private Font font3 = new Font("Serief",Font.PLAIN,13);
    private Font font4 = new Font("Serief",Font.PLAIN,18);
    private Font font5 = new Font("Serief",Font.PLAIN,10);
    private JButton headiconn;
    private Container cont = frame.getContentPane();
    private JTabbedPane tab = new JTabbedPane(JTabbedPane.TOP);
    private JTextField searchText = new JTextField();
    private JTextField signText = new JTextField();
    private JButton searchLab = new JButton("搜索");
    private JButton refresh = new JButton(refreshIcon);
    private JButton[] friend = new JButton[10];
    private JLabel[] friendName = new JLabel[10];
    private JLabel[] friendLab = new JLabel[10];
    private JButton[] send = new JButton[10];
    private JButton[] delFriend = new JButton[10];
    private JButton[] delGroup = new JButton[10];
    private JLabel nameLab;
    private JLabel signLab = new JLabel("sign:");
    private JButton addFriend = new JButton("+");
    private JButton addGroup = new JButton("+");
    private JButton modifypass = new JButton("修改密码");
    private JButton modifyuser = new JButton("修改信息");
    private JPanel pan1 = new JPanel();
    private JPanel pan2 = new JPanel();
    private JLabel groupLab[] = new JLabel[10];
    private JButton createGroup = new JButton("创建群聊");
    private JButton group[] = new JButton[10];
    private String name;
    private String account;
    private String password;
    private String sex;
    private String birthday;
    private String place;
    private String question1;
    private String question2;
    private String question3;
    private String sign;
    private String headicon;
    public static String msg;
    public MainInterface(String name,String account,String password,String sex,String birthday,String place,
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
        pan1.add(addFriend);
        pan2.add(addGroup);
        pan2.add(createGroup);
        icon = new ImageIcon(headicon);
        headiconn = new JButton(icon);
        nameLab = new JLabel(name);
        FindFriendByAccount ffba = new FindFriendByAccount(account);
        int y = 15;
        for(int i=0;i<ffba.friendNum;i++) {
            Icon friendIcon = new ImageIcon(ffba.iconList[i]);
            friend[i] = new JButton(friendIcon);
            friend[i].setBounds(10,y,45,45);
            friend[i].addActionListener(this);
            friendLab[i] = new JLabel("("+ffba.friensList[i]+")");
            friendLab[i].setBounds(100,y,100,40);
            friendLab[i].setFont(font1);
            send[i] = new JButton("发消息");
            send[i].setBounds(275,y,80,30);
            send[i].setFont(font3);
            send[i].addActionListener(this);
            friendName[i] = new JLabel(ffba.friendName[i]);
            friendName[i].setBounds(75,y,35,40);
            friendName[i].setFont(font1);
            delFriend[i] = new JButton(deleteIcon);
            delFriend[i].setBounds(200,y+5,20,20);
            delFriend[i].addActionListener(this);
            pan1.add(friendLab[i]);
            pan1.add(friend[i]);
            pan1.add(send[i]);
            pan1.add(friendName[i]);
            pan1.add(delFriend[i]);
            y+=55;
        }
        FindGroupByAccount fgba = new FindGroupByAccount(account);
        int y1 = 10;
        for(int i=0;i<fgba.groupNum;i++) {
            groupLab[i] = new JLabel(fgba.groupName[i]);
            groupLab[i].setFont(font4);
            groupLab[i].setBounds(10,y1,120,40);
            group[i] = new JButton("进入群聊");
            group[i].setFont(font3);
            group[i].setBounds(250,y1,120,30);
            group[i].addActionListener(this);
            delGroup[i] = new JButton(deleteIcon);
            delGroup[i].setBounds(200,y1+5,20,20);
            delGroup[i].addActionListener(this);
            pan2.add(groupLab[i]);
            pan2.add(group[i]);
            pan2.add(delGroup[i]);
            y1+=45;
        }
        tab.setFont(font1);
        searchText.setFont(font2);
        searchLab.setFont(font3);
        refresh.setFont(font3);
        nameLab.setFont(font2);
        signLab.setFont(font2);
        signText.setFont(font2);
        addFriend.setFont(font2);
        addGroup.setFont(font2);
        createGroup.setFont(font3);
        modifypass.setFont(font3);
        modifyuser.setFont(font3);
        tab.addTab("我的好友",pan1);
        tab.addTab("我的群聊",pan2);
        headiconn.setBounds(30,30,60,60);
        tab.setBounds(0,150,380,710);
        modifypass.setBounds(181,150,90,28);
        modifyuser.setBounds(271,150,90,28);
        addFriend.setBounds(310,598,52,32);
        addGroup.setBounds(310,598,52,32);
        searchText.setBounds(60,120,380,30);
        searchLab.setBounds(0,120,60,30);
        nameLab.setBounds(125,20,100,30);
        signLab.setBounds(120,55,40,30);
        signText.setText(sign);
        signText.setBounds(160,55,120,30);
        refresh.setBounds(335,0,25,25);
        createGroup.setBounds(0,598,100,32);
        frame.add(headiconn);
        frame.add(searchText);
        frame.add(searchLab);
        frame.add(nameLab);
        frame.add(signLab);
        frame.add(signText);
        frame.add(refresh);
        frame.add(modifypass);
        frame.add(modifyuser);
        cont.add(tab);
        headiconn.addActionListener(this);
        addFriend.addActionListener(this);
        addGroup.addActionListener(this);
        createGroup.addActionListener(this);
        refresh.addActionListener(this);
        modifypass.addActionListener(this);
        modifyuser.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                //frame.setVisible(false);
                msg = "success";
                System.exit(1);
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
        } else if(e.getSource() == addFriend) {
            new AddFriend(account);
        } else if(e.getSource() == addGroup ) {
            new AddGroup(account);
        } else if(e.getSource() == createGroup) {
            new CreateGroup(account);
        } else if(e.getSource() == modifypass) {
            new ModifyPassword(account);
        } else if(e.getSource() == modifyuser) {
            new ModifyUser(account);
        }else if(e.getSource() == refresh) {
            frame.setVisible(false);
            MainInterface mainInterface = new MainInterface(name,account,password,sex,birthday,place,question1,question2,question3,sign,headicon);
            new Thread(mainInterface).start();
        } else{
            FindFriendByAccount ffba = new FindFriendByAccount(account);
            for(int i=0;i<ffba.friendNum;i++) {
                if(e.getSource() == send[i]) {
                    FindByAccount fb = new FindByAccount(ffba.friensList[i]);
                    new Chat(name,fb.name);
                } else if(e.getSource() == friend[i]) {
                    FindByAccount fb = new FindByAccount(ffba.friensList[i]);
                    new DisplayInformation(fb.name,fb.account,fb.password,fb.sex,fb.birthday,fb.place,fb.question1,
                            fb.question2,fb.question3,fb.sign,fb.headicon);
                } else if(e.getSource() == delFriend[i]) {
                    FindByAccount fb = new FindByAccount(ffba.friensList[i]);
                    System.out.println("del");
                    new DeleteFriend(account,fb.account);
                }
            }
            FindGroupByAccount fgba = new FindGroupByAccount(account);
            for(int i=0;i<fgba.groupNum;i++) {
                if(e.getSource() == group[i]) {
                    new ChatAll(fgba.groupName[i],name);
                } else if(e.getSource() == delGroup[i]) {
                    new DeleteGroup(fgba.groupName[i],account);
                }
            }
        }
    }
    public static void main(String[] args) {
        MainInterface t1 = new MainInterface("123","123","2","1","12","23","1","2","3","2","1");
        t1.start();
    }
}
