package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class SaveGroupRecord {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private String groupName;
    private String send;
    private String content;
    public SaveGroupRecord(String groupName,String send,String content) {
        this.groupName = groupName;
        this.send = send;
        this.content = content;
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            String sql = "insert into grouprecord(groupname,send,content)"+"values(?,?,?)";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,groupName);
            pstmt.setString(2,send);
            pstmt.setString(3,content);
            pstmt.executeUpdate();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new SaveGroupRecord("1","2","abc");
    }
}
