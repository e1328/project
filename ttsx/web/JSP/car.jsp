<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: 86173
  Date: 2019/2/11
  Time: 21:32
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>购物车</title>
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
                <a href="CarServlet"><span class="text-muted">我的购物车</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="#"><span class="text-muted">我的订单</span></a>
            </div>
        </div>
    </div>
    <div class="container" style="width: 1228px;height: 115px">
        <a href="HomeServlet"><img src="../images/logo02.png" alt="" class="pull-left" style="width: 150px;height: 59px;margin-top: 22px;"></a>
        <span class="h4 pull-left" style="margin: 45px 0 0 20px;">| &nbsp;&nbsp;&nbsp;购物车</span>
        <div class="input-group pull-right" style="width: 620px;margin: 35px 0 0 120px">
            <input type="text" class="form-control" placeholder="搜索商品">
            <span class="input-group-btn">
                <button class="btn btn-default" type="button">搜索</button>
            </span>
        </div>
    </div>
    <div class="container" style="width: 1228px;height: 40px;line-height: 40px;">全部商品 0 件</div>
    <div class="container" style="width: 1228px;">
        <form action="OrderServlet" method="post">
            <table class="table table-bordered">
                <tr>
                    <td>商品名称</td>
                    <td>商品单位</td>
                    <td>商品价格</td>
                    <td>数量</td>
                    <td>小计</td>
                    <td>操作</td>
                </tr>
                <c:forEach items="${list}" var="car">
                    <tr>
                        <td>
                            <input type="checkbox" name="sub" value="${car.name}">
                            <img style="width: 102px;height: 102px;" src="../images/${car.image}"/>
                            <span class="h6">${car.name}</span>
                            <span class="h6">${car.price}元/${car.unit}</span>
                        </td>
                        <td style="line-height: 105px;">${car.unit}</td>
                        <td style="line-height: 105px;">${car.price}元</td>
                        <td>
                            <div style="width: 100px;height: 40px;margin-top: 34px;">
                                <input type="button" class="form-control pull-left" style="width: 30px;height: 30px;" value="+">
                                <input type="text" class="form-control pull-left" style="width: 40px;height: 30px;" value="${car.amount}">
                                <input type="button" class="form-control pull-left" style="width: 30px;height: 30px;" value="-">
                            </div>
                        </td>
                        <td style="line-height: 105px;">${car.subtotal}元</td>
                        <td style="line-height: 105px;"><a href="DelCarServlet?name=${car.name}">删除</a></td>
                    </tr>
                </c:forEach>
                <tr>
                    <td>
                        <input type="checkbox" id="all"><span class="h6"> &nbsp;&nbsp;全选</span>
                        <script>
                            $(document).ready(function () {
                                $('#all').on('click',function(){
                                    $("input[name='sub']").prop("checked", this.checked);
                                });
                            });
                        </script>
                    </td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td>
                        <h6>合计(不含运费)：￥9.99元</h6>
                        <h6>共计 2 件商品</h6>
                    </td>
                    <td><input type="submit" value="去结算" class="form-control"></td>
                </tr>
            </table>
        </form>
    </div>
    <div style="width: 1519px;height: 100px;margin:30px 0;border-top:2px solid #42ac46" class="container text-center">
        <br>
        <h6>关于我们 | 联系我们 | 招聘人才 | 友情链接</h6>
        <h6>CopyRight © 2016 北京******技术有限公司 All Rights Reserved</h6>
        <h6>电话：010-******* 京ICP备18051957号-1</h6>
    </div>
</body>
</html>
