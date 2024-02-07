int* p = new int(25);
float* q = new float(75.25);
 
// Custom data type
struct cust
{
    int p;
    cust(int q) : p(q) {}
    cust() = default;
    //cust& operator=(const cust& that) = default;
};
 
int main()
{
    // Works fine, doesn’t require constructor
    cust* var1 = new cust;
 
    //OR
 
    // Works fine, doesn’t require constructor
    var1 = new cust();
 
    // Notice error if you comment this line
    cust* var = new cust(25);
    return 0;
}