class Singleton
{
private:
    static Singleton* m_instance;
    Singleton(){}
public:
    static Singleton* getInstance();
};

Singleton* Singleton::getInstance()
{
    if(NULL == m_instance)
    {
        Lock();//借用其它类来实现，如boost
        if(NULL == m_instance)
        {
            m_instance = new Singleton;
        }
        UnLock();
    }
    return m_instance;
}

class SingletonStatic
{
private:
    static const SingletonStatic* m_instance;
    SingletonStatic(){}
public:
    static const SingletonStatic* getInstance()
    {
        return m_instance;
    }
};

//外部初始化 before invoke main
const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;