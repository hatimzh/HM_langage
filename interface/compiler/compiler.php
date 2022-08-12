<!DOCTYPE html>
<html>
<head>
    <title>HM Compiler - Compiler</title>
    
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-+0n0xVW2eSR5OomGNYDnhzAbDsOXxcvSN1TPprVMTNDbiYZCxYbOOl7+AMvyTG2x" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="../codemirror/lib/codemirror.css">
    <link rel="stylesheet" type="text/css" href="../codemirror/theme/material-darker.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-gtEjrD/SeCtmISkJkNUaaKMoLD0//ElJ19smozuHV6z3Iehds+3Ulb9Bn9Plx0x4" crossorigin="anonymous"></script>
    <?php
        if(isset($_POST["compile"])){
            $file_content = $_POST["code"];
            if (($file = fopen("code", "w+")) !== FALSE){
                fwrite($file, $file_content);
                fclose($file);
            }
            exec('MH_langage.exe < code > res');
            echo "
                <div class='modal fade' id='error_modal' tabindex='-1' aria-labelledby='error_modal' aria-hidden='true'>
                    <div class='modal-dialog'>
                        <div class='modal-content'>
                            <div class='modal-header bg-dark text-white'>
                                <h5 class='modal-title'>Message</h5>
                                <button type='button' class='btn-close' data-bs-dismiss='modal' aria-label='Close'></button>
                            </div>
                            <div class='modal-body bg-dark text-white'>
                                <p>".file_get_contents("res")."</p>
                            </div>
                            <div class='modal-footer bg-dark text-white'>
                                <button type='button' class='btn btn-light' data-bs-dismiss='modal'>Close</button>
                            </div>
                        </div>
                    </div>
                </div>";
        }
        if(isset($_POST["run"])){
            exec('MH_langage.exe < code > res');
            exec('gcc -o code.cgi code.c');
            exec("start code.cgi");
            exec('del code.c code.cgi res');
        }
    ?>
</head>
<body>

    <div class="container-fluid" style=" padding-left: 0px; padding-right: 0px; justify-content : center;">
        <nav class="navbar navbar-expand-lg navbar-dark bg-dark sticky-top">
            <div class="container-fluid" >
                <a class="navbar-brand"  ><h3>HM Compiler</h3></a>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarNav">
                </div>
            </div>
        </nav>
    </div>

    <div div="container-fluid">
        <form method="post">
            <div class="row container-fluid" style="margin-right: 0px; margin-left: 0px; padding-right: 0px; padding-left: 0px;">
                <textarea class="codemirror-textarea" name="code" id="code-area"><?php echo file_get_contents("code");?></textarea>
            </div>
            <div class="bg-dark">
                <div class="row container-fluid">
                    <div class="col">
                        <div class="d-grid gap-2">
                            <button type="submit" name="compile" class="btn btn-success btn-lg" onclick="test();">Compile</button>
                        </div>
                    </div>
                    <div class="col">
                        <div class="d-grid gap-2">
                            <button type="submit" name="run" class="btn btn-danger btn-lg">Run</button>
                        </div>
                    </div>
                </div>
            </div>
        </form>
    </div>

    <script type="text/javascript" src="../javascript/jquery.js"/></script>
    <script type="text/javascript" src="../codemirror/lib/codemirror.js"/></script>
    <script type="text/javascript" src="../javascript/default.js"/></script>
    <script src="../codemirror/mode/clike/clike.js"></script>
    <script>
        $(document).ready(function(){
            $('#error_modal').modal('show');
        });
    </script>

</body>
</html>