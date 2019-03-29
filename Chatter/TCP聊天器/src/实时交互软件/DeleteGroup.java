package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class DeleteGroup {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private String groupname;
    private String account;
    public DeleteGroup(String groupname,String account) {
        this.groupname = groupname;
        this.account = account;
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            String sql = "delete from groupchat where group_name=? and user_qq=?";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL, DBUSER, DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,groupname);
            pstmt.setString(2,account);
            pstmt.executeUpdate();
            pstmt.close();
            conn.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new DeleteGroup("wechat","123");
    }
}
