class View {
    public:
        virtual ~View() = default;

        void Display() {
            SetFocus();
            DoDisplay();
            ResetFocus();
        }

    protected:
        virtual void DoDisplay() { }

    private:
        void SetFocus() { }
        void ResetFocus() { }
};

class MyView : public View {
    public:
        virtual ~MyView() final override = default;

    protected:
        virtual void DoDisplay() final override { }
};

int main() {
    View* view= new MyView;
    view->Display();

    return 0;
}
