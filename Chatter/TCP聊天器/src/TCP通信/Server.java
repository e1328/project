package TCP通信;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket(5678);
        Socket client = server.accept();
        BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
        PrintStream out = new PrintStream(client.getOutputStream());
        while(true) {
            String str = in.readLine();
            System.out.println(str);
            out.println("has receive...");
            out.flush();
            if(str.equals("end")) {
                break;
            }
        }
        client.close();
        server.close();
    }
}
