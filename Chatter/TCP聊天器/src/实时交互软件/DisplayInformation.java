package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class DisplayInformation implements ActionListener {
    private JFrame frame = new JFrame("DisplayInformation");
    private Font font1 = new Font("Serief",Font.PLAIN,20);
    private Font font2 = new Font("Serief",Font.PLAIN,16);
    private Font font3 = new Font("Serief",Font.PLAIN,13);
    private Container cont = frame.getContentPane();
    private JTextField signText = new JTextField();
    private JSplitPane split;
    private JPanel pan1 = new JPanel();
    private JPanel pan2 = new JPanel();
    private JLabel iconLab;
    private JLabel nameLab;
    private JLabel signLab;
    private JLabel sexLab;
    private JLabel ageLab;
    private JLabel dateLab;
    private JLabel qqLab;
    private JLabel manLab;
    private JLabel accountLab;
    private JLabel placeLab;
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
    public DisplayInformation(String name,String account,String password,String sex,String birthday,String place,
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
        int year = (birthday.charAt(0)-48)*1000+(birthday.charAt(1)-48)*100+(birthday.charAt(2)-48)*10+(birthday.charAt(3)-48);
        int month = (birthday.charAt(5)-48)*10+birthday.charAt(6)-48;
        int day = (birthday.charAt(8)-48)*10+birthday.charAt(9)-48;
        frame.setLayout(null);
        pan1.setLayout(null);
        pan2.setLayout(null);
        split = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,pan1,pan2);
        split.setDividerLocation(455);
        split.setDividerSize(5);
        split.setBounds(0,0,910,655);
        Icon icon1 = new ImageIcon(headicon);
        Icon icon2 = new ImageIcon("K:\\icon\\qq.png");
        Icon icon3 = new ImageIcon("K:\\icon\\man.png");
        iconLab = new JLabel(icon1);
        iconLab.setBounds(120,430,60,60);
        nameLab = new JLabel(name);
        signLab = new JLabel("sign:");
        accountLab = new JLabel(account);
        qqLab = new JLabel(icon2);
        manLab = new JLabel(icon3);
        sexLab = new JLabel(sex);
        ageLab = new JLabel(2018-year+"岁");
        dateLab = new JLabel(month+"月"+day+"日");
        placeLab = new JLabel(place);
        nameLab.setFont(font2);
        signLab.setFont(font2);
        signText.setFont(font2);
        signText.setText(sign);
        accountLab.setFont(font2);
        sexLab.setFont(font2);
        ageLab.setFont(font2);
        dateLab.setFont(font2);
        placeLab.setFont(font2);
        nameLab.setBounds(200,430,60,30);
        signLab.setBounds(200,460,40,30);
        signText.setBounds(240,460,120,30);
        qqLab.setBounds(40,50,29,29);
        accountLab.setBounds(90,48,100,29);
        manLab.setBounds(40,100,29,29);
        sexLab.setBounds(90,100,80,29);
        ageLab.setBounds(120,100,80,29);
        dateLab.setBounds(170,100,80,29);
        placeLab.setBounds(250,100,80,29);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        pan1.add(iconLab);
        pan1.add(nameLab);
        pan1.add(signLab);
        pan1.add(signText);
        pan2.add(qqLab);
        pan2.add(accountLab);
        pan2.add(manLab);
        pan2.add(sexLab);
        pan2.add(ageLab);
        pan2.add(dateLab);
        pan2.add(placeLab);
        cont.add(split);
        frame.setSize(910,655);
        frame.setLocation(100,150);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
    }
    public static void main(String[] args) {
        new DisplayInformation("1","1","1","2","1998-10-23","3","54","3","54","12","21");
    }
}