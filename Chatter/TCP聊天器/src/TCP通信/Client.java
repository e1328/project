package TCP通信;

import java.io.*;
import java.net.Socket;

class Client_Send extends Thread {
    private PrintStream out = null;
    private BufferedReader wt = null;
    private Socket socket;
    public Client_Send(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try {
            out = new PrintStream(socket.getOutputStream());
            wt = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("请输入要发送的信息：");
            String str = wt.readLine();
            out.println(str);
            out.flush();
                /*if(str.equals("end")) {
                    break;
                }*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Client_Receive extends Thread {
    private BufferedReader in = null;
    private Socket socket;
    public Client_Receive(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String str = in.readLine();
            System.out.println(str);
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

public class Client {
    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("127.0.0.1",5678);
        System.out.println("已连接服务器！");
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        //PrintStream out = new PrintStream(socket.getOutputStream());
        //BufferedReader wt = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            /*System.out.print("请输入要发送的信息：");
            String str = wt.readLine();
            out.println(str);
            out.flush();
            if(str.equals("end")) {
                break;
            }*/
            new Client_Send(socket).start();
            System.out.println(in.readLine());
            //new Client_Receive(socket).start();
        }
        //socket.close();
    }
}
