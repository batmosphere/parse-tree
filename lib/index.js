function escapeHtml(unsafe) {
    return unsafe
         .replace(/&/g, "&amp;")
         .replace(/</g, "&lt;")
         .replace(/>/g, "&gt;")
         .replace(/"/g, "&quot;")
         .replace(/'/g, "&#039;");
 }

function showPage(title) {
	var elements = document.getElementsByClassName('tab');
	var titles = document.getElementsByClassName('tab-title');
	var arr = Array.prototype.slice.call( elements );
	var arr2 = Array.prototype.slice.call( titles );
	arr.forEach(function(elem){
		elem.classList.add('hidden');
	})
	arr2.forEach(function(elem){
		elem.classList.remove('selected');
	})
	document.getElementById(title).classList.remove('hidden');
	document.getElementById(title+"-title").classList.add('selected');
}

function loadPage(title) {
    var request = new XMLHttpRequest();
    request.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            showPage(title);
            document.getElementById(title+'-code').innerHTML = escapeHtml(this.responseText);
            Prism.highlightAll();
        }
    };
    request.open("GET", "src/"+title+".cpp", true);
    request.send();
}

window.onload = function() {
	loadPage('main');
}