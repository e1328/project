package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class FindGroup {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    public boolean hasGroup = false;
    public FindGroup(String groupName) {
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            String sql =  "select group_name from groupchat where group_name=?";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,groupName);
            rs = pstmt.executeQuery();
            while (rs.next()) {
                String group_name = rs.getString("group_name");
                if(group_name.equals(groupName)) {
                    hasGroup = true;
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
}
