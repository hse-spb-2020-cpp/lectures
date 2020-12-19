//#define DEBUG
//-DDEBUG


class Summer { private:
//struct Summer { public:
    #ifdef DEBUG
    vector<int> data;
    #endif
    vector<int> pref_sum;

public:
    void init(const vector<int> &data_) {
        #ifdef DEBUG
        data = data_;
        #endif
        pref_sum.resize(data_.size() + 1);
        for (......) .....
    }

    int getSum(int L, int R) {
        assert(0 <= L);
        assert(L <= R);
        assert(R + 1 < pref_sum.size());
        return pref_sum[R + 1] - pref_sum[L];
    }
};

int main() {
    vector<int> a = {10, 20, 30};
    Summer a_sum;
    a_sum.init(a);

    assert(a_sum.getSum(1, 2) == 50);
/*    vector<int> pref_sum = {
        0,
        a[0],
        a[0] + a[1],
        a[0] + a[1] + a[2]
    };

    int L, R;
    int sum = pref_sum[R + 1] - pref_sum[L];*/
}
