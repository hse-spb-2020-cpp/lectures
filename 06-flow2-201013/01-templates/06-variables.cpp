template<typename T>
const T default_value{};

int main() {
    [[maybe_unused]] auto x = default_value<int>;
    [[maybe_unused]] auto y = default_value<double>;
    default_value<double> = 20.5;
}
very_very_complex_container<int>::default_capacity
default_capacity<int>
