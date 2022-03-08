#pragma once
#ifndef PRIORITYSTACK_H
#define PRIORITYSTACK_H
template <typename Type>
class PriorityStack {
private:
    struct StackItem {
        int priority = 0;
        Type data;
        StackItem* next = nullptr, * last = nullptr;
    };
    StackItem* top_, * bottom_;
    long size_;


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

    bool isEmpty() const {
        return (!(bool)size_);
    }
    int size() const {
        return size_;
    }
    Type top() const {
        return top_->data;
    }
    Type bottom() const {
        return bottom_->data;
    }
    void push(int priority, const Type& data) {
        try {
            StackItem* temp = new StackItem;
            temp->priority = priority, temp->data = data, size_++;
            if (!top_)
                top_ = bottom_ = temp;
            else {
                StackItem* stackptr = bottom_;
                while (stackptr != nullptr) {
                    if (temp->priority < stackptr->priority) {
                        if (stackptr == bottom_) {
                            bottom_->last = temp;
                            temp->next = bottom_;
                            bottom_ = temp;
                        }
                        else {
                            temp->last = stackptr->last;
                            stackptr->last = temp;
                            temp->next = stackptr;
                            stackptr = temp->last;
                            stackptr->next = temp;
                        }
                        return;
                    }
                    stackptr = stackptr->next;
                }
                // if the inserted element has the maximum priority from the entire stack
                top_->next = temp, temp->last = top_, top_ = temp;
            }
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
    PriorityStack operator()(int priority) {
        if (isEmpty()) throw new std::exception("The stack is empty");
        PriorityStack temp;
        StackItem* stackptr = bottom_;
        while (stackptr != nullptr) {
            if (stackptr->priority == priority) {
                temp.push(stackptr->priority, stackptr->data);
                if ((stackptr->next)->priority != priority)
                    return temp;
            }
            stackptr = stackptr->next;
        }
        return temp;
    }
    PriorityStack& operator= (const PriorityStack& that) {
        if (this == &that) return *this;
        this->clear();
        if (that.isEmpty()) return *this;
        StackItem* temp = that.bottom_;
        do {
            this->push(temp->priority, temp->data);
            temp = temp->next;
        } while (temp != nullptr);
        return *this;
    }
    friend PriorityStack operator+ (const PriorityStack& left, const PriorityStack& right) {
        PriorityStack stack;
        if (left.isEmpty() && right.isEmpty())
            return stack;
        if (left.isEmpty()) {
            stack = right;
            return stack;
        }
        if (right.isEmpty()) {
            stack = left;
            return stack;
        }
        stack = left;
        StackItem* temp = right.top_;
        while (temp != nullptr) {
            stack.push(temp->priority, temp->data);
            temp = temp->last;
        }
        return stack;
    }
    friend std::ostream& operator<< (std::ostream& out, const PriorityStack& stack) {
        if (stack.isEmpty()) {
            out << "Stack is empty";
            return out;
        }
        StackItem* temp = stack.top_;
        out << "[";
        while (temp->last != nullptr)
            out << "(" << temp->priority << ", " << temp->data << "),\n", temp = temp->last;
        out << "(" << temp->priority << ", " << temp->data << ")]";
        return out;
    }

    friend bool operator> (const PriorityStack& left, const PriorityStack& right) {
        return (left.size() > right.size());
    }
    friend bool operator< (const PriorityStack& left, const PriorityStack& right) {
        return (left.size() < right.size());
    }
    friend bool operator== (const PriorityStack& left, const PriorityStack& right) {
        return (left.size() == right.size());
    }
    friend bool operator!= (const PriorityStack& left, const PriorityStack& right) {
        return (left.size() != right.size());
    }
    friend bool operator>= (const PriorityStack& left, const PriorityStack& right) {
        return (left.size() >= right.size());
    }
    friend bool operator<= (const PriorityStack& left, const PriorityStack& right) {
        return (left.size() <= right.size());
    }

    ~PriorityStack() { clear(); }
};
#endif PRIORITYSTACK_H