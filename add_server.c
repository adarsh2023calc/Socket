#include <stdio.h>
#include "add.h"

// Implement the RPC function
int *add_1_svc(num *nums, struct svc_req *rqstp) {
    static int result;
    result = nums->a + nums->b; // Adding the two numbers
    return &result;
}

int main() {
    register SVCXPRT *transp;

    // Unregister any previous instances
    pmap_unset(ADD_PROG, ADD_VERS);

    // Create UDP service
    transp = svcudp_create(RPC_ANYSOCK);
    if (transp == NULL) {
        fprintf(stderr, "Cannot create UDP service.\n");
        exit(1);
    }
    if (!svc_register(transp, ADD_PROG, ADD_VERS, add_1, IPPROTO_UDP)) {
        fprintf(stderr, "Unable to register (ADD_PROG, ADD_VERS, udp).\n");
        exit(1);
    }

    // Create TCP service
    transp = svctcp_create(RPC_ANYSOCK, 0, 0);
    if (transp == NULL) {
        fprintf(stderr, "Cannot create TCP service.\n");
        exit(1);
    }
    if (!svc_register(transp, ADD_PROG, ADD_VERS, add_prog_1, IPPROTO_TCP)) {
        fprintf(stderr, "Unable to register (ADD_PROG, ADD_VERS, tcp).\n");
        exit(1);
    }

    svc_run(); // Start listening for RPC calls
    fprintf(stderr, "svc_run returned\n");
    exit(1);
}
