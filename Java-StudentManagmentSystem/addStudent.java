package demo1;

import java.util.ArrayList;
import java.util.Scanner;

public class addStudent {
    public static void add(ArrayList<StudentData> list){
        StudentData s = new StudentData();

        Scanner sc = new Scanner(System.in);
        System.out.println("enter the student ID");
        String id = sc.next();
        boolean flag = Student.compare(list, id);
        if(!flag){
            s.setId(id);
            System.out.println("enter the student name");
            String name = sc.next();
            s.setName(name);

            System.out.println("enter the student age");
            String age = sc.next();
            sc.nextLine(); // 由于下一个nextLine会把这一行之前的输入的回车作为结束符
            // 所以在nextLine 和 next 连用的情况下，必须多加一行nextLine去接受这个结束符
            s.setAge(age);

            System.out.println("enter the student address");
            String address = sc.nextLine();
            s.setAddress(address);
            list.add(s);
        }else{
            System.out.println("The student already exist.");
        }



    }
}
