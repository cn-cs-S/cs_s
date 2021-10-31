function createTopic() {
    console.log($("#form").serialize())
    $.ajax({
        type: "GET",
        url: "./test.php",
        data: $("#form").serialize(),
        // dataType: "json",
        processData: false,
        contentType: false,
        success: function (response) {
            console.log(response);
            alert("success");
        },
        error: function () {
            alert("error");
        }
    });
}