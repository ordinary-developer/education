
class Point { };

class Graphic { 
    public:
        void Move(const Point& point) { }
};

class ConstraintSolverMemento { 
    public:
        virtual ~ConstraintSolverMemento() = default;
        
    private:
        friend class ConstraintSolver;
        ConstraintSolverMemento() { }
};

class ConstraintSolver {
    public:
        static ConstraintSolver* Instance() {
            if (nullptr == _instance) 
                _instance = new ConstraintSolver;
            return _instance;
        }

        void Solve() { }

        void AddConstraint(Graphic* startConnection,
                           Graphic* endConnection) { }

        void RemoveConstraint(Graphic* startConnection,
                              Graphic* endConnection) { }

        ConstraintSolverMemento* CreateMemento() {
            return new ConstraintSolverMemento;
        }

        void SetMemento(ConstraintSolverMemento* memento) {
            _memento = memento;
        }

    private:
        static ConstraintSolver* _instance;
        ConstraintSolverMemento* _memento;
};

ConstraintSolver* ConstraintSolver::_instance;

class MoveCommand {
    public:
        MoveCommand(Graphic* target, const Point& delta) 
            : _target(target), _delta(delta) { }

        void Execute() { 
            ConstraintSolver* solver = ConstraintSolver::Instance();
            _state = solver->CreateMemento();
            _target->Move(_delta);
            solver->Solve();
        }
        void Unexecute() { 
            ConstraintSolver* solver = ConstraintSolver::Instance();
            _target->Move(_delta); // -delta
            solver->SetMemento(_state);
            solver->Solve();
        }

    private:
        Graphic* _target;
        Point _delta;
        ConstraintSolverMemento* _state;
};

int main() {
    Graphic g1;
    Point point;
    MoveCommand command(&g1, point);

    command.Execute();
    command.Unexecute();

    return 0;
}
