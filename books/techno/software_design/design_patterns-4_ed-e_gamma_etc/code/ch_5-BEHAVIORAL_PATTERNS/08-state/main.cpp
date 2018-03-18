class TCPState;
class TCPOctetStream { };

class TCPConnection {
    public:
        TCPConnection();

        void ActiveOpen();
        void PassiveOpen();
        void Acknowledge(); 
        void Synchronize();
        void Send();
        void Close();

        void ProcessOctet(TCPOctetStream*) { }

    private:
        friend class TCPState;

        void ChangeState(TCPState* s) { 
            _state = s;
        }

        TCPState* _state;
};

class TCPState {
    public:

        virtual void Transmit(TCPConnection*, TCPOctetStream*) { }
        virtual void ActiveOpen(TCPConnection*) { }
        virtual void PassiveOpen(TCPConnection*) { }
        virtual void Acknowledge(TCPConnection*) { }
        virtual void Synchronize(TCPConnection*) { }
        virtual void Send(TCPConnection*) { }
        virtual void Close(TCPConnection*) { }

    protected:
        void ChangeState(TCPConnection* t, TCPState* s) { 
            t->ChangeState(s);
        }
};

class TCPListen : public TCPState {
    public:
        static TCPState* Instance() {
            if (nullptr == _state)
                _state = new TCPListen;
            return _state;
        }

        virtual void Send(TCPConnection* t) final override {
        }

    private:
        static TCPListen* _state;
};
TCPListen* TCPListen::_state;

class TCPEstablished : public TCPState {
    public:
        static TCPState* Instance() {
            if (nullptr == _state)
                _state = new TCPEstablished;
            return _state;
        }

        virtual void Transmit(TCPConnection* t,
                              TCPOctetStream* o) final override
        {
            t->ProcessOctet(o);
        }

        virtual void Close(TCPConnection* t) final override
        {
            ChangeState(t, TCPListen::Instance());
        }

    private:
        static TCPEstablished* _state;
};
TCPEstablished* TCPEstablished::_state;

class TCPClosed : public TCPState {
    public:
        static TCPState* Instance() {
            if (nullptr == _state)
                _state = new TCPClosed;
            return _state;
        }

        virtual void ActiveOpen(TCPConnection* t) final override {
            ChangeState(t, TCPEstablished::Instance());
        }

        virtual void PassiveOpen(TCPConnection* t) final override {
            ChangeState(t, TCPListen::Instance());
        }

    private:
        static TCPClosed* _state; 
};
TCPClosed* TCPClosed::_state;



//--------------
TCPConnection::TCPConnection() {
    _state = TCPClosed::Instance();
}

void TCPConnection::ActiveOpen() {
    _state->ActiveOpen(this);
}

void TCPConnection::PassiveOpen() {
    _state->PassiveOpen(this);
}

void TCPConnection::Close() {
    _state->Close(this);
}

void TCPConnection::Acknowledge() {
    _state->Acknowledge(this);
}

void TCPConnection::Send() {
    _state->Send(this);
}

void TCPConnection::Synchronize() {
    _state->Synchronize(this);
}


int main() {
    TCPConnection connection;
    connection.ActiveOpen();

    return 0;
}
