int main(void) {
    int x, y;

    x=5+7*4+12%3;   // x = 5 + 28 = 33
    x=5+(7%2);      // 8
    x=(5+7)%2;      // 6
    x=3; y = ++x;   //x=4,y=4 
    x=3; y = x++;   //x=4,y=3

    return 0;
}