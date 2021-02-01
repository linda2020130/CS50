$(document).ready(function() {
    $("#username").on('input', function(e) {
        $("#userCheck").hide();

        if ($("#username").val() == null || $("#username").val() == "") {
            $("#userCheck").show();
            $("#userCheck").html("<img src=\'static/invalid.png\' height=18 width=18>"
                                 + "<span style=\'color: #e60000;\'> username required</span>");
        } else {
            $.ajax({
                type: "POST",
                url: "/api/id/check",
                async: false,
                data: $("#registerform").serialize(),
                dataType: "json",
                cache: false,
                success: function(msg) {
                    $("#userCheck").show();
                    $("#userCheck").html(msg);
                },
                error: function(jqXHR, textStatus, errorThrown) {
                    $("#userCheck").show();
                    $("#userCheck").html(textStatus + " " + errorThrown);
                }
            });
        }
    });
})