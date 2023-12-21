class single{
public:
    static single* getinstance();

private:
    single(){}
    ~single(){}
    static single* p;
};

single* single::p = new single();
single* single::getinstance(){
    return p;
}
