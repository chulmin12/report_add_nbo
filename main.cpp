#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>

uint32_t getByte(char* dir){
    uint8_t buffer[4];
    FILE *fp = fopen("thousand.bin", "r");
    fread(buffer, sizeof(char), 4, fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
    fclose(fp);
    return *p;
}

uint32_t getByte2(char* dir){
    uint8_t buffer[4];
    FILE *fp = fopen("five-hundred.bin", "r");
    fread(buffer, sizeof(char), 4, fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
    fclose(fp);
    return *p;
}



int main(int argc, char *argv[]) {
    int x = htonl(getByte(argv[1]));
    int y = htonl(getByte2(argv[1]));
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", x, x, y, y, x+y, x+y);
    char name[] = "황철민";
    printf("[sdev][%s]add-nbo",name);

    return 0;
}
