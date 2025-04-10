#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>  // For uintptr_t
#include <unistd.h>  // For getpid()
#define BUFFER_SIZE 512*1024*1024   // buffer for storing text
#define MAX_DEPTH 10
typedef struct {
    char data[BUFFER_SIZE];
    unsigned top;
} Buffer;

Buffer buffer;  // Declare a global buffer

#define extend(c) { \
    buffer.data[buffer.top++] = c; \
}

#define clean() { \
    buffer.top = 0; \
}

unsigned seed;  // Random seed
unsigned branch;  // To hold branch value

typedef void (*Inst)();
Inst *PC;

// xor to get random number
#define xor(l) \
    seed ^= seed << 13; \
    seed ^= seed >> 17; \
    seed ^= seed << 5; \
    branch = seed % l

bool endless = false;

void func_105553170253696(unsigned depth);
void func_105553170253824(unsigned depth);
void func_105553170253952(unsigned depth);
void func_105553170254080(unsigned depth);
void func_105553170254208(unsigned depth);
void func_105553170254400(unsigned depth);
void func_105553170254528(unsigned depth);
void func_105553170254656(unsigned depth);
void func_105553170254784(unsigned depth);
void func_105553170254848(unsigned depth);
void func_105553170254976(unsigned depth);
void func_105553170255104(unsigned depth);
void func_105553170255232(unsigned depth);
void func_105553170255360(unsigned depth);
void func_105553170255488(unsigned depth);
void func_105553170255616(unsigned depth);
void func_105553170255744(unsigned depth);
void func_105553170255872(unsigned depth);
void func_105553170256000(unsigned depth);
void func_105553170256192(unsigned depth);
void func_105553170256320(unsigned depth);
void func_105553170256448(unsigned depth);
void func_105553170256576(unsigned depth);
void func_105553170256704(unsigned depth);
void func_105553170256896(unsigned depth);
void func_105553170257024(unsigned depth);
void func_105553170257152(unsigned depth);
void func_105553170257280(unsigned depth);
void func_105553170256832(unsigned depth);
void func_105553170257472(unsigned depth);
void func_105553170257600(unsigned depth);
void func_105553170257728(unsigned depth);
void func_105553170257856(unsigned depth);
void func_105553170257984(unsigned depth);
void func_105553170258176(unsigned depth);
void func_105553170258304(unsigned depth);
void func_105553170258432(unsigned depth);
void func_105553170258560(unsigned depth);
void func_105553170258688(unsigned depth);
void func_105553170258112(unsigned depth);
void func_105553170258880(unsigned depth);
void func_105553170259008(unsigned depth);
void func_105553170259136(unsigned depth);
void func_105553170259328(unsigned depth);
void func_105553170253696(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(49);
        extend(56);
        return;
    }
    xor(5);
    switch (branch) {
        case 0:
            func_105553170254400(depth+1);
        break;
        case 1:
            func_105553170254848(depth+1);
        break;
        case 2:
            func_105553170255104(depth+1);
        break;
        case 3:
            func_105553170255488(depth+1);
        break;
        case 4:
            func_105553170255872(depth+1);
        break;
    }
    return;
}
void func_105553170253824(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(50);
        extend(56);
        return;
    }
    xor(10);
    switch (branch) {
        case 0:
            func_105553170256192(depth+1);
        break;
        case 1:
            func_105553170256320(depth+1);
        break;
        case 2:
            func_105553170256448(depth+1);
        break;
        case 3:
            func_105553170256576(depth+1);
        break;
        case 4:
            func_105553170256704(depth+1);
        break;
        case 5:
            func_105553170256896(depth+1);
        break;
        case 6:
            func_105553170257024(depth+1);
        break;
        case 7:
            func_105553170257152(depth+1);
        break;
        case 8:
            func_105553170257280(depth+1);
        break;
        case 9:
            func_105553170256832(depth+1);
        break;
    }
    return;
}
void func_105553170253952(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(49);
        extend(56);
        extend(45);
        extend(56);
        extend(50);
        extend(56);
        extend(45);
        extend(48);
        extend(48);
        extend(48);
        extend(57);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_105553170254208(depth+1);
        break;
    }
    return;
}
void func_105553170254080(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(57);
        return;
    }
    xor(9);
    switch (branch) {
        case 0:
            func_105553170257472(depth+1);
        break;
        case 1:
            func_105553170257600(depth+1);
        break;
        case 2:
            func_105553170257728(depth+1);
        break;
        case 3:
            func_105553170257856(depth+1);
        break;
        case 4:
            func_105553170257984(depth+1);
        break;
        case 5:
            func_105553170258176(depth+1);
        break;
        case 6:
            func_105553170258304(depth+1);
        break;
        case 7:
            func_105553170258432(depth+1);
        break;
        case 8:
            func_105553170258560(depth+1);
        break;
    }
    return;
}
void func_105553170254208(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(49);
        extend(56);
        extend(45);
        extend(56);
        extend(50);
        extend(56);
        extend(45);
        extend(48);
        extend(48);
        extend(48);
        extend(57);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_105553170258112(depth+1);
        break;
        case 1:
            func_105553170259328(depth+1);
        break;
    }
    return;
}
void func_105553170254400(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(51);
        extend(48);
        extend(49);
        return;
    }
    func_105553170254528(depth+1);
    func_105553170254656(depth+1);
    func_105553170254784(depth+1);
    return;
}
void func_105553170254528(register unsigned depth) {
    extend(51);
    return;
}
void func_105553170254656(register unsigned depth) {
    extend(48);
    return;
}
void func_105553170254784(register unsigned depth) {
    extend(49);
    return;
}
void func_105553170254848(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(50);
        extend(49);
        extend(50);
        return;
    }
    func_105553170254976(depth+1);
    func_105553170254784(depth+1);
    func_105553170254976(depth+1);
    return;
}
void func_105553170254976(register unsigned depth) {
    extend(50);
    return;
}
void func_105553170255104(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(52);
        extend(49);
        extend(53);
        return;
    }
    func_105553170255232(depth+1);
    func_105553170254784(depth+1);
    func_105553170255360(depth+1);
    return;
}
void func_105553170255232(register unsigned depth) {
    extend(52);
    return;
}
void func_105553170255360(register unsigned depth) {
    extend(53);
    return;
}
void func_105553170255488(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(54);
        extend(49);
        extend(55);
        return;
    }
    func_105553170255616(depth+1);
    func_105553170254784(depth+1);
    func_105553170255744(depth+1);
    return;
}
void func_105553170255616(register unsigned depth) {
    extend(54);
    return;
}
void func_105553170255744(register unsigned depth) {
    extend(55);
    return;
}
void func_105553170255872(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(49);
        extend(56);
        return;
    }
    func_105553170256000(depth+1);
    func_105553170254784(depth+1);
    func_105553170256000(depth+1);
    return;
}
void func_105553170256000(register unsigned depth) {
    extend(56);
    return;
}
void func_105553170256192(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(50);
        extend(48);
        extend(50);
        return;
    }
    func_105553170254976(depth+1);
    func_105553170254656(depth+1);
    func_105553170254976(depth+1);
    return;
}
void func_105553170256320(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(50);
        extend(49);
        extend(51);
        return;
    }
    func_105553170254976(depth+1);
    func_105553170254784(depth+1);
    func_105553170254528(depth+1);
    return;
}
void func_105553170256448(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(52);
        extend(49);
        extend(53);
        return;
    }
    func_105553170255232(depth+1);
    func_105553170254784(depth+1);
    func_105553170255360(depth+1);
    return;
}
void func_105553170256576(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(54);
        extend(49);
        extend(55);
        return;
    }
    func_105553170255616(depth+1);
    func_105553170254784(depth+1);
    func_105553170255744(depth+1);
    return;
}
void func_105553170256704(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(49);
        extend(56);
        return;
    }
    func_105553170256000(depth+1);
    func_105553170254784(depth+1);
    func_105553170256000(depth+1);
    return;
}
void func_105553170256896(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(50);
        extend(51);
        extend(52);
        return;
    }
    func_105553170254976(depth+1);
    func_105553170254528(depth+1);
    func_105553170255232(depth+1);
    return;
}
void func_105553170257024(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(50);
        extend(52);
        extend(53);
        return;
    }
    func_105553170254976(depth+1);
    func_105553170255232(depth+1);
    func_105553170255360(depth+1);
    return;
}
void func_105553170257152(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(52);
        extend(50);
        extend(54);
        return;
    }
    func_105553170255232(depth+1);
    func_105553170254976(depth+1);
    func_105553170255616(depth+1);
    return;
}
void func_105553170257280(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(54);
        extend(50);
        extend(55);
        return;
    }
    func_105553170255616(depth+1);
    func_105553170254976(depth+1);
    func_105553170255744(depth+1);
    return;
}
void func_105553170256832(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(50);
        extend(56);
        return;
    }
    func_105553170256000(depth+1);
    func_105553170254976(depth+1);
    func_105553170256000(depth+1);
    return;
}
void func_105553170257472(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(49);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254784(depth+1);
    return;
}
void func_105553170257600(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(50);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254976(depth+1);
    return;
}
void func_105553170257728(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(51);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254528(depth+1);
    return;
}
void func_105553170257856(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(52);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170255232(depth+1);
    return;
}
void func_105553170257984(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(53);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170255360(depth+1);
    return;
}
void func_105553170258176(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(54);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170255616(depth+1);
    return;
}
void func_105553170258304(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(55);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170255744(depth+1);
    return;
}
void func_105553170258432(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(56);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170256000(depth+1);
    return;
}
void func_105553170258560(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(48);
        extend(48);
        extend(48);
        extend(57);
        return;
    }
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170254656(depth+1);
    func_105553170258688(depth+1);
    return;
}
void func_105553170258688(register unsigned depth) {
    extend(57);
    return;
}
void func_105553170258112(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(40);
        extend(56);
        extend(49);
        extend(56);
        extend(41);
        extend(45);
        extend(56);
        extend(50);
        extend(56);
        extend(45);
        extend(48);
        extend(48);
        extend(48);
        extend(57);
        return;
    }
    func_105553170258880(depth+1);
    func_105553170253696(depth+1);
    func_105553170259008(depth+1);
    func_105553170259136(depth+1);
    func_105553170253824(depth+1);
    func_105553170259136(depth+1);
    func_105553170254080(depth+1);
    return;
}
void func_105553170258880(register unsigned depth) {
    extend(40);
    return;
}
void func_105553170259008(register unsigned depth) {
    extend(41);
    return;
}
void func_105553170259136(register unsigned depth) {
    extend(45);
    return;
}
void func_105553170259328(register unsigned depth) {
    if (depth > MAX_DEPTH) {
        extend(56);
        extend(49);
        extend(56);
        extend(45);
        extend(56);
        extend(50);
        extend(56);
        extend(45);
        extend(48);
        extend(48);
        extend(48);
        extend(57);
        return;
    }
    func_105553170253696(depth+1);
    func_105553170259136(depth+1);
    func_105553170253824(depth+1);
    func_105553170259136(depth+1);
    func_105553170254080(depth+1);
    return;
}
int main(void) {
    static unsigned count = 1;

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    unsigned long timeSeed = (unsigned long)ts.tv_sec * 1000000000L + ts.tv_nsec; // Nanosecond precision
    unsigned long pid = (unsigned long)getpid(); // Process ID
    seed = timeSeed ^ pid; // Combine time and PID for the seed
    while (endless || (count > 0)) {
        func_105553170253952(1);
        count--;
        printf("%.*s\n", (int)buffer.top, buffer.data);
        clean();
    }
    return 0;
}
