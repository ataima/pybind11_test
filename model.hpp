

#include <string>
#include <sstream>
#include <iostream>

class POS;

class SIZE {
public:
    int width;
    int height;
    SIZE(const int w=0, const int h=0) {
        width=w;
        height=h;
    }
    SIZE & operator=( const SIZE  & other) {
        if(this==&other)
            return *this;
        width=other.width;
        height=other.height;
        return *this;
    }
    SIZE & operator+=(  const SIZE &  other) {
        width+=other.width;
        height+=other.height;
        return *this;
    }
    SIZE & operator-=(  const SIZE  & other) {
        width-=other.width;
        height-=other.height;
        return *this;
    }
    void inflate(const int w,const int h) {
        width+=w;
        height+=h;
    }
    void fromPos (const POS & p);
    std::string toString()  {
        return "[W:" + std::to_string(width) + ",H: " + std::to_string(height) + "]";
    }
    friend SIZE  operator+(const SIZE &a, const SIZE&b){
	    return SIZE(a.width+b.width,a.height+b.height);
    }
    friend SIZE  operator-(const SIZE &a, const SIZE&b){
	    return SIZE(a.width-b.width,a.height-b.height);
    }
};

class POS {
public:
    int X;
    int Y;
    POS(const int x=0, const int y=0) {
        X=x;
        Y=y;
    }
    POS & operator=( const POS & other) {
        if(this==&other)
            return *this;
        X=other.X;
        Y=other.Y;
        return *this;
    }
    POS & operator+=( const POS  & other) {
        X+=other.X;
        Y+=other.Y;
        return *this;
    }
    POS & operator-=(  const POS  & other) {
        X-=other.X;
        Y-=other.Y;
        return *this;
    }
    void fromSize (const SIZE & p) {
        X=p.width;
        Y=p.height;
    }
    void move(const int mx, const int my) {
        X+=mx;
        Y+=my;
    }
    void move(const POS &p) {
        X+=p.X;
        Y+=p.Y;
    }
    std::string toString()  {
        return "[X:" + std::to_string(X) + ",Y: " + std::to_string(Y) + "]";
    }
    friend POS  operator+(const POS &a, const POS&b){
	    return POS(a.X+b.X,a.Y+b.Y);
    }
    friend POS  operator-(const POS &a, const POS&b){
	    return POS(a.X-b.X,a.Y-b.Y);
    }
};

void SIZE::fromPos (const POS & p) {
    width=p.X;
    height=p.Y;
}


class IObj {
public:
    virtual std::string toString()=0;
    virtual const SIZE & getSize()=0;
    virtual const POS &  getPos()=0;
    virtual void setSize(const SIZE & s)=0;
    virtual void setPos(const POS & p)=0;
    virtual void move(const int mx, const int my)=0;
};



class BaseObj:
    public IObj {
protected:
    SIZE size;
    POS  pos;
public:
    BaseObj() {}
    virtual ~BaseObj() {}
    BaseObj(const int x, const int y, const int w=0, const int h=0) {
        pos.X=x;
        pos.Y=y;
        size.width=w;
        size.height=h;
    }
    // request
    const SIZE & getSize() final {return size;}
    const POS &  getPos() final { return pos; }
    void setSize(const SIZE & s) final{ size=s;}
    void setPos(const POS & p) final  { pos=p;}
    virtual std::string toString() {
        std::stringstream ss;
        ss<<"class BaseObj : X="<<pos.X<<",Y="<<pos.Y<<",W="<<size.width<<",H="<<size.height<<std::endl;
        return ss.str();
    }
    void move(const int mx, const int my) final {
        pos.move(mx,my);
    }
    void move(const POS & p) {
        pos.move(p);
    }
    void inflate (const int w,const int h) {
        size.inflate(w,h);
    }
};

class Circle:
    public BaseObj {
    int radius;
public :
    Circle() {}
    Circle(const int x, const int y, const int r=0):
        BaseObj(x,y) {
        setRadius(r);
    }
    virtual std::string toString() {
        std::stringstream ss;
        ss<<"class Circle : X="<<pos.X<<",Y="<<pos.Y<<",W="<<size.width<<",H="<<
          size.height<<",R="<<radius<<std::endl;
        return ss.str();
    }

    void setRadius(const int  r) {
        int w=2*r;
        radius=r;
        inflate(w,w);
    }

};

class Rectangle:
    public BaseObj {
public :
	// I not resolving problem class with no costructor
    Rectangle():BaseObj() {}
    Rectangle(const int x, const int y, const int w=0, const int h=0):
	    BaseObj(x,y,w,h) {}
     //		    
    virtual std::string toString() {
        std::stringstream ss;
        ss<<"class Rectangle : X="<<pos.X<<",Y="<<pos.Y<<",W="<<size.width<<",H="<<
          size.height<<std::endl;
        return ss.str();
    }
};

