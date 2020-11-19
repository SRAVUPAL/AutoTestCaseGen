#RunPHP
clear

echo "starting script file..."

#Commands to take testPhp as input file.
INPUT=testPhp.txt
OLDIFS=$IFS
IFS=','
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
#Commands to execute the given php file with aruments and validate the obtained html files.
flag=1
while read line
do	
	php.exe summation.php $line	> output$flag.html
	validatehtml output$flag.html >> htmlErrors.txt
	((flag=flag + 1))
done < $INPUT
IFS=$OLDIFS

echo "terminating script file..."