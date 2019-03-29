package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class DeleteFriend {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private String account1;
    private String account2;
    public DeleteFriend(String account1,String account2) {
        this.account1 = account1;
        this.account2 = account2;
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            String sql = "delete from friend where friend_qq=? and user_qq=?";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL, DBUSER, DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,account1);
            pstmt.setString(2,account2);
            pstmt.executeUpdate();
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,account2);
            pstmt.setString(2,account1);
            pstmt.executeUpdate();
            pstmt.close();
            conn.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new DeleteFriend("123","356");
    }
}
