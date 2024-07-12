package demo1;

import java.util.ArrayList;

public class searchStudent {
    public static void search(ArrayList<StudentData> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i).toString());
        }
    }
}
