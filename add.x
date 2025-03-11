/* add.x - RPC definition file */

struct num{
    int a;
    int b;
};
program ADD_PROG {
    version ADD_VERS {
        int add(num) = 1;
        int sub(num)=2;
        
    } = 1;
} = 0x20000001;
