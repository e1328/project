package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server extends Thread {
    public static String msg = "";
    public static JTextArea text = new JTextArea();
    public static void main(String[] args) throws Exception {
        JFrame frame = new JFrame("服务器");
        Font font1 = new Font("Serief",Font.PLAIN,23);
        Font font2 = new Font("Serief",Font.PLAIN,25);
        JLabel lab = new JLabel("服务器正在运行");
        frame.setLayout(null);
        text.setFont(font1);
        text.setBounds(0,50,800,540);
        lab.setFont(font1);
        lab.setBounds(300,0,200,50);
        frame.add(text);
        frame.add(lab);
        frame.setSize(800,600);
        frame.setLocation(400,200);
        frame.setVisible(true);
        List<User> socketList = new ArrayList<User>();
        ServerSocket serverSocket = new ServerSocket(8888);
        //System.out.println("-----服务器正在运行-----");
        while(true) {
            Socket socket = serverSocket.accept();
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream());
            String str = in.readLine();
            System.out.println(str);
            String str1[] = str.split(",");
            if (str1[0].equals("login")) {
                FindByAccount fba = new FindByAccount(str1[1]);
                User user = new User(fba.name, fba.account, fba.password, fba.sex, fba.birthday, fba.place, fba.question1,
                        fba.question2, fba.question3, fba.sign, fba.headicon, socket);
                boolean isLogin = true;
                for (User user1 : socketList) {
                    if (user1.getAccount().equals(user.getAccount())) {
                        isLogin = false;
                        socket.close();
                        msg = msg + user.getName() + "(" + user.getAccount() + ")" + "已经登录，不能重复登录\n";
                        text.setText(msg);
                        break;
                    }
                }
                if (isLogin) {
                    out.println("yes");
                    out.flush();
                    msg = msg + user.getName() + "(" + user.getAccount() + ")" + "上线\n";
                    text.setText(msg);
                    socketList.add(user);
                    ServerThread thread = new ServerThread(user, socketList);
                    thread.start();
                }
            }
        }
    }
}
