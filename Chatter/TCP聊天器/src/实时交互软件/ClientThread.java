package 实时交互软件;

import java.io.*;
import java.net.Socket;
import java.util.Random;

public class ClientThread extends Thread {
    private Socket socket;
    public ClientThread(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String str1 = in.readLine();
            if(str1.equals("ok")) {
                PrintWriter pw = new PrintWriter(socket.getOutputStream());
                //pw.println("start");
                //pw.flush();
                InputStream fis = socket.getInputStream();
                File upload = new File("E:\\upload");
                if(! upload.exists()){
                    upload.mkdirs();
                }
                String filename="receive.docs";
                FileOutputStream fos = new FileOutputStream(upload+File.separator+filename);
                byte[] bytes = new byte[1024];
                int len = 0;
                pw.println("另外一个客户端接收开始");
                while((len = fis.read(bytes)) != -1){
                    fos.write(bytes,0,len);
                }
                pw.println("另外一个客户端接收接收");
                //pw.println("over");
                pw.flush();
            }
            try {
                while(true) {
                    String msg = in.readLine();
                    System.out.println(msg);
                    String[] str = msg.split(",");
                    switch (str[0]) {
                        case "say":
                            System.out.println(str[2]+"对"+str[1]+"说："+str[3]);
                            Chat.text1.append(Chat.name2+":"+str[3]+"\n");
                            break;
                        case "all":
                            System.out.println(str[1]+"说："+str[2]);
                            ChatAll.text1.append(str[1]+":"+str[2]+"\n");
                            break;
                        default:
                            break;
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
