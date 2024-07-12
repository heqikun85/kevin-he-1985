package demo1;

import java.util.ArrayList;
import java.util.Scanner;

public class Student {
    public static void main(String[] args) {
        ArrayList<StudentData> list = new ArrayList<>();

        loop: while(true){
            System.out.println("---UC Davis Student Management system---");
            System.out.println("1. add student");
            System.out.println("2. delete student");
            System.out.println("3. modify");
            System.out.println("4. search");
            System.out.println("5. exit");
            System.out.println("Please enter your choice");
            Scanner sc = new Scanner(System.in);
            String choose = sc.next();
            switch (choose){
                case "1":
                    addStudent.add(list);
                    break;
                case "2":
                    deleteStudent.delete(list);
                    break;
                case "3":
                    modStudent.mod();
                    break;
                case "4":
                    searchStudent.search(list);
                    break;
                case "5":
                    System.out.println("5. exit");
                    break loop;
                default: System.out.println("wrong choose");
            }

        }
        System.out.println("我执行了吗？");

    }

    public static boolean compare(ArrayList<StudentData> list, String id){
        for (StudentData student : list) {
            String sid = student.getId();
            if (sid.equals(id)) {
                return true;
            }
        }
        return false;
    }

    public static int getIndex(ArrayList<StudentData> list, String id){
        for (int i = 0; i < list.size(); i++) {
            StudentData student = list.get(i);
            String sid = student.getId();
            if(sid.equals(id)){
                return i;
            }
        }
        return -1;
    }
}
