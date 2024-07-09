package Demo1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Test1 {
    public static void main(String[] args) {
        /*班级里有N个学生，学生属性：姓名，年龄，性别。
        实现随机点名器*/
        ArrayList<String> stus = new ArrayList<>();
        Collections.addAll(stus,"Kevin He","Gina Jin","Angela Xu","Cathy Li","Jane lin","Siming Zhang","Xun Zhu","Yi Huang","Yi Zhao","Wenhui Li","Evan Zhou","Jason Liu","Will wang","William Tan","Blues Wang");
        //随机点名
        Random r =  new Random();
        int index = r.nextInt(stus.size());
        String name = stus.get(index);
        System.out.println(name);

        Collections.shuffle(stus); //打乱集合内数据，直接遍历即可
        System.out.println(stus);

        // 70% 随机到男生 30% 随机到女生
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<String> male = new ArrayList<>();
        ArrayList<String> female = new ArrayList<>();
        Collections.addAll(male,"Kevin He","Xun Zhu","Yi Huang","Yi Zhao","Evan Zhou","Jason Liu","Will wang","William Tan","Blues Wang");
        Collections.addAll(female, "Gina Jin","Angela Xu","Cathy Li","Jane lin","Siming Zhang","Wenhui Li");
        // 1 0 被随机到的概率就是70%和30%，以此来判断该选择谁
        Collections.addAll(list,1,1,1,1,1,1,1,0,0,0);
        Collections.shuffle(list);
        System.out.println(list);
        switch (list.get(0)){
            case 1 -> {
                Collections.shuffle(male);
                System.out.println(male);
            }
            case 0 ->{
                Collections.shuffle(female);
                System.out.println(female);
            }

        }

    }
}
