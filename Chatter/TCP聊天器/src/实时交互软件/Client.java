package 实时交互软件;

import java.io.*;
import java.net.Socket;

public class Client extends Thread {
    private Socket socket;
    public Client(Socket socket) {
        this.socket = socket;
    }
    public void run() {
        try {
            //Socket socket = new Socket("127.0.0.1",8888);
            System.out.println("已经连上服务器...");
            ClientThread thread = new ClientThread(socket);
            thread.start();
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(socket.getOutputStream());
            //out.println(account);
            //out.flush();
            while (true) {
                System.out.println();
                if(Chat.msg1!=null) {
                    System.out.println(Chat.msg2);
                    out.println(Chat.msg2);
                    out.flush();
                    Chat.text1.append("                                                                                 "+Chat.name1+":"+Chat.msg1+"\n");
                    Chat.msg1 = null;
                }
                if(ChatAll.msg1!=null) {
                    System.out.println(ChatAll.msg2);
                    out.println(ChatAll.msg2);
                    out.flush();
                    ChatAll.text1.append("                                                                                 "+ChatAll.name+":"+ChatAll.msg1+"\n");
                    ChatAll.msg1 = null;
                }
                if(ModifyUser.msg!=null || ModifyPassword.msg!=null || MainInterface.msg!=null) {
                    System.out.println();
                    out.println("logout");
                    out.flush();
                    ModifyUser.msg = null;
                    ModifyPassword.msg = null;
                    MainInterface.msg = null;
                }
                if(FileChoose.str!=null) {
                    System.out.println();
                    out.println(FileChoose.str);
                    out.flush();
                    String msg[] = FileChoose.str.split(",");
                    OutputStream out1 = socket.getOutputStream();
                    InputStream in1 = new FileInputStream(new File(msg[3]));
                    out.println("客户端发送开始");
                    int len=0;
                    byte[] bytes = new byte[1024];
                    while((len=in1.read(bytes))!=-1) {
                        out1.write(bytes,0,len);
                    }
                    out.println("客户端发送结束");
                    socket.shutdownOutput();
                    FileChoose.str = null;
                }
            }
        } catch (Exception e) {
            //System.out.println("服务器异常");
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        //new Client("12");
    }
}
