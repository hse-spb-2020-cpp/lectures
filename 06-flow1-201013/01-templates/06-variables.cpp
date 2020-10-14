template<typename T>
const T default_value{};

int main() {
    // complex_type<int>::some_const
    [[maybe_unused]] auto x = default_value<int>;
    [[maybe_unused]] auto y = default_value<double>;
}
