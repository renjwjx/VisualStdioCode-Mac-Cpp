
class Singleton
{
    public:
        static Singleton* GetInstance();
        void show();
    private:
        Singleton() {}
        static Singleton *singleton;
};
