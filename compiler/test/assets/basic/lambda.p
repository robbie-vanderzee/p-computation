int main() {
    Number x = { 0, 1 }; // 2
    auto add_lambda = [x](Number p){
        return x + p;
    };
    return 0;
}