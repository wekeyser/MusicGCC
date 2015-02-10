///////////////////////////////////////////////
//      LAB 3 - EE 285 - Section A           //
//      Spring 2015                  		     //
//      Author: William Keyser               //
//      Instructor: Dr. Daniels              //
//		TA: Quinn Murphey					             //
///////////////////////////////////////////////
 
#include <stdio.h>
#include <math.h>
 
int noteLetter(char letter){		// Which note "letter" was entered?
        switch(letter){				// Here we use a switch to check the note letter and assign it to a note number
                case 'C':
                return -9;
                
                case 'D':
                return -7;
                
                case 'E':
                return -5;
                
				        case 'F':
                return -4;
                
                case 'G':	
                return -2;
                
                case 'A':
                return 0;
                
                case 'B':							 
                return 2;							  
                
                case 'c':
				        return -9;
				
        				case 'd':
				        return -7;
				
				        case 'e':
				        return -5;
				
				        case 'f':
			        	return -4;
				
			        	case 'g':
				        return -2;
				
				        case 'a':
				        return 0;
				
				        case 'b':
				        return 2;
				
				        default:
				        printf("\nInvalid Note, disregard output.\n");
        }
}
 
int noteMod(char modifier){			// Did the user enter a sharp or flat?
        switch(modifier){
                case '#':			// if a sharp is entered...
                return 1;			// add 1 to the note number
 
                case 'b':			// if a flat is entered...
                return -1;			// subtract 1 from the note number
 
                case ' ':			// if no modifier is entered...
				return 0;			// Don't add anything from the note number
				
				default:
				printf("\nInvalid Note, disregard output.\n");
        }
}
 
int noteOct(int octave){			// What octave was entered?
    int diffOct = 0;				// Initialize a variable to represent the octave we are in
	diffOct = octave - 4;			// Offset the octave integer in case it is in octave 4

	if(diffOct == 0){				// If the octave entered minus 4 is 0, we know the octave was 4 and we don't want to take it times four
		return 0;					// Return 0 so 0 is added to the note number
	}
	else{							
		return 12 * diffOct;		// If the octave is not 4, multiply it by 12, to be added to the note number
	}		
}
 
double freq(int halfSteps){			// This function does the math:
	double a = 0.0;					// The formula is: f = 440 * (2^(1/12))^n 
	double twelfth = 0.083333;		// twelfth is simply that... 1/12
	double freqTone = 0.0;			// freqTone = the frequency of the note in question
	double aToTheN = 0.0;			// n = the number of half-steps below A 440
	
	a = pow(2, twelfth);			// A = 2^(1/12)
	aToTheN = pow(a, halfSteps);	// A^n = A^halfSteps
	freqTone = 440 * aToTheN;		// f = 440 * a ^ n

	return freqTone;				// return the result of the above math
}

int main(){							// Our main frequency
	char letter;					// A variable to store the letter
	char modifier; 					// Sharps or flats
	int octave = 0;					// The integer representing the octave
	int halfSteps = 0;				// The numer of half-steps below A 440

	printf("\nEE 285 - Lab 3\nWill Keyser\nSpring 2015\n");
	printf("\nEnter a note.  (Format: Letter, Modifier, Octave)\n\n");
	scanf(" %c%c%d", &letter, &modifier, &octave);
	printf("\n%c%c%d\n", letter, modifier, octave);

	halfSteps = noteLetter(letter);					// Assign the note in question a value by the letter
	halfSteps = halfSteps + noteMod(modifier);		// Check for a modifier character and add or subtract accordingly
	halfSteps = halfSteps + noteOct(octave);		// Modify the integer representation proportionally to the octave the note is in

	printf("%2.2lf Hz\n\n", freq(halfSteps));		// Print the frequency
    
	return 0;										// Program ends here
}
