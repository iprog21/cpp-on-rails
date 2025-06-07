#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <stdexcept>

struct TestCase { std::string name; std::function<void()> func; };

inline std::vector<TestCase>& getTests(){
    static std::vector<TestCase> tests;
    return tests;
}

inline void registerTest(const std::string& name, std::function<void()> func){
    getTests().push_back({name, func});
}

#define TEST_CASE(name) \
    void name(); \
    struct name##_registrar { name##_registrar(){ registerTest(#name, name); } }; \
    static name##_registrar name##_registrar_instance; \
    void name()

#define REQUIRE(cond) \
    do { \
        if(!(cond)){ \
            std::cerr << __FILE__ << ":" << __LINE__ << " failed: " << #cond << "\n"; \
            throw std::runtime_error("test failure"); \
        } \
    } while(0)

inline int runTests(){
    int failures = 0;
    for(auto& t : getTests()){
        try {
            t.func();
            std::cout << t.name << " - ok" << std::endl;
        } catch(const std::exception& e){
            std::cout << t.name << " - failed: " << e.what() << std::endl;
            failures++;
        }
    }
    return failures;
}
