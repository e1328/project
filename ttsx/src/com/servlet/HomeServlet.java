package com.servlet;

import com.factory.DAOFactory;
import com.vo.Product;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;

@WebServlet(name = "HomeServlet")
public class HomeServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            List<Product> list1 = DAOFactory.getIProductDAOInstance().getAllProduct("fruit");
            List<Product> list2 = DAOFactory.getIProductDAOInstance().getAllProduct("seafood");
            List<Product> list3 = DAOFactory.getIProductDAOInstance().getAllProduct("meat");
            List<Product> list4 = DAOFactory.getIProductDAOInstance().getAllProduct("egg");
            List<Product> list5 = DAOFactory.getIProductDAOInstance().getAllProduct("vegetables");
            List<Product> list6 = DAOFactory.getIProductDAOInstance().getAllProduct("frozenfood");
            Iterator<Product> iter1 = list1.iterator();
            Iterator<Product> iter2 = list2.iterator();
            Iterator<Product> iter3 = list3.iterator();
            Iterator<Product> iter4 = list4.iterator();
            Iterator<Product> iter5 = list5.iterator();
            Iterator<Product> iter6 = list6.iterator();
            int i = 1;
            while (iter1.hasNext()) {
                request.setAttribute("fruit" + i, iter1.next());
                i++;
            }
            i = 1;
            while (iter2.hasNext()) {
                request.setAttribute("seafood" + i, iter2.next());
                i++;
            }
            i = 1;
            while (iter3.hasNext()) {
                request.setAttribute("meat" + i, iter3.next());
                i++;
            }
            i = 1;
            while (iter4.hasNext()) {
                request.setAttribute("egg" + i, iter4.next());
                i++;
            }
            i = 1;
            while (iter5.hasNext()) {
                request.setAttribute("vegetables" + i, iter5.next());
                i++;
            }
            i = 1;
            while (iter6.hasNext()) {
                request.setAttribute("frozenfood" + i, iter6.next());
                i++;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        request.getRequestDispatcher("home.jsp").forward(request, response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request,response);
    }
}
