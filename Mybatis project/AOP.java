package org.example;

import org.example.config.springconfig;
import org.example.dao.SpringDao;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class AOP {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(springconfig.class);
        SpringDao dao = ctx.getBean(SpringDao.class);
        int num = dao.select();
        System.out.println(num);
    }
}
