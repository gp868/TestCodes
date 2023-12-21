class single{
public:
    static single* getinstance();
private:
    single(){}
    ~single(){}
    
};

single* single::getinstance(){
    static single p;
    return &p;
}