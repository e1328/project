package 实时交互软件;

import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class TheServer extends JFrame {
    private JFrame frame = new JFrame("服务器");
    private Font font = new Font("Serief",Font.PLAIN,23);
    private static JTextArea text = new JTextArea();
    private static String msg = "";
    public TheServer() {
        frame.setLayout(null);
        text.setBounds(0,0,600,400);
        text.setFont(font);
        frame.add(text);
        frame.setSize(600,400);
        frame.setLocation(400,400);
        frame.setVisible(true);
    }
    public static void main(String[] args) throws Exception{
        TheServer theServer = new TheServer();
        List<User> socketList = new ArrayList<User>();
        ServerSocket serverSocket = new ServerSocket(8888);
        System.out.println("-----服务器正在运行-----");
        while(true) {
            Socket socket = serverSocket.accept();
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String str = in.readLine();
            System.out.println(str);
            FindByAccount fba = new FindByAccount(str);
            User user = new User(fba.name,fba.account,fba.password,fba.sex,fba.birthday,fba.place,fba.question1,
                    fba.question2,fba.question3,fba.sign,fba.headicon,socket);
            System.out.println(user.getName()+"正在登录...");
            msg = msg + user.getName()+"正在登录..." + "\n";
            text.setText(msg);
            socketList.add(user);
            ServerThread thread = new ServerThread(user,socketList);
            thread.start();
        }
    }
}
