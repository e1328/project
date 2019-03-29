package 实时交互软件;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class User {
    private String name;
    private String account;
    private String password;
    private String sex;
    private String birthday;
    private String place;
    private String question1;
    private String question2;
    private String question3;
    private String sign;
    private String headicon;
    private Socket socket;
    private BufferedReader br;
    private PrintWriter pw;
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getAccount() {
        return account;
    }
    public void setAccount(String account) {
        this.account = account;
    }
    public String getPassword() {
        return password;
    }
    public void setPassword(String password) {
        this.password = password;
    }
    public String getSex() {
        return sex;
    }
    public void setSex(String sex) {
        this.sex = sex;
    }
    public String getBirthday() {
        return birthday;
    }
    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }
    public String getPlace() {
        return place;
    }
    public void setPlace() {
        this.place = place;
    }
    public String getQuestion1() {
        return question1;
    }
    public void setQuestion1(String question1) {
        this.question1 = question1;
    }
    public String getQuestion2() {
        return question2;
    }
    public void setQuestion2(String question2) {
        this.question2 = question2;
    }
    public String getQuestion3() {
        return question3;
    }
    public void setQuestion3(String question3) {
        this.question3 = question3;
    }
    public String getSign() {
        return sign;
    }
    public void setSign(String sign) {
        this.sign = sign;
    }
    public String getHeadicon() {
        return headicon;
    }
    public void setHeadicon(String icon) {
        this.headicon = headicon;
    }
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
    public User(String name,String account,String password,String sex,String birthday,String place,String question1,
                String question2,String question3,String sign,String headicon,Socket socket) throws IOException {
        this.name = name;
        this.account = account;
        this.password = password;
        this.sex = sex;
        this.birthday = birthday;
        this.place = place;
        this.question1 = question1;
        this.question2 = question2;
        this.question3 = question3;
        this.sign = sign;
        this.headicon = headicon;
        this.socket = socket;
        this.br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.pw = new PrintWriter(socket.getOutputStream());
    }
    public String toString() {
        return "User[name:"+name+",account:"+account+",password:"+password+",sex:"+sex+",birthday:"+birthday+
                ",place:"+place+",question1:"+question1+",question2:"+question2+",question3:"+question3+
                ",headicon:"+headicon+",socket:"+socket+"]";
    }
}
