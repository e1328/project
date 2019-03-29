package TCP通信;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class Receive implements Runnable {
    private Socket socket;
    public Receive(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        InputStream in = null;
        try {
            in = socket.getInputStream();
            byte[] data = new byte[1024];
            int len = in.read(data);
            System.out.println(new String(data,0,len));
            in.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}
