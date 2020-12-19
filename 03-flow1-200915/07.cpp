std::vector<int> vec;

int foo() {
    vec.push_back(2);
    return 10;
}

int main() {
    vec.push_back(1);
    // vec.size() == 1
    vec[0] = foo();
}
