    package StudentSystem;

    import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

    public class App2 {
        private static final Scanner sc = new Scanner(System.in);
        public static void main(String[] args) {
            // 显示欢迎页面
            System.out.println("Welcom to the student management system");
            // 创建用户对象List
            ArrayList<User> list = new ArrayList<>();

            
            // 首页循环选项
            loop: while(true){
                System.out.println("Please select the option: \n 1. login  \n 2. Sign in \n 3. Forgot password \n 4. Exit");
                int op = sc.nextInt();
                switch(op){
                    // 选项进入各个功能
                    case 1 -> login(list);
                    case 2 -> register(list);
                    case 3 -> forgotPass(list);
                    case 4 -> {
                        System.out.println("Exit");
                        System.exit(0);
                    }
                    default -> System.out.println("Wrong Input");
                }
            }
        }

        private static void login(ArrayList<User> list){
            System.out.println("login");  
            String code = getCode();  
        }

        // 注册功能函数
        private static void register(ArrayList<User> list){
            String name,id,phone,pass;

            // 输入用户名
            while(true){
                System.out.println("Please enter user name"); 
                name = sc.next(); 
                boolean flag1 = checkUser(name); //确认用户名符合规则
                boolean flag2 = verifyUser(list, name); //确认用户名为唯一
                if(!flag1){
                    System.out.println("this user name isn't allowed");
                }else if(flag2){
                    System.out.println("this user name already exist");
                }else{
                    System.out.println("user name set");
                    break;
                }
            }
            
            pass = setPassWord(); // 设定密码

            // 设定用户id
            while(true){
                System.out.println("Please enter ID number");
                id = sc.next();
                boolean flag = checkId(id); // 确认id输入符合规则
                if(!flag){
                    System.out.println("this id is wrong");
                }else{
                    System.out.println("id set successful");
                    break;
                }
            }

            while(true){
                System.out.println("Please enter phone number");
                phone = sc.next();
                boolean flag = checkPhone(phone); //确认电话好吗输入符合规则
                if(flag){
                    System.out.println("Phone set successful");
                    break;
                }else{
                    System.out.println("phone number is wrong");
                }
            }
            
            User u = new User(name, pass, id, phone); // 创建用户对象
            list.add(u); //添加对象进入list
            System.out.println("user has been added");
            printList(list);
        }

        private static String setPassWord() {
            System.out.println("Please enter Password");
            String pass = sc.next();
            while(true){
                System.out.println("Please enter Password again");
                String pass2 = sc.next();
                if(pass.equals(pass2)){
                    System.out.println("Password is set");
                    return pass;
                }else{
                    System.out.println("two time password doesn't same");
                }
            }
        }

        private static void printList(ArrayList<User> list) {
            User u = new User();
            for(int i = 0; i < list.size(); i++){
                u = list.get(i);
                System.out.println(u.getName() + "\t" + u.getPass() + "\t" + u.getPerson() + "\t" + u.getPhone());
            }
            
        }

        private static boolean checkPhone(String phone) {
            if(phone.length()< 11 || phone.length() > 11){
                return false;
            }
            for(int i = 0; i < phone.length(); i++){
                char c = phone.charAt(i);
                if(!(c >= '0' && c <= '9')){
                    return false;
                }
            }
            return true;
        }

        private static void forgotPass(ArrayList<User> list){
            System.out.println("Please enter your user name: ");
            //录入用户名，确认用户名存在。
            String name = sc.next();
            int index = verifyIndex(list, name);
            if(index >= 0){
                System.out.println("this user is exist. ");
                User u = list.get(index);
                while(true){
                    System.out.println("Please enter id to verify your information ");
                    String id =sc.next();
                    System.out.println("Please enter phone to verify your information");
                    String phone = sc.next();
                    boolean flag = checkPhoId(u,id,phone);
                    if(flag){
                        String pass = setPassWord();
                        u.setPass(pass);
                    }else{
                        System.out.println("the information verify failed, please enter again");
                        continue;
                    }
                }
            }
        }

        private static int verifyIndex(ArrayList<User> list, String name) {
            User u = new User();
            for (int i =0; i < list.size(); i++) {
                u = list.get(i);
                if (u.getName().equals(name)) {
                    return i;
                }
            }
            return -1;
        }

        private static boolean checkPhoId(User u, String id, String phone) {
                if(u.getPerson().equals(id) && u.getPhone().equals(phone)){
                    System.out.println("information verified. ");
                    return true;
                }
            return false;
        }
        

        private static boolean checkUser(String user){
            int len = user.length();
            int count = 0;

            if(len < 3 || len > 15){
                return false;
            }

            for(int i =0; i<user.length();i++){
                char c = user.charAt(i);
                if(!((c >= 'a' && c <= 'z')||(c >='A' && c <= 'Z')||(c >= '0' && c < '9'))){
                    return false;
                }
                if(((c >= 'a' && c <= 'z')||(c >='A' && c <= 'Z'))){
                    count++;
                }
                if(count == user.length()){
                    return false;
                }
            }
            return count > 0;
        }
        
        private static boolean verifyUser(ArrayList<User> list, String user) {
            for (User u : list) {
                if (u.getName().equals(user)) {
                    return true;
                }
            }
            return false;
        }

        private static boolean checkId(String id){
            if(id.length() != 18){
                return false;
            }

            boolean f = id.startsWith("0");
            if(f){
                return false;
            }

            for(int i =0; i < id.length() - 1; i++){
                char c = id.charAt(i); 
                if(!(c >= '0' && c <= '9')){
                    return false;
                }
            }
            char end = id.charAt(id.length()-1);
            if(!(end == 'x' || end == 'X' || (end >= '0' && end <= '9'))){
                return false;
            }
            return true;
        }

        //生成一个验证码
        private static String getCode(){
            ArrayList<Character> list = new ArrayList<>();
            // 创建一个包含随机出现内容字符的list
            for(int i = 0; i < 26; i++){
                list.add((char)('a'+ i)); //'a'+ i = (char)98 
                list.add((char)('A'+ i));
                if(i<=9){
                    list.add((char)('0' + i));
                }
            }

            Random r = new Random();
            StringBuilder s = new StringBuilder();

            for(int i = 0; i < 4; i++){
                //获取随机索引
                int index = r.nextInt(list.size());
                char c = list.get(index);
                s.append(c);
            }
        
            return s.toString();
        }

    }
