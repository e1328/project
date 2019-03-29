package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class Register implements ItemListener,ActionListener {
    private JFrame frame = new JFrame("Register");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private Font font3 = new Font("Serief",Font.PLAIN,22);
    private Font font4 = new Font("Serief",Font.ITALIC,30);
    private Font font5 = new Font("Serief",Font.ITALIC,12);
    private Icon icon = new ImageIcon("K:\\icon\\bk.png");
    private JLabel nameLab = new JLabel("       昵称");
    private JLabel pass1Lab = new JLabel("       密码");
    private JLabel pass2Lab = new JLabel("确认密码");
    private JLabel sexLab = new JLabel("       性别");
    private JLabel dateLab = new JLabel("       生日");
    private JLabel placeLab = new JLabel("   所在地");
    private JLabel code = new JLabel("   验证码");
    private JLabel bk = new JLabel(icon);
    private JLabel signLab = new JLabel("个性签名");
    private JLabel questionLab = new JLabel("密保问题");
    private JLabel answerLab = new JLabel("密保答案");
    private JButton refresh = new JButton("换一张");
    private JButton register = new JButton("立即注册");
    private JTextField nameText = new JTextField();
    private JPasswordField pass1Text = new JPasswordField();
    private JPasswordField pass2Text = new JPasswordField();
    private JTextField code1Text = new JTextField();
    private JTextField code2Text = new JTextField();
    private JTextField signText = new JTextField();
    private JTextField answerText = new JTextField();
    private JRadioButton jrb1 = new JRadioButton("男");
    private JRadioButton jrb2 = new JRadioButton("女");
    private ButtonGroup group = new ButtonGroup();
    private JComboBox yearjcb;
    private JComboBox monthjcb;
    private JComboBox dayjcb;
    private JComboBox placejcb;
    private JComboBox questionjcb;
    private String tname;
    private String taccount;
    private String tpass1;
    private String tpass2;
    private String tsex;
    private String tyear;
    private String tmonth;
    private String tday;
    private String tplace;
    private String tquestion1;
    private String tquestion2;
    private String tquestion3;
    private String tsign;
    private String tcode1;
    private String tcode2;
    private String theadicon;
    public Register() {
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
        String str = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm";
        String[] question = new String[4];
        question[0] = "";
        question[1] = "您的学号是？";
        question[2] = "您的姓名是？";
        question[3] = "您的生日是？";
        tcode2 = "";
        for(int i=0;i<4;i++) {
            tcode2 = tcode2 + str.charAt(new Random().nextInt(62));
        }
        frame.setLayout(null);
        nameLab.setFont(font1);
        nameText.setFont(font1);
        pass1Lab.setFont(font1);
        pass1Text.setFont(font1);
        pass2Lab.setFont(font1);
        pass2Text.setFont(font1);
        sexLab.setFont(font1);
        jrb1.setFont(font2);
        jrb2.setFont(font2);
        dateLab.setFont(font1);
        placeLab.setFont(font1);
        questionLab.setFont(font1);
        answerLab.setFont(font1);
        answerText.setFont(font1);
        signLab.setFont(font1);
        signText.setFont(font1);
        code.setFont(font1);
        code1Text.setFont(font4);
        code2Text.setText(tcode2);
        code2Text.setFont(font4);
        register.setFont(font3);
        refresh.setFont(font5);
        nameLab.setBounds(90,120,120,40);
        nameText.setBounds(190,120,300,40);
        pass1Lab.setBounds(90,180,120,40);
        pass1Text.setBounds(190,180,300,40);
        pass2Lab.setBounds(90,240,120,40);
        pass2Text.setBounds(190,240,300,40);
        sexLab.setBounds(90,300,120,40);
        jrb1.setBounds(220,300,80,40);
        jrb2.setBounds(300,300,80,40);
        dateLab.setBounds(90,360,120,40);
        yearjcb = new JComboBox(year);
        yearjcb.setBounds(190,360,120,50);
        yearjcb.setBorder(BorderFactory.createTitledBorder("年"));
        yearjcb.setMaximumRowCount(5);
        monthjcb = new JComboBox(month);
        monthjcb.setBounds(320,360,80,50);
        monthjcb.setBorder(BorderFactory.createTitledBorder("月"));
        monthjcb.setMaximumRowCount(5);
        dayjcb = new JComboBox(day);
        dayjcb.setBounds(410,360,80,50);
        dayjcb.setBorder(BorderFactory.createTitledBorder("日"));
        dayjcb.setMaximumRowCount(5);
        placeLab.setBounds(90,420,120,40);
        placejcb = new JComboBox(place);
        placejcb.setBounds(190,420,90,50);
        placejcb.setBorder(BorderFactory.createTitledBorder("地区"));
        placejcb.setMaximumRowCount(5);
        questionLab.setBounds(90,490,120,40);
        questionjcb = new JComboBox(question);
        questionjcb.setBorder(BorderFactory.createTitledBorder("请选择一个问题"));
        questionjcb.setBounds(190,480,160,60);
        answerLab.setBounds(90,560,120,40);
        answerText.setBounds(190,560,300,40);
        signLab.setBounds(90,630,300,40);
        signText.setBounds(190,630,300,40);
        code.setBounds(90,700,120,40);
        code1Text.setBounds(200,700,140,60);
        code2Text.setEnabled(false);
        code2Text.setBounds(340,700,140,60);
        refresh.setBounds(490,720,80,28);
        register.setBounds(240,790,160,60);
        bk.setBounds(0,0,620,100);
        jrb1.addItemListener(this);
        jrb2.addItemListener(this);
        yearjcb.addItemListener(this);
        monthjcb.addItemListener(this);
        dayjcb.addItemListener(this);
        placejcb.addItemListener(this);
        questionjcb.addItemListener(this);
        register.addActionListener(this);
        refresh.addActionListener(this);
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
        frame.add(pass1Lab);
        frame.add(pass1Text);
        frame.add(pass2Lab);
        frame.add(pass2Text);
        frame.add(sexLab);
        frame.add(dateLab);
        frame.add(yearjcb);
        frame.add(monthjcb);
        frame.add(dayjcb);
        frame.add(placeLab);
        frame.add(placejcb);
        frame.add(questionLab);
        frame.add(questionjcb);
        frame.add(answerLab);
        frame.add(answerText);
        frame.add(signLab);
        frame.add(signText);
        frame.add(code);
        frame.add(code1Text);
        frame.add(code2Text);
        frame.add(register);
        frame.add(bk);
        frame.add(refresh);
        frame.setSize(620,940);
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
            } else if(e.getSource()==questionjcb) {
                String str = (String)e.getItem();
                if("您的学号是？".equals(str)) {
                    tquestion1 = "";
                    tquestion2 = "XXX";
                    tquestion3 = "XXX";
                    System.out.println(1);
                } else if("您的姓名是？".equals(str)) {
                    tquestion1 = "XXX";
                    tquestion2 = "";
                    tquestion3 = "XXX";
                } else if("您的生日是？".equals(str)) {
                    tquestion1 = "XXX";
                    tquestion2 = "XXX";
                    tquestion3 = "";
                }
            }
        }
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==register) {
            tname = nameText.getText();
            tpass1 = new String(pass1Text.getPassword());
            tpass2 = new String(pass2Text.getPassword());
            if(!tquestion1.equals("XXX")) {
                tquestion1 = answerText.getText();
            } else if(!tquestion2.equals("XXX")) {
                tquestion2 = answerText.getText();
            } else if(!tquestion3.equals("XXX")) {
                tquestion3 = answerText.getText();
            }
            tcode1 = code1Text.getText();
            tsign = signText.getText();
            int num = (int)(Math.random()*22);
            if(num < 10) {
                theadicon = "K:\\icon\\icon0" + num + ".png";
            } else {
                theadicon = "K:\\icon\\icon" + num + ".png";
            }
            if(tpass1.equals(tpass2)&&tcode1.equals(tcode2)) {
                taccount = createAccount();
                new RegisterSuccess(taccount);
                new InsertData(tname,taccount,tpass1,tsex,tyear+"-"+tmonth+"-"+tday,tplace,tquestion1,
                        tquestion2,tquestion3,tsign,theadicon);
                frame.setVisible(false);
            } else {
                new RegisterFail();
            }
        } else if(e.getSource() == refresh) {
            String str = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm";
            tcode2 = "";
            for(int i=0;i<4;i++) {
                tcode2 = tcode2 + str.charAt(new Random().nextInt(62));
            }
            code2Text.setText(tcode2);
        }
    }
    public static String createAccount() {
        String str1 = "1234567890";
        String str2 = "";
        char c;
        for(int i=0;i<8;i++) {
            c = str1.charAt((int)(Math.random()*10));
            if(c == '0') {
                c = '9';
            }
            str2 = str2 + c;
        }
        return str2;
    }
    public static void main(String[] args) {
        new Register();
    }
}
