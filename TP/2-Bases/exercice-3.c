int main(void) {
    int x = 8; 
    int y = 5; 
    float z = -0.7; 
    float w = -0.3; 
    char p = 'c'; 
    char q = 'd';

    (5*x - 2*y)% (4*p - q)              // 30 % (396 - 100) = 30 % 296 = 0
    2*((x/3)) + (4*(y-5))%(x + y -2)    // 4 + (0 % 11) = 4
    x <= y                              // false
    y!=6                                // true
    p==99                               // true
    (x>0)&&(y<5)                        // false
    (x>0)||(y<5)                        // true
    (z>w)&&(x>0)||(y<5)                 // true

    return 0;
}