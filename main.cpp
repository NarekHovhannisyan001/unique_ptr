#include "unique_ptr.hpp"

int main() {
    Unique_ptr<int> intPtr(new int(42));
    std::cout << "Value: " << *intPtr << std::endl;

    class MyClass {
    public:
        void print() const {
            std::cout << "Hello from MyClass!" << std::endl;
        }
    };

    Unique_ptr<MyClass> classPtr(new MyClass);
    classPtr->print();

    Unique_ptr<MyClass> movedPtr = std::move(classPtr);

    if (!classPtr.get()) {
        std::cout << "classPtr is nullptr after move." << std::endl;
    }

    movedPtr->print();

    movedPtr.reset(MyClass());
    movedPtr->print();

    MyClass* rawPtr = movedPtr.release();
    rawPtr->print();

    delete rawPtr;

    return 0;
}
