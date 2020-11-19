<!DOCTYPE html>
<html lang="en">
<head>

</head>
<body>

<form method="get">  
Enter First Number:  
<input type="number" name="a" /><br><br>  
Enter Second Number:  
<input type="number" name="b" /><br><br>  
<input  type="submit" name="submit" value="Add">
</form>

<?php  
for ($i = 0; $i < count($argv); $i++) {
	echo $argv[$i];
	echo "<br>";
}
// declarations
$sum = 0;
$c = 0;
$b = 0;
$a = 0;

//code to do the summation of the given numbers
if(!($argv[1][0]=="#")){
		for ($temp = 0; $temp < count($argv); $temp++) {
		$temp1 = explode("/", $argv[$temp], 2);
		$first = $temp1[0];
		
		eval("\$$first;");
		echo "\n aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ".$a;
		echo "\n bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb ".$b;
		echo "\n ccccccccccccccccccccccccccccccc ".$c;
		$sum = $a + $b + $c;     
		}
echo "The sum is: ".$sum;   
}
?>

</body>
</html>