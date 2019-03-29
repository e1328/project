package 实时交互软件;

import java.io.*;
import java.util.List;

public class ServerThread extends Thread {
    public OutputStream out1;
    private User user;
    private List<User> list;
    public ServerThread(User user,List<User> list) {
        this.user = user;
        this.list = list;
    }
    public void run() {
        try {
            while(true) {
                String msg = user.getBr().readLine();
                System.out.println(msg);
                String[] str = msg.split(",");
                switch (str[0]) {
                    case "logout":
                        Server.msg = Server.msg+user.getName()+"("+user.getAccount()+")下线\n";
                        Server.text.setText(Server.msg);
                        remove(user);
                        user.getSocket().close();
                        break;
                    case "say":
                        Server.msg = Server.msg+str[2]+"对"+str[1]+"说："+str[3]+"\n";
                        Server.text.setText(Server.msg);
                        sendToClient(str[1],msg);
                        break;
                    case "all":
                        Server.msg = Server.msg+str[1]+"说："+str[2]+"\n";
                        Server.text.setText(Server.msg);
                        sendToAllClient(str[1],msg);
                        break;
                    case "file":
                        sendFileToClient(str[1],str[2],str[3]);
                        break;
                    default:
                        break;
                }
            }
        } catch (Exception e) {
            System.out.println(user.getName()+"("+user.getAccount()+")"+"下线");
        } finally {
            try {
                user.getBr().close();
                user.getSocket().close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    public void sendToClient(String username,String msg) {
        for(User user : list) {
            if(user.getName().equals(username)) {
                try {
                    PrintWriter out = user.getPw();
                    out.println(msg);
                    out.flush();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    public void sendToAllClient(String sender,String msg) {
        for(User user : list) {
            if(!sender.equals(user.getName())) {
                try {
                    PrintWriter out = user.getPw();
                    out.println(msg);
                    out.flush();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    public void sendFileToClient(String sender,String receiver,String str) {
        for(User user : list) {
            try {
                if (user.getName().equals(receiver)) {
                    out1 = user.getSocket().getOutputStream();
                    PrintWriter pw = user.getPw();
                    pw.println("ok");
                    pw.flush();
                    break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        for(User user : list) {
            if(user.getName().equals(sender)) {
                try {
                    System.out.println("服务器接收并发送开始");
                    InputStream in = user.getSocket().getInputStream();
                    OutputStream out2 = out1;
                    int len=0;
                    byte[] bytes = new byte[1024];
                    while((len=in.read(bytes))!=-1) {
                        out2.write(bytes,0,len);
                    }
                    System.out.println("服务器接收并发送接收");
                    user.getSocket().shutdownOutput();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    public void remove(User user) {
        list.remove(user);
    }
}
