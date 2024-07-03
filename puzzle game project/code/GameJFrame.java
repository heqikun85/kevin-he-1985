package Pizze;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.event.*;
import java.util.Arrays;
import java.util.Random;

public class GameJFrame extends JFrame implements KeyListener, ActionListener {
    //创建二维数组，储存随机的图片index
    int[][] data = new int[4][4];
    int[][] win = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,0}
    };
    int step = 0;

    //创建选项下拉条目object
    JMenuItem replayItem = new JMenuItem("重新游戏");
    JMenuItem reloginItem = new JMenuItem("重新登录");
    JMenuItem closeItem = new JMenuItem("关闭游戏");

    JMenuItem accItem = new JMenuItem("公众号");

    //记录当前展示的图片的路径
    Random range = new Random();
    int r = range.nextInt(8) + 1;
    String url = "/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/animal/animal"+r+"/";

    //1. 创建游戏的主界面，继承自JFrame Obj，java自带JFrame的object
    public GameJFrame(){
        initJFrame(); // initial frame

        initJMenuBar(); // initial menu

        initalData(); // initial image index data

        initImage(); // initial image

        this.setVisible(true); // 界面默认隐藏，需要手动显示，建议写在最后
    }

    int x,y; // remember the location of empty block

    private void initalData() {
        //创建图片列表数组
        int[] tempArr = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        //获取随机索引
        Random r = new Random();

        // 打乱数组顺序
        for (int i = 0; i < tempArr.length; i++) {
            int index = r.nextInt(tempArr.length);
            int temp = tempArr[i];
            tempArr[i] = tempArr[index];
            tempArr[index] = temp;
        }

        for (int i = 0; i < tempArr.length; i++) {
            if(tempArr[i] == 0){
                x = i/4;
                y = i%4;
            }
            data[i/4][i%4] = tempArr[i];
        }
    }

    private void initImage() {
       //清空所有之前图片缓存。用来刷新新的移动后的图片。
        this.getContentPane().removeAll();
        System.out.println(victory());
        if(victory()){
            JLabel wJlabel = new JLabel(new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/win.png"));
            wJlabel.setBounds(203,283,197,73);
            this.getContentPane().add(wJlabel);
            this.getContentPane().repaint();
        }

        //计步器
        JLabel stepCount = new JLabel("步数: " + step);
        stepCount.setBounds(50,30,100,20);
        this.getContentPane().add(stepCount);



        // 用for loop的形式编写重复代码
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                JLabel jLabel = new JLabel(new ImageIcon(url +data[i][j]+ ".jpg"));
                //设置图片位置
                jLabel.setBounds(105 * j + 83,105 * i + 134,105,105);
                //设施边框,参数是一个接口，这个接口有不同的类型边框
                jLabel.setBorder(new BevelBorder(0));
                //把管理容器添加到界面中
                // this.add(jLabel1) 为何不使用这个暂时不确定
                this.getContentPane().add(jLabel);
            }
        }
        /*
        // 非内嵌循环，用for loop的形式编写重复代码
        for (int i = 0; i < 4; i++) {
            //创建一个JLabel的对象（管理容器）
            JLabel jLabel = new JLabel(new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/animal/animal3/" +num+ ".jpg"));
            //设置图片位置
            jLabel.setBounds(105 * i,0,105,105);
            //把管理容器添加到界面中
            // this.add(jLabel1) 为何不使用这个暂时不确定
            this.getContentPane().add(jLabel);
            num++;
        }

        //第二行的图片代码
        for (int i = 0; i < 4; i++) {
            JLabel jLabel = new JLabel(new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/animal/animal3/" +num+ ".jpg"));
            //设置图片位置
            jLabel.setBounds(105 * i,105,105,105);
            //把管理容器添加到界面中
            this.getContentPane().add(jLabel);
            num++;
        }

        //也可以选择内嵌一个loop 让代码行数更少，但是我的学习理念是尽量永远不要使用内嵌loop
        for (int i = 0; i < 4; i++) {
            JLabel jLabel = new JLabel(new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/animal/animal3/" +num+ ".jpg"));
            //设置图片位置
            jLabel.setBounds(105 * i,210,105,105);
            //把管理容器添加到界面中
            this.getContentPane().add(jLabel);
            num++;
        }

        for (int i = 0; i < 3; i++) {
            JLabel jLabel = new JLabel(new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/animal/animal3/" +num+ ".jpg"));
            //设置图片位置
            jLabel.setBounds(105 * i,315,105,105);
            //把管理容器添加到界面中
            this.getContentPane().add(jLabel);
            num++;
        }*/
        //先加载的图片在top，后加载的图片在bottom
        ImageIcon backG = new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/background.png");
        JLabel bG = new JLabel(backG);
        bG.setBounds(40,40,508,560);
        this.getContentPane().add(bG);

        //刷新界面
        this.getContentPane().repaint();
    }

    private void initJMenuBar() {
        //初始化菜单
        //创建菜单object
        JMenuBar jMenuBar = new JMenuBar();

        //创建菜单上的两个选项的object
        JMenu funcMenu = new JMenu("功能");
        JMenu infoMenu = new JMenu("关于我们");

        //将每一个选项下面的条目添加到选项当中
        funcMenu.add(replayItem);
        funcMenu.add(reloginItem);
        funcMenu.add(closeItem);

        infoMenu.add(accItem);

        jMenuBar.add(funcMenu);
        jMenuBar.add(infoMenu);

        //给整个界面设置菜单
        this.setJMenuBar(jMenuBar);

        replayItem.addActionListener(this);
        closeItem.addActionListener(this);
        reloginItem.addActionListener(this);
        accItem.addActionListener(this);
    }

    private void initJFrame() {
        this.setSize(603,680); // 设置界面大小
        this.setTitle("puzzle game v1.0"); // 设置界面title
        this.setAlwaysOnTop(true); // 保持界面在最上层。
        this.setLocationRelativeTo(null); // 设置界面居中
        // 设置程序关闭模式，0是不关闭，1是默认，2是当最后一个关闭时才结束虚拟机 3关闭任何一个都关闭虚拟机
        this.setDefaultCloseOperation(3);

        this.setLayout(null); // 取消框架内默认的设置规格
        this.addKeyListener(this);
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();
        if(code == 65){
            this.getContentPane().removeAll();
            JLabel jLabel = new JLabel(new ImageIcon(url +"all.jpg"));
            jLabel.setBounds(83,134,420,420);
            this.getContentPane().add(jLabel);

            ImageIcon backG = new ImageIcon("/Users/kevinhe/Desktop/学习/Code_Note/Java note/project/Test/image/background.png");
            JLabel bG = new JLabel(backG);
            bG.setBounds(40,40,508,560);
            this.getContentPane().add(bG);

            //刷新界面
            this.getContentPane().repaint();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        if(victory()){
            return;
        }

        // 37 left, 38 up, 39 right, 40 down
        int code = e.getKeyCode();
        int temp;
        if(code == 37){
            System.out.println("向左移动");
            //把空白方块右侧图片往左移动
            if(y == 3) return;
            data[x][y] = data[x][y+1];
            data[x][y+1] = 0;
            y++;
            step++;
            initImage();
        }else if(code == 38){
            System.out.println("向上移动");
            if(x == 3) {
                return;
            }
            //把空白方块下侧图片往上移动
            data[x][y] = data[x+1][y];
            data[x + 1][y] = 0;
            x++;
            step++;
            initImage();
        }else if(code == 39){
            System.out.println("向右移动");
            //把空白方块左侧图片往右移动
            if(y == 0){
                return;
            }
            data[x][y] = data[x][y-1];
            data[x][y-1] = 0;
            y--;
            step++;
            initImage();
        }else if(code == 40){
            System.out.println("向下移动");
            //把空白方块上方图片往下移动
            if(x == 0) return;
            data[x][y] = data[x-1][y];
            data[x - 1][y] = 0;
            x--;
            step++;
            initImage();
        }else if(code == 65){
            initImage();
        }else if(code == 87){
            data = new int[][]{
                    {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,0}
            };
            initImage();
        }
    }

    private boolean victory() {
        return Arrays.deepEquals(win, data);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();
        if(obj == replayItem){
            System.out.println("replay");
            step = 0;
            //再次打乱二维数组
            initalData();
            //重新加载图片
            initImage();
            //重制计步器
        }else if(obj == reloginItem){
            System.out.println("relogin");
            this.setVisible(false);//隐藏当前界面
            new LoginJFrame();
        }else if(obj == closeItem){
            System.out.println("close game");
            System.exit(0);
        }else if(obj == accItem){
            System.out.println("相关信息");
        }
    }
}
