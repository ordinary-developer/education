#include <cstring>
#include <unordered_map>
#include <iostream>

class Context;
class BooleanExp;
class VariableExp;

class Context {
    public:
        bool Lookup(char* name) const;
        void Assign(VariableExp* exp, bool value);

    private:
        std::unordered_map<char*, bool> _symbolTable;
};

class BooleanExp {
    public:
        virtual ~BooleanExp() = default;

        virtual bool Evaluate(Context&) = 0;
        virtual BooleanExp* Replace(char*, BooleanExp&) = 0;
        virtual BooleanExp* Copy() const = 0;
};

class VariableExp : public BooleanExp {
    public:
        VariableExp(char* name) : _name(name) { }
        virtual ~VariableExp() final override = default;

        virtual bool Evaluate(Context& aContext) final override { 
            return aContext.Lookup(_name);
        }

        virtual BooleanExp* Replace(char* name,
                                    BooleanExp& exp) final override 
        {
            if (0 == strcmp(name, _name)) {
                return exp.Copy();
            }
            else {
                return new VariableExp(_name);
            }
        }

        virtual BooleanExp* Copy() const final override {
            return new VariableExp(_name);
        }

        char* GetName() { return _name; }

    private:
        char* _name;
};



class AndExp : public BooleanExp {
    public:
        AndExp(BooleanExp* operand1, BooleanExp* operand2)
            : _operand1(operand1), _operand2(operand2) { }

        virtual ~AndExp() final override = default;

        virtual bool Evaluate(Context& context) final override {
            return _operand1->Evaluate(context) 
                   &&
                   _operand2->Evaluate(context);
        }

        virtual BooleanExp* Replace(char* name, 
                                    BooleanExp& exp) final override
        {
            return new AndExp(_operand1->Replace(name, exp),
                              _operand2->Replace(name, exp));
        }

        virtual BooleanExp* Copy() const final override {
            return new AndExp(_operand1->Copy(), _operand2->Copy());
        }

    private:
        BooleanExp* _operand1;
        BooleanExp* _operand2;
};


bool Context::Lookup(char* name) const {
    return _symbolTable.find(name)->second;
}

void Context::Assign(VariableExp* exp, bool value) {
    _symbolTable[exp->GetName()] = value; 
}

int main() {
    BooleanExp* expression;
    Context context;

    VariableExp* x = new VariableExp("X");
    VariableExp* y = new VariableExp("Y");

    context.Assign(x, true);
    context.Assign(y, false);

    expression = new AndExp(x, y);

    bool result = expression->Evaluate(context);
    std::cout << (result ? "true" : "false") << std::endl;

    VariableExp* z = new VariableExp("Z");
    BooleanExp* replacement = expression->Replace("Y", *z);
    context.Assign(z, true);

    result = replacement->Evaluate(context);
    std::cout << (result ? "true" : "false") << std::endl;

    return 0;
}
