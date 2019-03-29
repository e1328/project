package TCP通信;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class MultiUser extends Thread {
    private Socket socket;
    public MultiUser(Socket socket) {
        System.out.println("一个客户端已连接！");
        this.socket = socket;
    }
    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream out = new PrintStream(socket.getOutputStream());
            while(true) {
                String str = in.readLine();
                System.out.println("客户端发送过来的消息："+str);
                out.println("has receive...");
                out.flush();
                if(str.equals("end")) {
                    break;
                }
                //new Send1(socket).start();
                //new Client_Receive(socket).start();
            }
            //socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(5678);
        while(true) {
            System.out.println("等待客户端连接...");
            MultiUser mu = new MultiUser(server.accept());
            mu.start();
        }
    }
}
