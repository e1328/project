package 实时交互软件;

import java.io.File;
import javax.swing.JFileChooser;

public class FileChoose {
    public File path;
    public static String str;
    public FileChoose(String name1,String name2) {
        JFileChooser jf = new JFileChooser();
        jf.setSelectedFile(new File("c:\\我的报表.xls"));
        int value = jf.showSaveDialog(null);
        jf.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
        jf.setFileHidingEnabled(false);
        if (value == JFileChooser.APPROVE_OPTION) {
            path = jf.getSelectedFile();
            str = "file,"+name1+","+name2+","+path.getAbsolutePath();
            //System.out.println(path);
            // TODO
        } else {
            // TODO
        }
    }
    public static void main(String[] args) {
        new FileChoose("12","34");
    }
}
