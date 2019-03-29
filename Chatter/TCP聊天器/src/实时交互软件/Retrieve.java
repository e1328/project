package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Retrieve implements ItemListener, ActionListener {
    private JFrame frame = new JFrame("Retrieve");
    private Icon icon = new ImageIcon("K:\\bk.png");
    private Font font1 = new Font("Serief",Font.PLAIN,18);
    private Font font2 = new Font("Serief",Font.PLAIN,22);
    private JLabel bk = new JLabel(icon);
    private JLabel accountLab = new JLabel("填写账号");
    private JLabel questionLab = new JLabel("密保问题");
    private JLabel answerLab = new JLabel("密保答案");
    private JComboBox questionjcb;
    private JTextField accountText = new JTextField();
    private JTextField answerText = new JTextField();
    private JButton validate = new JButton("验证");
    private String taccount;
    private String tquestion1;
    private String tquestion2;
    private String tquestion3;
    public Retrieve() {
        String[] question = new String[4];
        question[0] = "";
        question[1] = "您的学号是？";
        question[2] = "您的姓名是？";
        question[3] = "您的生日是？";
        frame.setLayout(null);
        accountLab.setFont(font1);
        accountText.setFont(font1);
        questionLab.setFont(font1);
        answerLab.setFont(font1);
        answerText.setFont(font1);
        validate.setFont(font2);
        bk.setBounds(0,0,620,75);
        accountLab.setBounds(145,100,105,40);
        accountText.setBounds(245,100,205,40);
        questionLab.setBounds(145,155,105,40);
        questionjcb = new JComboBox(question);
        questionjcb.setBorder(BorderFactory.createTitledBorder("请选择一个问题"));
        questionjcb.setBounds(245,145,205,60);
        answerLab.setBounds(145,220,105,40);
        answerText.setBounds(245,220,205,40);
        validate.setBounds(195,290,220,48);
        questionjcb.addItemListener(this);
        validate.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.add(bk);
        frame.add(accountLab);
        frame.add(accountText);
        frame.add(questionLab);
        frame.add(questionjcb);
        frame.add(answerLab);
        frame.add(answerText);
        frame.add(validate);
        frame.setSize(620,420);
        frame.setLocation(540,260);
        frame.setVisible(true);
    }
    public void itemStateChanged(ItemEvent e) {
        if(e.getStateChange()==ItemEvent.SELECTED) {
            if(e.getSource() == questionjcb) {
                String str = (String)e.getItem();
                if("您的学号是？".equals(str)) {
                    tquestion1 = "";
                    tquestion2 = "XXX";
                    tquestion3 = "XXX";
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
        if(e.getSource() == validate) {
            taccount = accountText.getText();
            if(!tquestion1.equals("XXX")) {
                tquestion1 = answerText.getText();
            } else if(!tquestion2.equals("XXX")) {
                tquestion2 = answerText.getText();
            } else if(!tquestion3.equals("XXX")) {
                tquestion3 = answerText.getText();
            }
            RetrieveCheck rc = new RetrieveCheck(taccount,tquestion1,tquestion2,tquestion3);
            if(rc.validate()) {
                new RetrieveSuccess(rc.password);
                frame.setVisible(false);
            } else {
                new RetrieveFail();
            }
        }
    }
    public static void main(String[] args) {
        new Retrieve();
    }
}
