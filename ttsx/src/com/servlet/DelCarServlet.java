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

@WebServlet(name = "DelCarServlet")
public class DelCarServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String user = (String)session.getAttribute("user");
        System.out.println(user);
        String name = request.getParameter("name");
        try {
            DAOFactory.getCarIDAOInstance().delCar(name,user);
            response.sendRedirect("CarServlet");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
