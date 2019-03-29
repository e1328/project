package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Login implements ActionListener {
    private JFrame frame = new JFrame("Login");
    private Icon icon = new ImageIcon("K:\\icon\\bk.png");
    private Font font1 = new Font("Serief",Font.PLAIN,12);
    private Font font2 = new Font("Serief",Font.PLAIN,15);
    private Font font3 = new Font("Serief",Font.PLAIN,20);
    private Font font4 = new Font("Serief",Font.PLAIN,18);
    private JButton submit = new JButton("登录");
    private JButton register = new JButton("注册账号");
    private JButton retrieve = new JButton("找回密码");
    private JLabel accountLab = new JLabel("账号");
    private JLabel passLab = new JLabel("密码");
    private JLabel bk = new JLabel(icon);
    private JCheckBox jcb1 = new JCheckBox("自动登录");
    private JCheckBox jcb2 = new JCheckBox("记住密码");
    private JTextField nameText = new JTextField();
    private JPasswordField passText = new JPasswordField();
    public Login() {
        frame.setLayout(null);
        accountLab.setFont(font4);
        passLab.setFont(font4);
        nameText.setFont(font4);
        passText.setFont(font4);
        submit.setFont(font3);
        register.setFont(font1);
        jcb1.setFont(font2);
        jcb2.setFont(font2);
        retrieve.setFont(font1);
        accountLab.setBounds(80,140,50,40);
        passLab.setBounds(80,180,50,40);
        nameText.setBounds(140,140,300,40);
        passText.setBounds(140,180,300,40);
        submit.setBounds(140,280,290,45);
        register.setBounds(13,335,90,26);
        jcb1.setBounds(140,240,90,26);
        jcb2.setBounds(240,240,90,26);
        retrieve.setBounds(340,240,90,26);
        bk.setBounds(0,0,550,110);
        submit.addActionListener(this);
        register.addActionListener(this);
        retrieve.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent arg0) {
                frame.setVisible(false);
            }
        });
        frame.add(accountLab);
        frame.add(passLab);
        frame.add(nameText);
        frame.add(passText);
        frame.add(submit);
        frame.add(register);
        frame.add(jcb1);
        frame.add(jcb2);
        frame.add(retrieve);
        frame.add(bk);
        frame.setSize(550,420);
        frame.setLocation(600,340);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == register) {
            new Register();
        } else if(e.getSource() == retrieve) {
            new Retrieve();
        }
        else if (e.getSource() == submit) {
            try {
                String account = nameText.getText();
                String password = new String(passText.getPassword());
                LoginCheck log = new LoginCheck(account, password);
                if (log.validate()) {
                    Socket socket = new Socket("127.0.0.1", 8888);
                    PrintWriter out = new PrintWriter(socket.getOutputStream());
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    out.println("login,"+account);
                    out.flush();
                    String str = in.readLine();
                    if("yes".equals(str)) {
                        frame.setVisible(false);
                        FindByAccount fba = new FindByAccount(account);
                        new Client(socket);
                        Client thread1 = new Client(socket);
                        MainInterface thread2 = new MainInterface(fba.name, fba.account, fba.password, fba.sex, fba.birthday,
                                fba.place, fba.question1, fba.question2, fba.question3, fba.sign, fba.headicon);
                        thread1.start();
                        thread2.start();
                    } else {
                        new LoginRepeat();
                    }
                } else {
                    new LoginFail();
                }
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        new Login();
    }
}
