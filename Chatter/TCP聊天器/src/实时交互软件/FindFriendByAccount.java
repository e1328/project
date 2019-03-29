package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class FindFriendByAccount {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    public String[] friensList = new String[10];
    public String[] friendName = new String[10];
    public String[] iconList = new String[10];
    public int friendNum = 0;
    public FindFriendByAccount(String number) {
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            ResultSet rs = null;
            String sql =  "select * from friend b,user a where a.account=b.user_qq and a.account=?";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,number);
            rs = pstmt.executeQuery();
            while (rs.next()) {
                String friend_qq = rs.getString("friend_qq");
                FindByAccount fba = new FindByAccount(friend_qq);
                friensList[friendNum] = friend_qq;
                iconList[friendNum] = fba.headicon;
                friendName[friendNum] = fba.name;
                friendNum++;
            }
            rs.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        FindFriendByAccount ffba = new FindFriendByAccount("61391266");
        for(int i=0;i<ffba.friendNum;i++) {
            System.out.println(ffba.friensList[i]+" "+ffba.iconList[i]);
        }
    }
}
