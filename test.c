#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 512*1024*1024   // buffer for storing text
#define MAX_DEPTH 100
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

void func_5325771696(unsigned depth);
void func_5325771824(unsigned depth);
void func_5325771984(unsigned depth);
void func_5325773392(unsigned depth);
void func_5325771440(unsigned depth);
void func_5325772256(unsigned depth);
void func_5325772480(unsigned depth);
void func_5325771328(unsigned depth);
void func_5325772912(unsigned depth);
void func_5325772752(unsigned depth);
void func_5325772672(unsigned depth);
void func_5325773648(unsigned depth);
void func_5325773520(unsigned depth);
void func_5325774784(unsigned depth);
void func_5325773904(unsigned depth);
void func_5325774512(unsigned depth);
void func_5325774640(unsigned depth);
void func_5325773040(unsigned depth);
void func_5325772976(unsigned depth);
void func_5325774416(unsigned depth);
void func_5325773840(unsigned depth);
void func_5325775024(unsigned depth);
void func_5325775152(unsigned depth);
void func_5325775360(unsigned depth);
void func_5325775280(unsigned depth);
void func_5325775936(unsigned depth);
void func_5325775600(unsigned depth);
void func_5325774224(unsigned depth);
void func_5325776144(unsigned depth);
void func_5325775728(unsigned depth);
void func_5325775856(unsigned depth);
void func_5325776624(unsigned depth);
void func_5325776752(unsigned depth);
void func_5325776528(unsigned depth);
void func_5325777488(unsigned depth);
void func_5325777616(unsigned depth);
void func_5325777744(unsigned depth);
void func_5325777872(unsigned depth);
void func_5325777360(unsigned depth);
void func_5325778032(unsigned depth);
void func_5325778192(unsigned depth);
void func_5325778320(unsigned depth);
void func_5325779552(unsigned depth);
void func_5325779680(unsigned depth);
void func_5325779808(unsigned depth);
void func_5325779968(unsigned depth);
void func_5325780096(unsigned depth);
void func_5325780288(unsigned depth);
void func_5325780416(unsigned depth);
void func_5325780544(unsigned depth);
void func_5325780672(unsigned depth);
void func_5325780224(unsigned depth);
void func_5325780992(unsigned depth);
void func_5325781120(unsigned depth);
void func_5325781248(unsigned depth);
void func_5325781376(unsigned depth);
void func_5325781504(unsigned depth);
void func_5325781632(unsigned depth);
void func_5325781760(unsigned depth);
void func_5325780800(unsigned depth);
void func_5325782144(unsigned depth);
void func_5325782272(unsigned depth);
void func_5325782400(unsigned depth);
void func_5325782528(unsigned depth);
void func_5325782656(unsigned depth);
void func_5325776880(unsigned depth);
void func_5325777008(unsigned depth);
void func_5325777136(unsigned depth);
void func_5325776336(unsigned depth);
void func_5325778528(unsigned depth);
void func_5325777264(unsigned depth);
void func_5325779040(unsigned depth);
void func_5325779168(unsigned depth);
void func_5325779296(unsigned depth);
void func_5325779424(unsigned depth);
void func_5325778896(unsigned depth);
void func_5325782720(unsigned depth);
void func_5325783088(unsigned depth);
void func_5325783216(unsigned depth);
void func_5325783344(unsigned depth);
void func_5325783504(unsigned depth);
void func_5325783632(unsigned depth);
void func_5325783824(unsigned depth);
void func_5325783952(unsigned depth);
void func_5325784080(unsigned depth);
void func_5325784208(unsigned depth);
void func_5325783760(unsigned depth);
void func_5325778720(unsigned depth);
void func_5325782848(unsigned depth);
void func_5325782976(unsigned depth);
void func_5325785040(unsigned depth);
void func_5325785168(unsigned depth);
void func_5325786112(unsigned depth);
void func_5325786240(unsigned depth);
void func_5325786368(unsigned depth);
void func_5325786528(unsigned depth);
void func_5325786656(unsigned depth);
void func_5325786848(unsigned depth);
void func_5325786976(unsigned depth);
void func_5325787104(unsigned depth);
void func_5325787232(unsigned depth);
void func_5325786784(unsigned depth);
void func_5325787552(unsigned depth);
void func_5325787680(unsigned depth);
void func_5325787808(unsigned depth);
void func_5325787936(unsigned depth);
void func_5325788064(unsigned depth);
void func_5325788192(unsigned depth);
void func_5325788320(unsigned depth);
void func_5325787360(unsigned depth);
void func_5325788704(unsigned depth);
void func_5325788832(unsigned depth);
void func_5325788960(unsigned depth);
void func_5325789088(unsigned depth);
void func_5325789216(unsigned depth);
void func_5325789344(unsigned depth);
void func_5325789472(unsigned depth);
void func_5325789600(unsigned depth);
void func_5325784800(unsigned depth);
void func_5325785360(unsigned depth);
void func_5325785488(unsigned depth);
void func_5325785616(unsigned depth);
void func_5325785744(unsigned depth);
void func_5325785936(unsigned depth);
void func_5325789728(unsigned depth);
void func_5325789856(unsigned depth);
void func_5325789984(unsigned depth);
void func_5325785872(unsigned depth);
void func_5325790992(unsigned depth);
void func_5325791120(unsigned depth);
void func_5325791248(unsigned depth);
void func_5325791376(unsigned depth);
void func_5325790928(unsigned depth);
void func_5325784672(unsigned depth);
void func_5325790448(unsigned depth);
void func_5325790576(unsigned depth);
void func_5325790704(unsigned depth);
void func_5325790304(unsigned depth);
void func_5325791984(unsigned depth);
void func_5325792112(unsigned depth);
void func_5325792304(unsigned depth);
void func_5325792432(unsigned depth);
void func_5325792560(unsigned depth);
void func_5325792688(unsigned depth);
void func_5325791872(unsigned depth);
void func_5325791792(unsigned depth);
void func_5325791712(unsigned depth);
void func_5325791632(unsigned depth);
void func_5325793344(unsigned depth);
void func_5325793088(unsigned depth);
void func_5325793952(unsigned depth);
void func_5325794080(unsigned depth);
void func_5325794272(unsigned depth);
void func_5325794400(unsigned depth);
void func_5325794560(unsigned depth);
void func_5325794688(unsigned depth);
void func_5325794848(unsigned depth);
void func_5325794976(unsigned depth);
void func_5325793552(unsigned depth);
void func_5325793680(unsigned depth);
void func_5325793808(unsigned depth);
void func_5325793008(unsigned depth);
void func_5325795712(unsigned depth);
void func_5325795904(unsigned depth);
void func_5325796160(unsigned depth);
void func_5325795600(unsigned depth);
void func_5325796096(unsigned depth);
void func_5325795296(unsigned depth);
void func_5325796384(unsigned depth);
void func_5325796512(unsigned depth);
void func_5325796720(unsigned depth);
void func_5325796288(unsigned depth);
void func_5325796992(unsigned depth);
void func_5325771696(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325777488(depth+1);
        break;
        case 1:
            func_5325777744(depth+1);
        break;
        case 2:
            func_5325774416(depth+1);
        break;
    }
    return;
}
void func_5325771824(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325777360(depth+1);
        break;
        case 1:
            func_5325771984(depth+1);
        break;
    }
    return;
}
void func_5325771984(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325778192(depth+1);
        break;
        case 1:
            func_5325773040(depth+1);
        break;
    }
    return;
}
void func_5325773392(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(26);
    switch (branch) {
        case 0:
            func_5325779552(depth+1);
        break;
        case 1:
            func_5325779680(depth+1);
        break;
        case 2:
            func_5325779808(depth+1);
        break;
        case 3:
            func_5325779968(depth+1);
        break;
        case 4:
            func_5325780096(depth+1);
        break;
        case 5:
            func_5325780288(depth+1);
        break;
        case 6:
            func_5325780416(depth+1);
        break;
        case 7:
            func_5325780544(depth+1);
        break;
        case 8:
            func_5325780672(depth+1);
        break;
        case 9:
            func_5325780224(depth+1);
        break;
        case 10:
            func_5325780992(depth+1);
        break;
        case 11:
            func_5325781120(depth+1);
        break;
        case 12:
            func_5325781248(depth+1);
        break;
        case 13:
            func_5325781376(depth+1);
        break;
        case 14:
            func_5325781504(depth+1);
        break;
        case 15:
            func_5325781632(depth+1);
        break;
        case 16:
            func_5325781760(depth+1);
        break;
        case 17:
            func_5325780800(depth+1);
        break;
        case 18:
            func_5325782144(depth+1);
        break;
        case 19:
            func_5325782272(depth+1);
        break;
        case 20:
            func_5325782400(depth+1);
        break;
        case 21:
            func_5325782528(depth+1);
        break;
        case 22:
            func_5325782656(depth+1);
        break;
        case 23:
            func_5325776880(depth+1);
        break;
        case 24:
            func_5325777008(depth+1);
        break;
        case 25:
            func_5325777136(depth+1);
        break;
    }
    return;
}
void func_5325771440(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325776336(depth+1);
        break;
    }
    return;
}
void func_5325772256(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325773904(depth+1);
        break;
        case 1:
            func_5325773648(depth+1);
        break;
        case 2:
            func_5325773392(depth+1);
        break;
    }
    return;
}
void func_5325772480(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325778528(depth+1);
        break;
        case 1:
            func_5325777264(depth+1);
        break;
    }
    return;
}
void func_5325771328(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(59);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325776528(depth+1);
        break;
        case 1:
            func_5325773520(depth+1);
        break;
    }
    return;
}
void func_5325772912(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325779040(depth+1);
        break;
        case 1:
            func_5325779296(depth+1);
        break;
        case 2:
            func_5325775936(depth+1);
        break;
    }
    return;
}
void func_5325772752(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(59);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325778896(depth+1);
        break;
        case 1:
            func_5325782720(depth+1);
        break;
    }
    return;
}
void func_5325772672(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325771984(depth+1);
        break;
    }
    return;
}
void func_5325773648(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(57);
        extend(46);
        extend(48);
        return;
    }
    xor(10);
    switch (branch) {
        case 0:
            func_5325783088(depth+1);
        break;
        case 1:
            func_5325783216(depth+1);
        break;
        case 2:
            func_5325783344(depth+1);
        break;
        case 3:
            func_5325783504(depth+1);
        break;
        case 4:
            func_5325783632(depth+1);
        break;
        case 5:
            func_5325783824(depth+1);
        break;
        case 6:
            func_5325783952(depth+1);
        break;
        case 7:
            func_5325784080(depth+1);
        break;
        case 8:
            func_5325784208(depth+1);
        break;
        case 9:
            func_5325783760(depth+1);
        break;
    }
    return;
}
void func_5325773520(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325778720(depth+1);
        break;
    }
    return;
}
void func_5325774784(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(122);
        return;
    }
    xor(26);
    switch (branch) {
        case 0:
            func_5325786112(depth+1);
        break;
        case 1:
            func_5325786240(depth+1);
        break;
        case 2:
            func_5325786368(depth+1);
        break;
        case 3:
            func_5325786528(depth+1);
        break;
        case 4:
            func_5325786656(depth+1);
        break;
        case 5:
            func_5325786848(depth+1);
        break;
        case 6:
            func_5325786976(depth+1);
        break;
        case 7:
            func_5325787104(depth+1);
        break;
        case 8:
            func_5325787232(depth+1);
        break;
        case 9:
            func_5325786784(depth+1);
        break;
        case 10:
            func_5325787552(depth+1);
        break;
        case 11:
            func_5325787680(depth+1);
        break;
        case 12:
            func_5325787808(depth+1);
        break;
        case 13:
            func_5325787936(depth+1);
        break;
        case 14:
            func_5325788064(depth+1);
        break;
        case 15:
            func_5325788192(depth+1);
        break;
        case 16:
            func_5325788320(depth+1);
        break;
        case 17:
            func_5325787360(depth+1);
        break;
        case 18:
            func_5325788704(depth+1);
        break;
        case 19:
            func_5325788832(depth+1);
        break;
        case 20:
            func_5325788960(depth+1);
        break;
        case 21:
            func_5325789088(depth+1);
        break;
        case 22:
            func_5325789216(depth+1);
        break;
        case 23:
            func_5325789344(depth+1);
        break;
        case 24:
            func_5325789472(depth+1);
        break;
        case 25:
            func_5325789600(depth+1);
        break;
    }
    return;
}
void func_5325773904(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(57);
        return;
    }
    xor(10);
    switch (branch) {
        case 0:
            func_5325784800(depth+1);
        break;
        case 1:
            func_5325785360(depth+1);
        break;
        case 2:
            func_5325785488(depth+1);
        break;
        case 3:
            func_5325785616(depth+1);
        break;
        case 4:
            func_5325785744(depth+1);
        break;
        case 5:
            func_5325785936(depth+1);
        break;
        case 6:
            func_5325789728(depth+1);
        break;
        case 7:
            func_5325789856(depth+1);
        break;
        case 8:
            func_5325789984(depth+1);
        break;
        case 9:
            func_5325785872(depth+1);
        break;
    }
    return;
}
void func_5325774512(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(102);
        extend(111);
        extend(114);
        extend(40);
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(59);
        extend(59);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325790992(depth+1);
        break;
        case 1:
            func_5325791248(depth+1);
        break;
        case 2:
            func_5325790928(depth+1);
        break;
    }
    return;
}
void func_5325774640(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325784672(depth+1);
        break;
        case 1:
            func_5325772912(depth+1);
        break;
    }
    return;
}
void func_5325773040(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325790576(depth+1);
        break;
        case 1:
            func_5325774640(depth+1);
        break;
    }
    return;
}
void func_5325772976(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(110);
        extend(116);
        extend(109);
        extend(97);
        extend(105);
        extend(110);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325790304(depth+1);
        break;
    }
    return;
}
void func_5325774416(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325792304(depth+1);
        break;
        case 1:
            func_5325792560(depth+1);
        break;
        case 2:
            func_5325776752(depth+1);
        break;
    }
    return;
}
void func_5325773840(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325791872(depth+1);
        break;
        case 1:
            func_5325775024(depth+1);
        break;
        case 2:
            func_5325791792(depth+1);
        break;
    }
    return;
}
void func_5325775024(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325791712(depth+1);
        break;
    }
    return;
}
void func_5325775152(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325775360(depth+1);
        break;
        case 1:
            func_5325791632(depth+1);
        break;
    }
    return;
}
void func_5325775360(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325774784(depth+1);
        break;
        case 1:
            func_5325772256(depth+1);
        break;
        case 2:
            func_5325793344(depth+1);
        break;
    }
    return;
}
void func_5325775280(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(110);
        extend(116);
        extend(109);
        extend(97);
        extend(105);
        extend(110);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325793088(depth+1);
        break;
    }
    return;
}
void func_5325775936(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(5);
    switch (branch) {
        case 0:
            func_5325793952(depth+1);
        break;
        case 1:
            func_5325794272(depth+1);
        break;
        case 2:
            func_5325794560(depth+1);
        break;
        case 3:
            func_5325794848(depth+1);
        break;
        case 4:
            func_5325771696(depth+1);
        break;
    }
    return;
}
void func_5325775600(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(114);
        extend(101);
        extend(116);
        extend(117);
        extend(114);
        extend(110);
        extend(59);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325793552(depth+1);
        break;
        case 1:
            func_5325793808(depth+1);
        break;
    }
    return;
}
void func_5325774224(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(102);
        extend(40);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325793008(depth+1);
        break;
        case 1:
            func_5325796160(depth+1);
        break;
    }
    return;
}
void func_5325776144(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(110);
        extend(116);
        extend(109);
        extend(97);
        extend(105);
        extend(110);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325775280(depth+1);
        break;
    }
    return;
}
void func_5325775728(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    xor(2);
    switch (branch) {
        case 0:
            func_5325795600(depth+1);
        break;
        case 1:
            func_5325796096(depth+1);
        break;
    }
    return;
}
void func_5325775856(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(59);
        return;
    }
    xor(5);
    switch (branch) {
        case 0:
            func_5325772752(depth+1);
        break;
        case 1:
            func_5325771440(depth+1);
        break;
        case 2:
            func_5325774224(depth+1);
        break;
        case 3:
            func_5325774512(depth+1);
        break;
        case 4:
            func_5325775600(depth+1);
        break;
    }
    return;
}
void func_5325776624(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        return;
    }
    xor(4);
    switch (branch) {
        case 0:
            func_5325791984(depth+1);
        break;
        case 1:
            func_5325795296(depth+1);
        break;
        case 2:
            func_5325796384(depth+1);
        break;
        case 3:
            func_5325796512(depth+1);
        break;
    }
    return;
}
void func_5325776752(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    xor(3);
    switch (branch) {
        case 0:
            func_5325796720(depth+1);
        break;
        case 1:
            func_5325796288(depth+1);
        break;
        case 2:
            func_5325775152(depth+1);
        break;
    }
    return;
}
void func_5325776528(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(59);
        return;
    }
    xor(1);
    switch (branch) {
        case 0:
            func_5325796992(depth+1);
        break;
    }
    return;
}
void func_5325777488(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(43);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325774416(depth+1);
    func_5325777616(depth+1);
    func_5325771696(depth+1);
    return;
}
void func_5325777616(register unsigned depth) {
    extend(43);
    return;
}
void func_5325777744(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(45);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325774416(depth+1);
    func_5325777872(depth+1);
    func_5325771696(depth+1);
    return;
}
void func_5325777872(register unsigned depth) {
    extend(45);
    return;
}
void func_5325777360(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(44);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325771984(depth+1);
    func_5325778032(depth+1);
    func_5325771824(depth+1);
    return;
}
void func_5325778032(register unsigned depth) {
    extend(44);
    return;
}
void func_5325778192(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(61);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325773040(depth+1);
    func_5325778320(depth+1);
    func_5325771984(depth+1);
    return;
}
void func_5325778320(register unsigned depth) {
    extend(61);
    return;
}
void func_5325779552(register unsigned depth) {
    extend(39);
    extend(97);
    extend(39);
    return;
}
void func_5325779680(register unsigned depth) {
    extend(39);
    extend(98);
    extend(39);
    return;
}
void func_5325779808(register unsigned depth) {
    extend(39);
    extend(99);
    extend(39);
    return;
}
void func_5325779968(register unsigned depth) {
    extend(39);
    extend(100);
    extend(39);
    return;
}
void func_5325780096(register unsigned depth) {
    extend(39);
    extend(101);
    extend(39);
    return;
}
void func_5325780288(register unsigned depth) {
    extend(39);
    extend(102);
    extend(39);
    return;
}
void func_5325780416(register unsigned depth) {
    extend(39);
    extend(103);
    extend(39);
    return;
}
void func_5325780544(register unsigned depth) {
    extend(39);
    extend(104);
    extend(39);
    return;
}
void func_5325780672(register unsigned depth) {
    extend(39);
    extend(105);
    extend(39);
    return;
}
void func_5325780224(register unsigned depth) {
    extend(39);
    extend(106);
    extend(39);
    return;
}
void func_5325780992(register unsigned depth) {
    extend(39);
    extend(107);
    extend(39);
    return;
}
void func_5325781120(register unsigned depth) {
    extend(39);
    extend(108);
    extend(39);
    return;
}
void func_5325781248(register unsigned depth) {
    extend(39);
    extend(109);
    extend(39);
    return;
}
void func_5325781376(register unsigned depth) {
    extend(39);
    extend(110);
    extend(39);
    return;
}
void func_5325781504(register unsigned depth) {
    extend(39);
    extend(111);
    extend(39);
    return;
}
void func_5325781632(register unsigned depth) {
    extend(39);
    extend(112);
    extend(39);
    return;
}
void func_5325781760(register unsigned depth) {
    extend(39);
    extend(113);
    extend(39);
    return;
}
void func_5325780800(register unsigned depth) {
    extend(39);
    extend(114);
    extend(39);
    return;
}
void func_5325782144(register unsigned depth) {
    extend(39);
    extend(115);
    extend(39);
    return;
}
void func_5325782272(register unsigned depth) {
    extend(39);
    extend(116);
    extend(39);
    return;
}
void func_5325782400(register unsigned depth) {
    extend(39);
    extend(117);
    extend(39);
    return;
}
void func_5325782528(register unsigned depth) {
    extend(39);
    extend(118);
    extend(39);
    return;
}
void func_5325782656(register unsigned depth) {
    extend(39);
    extend(119);
    extend(39);
    return;
}
void func_5325776880(register unsigned depth) {
    extend(39);
    extend(120);
    extend(39);
    return;
}
void func_5325777008(register unsigned depth) {
    extend(39);
    extend(121);
    extend(39);
    return;
}
void func_5325777136(register unsigned depth) {
    extend(39);
    extend(122);
    extend(39);
    return;
}
void func_5325776336(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    func_5325772480(depth+1);
    func_5325775728(depth+1);
    return;
}
void func_5325778528(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(59);
        return;
    }
    func_5325771328(depth+1);
    func_5325772480(depth+1);
    return;
}
void func_5325777264(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    return;
}
void func_5325779040(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(61);
        extend(61);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325775936(depth+1);
    func_5325779168(depth+1);
    func_5325772912(depth+1);
    return;
}
void func_5325779168(register unsigned depth) {
    extend(61);
    extend(61);
    return;
}
void func_5325779296(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(33);
        extend(61);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325775936(depth+1);
    func_5325779424(depth+1);
    func_5325772912(depth+1);
    return;
}
void func_5325779424(register unsigned depth) {
    extend(33);
    extend(61);
    return;
}
void func_5325778896(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(59);
        return;
    }
    func_5325772672(depth+1);
    func_5325782720(depth+1);
    return;
}
void func_5325782720(register unsigned depth) {
    extend(59);
    return;
}
void func_5325783088(register unsigned depth) {
    extend(48);
    extend(46);
    extend(48);
    return;
}
void func_5325783216(register unsigned depth) {
    extend(49);
    extend(46);
    extend(48);
    return;
}
void func_5325783344(register unsigned depth) {
    extend(50);
    extend(46);
    extend(48);
    return;
}
void func_5325783504(register unsigned depth) {
    extend(51);
    extend(46);
    extend(48);
    return;
}
void func_5325783632(register unsigned depth) {
    extend(52);
    extend(46);
    extend(48);
    return;
}
void func_5325783824(register unsigned depth) {
    extend(53);
    extend(46);
    extend(48);
    return;
}
void func_5325783952(register unsigned depth) {
    extend(54);
    extend(46);
    extend(48);
    return;
}
void func_5325784080(register unsigned depth) {
    extend(55);
    extend(46);
    extend(48);
    return;
}
void func_5325784208(register unsigned depth) {
    extend(56);
    extend(46);
    extend(48);
    return;
}
void func_5325783760(register unsigned depth) {
    extend(57);
    extend(46);
    extend(48);
    return;
}
void func_5325778720(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    func_5325776624(depth+1);
    func_5325774784(depth+1);
    func_5325782848(depth+1);
    func_5325773840(depth+1);
    func_5325782976(depth+1);
    func_5325785040(depth+1);
    func_5325771440(depth+1);
    func_5325785168(depth+1);
    return;
}
void func_5325782848(register unsigned depth) {
    extend(40);
    return;
}
void func_5325782976(register unsigned depth) {
    extend(41);
    return;
}
void func_5325785040(register unsigned depth) {
    extend(123);
    return;
}
void func_5325785168(register unsigned depth) {
    extend(125);
    return;
}
void func_5325786112(register unsigned depth) {
    extend(97);
    return;
}
void func_5325786240(register unsigned depth) {
    extend(98);
    return;
}
void func_5325786368(register unsigned depth) {
    extend(99);
    return;
}
void func_5325786528(register unsigned depth) {
    extend(100);
    return;
}
void func_5325786656(register unsigned depth) {
    extend(101);
    return;
}
void func_5325786848(register unsigned depth) {
    extend(102);
    return;
}
void func_5325786976(register unsigned depth) {
    extend(103);
    return;
}
void func_5325787104(register unsigned depth) {
    extend(104);
    return;
}
void func_5325787232(register unsigned depth) {
    extend(105);
    return;
}
void func_5325786784(register unsigned depth) {
    extend(106);
    return;
}
void func_5325787552(register unsigned depth) {
    extend(107);
    return;
}
void func_5325787680(register unsigned depth) {
    extend(108);
    return;
}
void func_5325787808(register unsigned depth) {
    extend(109);
    return;
}
void func_5325787936(register unsigned depth) {
    extend(110);
    return;
}
void func_5325788064(register unsigned depth) {
    extend(111);
    return;
}
void func_5325788192(register unsigned depth) {
    extend(112);
    return;
}
void func_5325788320(register unsigned depth) {
    extend(113);
    return;
}
void func_5325787360(register unsigned depth) {
    extend(114);
    return;
}
void func_5325788704(register unsigned depth) {
    extend(115);
    return;
}
void func_5325788832(register unsigned depth) {
    extend(116);
    return;
}
void func_5325788960(register unsigned depth) {
    extend(117);
    return;
}
void func_5325789088(register unsigned depth) {
    extend(118);
    return;
}
void func_5325789216(register unsigned depth) {
    extend(119);
    return;
}
void func_5325789344(register unsigned depth) {
    extend(120);
    return;
}
void func_5325789472(register unsigned depth) {
    extend(121);
    return;
}
void func_5325789600(register unsigned depth) {
    extend(122);
    return;
}
void func_5325784800(register unsigned depth) {
    extend(48);
    return;
}
void func_5325785360(register unsigned depth) {
    extend(49);
    return;
}
void func_5325785488(register unsigned depth) {
    extend(50);
    return;
}
void func_5325785616(register unsigned depth) {
    extend(51);
    return;
}
void func_5325785744(register unsigned depth) {
    extend(52);
    return;
}
void func_5325785936(register unsigned depth) {
    extend(53);
    return;
}
void func_5325789728(register unsigned depth) {
    extend(54);
    return;
}
void func_5325789856(register unsigned depth) {
    extend(55);
    return;
}
void func_5325789984(register unsigned depth) {
    extend(56);
    return;
}
void func_5325785872(register unsigned depth) {
    extend(57);
    return;
}
void func_5325790992(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(119);
        extend(104);
        extend(105);
        extend(108);
        extend(101);
        extend(40);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        return;
    }
    func_5325791120(depth+1);
    func_5325782848(depth+1);
    func_5325772672(depth+1);
    func_5325782976(depth+1);
    func_5325775856(depth+1);
    return;
}
void func_5325791120(register unsigned depth) {
    extend(119);
    extend(104);
    extend(105);
    extend(108);
    extend(101);
    return;
}
void func_5325791248(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(102);
        extend(111);
        extend(114);
        extend(40);
        extend(59);
        extend(59);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        return;
    }
    func_5325791376(depth+1);
    func_5325782848(depth+1);
    func_5325772752(depth+1);
    func_5325772752(depth+1);
    func_5325772672(depth+1);
    func_5325782976(depth+1);
    func_5325775856(depth+1);
    return;
}
void func_5325791376(register unsigned depth) {
    extend(102);
    extend(111);
    extend(114);
    return;
}
void func_5325790928(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(102);
        extend(111);
        extend(114);
        extend(40);
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(59);
        extend(59);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        return;
    }
    func_5325791376(depth+1);
    func_5325782848(depth+1);
    func_5325771328(depth+1);
    func_5325772752(depth+1);
    func_5325772672(depth+1);
    func_5325782976(depth+1);
    func_5325775856(depth+1);
    return;
}
void func_5325784672(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(38);
        extend(38);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325772912(depth+1);
    func_5325790448(depth+1);
    func_5325774640(depth+1);
    return;
}
void func_5325790448(register unsigned depth) {
    extend(38);
    extend(38);
    return;
}
void func_5325790576(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(124);
        extend(124);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325774640(depth+1);
    func_5325790704(depth+1);
    func_5325773040(depth+1);
    return;
}
void func_5325790704(register unsigned depth) {
    extend(124);
    extend(124);
    return;
}
void func_5325790304(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(110);
        extend(116);
        extend(109);
        extend(97);
        extend(105);
        extend(110);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    func_5325791984(depth+1);
    func_5325792112(depth+1);
    func_5325782848(depth+1);
    func_5325782976(depth+1);
    func_5325785040(depth+1);
    func_5325771440(depth+1);
    func_5325785168(depth+1);
    return;
}
void func_5325791984(register unsigned depth) {
    extend(105);
    extend(110);
    extend(116);
    return;
}
void func_5325792112(register unsigned depth) {
    extend(109);
    extend(97);
    extend(105);
    extend(110);
    return;
}
void func_5325792304(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(42);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325776752(depth+1);
    func_5325792432(depth+1);
    func_5325774416(depth+1);
    return;
}
void func_5325792432(register unsigned depth) {
    extend(42);
    return;
}
void func_5325792560(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(47);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325776752(depth+1);
    func_5325792688(depth+1);
    func_5325774416(depth+1);
    return;
}
void func_5325792688(register unsigned depth) {
    extend(47);
    return;
}
void func_5325791872(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(44);
        return;
    }
    func_5325775024(depth+1);
    func_5325778032(depth+1);
    func_5325773840(depth+1);
    return;
}
void func_5325791792(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    return;
}
void func_5325791712(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        return;
    }
    func_5325776624(depth+1);
    func_5325774784(depth+1);
    return;
}
void func_5325791632(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(40);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        return;
    }
    func_5325775152(depth+1);
    func_5325782848(depth+1);
    func_5325771824(depth+1);
    func_5325782976(depth+1);
    return;
}
void func_5325793344(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(40);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        return;
    }
    func_5325782848(depth+1);
    func_5325772672(depth+1);
    func_5325782976(depth+1);
    return;
}
void func_5325793088(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(110);
        extend(116);
        extend(109);
        extend(97);
        extend(105);
        extend(110);
        extend(40);
        extend(41);
        extend(123);
        extend(125);
        return;
    }
    func_5325772480(depth+1);
    func_5325772976(depth+1);
    return;
}
void func_5325793952(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(60);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325771696(depth+1);
    func_5325794080(depth+1);
    func_5325775936(depth+1);
    return;
}
void func_5325794080(register unsigned depth) {
    extend(60);
    return;
}
void func_5325794272(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(62);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325771696(depth+1);
    func_5325794400(depth+1);
    func_5325775936(depth+1);
    return;
}
void func_5325794400(register unsigned depth) {
    extend(62);
    return;
}
void func_5325794560(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(60);
        extend(61);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325771696(depth+1);
    func_5325794688(depth+1);
    func_5325775936(depth+1);
    return;
}
void func_5325794688(register unsigned depth) {
    extend(60);
    extend(61);
    return;
}
void func_5325794848(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(39);
        extend(122);
        extend(39);
        extend(62);
        extend(61);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325771696(depth+1);
    func_5325794976(depth+1);
    func_5325775936(depth+1);
    return;
}
void func_5325794976(register unsigned depth) {
    extend(62);
    extend(61);
    return;
}
void func_5325793552(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(114);
        extend(101);
        extend(116);
        extend(117);
        extend(114);
        extend(110);
        extend(39);
        extend(122);
        extend(39);
        extend(59);
        return;
    }
    func_5325793680(depth+1);
    func_5325772672(depth+1);
    func_5325782720(depth+1);
    return;
}
void func_5325793680(register unsigned depth) {
    extend(114);
    extend(101);
    extend(116);
    extend(117);
    extend(114);
    extend(110);
    return;
}
void func_5325793808(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(114);
        extend(101);
        extend(116);
        extend(117);
        extend(114);
        extend(110);
        extend(59);
        return;
    }
    func_5325793680(depth+1);
    func_5325782720(depth+1);
    return;
}
void func_5325793008(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(102);
        extend(40);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        extend(101);
        extend(108);
        extend(115);
        extend(101);
        extend(59);
        return;
    }
    func_5325795712(depth+1);
    func_5325782848(depth+1);
    func_5325772672(depth+1);
    func_5325782976(depth+1);
    func_5325775856(depth+1);
    func_5325795904(depth+1);
    func_5325775856(depth+1);
    return;
}
void func_5325795712(register unsigned depth) {
    extend(105);
    extend(102);
    return;
}
void func_5325795904(register unsigned depth) {
    extend(101);
    extend(108);
    extend(115);
    extend(101);
    return;
}
void func_5325796160(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(105);
        extend(102);
        extend(40);
        extend(39);
        extend(122);
        extend(39);
        extend(41);
        extend(59);
        return;
    }
    func_5325795712(depth+1);
    func_5325782848(depth+1);
    func_5325772672(depth+1);
    func_5325782976(depth+1);
    func_5325775856(depth+1);
    return;
}
void func_5325795600(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(59);
        return;
    }
    func_5325775856(depth+1);
    func_5325775728(depth+1);
    return;
}
void func_5325796096(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        return;
    }
    return;
}
void func_5325795296(register unsigned depth) {
    extend(102);
    extend(108);
    extend(111);
    extend(97);
    extend(116);
    return;
}
void func_5325796384(register unsigned depth) {
    extend(99);
    extend(104);
    extend(97);
    extend(114);
    return;
}
void func_5325796512(register unsigned depth) {
    extend(118);
    extend(111);
    extend(105);
    extend(100);
    return;
}
void func_5325796720(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(43);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325777616(depth+1);
    func_5325776752(depth+1);
    return;
}
void func_5325796288(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(45);
        extend(39);
        extend(122);
        extend(39);
        return;
    }
    func_5325777872(depth+1);
    func_5325776752(depth+1);
    return;
}
void func_5325796992(register unsigned depth) {
    if(depth > MAX_DEPTH) {
        extend(118);
        extend(111);
        extend(105);
        extend(100);
        extend(122);
        extend(59);
        return;
    }
    func_5325776624(depth+1);
    func_5325774784(depth+1);
    func_5325782720(depth+1);
    return;
}
int main(void) {
    static unsigned count = -1;
    seed = time(NULL);
    endless = true;
    while(endless || (count>0) ) {
        func_5325776144(1);
        count--;
        printf("%.*s\n", (int)buffer.top, buffer.data);
        clean();
    }
    return 0;
}
