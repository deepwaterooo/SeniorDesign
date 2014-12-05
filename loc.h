#ifndef LOC_H
#define LOC_H

class Loc {
 public:
    Loc(int sx, int sy) { x = sx; y = sy;}
    void setX(Loc src){ x = src.x; }
    void setY(Loc src){ y = src.y; }
    int getX(Loc src){ return src.x; }
    int getY(Loc src){ return src.y; }
    int getmX(){ return x; }
    int getmY(){ return y; }
 private:
    int x;
    int y;
};
#endif
