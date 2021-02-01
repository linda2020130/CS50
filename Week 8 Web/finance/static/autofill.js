function autofill() {
    var url_string = window.location.href; //window.location.href
    var url = new URL(url_string);
    var c = url.searchParams.get("symbol");
    document.getElementById("symbol").value = c;
    if(c){
      $('input').each(function(){
        if($(this).val() == ''){
        this.focus();
        return false;
        }
      });
    }
}

autofill();

