using namespace std;

class MyBoolVector {
public:
	MyBoolVector();
	MyBoolVector(const MyBoolVector& v);
	~MyBoolVector();
	
	void pop_back();
	void push_back(bool x);
	size_t capacity() const;
	size_t size() const;
	void reserve(size_t n);
	bool is_empty() const;
	void clear();

	bool operator = (const MyBoolVector& source);
	bool operator +=(const MyBoolVector& addend);
	bool operator [](size_t num);
	bool operator +(const MyBoolVector& v);
	bool operator -();
	bool operator ==(const MyBoolVector& v);
	bool operator !=(const MyBoolVector& v);

	typedef bool value_type;
private:
	bool* data;
	size_t v_used;
	size_t v_capacity;
};