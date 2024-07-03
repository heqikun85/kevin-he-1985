package Pizze;

import javax.swing.*;

public class LoginJFrame extends JFrame {
    //2. 创建一个登录界面
    public LoginJFrame(){
        this.setSize(488,430);
        this.setTitle("puzzle game v1.0");
        this.setAlwaysOnTop(true); // 保持界面在最上层。
        this.setLocationRelativeTo(null); // 设置界面居中
        this.setDefaultCloseOperation(3); // 甚至关闭模式
        this.setVisible(true);
    }

}
