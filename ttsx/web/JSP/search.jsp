<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: 86173
  Date: 2019/2/12
  Time: 16:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>商品列表</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="http://how2j.cn/study/js/jquery/2.0.0/jquery.min.js"></script>
    <link href="http://how2j.cn/study/css/bootstrap/3.3.6/bootstrap.min.css" rel="stylesheet">
    <script src="http://how2j.cn/study/js/bootstrap/3.3.6/bootstrap.min.js"></script>
</head>
<body>
    <div style="width: 100%;height: 29px;background-color: #f6f6f6;line-height: 29px;">
        <div class="container" style="width: 1228px;">
            <span class="text-muted">欢迎来到天天生鲜！</span>
            <div class="pull-right">
                <%
                    if(session.getAttribute("user")!=null) {
                %>
                <span class="text-muted">欢迎您：<span style="color: #ff8800;"><%=session.getAttribute("user")%></span></span>&nbsp;&nbsp;
                    <span class="text-muted">|</span>&nbsp;&nbsp;
                    <a href="LogoutServlet"><span class="text-muted">退出</span></a>&nbsp;&nbsp;
                    <span class="text-muted">|</span>&nbsp;&nbsp;
                <%
                } else {
                %>
                    <a href="login.jsp"><span class="text-muted">登录</span></a>&nbsp;&nbsp;
                    <span class="text-muted">|</span>&nbsp;&nbsp;
                    <a href="register.jsp"><span class="text-muted">注册</span></a>&nbsp;&nbsp;
                    <span class="text-muted">|</span>&nbsp;&nbsp;
                <%
                    }
                %>
                <a href="#"><span class="text-muted">用户中心</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="#"><span class="text-muted">我的购物车</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="#"><span class="text-muted">我的订单</span></a>
            </div>
        </div>
    </div>
    <div class="container" style="width: 1228px;height: 115px">
        <a href="HomeServlet"><img src="../images/logo02.png" alt="" class="pull-left" style="width: 150px;height: 59px;margin-top: 22px;"></a>
        <form action="SearchServlet" method="post">
            <div class="input-group pull-left" style="width: 620px;margin: 35px 0 0 120px">
                <input type="text" class="form-control" placeholder="搜索商品" name="key">
                <span class="input-group-btn">
                    <button class="btn btn-default" type="submit">搜索</button>
                </span>
            </div>
        </form>
        <input type="text" class="form-control pull-right" value="0" style="width: 40px;margin-top: 21px;">
        <input type="button" class="form-control pull-right" value="我的购物车" style="width: 160px;margin-top: 21px;" id="car">
        <script>
            $(function () {
                $("#car").click(function () {
                    $(location).attr("href","CarServlet");
                });
            });
        </script>
    </div>
    <div class="container" style="width: 1228px;height: 42px;">
        <ul class="nav nav-pills">
            <li role="presentation" class="active" style="width: 200px;height: 40px;"><a href="#">全部商品分类</a></li>
            <li role="presentation"><a href="#">首页</a></li>
            <li role="presentation"><a href="#">|</a></li>
            <li role="presentation"><a href="#">手机生鲜</a></li>
            <li role="presentation"><a href="#">|</a></li>
            <li role="presentation"><a href="#">抽奖</a></li>
        </ul>
    </div>
    <div style="width: 100%;height: 2px;background-color: #39a93e;"></div>
    <div class="container" style="width: 1228px;">
        <ol class="breadcrumb">
            <li><a href="#">苹果</a></li>
            <li class="active">收藏内容如下</li>
        </ol>
        <ul style="list-style: none;">
            <c:forEach items="${list}" var="mem">
                <li class="pull-left" style="margin-left: 20px;">
                    <a href="DetailServlet?name=${mem.name}">
                        <img src="../images/${mem.image}" alt="" style="width: 160px;height: 160px;">
                    </a>
                    <a href="DetailServlet?name=${mem.name}">
                        <h6>${mem.name}</h6>
                    </a>
                    <h6>￥${mem.price} ${mem.unit}</h6>
                </li>
            </c:forEach>
        </ul>
    </div>
</body>
</html>
