#include <iostream>
#include <vector>
#include <string>

template <typename Type>
class PriorityStack {
private:
    struct StackItem {
        int priority = 0;
        Type data;
        StackItem* next = nullptr, * last = nullptr;
        bool operator< (const StackItem& right) const {
            return priority < right.priority;
        }
        bool operator> (const StackItem& right) const {
            return priority > right.priority;
        }
    };
    StackItem* top_, * bottom_;
    long size_;



protected:
    StackItem& topItem() const { return top_; }
    StackItem& bottomItem() const { return bottom_; }
    void push(int priority, const Type& data) {
        try {
            StackItem* temp = new StackItem;
            temp->priority = priority, temp->data = data;
            if (!top_)
                top_ = bottom_ = temp;
            else
                temp->last = top_, top_->next = temp, top_ = temp;
            size_++;
        }
        catch (const std::bad_alloc& error) {
            std::cout << "Error: " << error.what() << std::endl;
        }
    }
    std::vector <Type> getArray(const PriorityStack& stack) {
        std::vector <Type> temp(stack.size());
        //TODO
        return;
    }



public:
    PriorityStack() : size_(0), top_(nullptr), bottom_(nullptr) { }
    PriorityStack(const PriorityStack& that) {
        size_ = 0, top_ = bottom_ = nullptr;
        if (that.isEmpty()) return;
        //TODO 
    }

    bool isEmpty() const { return (!(bool)size_); }
    int size() const { return size_; }
    Type top() const { return top_.data; }
    Type bottom() const { return bottom_.data; }
    Type pop() {
        if (isEmpty()) throw new std::exception("The stack is empty");
        //TODO
        return;
    }
    Type popMaxPriority() {
        if (isEmpty()) throw new std::exception("The stack is empty");
        //TODO
        return;
    }
    Type popMinPriority() {
        if (isEmpty()) throw new std::exception("The stack is empty");
        //TODO
        return;
    }
    void clear() {
        //TODO
    }

    Type& operator[](int index) {
        if (isEmpty()) throw new std::exception("The stack is empty");
        //TODO
        return;
    }
    PriorityStack& operator()(int priority) {
        if (isEmpty()) throw new std::exception("The stack is empty");
        //TODO
        return;
    }
    PriorityStack& operator= (const PriorityStack& that) {
        if (this == that) return *this;
        this->clear();
        if (that.isEmpty()) return *this;
        //TODO
        return;
    }
    friend PriorityStack operator+ (const PriorityStack& left, const PriorityStack& right) {
        //TODO
        return;
    }
    friend std::ostream& operator<< (std::ostream& out, const PriorityStack& stack) {
        //TODO
        return out;
    }

    friend bool operator> (const StackItem& left, const StackItem& right) { return (left.size() > right.size()); }
    friend bool operator< (const StackItem& left, const StackItem& right) { return (left.size() < right.size()); }
    friend bool operator== (const StackItem& left, const StackItem& right) { return (left.size() == right.size()); }
    friend bool operator!= (const StackItem& left, const StackItem& right) { return (left.size() != right.size()); }
    friend bool operator>= (const StackItem& left, const StackItem& right) { return (left.size() >= right.size()); }
    friend bool operator<= (const StackItem& left, const StackItem& right) { return (left.size() <= right.size()); }

    ~PriorityStack() { clear(); }
};

int main() {
    PriorityStack <std::string> stack;

    return 0;
}