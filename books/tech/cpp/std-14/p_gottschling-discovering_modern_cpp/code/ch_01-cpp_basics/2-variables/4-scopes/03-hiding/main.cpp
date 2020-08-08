int main() {
    int a = 5;
    {
        a = 3;
        int a;
        a = 8;
        {
            a = 7;
        }
    }
    a = 11;

    return 0;
}
