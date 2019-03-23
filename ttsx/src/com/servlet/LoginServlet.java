package com.servlet;

import com.factory.DAOFactory;
import com.vo.User;

import javax.servlet.http.HttpSession;
import java.io.IOException;

public class LoginServlet extends javax.servlet.http.HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        String name = request.getParameter("name");
        String pass = request.getParameter("pass");
        User user = new User();
        user.setName(name);
        user.setPass(pass);
        System.out.println("hello");
        try {
            if(DAOFactory.getIUserDAOInstance().login(user)) {
                HttpSession session = request.getSession();
                session.setAttribute("user",user.getName());
                request.getRequestDispatcher("HomeServlet").forward(request,response);
            } else {
                response.sendRedirect("fail.jsp");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        doPost(request,response);
    }
}
