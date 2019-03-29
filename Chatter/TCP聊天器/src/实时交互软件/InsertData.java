package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.text.SimpleDateFormat;

public class InsertData {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private String name;
    private String account;
    private String password;
    private String sex;
    private String birthday;
    private String place;
    private String question1;
    private String question2;
    private String question3;
    private String headicon;
    public InsertData(String name,String account,String password,String sex,String birthday,String place,
                      String question1,String question2,String question3,String sign,String headicon) {
        this.name = name;
        this.account = account;
        this.password = password;
        this.sex = sex;
        this.birthday = birthday;
        this.place = place;
        this.question1 = question1;
        this.question2 = question2;
        this.question3 = question3;
        this.headicon = headicon;
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            java.util.Date temp = null;
            temp = new SimpleDateFormat("yyyy-MM-dd").parse(birthday);
            java.sql.Date bir = new java.sql.Date(temp.getTime());
            String sql = "insert into user(name,account,password,sex,birthday,place,question1,question2,question3,sign,headicon)"
                    +"values(?,?,?,?,?,?,?,?,?,?,?)";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,name);
            pstmt.setString(2,account);
            pstmt.setString(3,password);
            pstmt.setString(4,sex);
            pstmt.setDate(5,bir);
            pstmt.setString(6,place);
            pstmt.setString(7,question1);
            pstmt.setString(8,question2);
            pstmt.setString(9,question3);
            pstmt.setString(10,sign);
            pstmt.setString(11,headicon);
            pstmt.executeUpdate();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        //new InsertData(name,password,sex,birthday,place,account);
    }
}
