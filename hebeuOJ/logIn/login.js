function isOK() {
    var x = document.forms["form"]["username"].value;
    if (x == '') {
        alert("请输入用户名")
        return false;
    }
    x = document.forms["form"]["password"].value;
    if (x == '') {
        alert("请输入密码");
        return false;
    }
    x = document.forms["form"]["verfication"].value;
    if (x == '') {
        alert("请输入验证码");
        return false;
    }
    return true;
}

function login() {
    $.ajax({
        type: "POST",
        dataType: "json",
        contentType: "application/json",
        url: "../web/judgement.php",
        data: $("#form").serialize(),
        success: function (result) {
            console.log(result);
            alert("success");
        },
        error: function () {
            alert("error");
        }
    })
}