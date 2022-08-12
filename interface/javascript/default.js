var editor = CodeMirror.fromTextArea
	(document.getElementById('code-area'),{
		mode : "text/x-csharp",
		theme : "material-darker",
		lineNumbers: true
});
	editor.setSize(1600,612);