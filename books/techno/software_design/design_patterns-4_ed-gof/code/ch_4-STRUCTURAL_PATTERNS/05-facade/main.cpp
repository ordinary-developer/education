

class CodeGenerator;

class ProgramNode {
    public:
        ProgramNode() = default;
        virtual ~ProgramNode() = default;

        virtual void GetSourcePotision(int& line, int& index) { }

        virtual void Add(ProgramNode*) { }
        virtual void Remove(ProgramNode*) { }

        virtual void Traverse(CodeGenerator&)  { }
};


class ProgramNodeBuilder {
    public:
        ProgramNodeBuilder() : _node(new ProgramNode()) { }
        virtual ~ProgramNodeBuilder() = default;

        virtual ProgramNode* 
            NewVariable(const char* variableName) const
        {
            return new ProgramNode();
        }

        virtual ProgramNode* NewAssignment(ProgramNode* variable,
                                           ProgramNode* expr) const
        {
            return new ProgramNode();
        }

        virtual ProgramNode* NewReturnStatement(ProgramNode* value) 
                                                                const
        {
            return new ProgramNode();
        }

        virtual ProgramNode* NewCondition(ProgramNode* condition,
                                          ProgramNode* truePart,
                                          ProgramNode* falsePart) const
        {
            return new ProgramNode();
        }

        ProgramNode* GetRootNode() { return _node; }

    private:
        ProgramNode* _node;
};


class Stream { };
class Token { };

class Scanner {
    public:
        Scanner(Stream& inputStream) 
            : _inputStream(inputStream) { }
        virtual ~Scanner() = default;

        virtual Token& Scan() { return _token; }

    private:
        Token _token;
        Stream& _inputStream;
};

class Parser {
    public:
        Parser() = default;
        virtual ~Parser() = default;

        virtual void Parse(Scanner&, ProgramNodeBuilder&) { }
};


class BytecodeStream { };

class CodeGenerator {
    public:
        CodeGenerator(BytecodeStream& output) 
            : _output(output) { }
        virtual void Visit(ProgramNode*) { }

    private:
        BytecodeStream& _output;
};

class Compiler {
    public:
        Compiler() = default;

        virtual void Compile(Stream& input, BytecodeStream& output) {
            Scanner scanner(input);
            ProgramNodeBuilder builder;
            Parser parser;

            parser.Parse(scanner, builder);

            CodeGenerator generator(output);
            ProgramNode* parseTree =  builder.GetRootNode();
            parseTree->Traverse(generator);
        }
};

int main() {
    Stream input;
    BytecodeStream output;
    Compiler().Compile(input, output);

    return 0;
}
