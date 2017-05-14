enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              indeterminate = 0xFFFFFFFF
};

// all project after unscoped enum modification must be recompiled
/*
enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              audited = 500,
              indeterminate = 0xFFFFFFFF
};*/


// forward declaration of an enum
// the projet need not be recompiled
enum class ScopedStatus;

void continueProcessing(ScopedStatus s);

int main() {
    
}
