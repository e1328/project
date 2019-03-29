package 实时交互软件;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class User1 {
    private String name;
    //private String account;
    private Socket socket;
    private BufferedReader br;
    private PrintWriter pw;
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    /*public String getAccount() {
        return account;
    }
    public void setAccount(String account) {
        this.account = account;
    }*/
    public Socket getSocket() {
        return socket;
    }
    public void setSocket(Socket socket) {
        this.socket = socket;
    }
    public BufferedReader getBr() {
        return br;
    }
    public void setBr(BufferedReader br) {
        this.br = br;
    }
    public PrintWriter getPw() {
        return pw;
    }
    public void setPw(PrintWriter pw) {
        this.pw = pw;
    }
    public User1(String name, Socket socket) throws Exception {
        this.name = name;
        this.socket = socket;
        this.br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.pw = new PrintWriter(socket.getOutputStream());
    }
    public String toString() {
        return "User[name:"+name+",socket:"+socket+"]";
    }
}
