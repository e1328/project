<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: 86173
  Date: 2019/2/13
  Time: 16:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>提交订单</title>
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
                <a href="login.html"><span class="text-muted">登录</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="register.html"><span class="text-muted">注册</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="#"><span class="text-muted">用户中心</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="#"><span class="text-muted">我的购物车</span></a>&nbsp;&nbsp;
                <span class="text-muted">|</span>&nbsp;&nbsp;
                <a href="#"><span class="text-muted">我的订单</span></a>
            </div>
        </div>
    </div>
    <div class="container" style="width: 1228px;height: 115px">
        <a href="home.html"><img src="../images/logo02.png" alt="" class="pull-left" style="width: 150px;height: 59px;margin-top: 22px;"></a>
        <span class="h4 pull-left" style="margin: 45px 0 0 20px;">| &nbsp;&nbsp;&nbsp;提交订单</span>
        <div class="input-group pull-right" style="width: 620px;margin: 35px 0 0 120px">
            <input type="text" class="form-control" placeholder="搜索商品">
            <span class="input-group-btn">
                    <button class="btn btn-default" type="button">搜索</button>
                </span>
        </div>
    </div>
    <form action="fail.jsp" method="post">
        <div class="container" style="width: 1228px;">确认收货地址</div><br>
        <div class="container" style="width: 1200px;height: 62px;background:#f6f6f6;">
            <span class="pull-left" style="margin-top: 22px;">寄送到：</span>
            <span class="pull-right" style="margin-top: 40px;">编辑收货地址</span>
        </div><br>
        <div class="container" style="width: 1228px;">支付方式</div><br>
        <div class="container" style="width: 1200px;height: 81px;line-height: 81px;background:#f6f6f6;">
            <input type="radio" name="pay" checked="checked">货到付款&nbsp;&nbsp;&nbsp;&nbsp;
            <input type="radio" name="pay">微信支付&nbsp;&nbsp;&nbsp;&nbsp;
            <input type="radio" name="pay">支付宝&nbsp;&nbsp;&nbsp;&nbsp;
            <input type="radio" name="pay">银行卡支付
        </div><br>
        <div class="container" style="width: 1228px;">商品列表</div><br>
        <div class="container" style="width: 1228px;">
            <table class="table table-bordered" style="background:#f6f6f6;">
                <tr>
                    <td>商品名称</td>
                    <td>商品单位</td>
                    <td>商品价格</td>
                    <td>数量</td>
                    <td>小计</td>
                </tr>
                <c:forEach items="${list}" var="order">
                    <tr>
                        <td>
                            <span>1&nbsp;</span>
                            <img src="../images/${order.image}" alt="" style="width: 65px;height: 65px;">
                            <span class="h6">${order.name}</span>
                            <input type="hidden" name="sub" value="${order.name}">
                        </td>
                        <td style="line-height: 64px;">${order.unit}</td>
                        <td style="line-height: 64px;">${order.price}元</td>
                        <td style="line-height: 64px;">${order.amount}</td>
                        <td style="line-height: 64px;">${order.subtotal}元</td>
                    </tr>
                </c:forEach>
            </table>
        </div>
        <div class="container" style="width: 1228px;">总金额结算</div><br>
        <div class="container" style="width: 1200px;height: 97px;background:#f6f6f6;">
            <h6 class="text-right">共 2 件商品，总金额 9.99元</h6>
            <h6 class="text-right">运费：10元</h6>
            <h6 class="text-right">实付款：19.99元</h6>
        </div><br>
        <div class="container" style="width: 1228px;">
            <input class="form-control pull-right" type="submit" value="提交订单" style="width: 160px;">
        </div>
    </form>
    <div style="width: 1519px;height: 100px;margin:30px 0;border-top:2px solid #42ac46" class="container text-center">
        <br>
        <h6>关于我们 | 联系我们 | 招聘人才 | 友情链接</h6>
        <h6>CopyRight © 2016 北京******技术有限公司 All Rights Reserved</h6>
        <h6>电话：010-******* 京ICP备18051957号-1</h6>
    </div>
</body>
</html>
