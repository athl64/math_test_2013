function showPreview(imageName) {
    var popup = $("#popupDiv");
    var topPos = $(document).scrollTop();
    var windowHeight = $(window).height();
    popup.show();
    popup.css({top: topPos});
    popup.css({height: windowHeight});
    popup.html("<img id=\"popupImage\" src='" + imageName + "' />");
    var imageHeight = $("#popupImage").height();
    var imageTopMargin = (windowHeight - imageHeight)/2;
    $("#popupImage").css("margin-top", imageTopMargin);
}

function closePreview() {
    $("#popupDiv").hide();
}
