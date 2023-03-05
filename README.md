# Cat-but-Better

This is essentially an improved version of the command line cat command. Normally cat just prints out the contents of a file, but with this program I created multiple different commands to alter the said output when using this program.

Commands:

1) The first command implemented is "-n", if you use this you can change the amount of bytes that are read from the file of your choosing. For example, if you file contained "Hello Wordld", if you had -n 5, then it would only print "Hello". 

2) The next command implemented is to apply the Caesar Shift to your output using command "-c", it is a simple encryption in which all the letter will move forward a number of spots to your choice. It only affects alphabetic characters and will only increment them alphabetically. For example, if you file had "A", and you entered -c 2, the output would be "C". Likewise if you had "Y" and put -c 4 the output would be "C". It will do this for each letter of your file.

3) The third command is another encryption using the command "-s". It is essentially the same as ceasar shift but increments every single character, including spaces, numbers, etc. Increments through all 255 ASCII values.

4) The fourth command converts the digits into their hexadecimal values using an algorithm. Using command "-h".

5) The last command converts the digits into their binary values using an algorithm. Using command "-b"

Notes:
- You can use multiple commands at a time, for example you could do "-n 5 -c 3 -b"
- "-c" and "-s" can't be used at the same time
- "-h" and "-b" can't be used at the same time
