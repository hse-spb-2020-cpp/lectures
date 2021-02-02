// https://isocpp.org/wiki/faq/proper-inheritance

// OK
struct Circle {
    virtual void setRadius(int r);
};

struct Ellipse : Circle {
    virtual void setWidth(int w);
    virtual void setHeight(int h);
};

// WTF
struct Circle {
    virtual int radius();
};

struct Ellipse : Circle {
    virtual int radius() { ????????????? }
    virtual int width();
    virtual int height();
};

// OK
struct Ellipse {
    int width();
    int height();
};

struct Circle : Ellipse {
    int radius();
};

// WTF
struct Ellipse {
    virtual void setWidth(int w);
    virtual void setHeight(int h);
};

struct Circle : Ellipse {
    virtual void setWidth() { ..... }
    void setRadius(int r);
};

Ellipse &e = ......
e.setWidth(10);
e.setHeight(20);
assert(e.width() == 10);
assert(e.height() == 20);
