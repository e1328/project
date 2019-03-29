package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class FindGroupByAccount {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    public String[] groupName = new String[10];
    public int groupNum = 0;
    public FindGroupByAccount(String account) {
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            String sql =  "select group_name from groupchat where user_qq=?";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,account);
            rs = pstmt.executeQuery();
            while (rs.next()) {
                String group_name = rs.getString("group_name");
                groupName[groupNum] = group_name;
                groupNum++;
            }
            rs.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        FindGroupByAccount fgba = new FindGroupByAccount("123");
        for(int i=0;i<fgba.groupNum;i++) {
            System.out.println(fgba.groupName[i]);
        }
    }
}
