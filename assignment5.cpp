/*
 Tyler Stenberg
 
 Assignment 5 - dog
 
 2/24/23

 Purpose: Use multiple source code files
 */




// Include other files
#include "header.h" 

using namespace std;



int main(int argc, char* argv[])
{
    // Declare variables
    int i, file_descriptor, opt, num_chars;
    char buffer[1000];
    int num_a, num_n, num_c, num_s;
    bool check_a, check_n, check_c, check_s, check_h, check_b;
    int feat_count = 1;

	// Bools to check if features were called
    check_a = false;
    check_n = false;
    check_c = false;
    check_s = false;
    check_h = false;
    check_b = false;
    
    ssize_t bytes = 1000;
    ssize_t result;

	// Getopt to check for the commands
    while ((opt = getopt(argc, argv, "a:n:c:s:hb")) != -1)
    {
    	// For commands that take input, use atoi
    	// For each command present set the check to true, increment the feature count
        switch(opt)
        {
            case 'a':
                num_a = atoi(optarg);
                feat_count += 2;
                check_a = true;
                break;
            case 'n':
                num_n = atoi(optarg);
                feat_count += 2;
                check_n = true;
                break;
            case 'c':
                num_c = atoi(optarg);
                feat_count += 2;
                check_c = true;
                break;
            case 's':
                num_s = atoi(optarg);
                feat_count += 2;
                check_s = true;
                break;
            case 'h':
                ++feat_count;
                check_h = true;
                break;
            case 'b':
                ++feat_count;
                check_b = true;
                break;
        }
    }

    // Error check if -s and -c were both used
    if (check_s == true && check_c == true)
    {
        perror("ERROR: Cant use -s and -c");
        exit(1);
    }

    // Error check if -h and -b were both used
    if (check_h == true && check_b == true)
    {
        perror("ERROR: Cant use -h and -b");
        exit(1);
    }

    for (i = (feat_count); i < argc; ++i)
    {
            // Read file
            file_descriptor = open(argv[i], O_RDONLY);

            // Check if file opens
            if(file_descriptor == -1)
            {
                // Error message
                cout << "argv[i]: " << argv[i] << " " << file_descriptor << '\n';
                perror("Opening File Error");
                exit(1);
            }
            
            while(bytes > 0)
            {
                // Read counts the amount of bytes in the file and stores it into bytes variable
                bytes = read(file_descriptor, buffer, 1000);

                // Error check
                if(bytes == -1)
                {
                    // Error message
                    perror("Reading Error");
                    exit(1);
                }


				// If -a feature is present, call change memory function
                if (check_a == true)
                {
                	// i couldnt figure out this feature
                    num_a = 0;
                    if (num_a == 0)
                    {
                    }
                }


                // Check if -n was present
                if (check_n == true)
                {
                    // Call change_bytes function, number of characters to read is now equal to N
                    num_chars = change_bytes(num_n);
                    // Change to false so doesn't repeat
                    check_n = false;
                }
                else
                {
                    // Otherwise just have normal amount of bytes
                    num_chars = bytes;
                }

				// If -c feature is present, call ceasar cipher function
                if (check_c == true)
                {
                    caesar_cipher(num_c, num_chars, buffer);
                }

				// If -s feature is present, call general shift function
                if (check_s == true)
                {
                    general_shift(num_s, num_chars, buffer);
                }

				// If -h feature is present, call hexadecimal function
				if (check_h == true)
				{
					hexadecimal(num_chars, buffer);
					// Set number of characters read to double since each value is 2 digits in hexa
					num_chars = num_chars * 2;
				}

				// If -b feature is present, call binary function
                if (check_b == true)
                {
                	binary(num_chars, buffer);
                	// Set number of characters read to 8 times, since binary is 8 digits per value
                	num_chars = num_chars * 8;
                }
                
                // Sends output
                result = write(1, buffer, num_chars);
                // Can't be negative
                if(result == -1)
                {
                    // Error message
                    perror("Writing Error");
                    exit(1);
                }
            }
            // Closes file
            close(file_descriptor);
            
    }
    
    return 0;
}



