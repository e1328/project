package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.text.SimpleDateFormat;

public class ModifyUser implements ItemListener,ActionListener {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private JFrame frame = new JFrame("ModifyUser");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private Font font3 = new Font("Serief",Font.PLAIN,22);
    private Font font4 = new Font("Serief",Font.ITALIC,30);
    private JLabel nameLab = new JLabel("       昵称");
    private JLabel sexLab = new JLabel("       性别");
    private JLabel dateLab = new JLabel("       生日");
    private JLabel placeLab = new JLabel("   所在地");
    private JLabel signLab = new JLabel("个性签名");
    private JTextField nameText = new JTextField();
    private JTextField signText = new JTextField();
    private JRadioButton jrb1 = new JRadioButton("男");
    private JRadioButton jrb2 = new JRadioButton("女");
    private JButton modify = new JButton("修改");
    private ButtonGroup group = new ButtonGroup();
    private JComboBox yearjcb;
    private JComboBox monthjcb;
    private JComboBox dayjcb;
    private JComboBox placejcb;
    private String tname;
    private String tsex;
    private String tyear;
    private String tmonth;
    private String tday;
    private String tplace;
    private String tsign;
    private String account;
    public static String msg;
    public ModifyUser(String account) {
        this.account = account;
        String[] year = new String[101];
        year[0] = "";
        for(int i=1;i<=100;i++) {
            year[i] = String.valueOf(2019-i);
        }
        String[] month = {"","1","2","3","4","5","6","7","8","9","10","11","12"};
        String[] day = new String[32];
        day[0] = "";
        for(int i=1;i<32;i++) {
            day[i] = String.valueOf(i);
        }
        String[] place = {"","北京","天津","河北","山西","内蒙古","辽宁","吉林","黑龙江","上海","江苏","浙江",
                "安徽","福建","江西","山东","河南","湖北","湖南","广东","广西","海南","重庆","四川",
                "贵州","云南","西藏","陕西","甘肃","青海","宁夏","新疆","台湾","香港","澳门"};
        frame.setLayout(null);
        nameLab.setFont(font1);
        nameText.setFont(font1);
        sexLab.setFont(font1);
        jrb1.setFont(font2);
        jrb2.setFont(font2);
        dateLab.setFont(font1);
        placeLab.setFont(font1);
        signLab.setFont(font1);
        signText.setFont(font1);
        modify.setFont(font3);
        nameLab.setBounds(90,35,120,40);
        nameText.setBounds(190,35,300,40);
        sexLab.setBounds(90,85,120,40);
        jrb1.setBounds(220,85,80,40);
        jrb2.setBounds(300,85,80,40);
        dateLab.setBounds(90,135,120,40);
        yearjcb = new JComboBox(year);
        yearjcb.setBounds(190,135,120,50);
        yearjcb.setBorder(BorderFactory.createTitledBorder("年"));
        yearjcb.setMaximumRowCount(5);
        monthjcb = new JComboBox(month);
        monthjcb.setBounds(320,135,80,50);
        monthjcb.setBorder(BorderFactory.createTitledBorder("月"));
        monthjcb.setMaximumRowCount(5);
        dayjcb = new JComboBox(day);
        dayjcb.setBounds(410,135,80,50);
        dayjcb.setBorder(BorderFactory.createTitledBorder("日"));
        dayjcb.setMaximumRowCount(5);
        placeLab.setBounds(90,200,120,40);
        placejcb = new JComboBox(place);
        placejcb.setBounds(190,200,90,50);
        placejcb.setBorder(BorderFactory.createTitledBorder("地区"));
        placejcb.setMaximumRowCount(5);
        signLab.setBounds(90,265,300,40);
        signText.setBounds(190,270,300,40);
        modify.setBounds(240,340,160,45);
        jrb1.addItemListener(this);
        jrb2.addItemListener(this);
        yearjcb.addItemListener(this);
        monthjcb.addItemListener(this);
        dayjcb.addItemListener(this);
        placejcb.addItemListener(this);
        modify.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        group.add(jrb1);
        group.add(jrb2);
        frame.add(jrb1);
        frame.add(jrb2);
        frame.add(nameLab);
        frame.add(nameText);
        frame.add(sexLab);
        frame.add(dateLab);
        frame.add(yearjcb);
        frame.add(monthjcb);
        frame.add(dayjcb);
        frame.add(placeLab);
        frame.add(placejcb);
        frame.add(signLab);
        frame.add(signText);
        frame.add(modify);
        frame.setSize(620,470);
        frame.setLocation(400,80);
        frame.setVisible(true);
    }
    public void itemStateChanged(ItemEvent e) {
        if(e.getSource()==jrb1) {
            tsex = "男";
        } else if(e.getSource()==jrb2) {
            tsex = "女";
        } else if(e.getStateChange()==ItemEvent.SELECTED) {
            if(e.getSource()==yearjcb) {
                String str = (String)e.getItem();
                tyear = str;
            } else if(e.getSource()==monthjcb) {
                String str = (String)e.getItem();
                tmonth = str;
            } else if(e.getSource()==dayjcb) {
                String str = (String)e.getItem();
                tday = str;
            } else if(e.getSource()==placejcb) {
                String str = (String)e.getItem();
                tplace = str;
            }
        }
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == modify) {
            tname = nameText.getText();
            tsign = signText.getText();
            try {
                msg = "success";
                Connection conn = null;
                PreparedStatement pstmt = null;
                java.util.Date temp = null;
                temp = new SimpleDateFormat("yyyy-MM-dd").parse(tyear+"-"+tmonth+"-"+tday);
                java.sql.Date bir = new java.sql.Date(temp.getTime());
                String sql = "update user set name=?,sex=?,birthday=?,place=?,sign=? where account=?";
                Class.forName(DBDRIVER);
                conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1,tname);
                pstmt.setString(2,tsex);
                pstmt.setDate(3,bir);
                pstmt.setString(4,tplace);
                pstmt.setString(5,tsign);
                pstmt.setString(6,account);
                pstmt.executeUpdate();
                pstmt.close();
                conn.close();
                frame.setVisible(false);
                new ModifyUserSuccess();
                ModifyThread mt = new ModifyThread();
                new Thread(mt).start();
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        new ModifyUser("123");
    }
}
