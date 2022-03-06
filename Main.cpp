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
        StackItem* temp = that.bottom_;
        do {
            this->push(temp->priority, temp->data);
            temp = temp->next;
        } while (temp != nullptr);
    }

    bool isEmpty() const { return (!(bool)size_); }
    int size() const { return size_; }
    Type top() const { return top_.data; }
    Type bottom() const { return bottom_.data; }
    void push(int priority, const Type& data) {
        try {
            StackItem* temp = new StackItem;
            temp->priority = priority, temp->data = data;
            if (!top_)
                top_ = bottom_ = temp;
            else
                top_->next = temp, temp->last = top_, top_ = temp;
            size_++;
        }
        catch (const std::bad_alloc& error) {
            std::cout << "Error: " << error.what() << std::endl;
        }
    }
    Type pop() {
        return popMaxPriority();
    }
    Type popMaxPriority() {
        if (isEmpty()) throw new std::exception("The stack is empty");
        StackItem* temp = top_;
        Type data = temp->data;
        size_--;
        if (top_ == bottom_) {
            delete temp;
            top_ = bottom_ = nullptr;
            return data;
        }
        top_ = temp->last, top_->next = nullptr;
        delete temp;
        return data;
    }
    Type popMinPriority() {
        if (isEmpty()) throw new std::exception("The stack is empty");
        StackItem* temp = bottom_;
        Type data = temp->data;
        size_--;
        if (top_ == bottom_) {
            delete temp;
            top_ = bottom_ = nullptr;
            return data;
        }
        bottom_ = temp->next, bottom_->last = nullptr;
        delete temp;
        return data;
    }
    void clear() {
        while (top_ != bottom_) {
            StackItem* temp = top_;
            top_ = temp->last;
            delete temp;
        }
        if (top_ == bottom_) {
            StackItem* temp = top_;
            delete temp;
            top_ = bottom_ = nullptr;
        }
        size_ = 0;
    }

    Type& operator[](int index) {
        if (isEmpty()) throw new std::exception("The stack is empty");
        if (index < 0 || index > size() - 1) throw new std::exception("Going beyond the stack");
        StackItem* temp = bottom_;
        for (auto i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
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
    stack.push(10, "Hello world!");
    stack.push(3, "I'm Daniil");
    stack.push(4, "and I'm programmer");
    PriorityStack <std::string> stack1 = stack;
    stack.clear();
    std::cout << stack1[2];
    return 0;
}