package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class FindByAccount {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    public String name;
    public String account;
    public String password;
    public String sex;
    public String birthday;
    public String place;
    public String question1;
    public String question2;
    public String question3;
    public String sign;
    public String headicon;
    public boolean hasFriend = false;
    public FindByAccount(String number) {
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            String sql = "select * from user";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            rs = pstmt.executeQuery();
            while (rs.next()) {
                String taccount = rs.getString("account");
                if(taccount.equals(number)) {
                    hasFriend = true;
                    name = rs.getString("name");
                    account = taccount;
                    password = rs.getString("password");
                    sex = rs.getString("sex");
                    birthday = rs.getString("birthday");
                    place = rs.getString("place");
                    question1 = rs.getString("question1");
                    question2 = rs.getString("question2");
                    question3 = rs.getString("question3");
                    sign = rs.getString("sign");
                    headicon = rs.getString("headicon");
                    break;
                }
            }
            rs.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        FindByAccount fba = new FindByAccount("123");
        System.out.println(fba.birthday);
    }
}
