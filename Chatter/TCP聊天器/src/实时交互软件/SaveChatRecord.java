package 实时交互软件;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class SaveChatRecord {
    public static final String DBDRIVER = "com.mysql.jdbc.Driver";
    public static final String DBURL = "jdbc:mysql://localhost:3306/tcpchatting?characterEncoding=utf-8";
    public static final String DBUSER = "root";
    public static final String DBPASS = "2427887763Zwl";
    private String send;
    private String receive;
    private String content;
    public SaveChatRecord(String send,String receive,String content) {
        this.send = send;
        this.receive = receive;
        this.content = content;
        try {
            Connection conn = null;
            PreparedStatement pstmt = null;
            String sql = "insert into chatrecord(send,receive,content)"+"values(?,?,?)";
            Class.forName(DBDRIVER);
            conn = DriverManager.getConnection(DBURL,DBUSER,DBPASS);
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,send);
            pstmt.setString(2,receive);
            pstmt.setString(3,content);
            pstmt.executeUpdate();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new SaveChatRecord("1","2","abc");
    }
}
