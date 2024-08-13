#include <stdio.h>
#include <stdlib.h>

int main() {
    // The C code as a string
    const char *code = "#include <stdio.h>\nint main() { printf(\"Hello\\n\"); return 0; }";

    // Write the code to a temporary file
    FILE *file = fopen("temp_code.c", "w");
    if (file == NULL) {
        printf("Could not create file\n");
        return 1;
    }
    fprintf(file, "%s", code);
    fclose(file);

    // Compile the temporary file using the appropriate command for Windows
    if (system("gcc temp_code.c -o temp_code.exe") != 0) {
        printf("Compilation failed\n");
        return 1;
    }

    // Run the compiled program and capture its output
    FILE *pipe = _popen("temp_code.exe", "r");
    if (!pipe) {
        printf("Execution failed\n");
        return 1;
    }

    char buffer[128];
    printf("Program output:\n");
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }

    _pclose(pipe);

    // Clean up the temporary files
    remove("temp_code.c");
    remove("temp_code.exe");

    return 0;
}
