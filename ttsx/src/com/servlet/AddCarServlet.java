package com.servlet;

import com.factory.DAOFactory;
import com.vo.Car;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

@WebServlet(name = "AddCarServlet")
public class AddCarServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String user = (String)session.getAttribute("user");
        if(user==null) {
            response.sendRedirect("login.jsp");
        } else {
            System.out.println(user);
            String name = request.getParameter("name");
            double price = Double.parseDouble(request.getParameter("price"));
            String unit = request.getParameter("unit");
            int amount = Integer.parseInt(request.getParameter("amount"));
            double subtotal = price * amount;
            String image = request.getParameter("image");
            Car car = new Car();
            car.setUser(user);
            car.setName(name);
            car.setPrice(price);
            car.setUnit(unit);
            car.setAmount(amount);
            car.setSubtotal(subtotal);
            car.setImage(image);
            try {
                DAOFactory.getCarIDAOInstance().addCar(car);
                response.sendRedirect("CarServlet");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
