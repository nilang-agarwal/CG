#include <stdio.h>
#include <string.h>

int main() {
    char main_string[] = "Hello, World!";
    char sub_string[] = "World";
    
    char *ptr = strstr(main_string, sub_string);
    
    if (ptr != NULL) {
        int index = ptr - main_string;
        printf("Index of '%s' in '%s' is: %d\n", sub_string, main_string, index);
    } else {
        printf("Substring '%s' not found in '%s'\n", sub_string, main_string);
    }
    
    return 0;
}

