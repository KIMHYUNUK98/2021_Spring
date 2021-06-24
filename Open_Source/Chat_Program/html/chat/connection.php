<?php
$host = "localhost";
$user = "chatuser";
$pass = "1234";
$db_name = "chatdb";
$con = new mysqli($host, $user, $pass, $db_name);
function formatDate($date){
	return date('g:i a', strtotime($date));
}
?>