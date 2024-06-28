package StudentSystem;

import java.util.ArrayList;
import java.util.Scanner;

public class App {
    public static void main(String[] args){ 
        ArrayList<Student> list = new ArrayList<>();

        loop: while(true){
            System.out.println("-----------welcome to the Student system----------");
            System.out.println("1: Add student");
            System.out.println("2. Delete student");
            System.out.println("3. Modify student");
            System.out.println("4. Search student");
            System.out.println("5. Exit system");
            System.out.println("Please Enter your choice: ");
            Scanner sc = new Scanner(System.in);
            String choice = sc.next();
            switch(choice){
                case "1" -> addStudent(list);
                case "2" -> deleteStudent(list);    
                case "3" -> modifyStudent(list);
                case "4" -> searchStudent(list);
                case "5" -> {
                    System.out.println("exit system");
                    //break loop;  //仅结束while循环
                    System.exit(0); 
                    //System.exit(0);//停止虚拟机运行,运行这段,整个Java程序将结束
                }
                default -> System.out.println("You enter a wrong number");
            }
        }      
    }

    //添加学生
    public static void addStudent(ArrayList<Student> list){
        Student s = new Student(); //create local object

        Scanner sc = new Scanner(System.in);
        String id = null;
        while(true){
            System.out.println("Please enter the student ID: ");
            id = sc.next();
            boolean flag = checked(list,id);
            if(flag){
                System.out.println("This Student ID is already exist");
            }else{
                s.setId(id);
                break;
            }
        }
                
        System.out.println("Please enter the student Name: ");
        sc.nextLine();
        String name = sc.nextLine();
        s.setName(name);
        
        System.out.println("Please enter the student Age: ");
        int age = sc.nextInt(); // get int type value
        s.setAge(age); 
        
        System.out.println("Please enter the student Address: ");
        sc.nextLine();
        String address = sc.nextLine();
        s.setAddress(address);
        
        list.add(s);
        System.out.println("The student added into the System");
    }

    //删除学生
    public static void deleteStudent(ArrayList<Student> list){
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the ID who you want to Delete");
        String id = sc.next();
        int index = getIndex(list, id);
        if(index > 0){
            list.remove(index);
            System.out.println("id: "+ id + " student delete successful");
        }else{
            System.out.println("This id dosen't exist. ");
        }
    }
    
    //修改学生
    public static void modifyStudent(ArrayList<Student> list){
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the id who you want to modify");
        String id = sc.next();
        int index = getIndex(list, id);
        if(index == -1){
            System.out.println("This id dosen't exist. ");
        }
        Student s = list.get(index);

        loop: while(true){
                System.out.println("1. Student name");
                System.out.println("2. Student age");
                System.out.println("3. Student address");
                System.out.println("4. exit modify");
                System.out.println("Please enter the number of modify parts");
                int op = sc.nextInt();
            switch(op){
                case 1 -> {
                    System.out.println("Please enter the name that you want to modify");
                    sc.nextLine();
                    String name = sc.nextLine();
                    s.setName(name);
                    break;
                }
                case 2 ->{
                    System.out.println("Please enter the age that you want to modify");
                    int age = sc.nextInt();
                    s.setAge(age);
                    break;
                }
                case 3 ->{
                    System.out.println("Please enter the address that you want to modify");
                    sc.nextLine();
                    String address = sc.nextLine();
                    s.setAddress(address);
                    break;
                }
                case 4 ->{
                    System.out.println("exit modify");
                    break loop;
                }
            default -> System.out.println("wrong choice");
            }
        }
        
    }

    //查询学生
    public static void searchStudent(ArrayList<Student> list){
        if(list.size() == 0){
            System.out.println("no student in data base");
            return;
        }
        System.out.println("ID\tNAME\t\tAGE\tADDRESS");
        for(int i =0; i<list.size(); i++){
            Student stu = list.get(i);
            System.out.println(stu.getId()+"\t"+stu.getName()+"\t"+stu.getAge()+"\t"+stu.getAddress());
        }
        
    }

    //Check ID is unique
    public static boolean checked(ArrayList<Student> list, String id){     
        /*
        for(int i = 0; i < list.size(); i++){
            Student s = list.get(i);
            String stu = s.getId();
            if(stu.equals(id)){
                return true;
            }
        }
        return false;  */      
        return getIndex(list, id) > 0;
    }

    public static int getIndex(ArrayList<Student> list, String id){
        for(int i =0; i<list.size(); i++){
            Student s = list.get(i);
            String sid = s.getId();
            if(id.equals(sid)){
                return i;
            }
        }
        return -1;
    }
}
