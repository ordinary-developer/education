class MyClass {
	public:
		MyClass() = default;
		MyClass(const MyClass& rhs) = default;
		
	private:
		int m_Member;
};


int main() {
	MyClass objectA;
	
	// here an error will be
	// MyClass objectB(MyClass());
	
	return 0;
}
