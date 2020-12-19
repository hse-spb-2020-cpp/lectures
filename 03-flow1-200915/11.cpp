struct Point {
    int x = 0, y = 0;

    // метод / method - жаргон из Java
    // member function / функция-член - C++
    int dist2() {
        return x * x + y * y;
    }

    int dist4() {
        return dist2() * dist2();
    }
};

int main() {
    Point p1;
    Point p2 = {10};
    Point p3 = {10, 20};
    int d = p3.dist2();
}
