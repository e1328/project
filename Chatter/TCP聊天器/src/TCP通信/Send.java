package TCP通信;

import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Send implements Runnable {
    private Socket socket;
    private Scanner input;
    public Send(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        OutputStream out = null;
        try {
            out = socket.getOutputStream();
            input = new Scanner(System.in);
            String str = input.next();
            out.write(str.getBytes());
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
