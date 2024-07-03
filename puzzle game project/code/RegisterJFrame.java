package Pizze;

import javax.swing.*;

public class RegisterJFrame extends JFrame {
    //3. 创建一个注册界面
    public RegisterJFrame(){
        this.setTitle("puzzle game v1.0");
        this.setAlwaysOnTop(true); // 保持界面在最上层。
        this.setSize(488,430);
        this.setLocationRelativeTo(null); // 设置界面居中
        this.setDefaultCloseOperation(3);
        this.setVisible(true);
    }
}
