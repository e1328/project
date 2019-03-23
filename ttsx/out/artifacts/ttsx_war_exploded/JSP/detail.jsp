<%--
  Created by IntelliJ IDEA.
  User: 86173
  Date: 2019/2/10
  Time: 13:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>商品详情</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="jquery-3.3.1.js"></script>
    <script src="http://how2j.cn/study/js/jquery/2.0.0/jquery.min.js"></script>
    <link href="http://how2j.cn/study/css/bootstrap/3.3.6/bootstrap.min.css" rel="stylesheet">
    <script src="http://how2j.cn/study/js/bootstrap/3.3.6/bootstrap.min.js"></script>
    <script>
        $(function () {
            $("#plus").click(function () {
                var amount1 = parseInt($("#amount").val());
                var amount2 = amount1 + 1;
                $("#amount").val(amount2);
                var price = parseFloat($("#price").text());
                $("#subtotal").text(amount2*price);
            });
            $("#less").click(function () {
                var amount1 = parseInt($("#amount").val());
                var amount2 = amount1 - 1;
                $("#amount").val(amount2);
                var price = parseFloat($("#price").text());
                $("#subtotal").text(amount2*price);
            });
        });
    </script>
    <style>
        p{
            margin-left:10px;
            margin-top:10px;
        }
    </style>
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
    <div class="container" style="width: 1228px;height: 40px;">
        <ol class="breadcrumb">
            <li><a href="#">全部分类</a></li>
            <li><a href="#">新鲜水果</a></li>
            <li class="active">商品详情</li>
        </ol>
    </div>
    <div class="container" style="width: 1200px;height: 400px;border: 1px solid rgba(153,153,153,0.26)">
        <img class="pull-left" src="../images/${product.image}" alt="" style="width: 222px;height: 222px;margin: 20px 0 0 20px;">
        <div class="pull-right" style="width: 730px;height: 350px;margin: 20px 20px 0 0;">
            <form action="AddCarServlet?name=${product.name}&price=${product.price}&unit=${product.unit}&image=${product.image}" method="post">
                <h3>${product.name}</h3>
                <h6>${product.info01}</h6>
                <div><span class="h4">￥</span><span id="price" class="h1">${product.price}</span><span class="h6" style="margin-left: 180px;">单位：${product.unit}</span></div>
                <br>
                <div>
                    <span class="h6 pull-left">数量：</span>
                    <div style="width: 76px;height: 50px;" class="pull-left">
                        <input type="text" id="amount" name="amount" class="form-control pull-left" style="width: 50px;height: 50px;" value="1">
                        <input type="button" id="plus" class="form-control pull-left" style="width: 25px;height: 25px;" value="+">
                        <input type="button" id="less" class="form-control pull-left" style="width: 25px;height: 25px;" value="-">
                    </div>
                </div>
                <br><br><br>
                <h6>其他规格：</h6>
                <h6>${product.other}</h6><br>
                <div><span class="h6">总价：</span><span id="subtotal" class="h4">6.99</span><span class="h4">元</span></div>
                <input type="submit" value="加入购物车" class="form-control" style="width: 180px;margin: 66px 0 0 10px;">
            </form>
        </div>
    </div>
    <div class="container" style="width: 1228px;height: 574px;margin-top: 20px;">
        <div style="width: 200px;height: 497px;" class="pull-left">
            <p>新品推荐</p>
            <ul class="list-group">
                <li class="list-group-item"><img src="../images/greenapple.jpg" alt="" style="width: 150px;height: 150px;"></li>
                <li class="list-group-item">青苹果</li>
                <li class="list-group-item">￥3.00</li>
            </ul>
            <ul class="list-group">
                <li class="list-group-item"><img src="../images/banana.jpg" alt="" style="width: 150px;height: 150px;"></li>
                <li class="list-group-item">海南香蕉</li>
                <li class="list-group-item">￥2.99</li>
            </ul>
        </div>
        <div style="width: 980px;height: 528px;" class="pull-right">
            <ul id="myTab" class="nav nav-tabs">
                <li class="active">
                    <a href="#dota" data-toggle="tab">商品介绍</a>
                </li>
                <li>
                    <a href="#lol" data-toggle="tab">评论</a>
                </li>
            </ul>
            <div id="myTabContent" class="tab-content">
                <div class="tab-pane fade in active" id="dota">
                    <p>${product.info02}</p>
                </div>
                <div class="tab-pane fade" id="lol">
                    <p>${product.comment}</p>
                </div>
            </div>
            <div style="height:200px"></div>
        </div>
    </div>
    <div style="width: 1519px;height: 100px;margin:30px 0;border-top:2px solid #42ac46" class="container text-center">
        <br>
        <h6>关于我们 | 联系我们 | 招聘人才 | 友情链接</h6>
        <h6>CopyRight © 2016 北京******技术有限公司 All Rights Reserved</h6>
        <h6>电话：010-******* 京ICP备18051957号-1</h6>
    </div>
</body>
</html>
