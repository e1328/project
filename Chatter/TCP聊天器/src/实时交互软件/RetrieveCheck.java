package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class RetrieveCheck {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private String account;
    private String question1;
    private String question2;
    private String question3;
    public String password;
    public RetrieveCheck(String account,String question1,String question2,String question3) {
        this.account = account;
        this.question1 = question1;
        this.question2 = question2;
        this.question3 = question3;
    }
    public boolean validate() {
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            String sql = "select account,password,question1,question2,question3 from user";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            rs = pstmt.executeQuery();
            while (rs.next()) {
                String taccount = rs.getString("account");
                String tquestion1 = rs.getString("question1");
                String tquestion2 = rs.getString("question2");
                String tquestion3 = rs.getString("question3");
                if(taccount.equals(this.account) && tquestion1.equals(this.question1) &&
                    tquestion2.equals(this.question2) && tquestion3.equals(this.question3)) {
                    password = rs.getString("password");
                    return true;
                }
            }
            rs.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}
