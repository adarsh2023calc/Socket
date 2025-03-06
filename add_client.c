#include <stdio.h>
#include <stdlib.h>
#include "add.h"

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    num num;
    int *result;

    if (argc != 4) {
        printf("Usage: %s <server> <num1> <num2>\n", argv[0]);
        return 1;
    }

    // Get server name and numbers from command line
    char *server = argv[1];
    num.a = atoi(argv[2]);
    num.b = atoi(argv[3]);

    // Create a client handle
    clnt = clnt_create(server, ADD_PROG, ADD_VERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(server);
        return 1;
    }

    // Call the remote procedure
    result = add_1(&num, clnt);
    if (result == 0) {
        clnt_perror(clnt, server);
        return 1;
    }

    printf("Result of %d + %d = %d\n", num.a, num.b, *result);
    
    // Clean up
    clnt_destroy(clnt);
    return 0;
}
