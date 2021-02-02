struct TestCaseBase {
    virtual void run() = 0;
    int get_check_passed() const { return check_passed; }
    int get_check_total() const { return check_total; }

protected:
    void check(bool condition, const std::string &) {
        check_passed += condition;
        check_total++;
    }

private:
    int check_passed = 0;
    int check_total = 0;
};

struct TestCaseTwoPlusTwo : TestCaseBase {
    void run() {
        // .....
    }
};
