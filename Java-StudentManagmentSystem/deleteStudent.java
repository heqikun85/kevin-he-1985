package demo1;

import java.util.ArrayList;
import java.util.Scanner;

public class deleteStudent{
    public static void delete(ArrayList<StudentData> list){
        System.out.println("输入要删除学生的ID");
        Scanner s = new Scanner(System.in);
        String id = s.next();
        int sid = Student.getIndex(list, id);
        if(sid >= 0){
            list.remove(sid);
        }else{
            System.out.println("student not exist");
        }
    }
}
