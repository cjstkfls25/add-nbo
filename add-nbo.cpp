#include <stdio.h>              // for fopen, fread
#include <stdint.h>             // for uint32_t
#include <netinet/in.h>         // for ntohl

int main(int argc, char* argv[]){

    uint32_t n1, n2;

    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "rb");

    fread(&n1, sizeof(n1), 1, fp1);
    fread(&n2, sizeof(n2), 1, fp2);

    n1 = ntohl(n1);
    n2 = ntohl(n2);

    printf("%d(0x%x)  + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);

    fclose(fp1);
    fclose(fp2);
}
