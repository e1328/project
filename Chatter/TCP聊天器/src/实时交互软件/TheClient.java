package 实时交互软件;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class TheClient {
    public TheClient(String name,String account,String password,String sex,String birthday,String place,
                         String question1,String question2,String question3,String sign,String headicon) {
        try {
            Socket socket = new Socket("127.0.0.1",8888);
            System.out.println("已经连上服务器...");
            ClientThread thread = new ClientThread(socket);
            thread.start();
            TheClientGUI thread1 = new TheClientGUI(name,account,password,sex,birthday,place,question1,
                    question2,question3,sign,headicon);
            thread1.start();
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(socket.getOutputStream());
            out.println(account);
            out.flush();
            while (true) {
                String str = in.readLine();
                out.println(str);
                out.flush();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) throws Exception {

    }
}
