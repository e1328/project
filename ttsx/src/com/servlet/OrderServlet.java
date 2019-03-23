package com.servlet;

import com.factory.DAOFactory;
import com.vo.Car;
import com.vo.Product;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "OrderServlet")
public class OrderServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String user = (String)session.getAttribute("user");
        String subs[] = request.getParameterValues("sub");
        List<Car> list = new ArrayList<Car>();
        for(int i=0;i<subs.length;i++) {
            String name = new String(subs[i].getBytes("ISO-8859-1"),"utf-8");
            System.out.println(name);
            try {
                Car car = DAOFactory.getCarIDAOInstance().getCar(name,user);
                System.out.println("car"+car);
                list.add(car);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println("list"+list);
        request.setAttribute("list",list);
        request.getRequestDispatcher("order.jsp").forward(request, response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
