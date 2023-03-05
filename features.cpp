
#include "header.h"


/*
	Change Memory Function: no return value, arguments are size of buffer, and the buffer

	Changes the size of the buffer array
*/

/*
void change_memory(int N, char buffer[])
{
   
    ssize_t size = N;
    
    char* memory = new char[size];

    for (int i = 0; i < size; ++i)
    {
        memory[i] = buffer[i];
    }

    delete[] buffer;

    buffer = memory;
}
*/


/*
	Change Bytes Function: returns the new amount of bytes, the argument is the users input for this feature

	Changes the number of byte to be written
*/

int change_bytes(int N)
{
	// Returns the new amount of bytes
    return N;
}

/*
	Caesar Cipher Function: no return value, arguments are the amount to shift, the string size, and the buffer

	Shifts the ascii value by however much the user wants, only shifts alphabetical characters
*/

void caesar_cipher(int shift, int size, char buffer[])
{
    int i, x;

    // Loop through each character
    for (i = 0; i < size; ++i)
    {
        // Check if upper case
        if (isupper(buffer[i]))
        {
            // Loop through the amount you need to shift the character
            for (x = 0; x < shift; ++x)
            {
                // If you get to Z, go back to A
                if (buffer[i] == 90)
                {
                    buffer[i] = 64;
                }
                buffer[i] += 1;
            }
        }
        // Check if lower case
        else if (islower(buffer[i]))
        {
            // Loop through the amount you need to shift the character
            for (x = 0; x < shift; ++x)
            {
                // If you get to z, go back to a
                if (buffer[i] == 122)
                {
                    buffer[i] = 96;
                }
                buffer[i] += 1;
            }
        }
     }

    
}


/*
	General Shift Function: no return value, arguments are the amount to shift, the string size, and the buffer

	Shifts the ascii value by however much the user wants, any type of character
*/

void general_shift(int shift, int size, char buffer[])
{
    int i, x;

    // Loop through each character
    for (i = 0; i < size; ++i)
    {
        // Loop through the amount you need to shift the character
        for (x = 0; x < shift; ++x)
        {

            // If you get to last ascii value, go back to first
            if (buffer[i] == 255)
            {
                buffer[i] = -1;
            }
            buffer[i] += 1;
        }
    }
}


/*
	Hexadecimal Function: no return value, arguments are the string size and the buffer

	Converts the values into there hexadecimal counterpart
*/

void hexadecimal(int size, char buffer[])
{
	// Declare variables
    int lead_digit, i, j, x, y, z, second_digit;
    y = 0;
    lead_digit = 0;

    // Make a temporary array
    char temp_array[1000] = "";
    
    j = 0;
    z = 1;

	// Loop to go through each value
    for (i = 0; i < size; ++i)
    {
    	// Loop to go up to the value
        for (x = 0; x < buffer[i]; ++x)
        {
        	// Every 16, increment the leading digit by 1
            if (y == 15)
            {
                ++lead_digit;
                y = -1;
            }
            ++y;
        }

		// if the second digit is between 0 and 9, that is the second digit
        if (y >= 0 && y <= 9)
        {
        	second_digit = (y + 48);
        }
        // Otherwise, if between 10 and 15, the second digit is a through f
        else if (y >= 10 && y <= 15)
        {
        	switch (y) {
        	 case 10:
        	 	second_digit = 'a';
        	 	break;
        	 case 11:
        	 	second_digit = 'b';
        	 	break;
        	 case 12:
        	 	second_digit = 'c';
        	 	break;
        	 case 13:
        	 	second_digit = 'd';
        	 	break;
        	 case 14:
        	 	second_digit = 'e';
        	 	break;
        	 case 15:
        	 	second_digit = 'f';
        	 	break;
        	}
        }

		// Put the hexadecimals into the temporary array
        temp_array[j] = lead_digit + 48;
        temp_array[z] = second_digit;
        j += 2;
        z += 2;
        y = 0;
        lead_digit = 0;
    }

	// Copy temporary array into buffer
    strcpy(buffer, temp_array);
}


/*
	Binary Function: no return value, arguments the string size and the buffer

	Converts the numbers into binary counterpart
*/

void binary(int size, char buffer[])
{
	// Counter to incrememnt spot in array
	int counter = 7;

	// Bool to determine whether binary digit should be 1 or 2
	bool yes = false;

	// Create two temporary arrays
	char temp_array[1000];
	char temp_array2[1000] = "";

	// Coppy buffer into first temporary array
	strcpy(temp_array, buffer);

	int i, j;

	// Loop to fill temporary array 2 with all zeroes, 8 times the size
	for (i = 0; i < (size * 8); ++i)
	{
		temp_array2[i] = '0';
	}

	// Loop to go through each value
	for (i = 0; i < size; ++i)
	{
		// Loop to go through the powers of 2
		for (j = 7; j >= 0; --j)
		{
			// Determine if the value is greater than the power of j
			if (temp_array[i] >= pow(2, j))
			{
				// If it is, subtract that from the value and set yes = true
				temp_array[i] = (temp_array[i] - (pow(2,j)));
				yes = true;
			}

			// When yes == true, then turn the correct binary digit into 1
			if (yes == true)
			{
				temp_array2[counter - j] += 1;
				yes = false;
			}
		}

		// Incrememnt the counter to the next 8 numbers
		counter += 8;

	}

	// Copy the temporary array with the binary into the buffer
	strcpy(buffer, temp_array2);
}
