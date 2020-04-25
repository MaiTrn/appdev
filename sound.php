<?php
//$ID = $_POST['ID'];
//$name = $_POST['name'];
//$record = $today . ", " . $ID . ", " . $name . "\n";

$peaks = $_POST['peaks'];
$max = $_POST['max'];
$addr = $_SERVER['REMOTE_ADDR'];
$today= date("Y-m-d H:i:s");
$record = $today . ", peaks = " . $peaks . ", max = " . $max . ", " . $addr . "\n";

$file = "sound.log";
if (file_exists($file))
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");
fwrite($fp, $record);
fclose($fp);

echo "From e1900308\n";
?>
