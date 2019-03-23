<%--
  Created by IntelliJ IDEA.
  User: 86173
  Date: 2019/1/25
  Time: 21:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>首页</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="http://how2j.cn/study/js/jquery/2.0.0/jquery.min.js"></script>
    <link href="http://how2j.cn/study/css/bootstrap/3.3.6/bootstrap.min.css" rel="stylesheet">
    <script src="http://how2j.cn/study/js/bootstrap/3.3.6/bootstrap.min.js"></script>
    <style>
        div.item img{
            width:100%;
        }
        div#carousel-example-generic{
            width:80%;
            margin:0 auto;
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
    <div class="container" style="width: 1228px;height: 270px;">
        <div style="width: 1200px;height: 270px;border: 1px solid rgba(153,153,153,0.35);box-sizing: border-box;">
            <ul class="nav nav-pills nav-stacked pull-left" style="width:198px">
                <li role="presentation" style="width: 198px;height: 44px;"><a href="#">新鲜水果</a></li>
                <li role="presentation" style="width: 198px;height: 44px;"><a href="#">海鲜水产</a></li>
                <li role="presentation" style="width: 198px;height: 44px;"><a href="#">猪牛羊肉</a></li>
                <li role="presentation" style="width: 198px;height: 44px;"><a href="#">禽类蛋品</a></li>
                <li role="presentation" style="width: 198px;height: 44px;"><a href="#">新鲜蔬菜</a></li>
                <li role="presentation" style="width: 198px;height: 44px;"><a href="#">速冻食品</a></li>
            </ul>
            <div id="carousel-example-generic" class="carousel slide pull-left" data-ride="carousel" style="width: 760px;height: 270px;">
                <!-- Indicators -->
                <ol class="carousel-indicators">
                    <li data-target="#carousel-example-generic" data-slide-to="0" class="active"></li>
                    <li data-target="#carousel-example-generic" data-slide-to="1"></li>
                    <li data-target="#carousel-example-generic" data-slide-to="2"></li>
                    <li data-target="#carousel-example-generic" data-slide-to="3"></li>
                </ol>
                <!-- Wrapper for slides -->
                <div class="carousel-inner" role="listbox">
                    <div class="item active">
                        <img src="../images/bg1.jpg" >
                    </div>
                    <div class="item">
                        <img src="../images/bg2.jpg" >
                    </div>
                    <div class="item">
                        <img src="../images/bg3.jpg" >
                    </div>

                    <div class="item">
                        <img src="../images/bg4.jpg" >
                    </div>
                </div>
                <!-- Controls -->
                <a class="left carousel-control" href="#carousel-example-generic" role="button" data-slide="prev">
                    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
                </a>
                <a class="right carousel-control" href="#carousel-example-generic" role="button" data-slide="next">
                    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
                </a>
            </div>
            <img src="../images/bg5.jpg" alt="" class="pull-left">
            <img src="../images/bg6.jpg" alt="" class="pull-left">
        </div>
    </div>
    <br>
    <div class="container" style="width: 1228px;height: 2120px;">
        <span class="text-success">新鲜水果</span>
        <table class="table table-bordered text-center">
            <tr>
                <td>
                    <img src="../images/fruit.jpg"/>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${fruit1.name}">
                        <div class="text-muted">${fruit1.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${fruit1.name}">
                        <img src="../images/${fruit1.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${fruit1.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${fruit2.name}">
                        <div class="text-muted">${fruit2.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${fruit2.name}">
                        <img src="../images/${fruit2.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${fruit2.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${fruit3.name}">
                        <div class="text-muted">${fruit3.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${fruit3.name}">
                        <img src="../images/${fruit3.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${fruit3.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${fruit4.name}">
                        <div class="text-muted">${fruit4.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${fruit4.name}">
                        <img src="../images/${fruit4.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${fruit4.price}</div>
                </td>
            </tr>
        </table>
        <span class="text-success">海鲜水产</span>
        <table class="table table-bordered text-center">
            <tr>
                <td>
                    <img src="../images/seafood.jpg" alt="">
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${seafood1.name}">
                        <div class="text-muted">${seafood1.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${seafood1.name}">
                        <img src="../images/${seafood1.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${seafood1.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${seafood2.name}">
                        <div class="text-muted">${seafood2.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${seafood2.name}">
                        <img src="../images/${seafood2.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${seafood2.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${seafood3.name}">
                        <div class="text-muted">${seafood3.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${seafood3.name}">
                        <img src="../images/${seafood3.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${seafood3.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${seafood4.name}">
                        <div class="text-muted">${seafood4.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${seafood4.name}">
                        <img src="../images/${seafood4.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${seafood4.price}</div>
                </td>
            </tr>
        </table>
        <span class="text-success">猪牛羊肉</span>
        <table class="table table-bordered text-center">
            <tr>
                <td><img src="../images/meat.jpg"></td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${meat1.name}">
                        <div class="text-muted">${meat1.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${meat1.name}">
                        <img src="../images/${meat1.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${meat1.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${meat2.name}">
                        <div class="text-muted">${meat2.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${meat2.name}">
                        <img src="../images/${meat2.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${meat2.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${meat3.name}">
                        <div class="text-muted">${meat3.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${meat3.name}">
                        <img src="../images/${meat3.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${meat3.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${meat4.name}">
                        <div class="text-muted">${meat4.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${meat4.name}">
                        <img src="../images/${meat4.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${meat4.price}</div>
                </td>
            </tr>
        </table>
        <span class="text-success">禽类蛋品</span>
        <table class="table table-bordered text-center">
            <tr>
                <td><img src="../images/egg.jpg"/></td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${egg1.name}">
                        <div class="text-muted">${egg1.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${egg1.name}"><img src="../images/${egg1.image}" style="width: 180px;height: 180px;"></a><br><br>
                    <div class="text-danger">￥${egg1.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${egg2.name}">
                        <div class="text-muted">${egg2.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${egg2.name}">
                        <img src="../images/${egg2.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${egg2.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${egg3.name}">
                        <div class="text-muted">${egg3.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${egg3.name}">
                        <img src="../images/${egg3.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${egg3.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${egg4.name}">
                        <div class="text-muted">${egg4.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${egg4.name}">
                        <img src="../images/${egg4.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${egg4.price}</div>
                </td>
            </tr>
        </table>
        <span class="text-success">新鲜蔬菜</span>
        <table class="table table-bordered text-center">
            <tr>
                <td><img src="../images/vegetables.jpg"/></td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${vegetables1.name}">
                        <div class="text-muted">${vegetables1.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${vegetables1.name}">
                        <img src="../images/${vegetables1.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${vegetables1.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${vegetables2.name}">
                        <div class="text-muted">${vegetables2.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${vegetables2.name}">
                        <img src="../images/${vegetables2.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${vegetables2.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${vegetables3.name}">
                        <div class="text-muted">${vegetables3.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${vegetables3.name}">
                        <img src="../images/${vegetables3.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${vegetables3.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${vegetables4.name}">
                        <div class="text-muted">${vegetables4.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${vegetables4.name}">
                        <img src="../images/${vegetables4.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${vegetables4.price}</div>
                </td>
            </tr>
        </table>
        <span class="text-success">速冻食品</span>
        <table class="table table-bordered text-center">
            <tr>
                <td><img src="../images/frozenfood.jpg"/></td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${frozenfood1.name}">
                        <div class="text-muted">${frozenfood1.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${frozenfood1.name}">
                        <img src="../images/${frozenfood1.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${frozenfood1.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${frozenfood2.name}">
                        <div class="text-muted">${frozenfood2.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${frozenfood2.name}">
                        <img src="../images/${frozenfood2.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${frozenfood2.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${frozenfood3.name}">
                        <div class="text-muted">${frozenfood3.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${frozenfood3.name}">
                        <img src="../images/${frozenfood3.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${frozenfood3.price}</div>
                </td>
                <td>
                    <br>
                    <a href="DetailServlet?name=${frozenfood4.name}">
                        <div class="text-muted">${frozenfood4.name}</div>
                    </a><br>
                    <a href="DetailServlet?name=${frozenfood4.name}">
                        <img src="../images/${frozenfood4.image}" style="width: 180px;height: 180px;">
                    </a><br><br>
                    <div class="text-danger">￥${frozenfood4.price}</div>
                </td>
            </tr>
        </table>
    </div>
    <div style="width: 1519px;height: 100px;margin:30px 0;border-top:2px solid #42ac46" class="container text-center">
        <br>
        <h6>关于我们 | 联系我们 | 招聘人才 | 友情链接</h6>
        <h6>CopyRight © 2016 北京******技术有限公司 All Rights Reserved</h6>
        <h6>电话：010-******* 京ICP备18051957号-1</h6>
    </div>
</body>
</html>
