<<<<<<< HEAD
//Comment
=======

>>>>>>> fe6d031e7cf16e3ff5f00bcde6f9ba90641a867f
#include <stdio.h> 
int main() 
{ 
  int n=151, reversedN = 0, remainder, originalN; 
              originalN = n; 
              
  while (n != 0)    
        { 
          remainder = n % 10; 
          reversedN = reversedN * 10 + remainder; n /= 10;  // reversed integer is stored in reversedN 
        }
              if (originalN == reversedN) // palindrome if orignalN and reversedN are equal
              printf("%d is a palindrome.\n\n", originalN); 
              else printf("%d is not a palindrome.", originalN); 
return 0; 
}
<<<<<<< HEAD

=======
>>>>>>> fe6d031e7cf16e3ff5f00bcde6f9ba90641a867f
