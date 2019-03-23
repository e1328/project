<%@ page import="com.utils.CodeUtils" %><%--
  Created by IntelliJ IDEA.
  User: 86173
  Date: 2019/1/25
  Time: 21:55
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册界面</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="http://how2j.cn/study/js/jquery/2.0.0/jquery.min.js"></script>
    <link href="http://how2j.cn/study/css/bootstrap/3.3.6/bootstrap.min.css" rel="stylesheet">
    <script src="http://how2j.cn/study/js/bootstrap/3.3.6/bootstrap.min.js"></script>
    <script>
        var xmlhttp;
        function check(){
            var url = "RefreshServlet";
            xmlhttp =new XMLHttpRequest();
            xmlhttp.onreadystatechange=checkResult; //响应函数
            xmlhttp.open("GET",url,true);   //设置访问的页面
            xmlhttp.send(null);  //执行访问
        }
        function checkResult(){
            if (xmlhttp.readyState==4 && xmlhttp.status==200)
                document.getElementById('code').value = xmlhttp.responseText;
        }
    </script>
</head>
<body>
    <%
        String code = CodeUtils.getCode();
        pageContext.setAttribute("code",code);
    %>
    <div class="container" style="width: 800px;height: 560px;margin-top: 50px">
        <div class="pull-left" style="width: 300px;height: 475px;border-right: 1px solid rgba(153,153,153,0.26);">
            <a href="HomeServlet"><img src="../images/logo02.png" alt="" class="pull-right" style="margin-right: 60px;"></a>
            <h3 class="text-success pull-right" style="margin-right: 60px;">足不出户 · 新鲜每一天</h3>
        </div>
        <form action="RegisterServlet" class="pull-right" style="width: 360px;height: 501px;" method="post">
            <h3 class="text-muted pull-left" style="margin-left: 10px;">用户注册</h3>
            <h4 class="text-muted pull-right" style="margin: 25px 10px 0 0;"><a href="login.jsp">登录</a></h4>
            <br><br><hr><br>
            <div class="text-muted pull-left" style="width: 80px;height: 34px;line-height: 34px;">用户名：</div><input type="text" class="form-control pull-left" name="name" style="width: 280px;"><br><br><br>
            <div class="text-muted pull-left" style="width: 80px;height: 34px;line-height: 34px;">密码：</div><input type="password" class="form-control pull-left" name="pass" style="width: 280px;"><br><br><br>
            <div class="text-muted pull-left" style="width: 80px;height: 34px;line-height: 34px;">确认密码：</div><input type="password" class="form-control pull-left" name="pass" style="width: 280px;"><br><br><br>
            <div class="text-muted pull-left" style="width: 80px;height: 34px;line-height: 34px;">邮箱：</div><input type="email" class="form-control pull-left" name="email" style="width: 280px;"><br><br><br>
            <div class="text-muted pull-left" style="width: 80px;height: 34px;line-height: 34px;">验证码：</div><input type="text" class="form-control pull-left" style="width: 140px;"><br><br><br>
            <input type="button" class="form-control" id="code" value="${code}" style="width: 100px;margin: -60px 0 0 240px;" onclick="check()"><br>
            <input type="checkbox"><span class="text-muted">同意”天天生鲜用户使用协议“</span><br><br><br>
            <input type="submit" class="form-control" value="注册" style="width: 320px;margin-left: 25px;">
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
